#include <httpd.h>
#include <http_protocol.h>
#include <http_config.h>
#include <http_log.h>

#include <stdio.h>      /* for printf() and fprintf() */
#include <sys/socket.h> /* for socket(), bind(), and connect() */
#include <arpa/inet.h>  /* for sockaddr_in and inet_ntoa() */
#include <stdlib.h>     /* for atoi() and exit() */
#include <string.h>     /* for memset() */
#include <unistd.h>     /* for close() */
#include <time.h>       /* for time() */
#include <netdb.h>      /* gethostbyname() */

static void die(const char *message)
{
    perror(message);
    exit(1); 
}

static void do_mdb_lookup(request_rec *r)
{
    const char *mdbHost = "localhost";
    unsigned short mdbPort = 9999;

    int sock;
    struct sockaddr_in serverAddr;
    struct hostent *he;
    
    // get server ip from server name
    if ((he = gethostbyname(mdbHost)) == NULL) {
	die("gethoatbyname failed");
    }
    char *serverIP = inet_ntoa(*(struct in_addr *)he->h_addr);
    
    // create socket
    if ((sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0) {
	die("socket failed");
    }

    // construct server address
    memset(&serverAddr, 0, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = inet_addr(serverIP);
    serverAddr.sin_port = htons(mdbPort);

    // connect
    if (connect(sock, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) < 0) {
	die("connect failed");
    }

    FILE *mdbFp = fdopen(sock, "r");
    if (mdbFp == NULL)
	die("fdopen failed");

    const char *requestURI = r->unparsed_uri;

    // send the form
    const char *form =
	"<h1>mdb-lookup</h1>"
	"<p>"
	"<form method=GET action=/mdb-lookup>"
	"lookup: <input type=text name=key>"
	"<input type=submit>"
	"</form>"
	"<p>"
	;
    ap_rprintf(r, "%s", form);

    // do the lookup

    const char *keyURI = "/mdb-lookup?key=";
    if (strncmp(requestURI, keyURI, strlen(keyURI)) == 0) {

	// send the key to mdb-lookup-server
	char key[1000];
	strcpy(key, requestURI + strlen(keyURI));

	fprintf(stderr, "sending %s to mdb-lookup server\n", key);
	fflush(stderr);

	printf("sending %s to mdb-lookup server\n", key);
	fflush(stdout);
	
	strcat(key, "\n");
	if (send(sock, key, strlen(key), 0) != strlen(key)) {
	    return;
	}

	/*
	ap_log_rerror(APLOG_MARK, APLOG_INFO, 0, r, "key :", key);
	ap_log_rerror(APLOG_MARK, APLOG_DEBUG, 0, r, "key :", key);
	*/

	// Read lines from mdb-lookup-server and send thme to the
	// browser, formatted in an HTML table.
	char line[1000];
	char *table_header = "<p><table border>";
	ap_rprintf(r, "%s", table_header);
	int row = 1;
	for (;;) {
	    if (fgets(line, sizeof(line), mdbFp) == NULL) {
		if (ferror(mdbFp))
		    die("IO error");
		else {
		    //fprintf(stdout, "\nmdb-lookup-server connection failed: ");
		    //fflush(stdout);
		    return;
		}
	    }
	    if (strcmp("\n", line) == 0) {
		break;
	    }
	    char *table_row;
	    if (row++ % 2) {
		table_row = "<tr><td>";
	    }
	    else {
		table_row = "<tr><td bgcolor=yellow>";
	    }
	    ap_rprintf(r, "%s", table_row);
	    ap_rprintf(r, "%s", line);
	}
	char *table_footer = "</table>";
	ap_rprintf(r, "%s", table_footer);
    }

    fclose(mdbFp);
}

static int helloworld_handler(request_rec *r)
{
    if (!r->handler || strcmp(r->handler, "mdb-lookup")) {
	return DECLINED;
    }
    if (r->method_number != M_GET) {
	return HTTP_METHOD_NOT_ALLOWED;
    }
    ap_set_content_type(r, "text/html;charset=ascii");
    ap_rputs("<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.01//EN\">\n", r);
    ap_rputs("<html><body>", r);
    do_mdb_lookup(r);
    ap_rputs("</body></html>", r);
    return OK;
}

static void helloworld_hooks(apr_pool_t *pool)
{
    ap_hook_handler(helloworld_handler, NULL, NULL, APR_HOOK_MIDDLE);
}

module AP_MODULE_DECLARE_DATA mdb_lookup_module = {
    STANDARD20_MODULE_STUFF,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    helloworld_hooks
};
