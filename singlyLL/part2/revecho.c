/*
 *Name: Carlos Alberto López Montealegre
 *UNI: cal2266
 *Description: part 2 of lab. This c file gets strings as arguments prints then in reverse order 
 *and determines if a case-sensitive word is within the set of strings. 
 */
#include <stdio.h> 
#include <stdlib.h>
#include <mylist.h>
#include <string.h>
void printStr(void *list1);
void printFound(struct List *list1);
void dudeFound(struct List *list1);
int compareString(const void  *p, const void  *q);
static void die(const char *message)
{
    perror(message);
    exit(1); 
}
int main(int argc, char **argv){
   struct List listR;
   if(argc >1){
	   initList(&listR);
	   for(int i=1; i < argc;i++){
		if( addFront(&listR, argv[i])==NULL)
			die("addFron() messed up dude");
	   } 
	   traverseList(&listR, &printStr);
	   dudeFound(&listR);
	   removeAllNodes(&listR);           	    
   }
   return 0;
  
}
void printStr(void *list1){
		printf("%s\n",(char*)list1);
}
void dudeFound(struct List *list1){
	char* p = "dude";

	struct Node * result = findNode(list1, p,&compareString);
	if(result!=NULL){
	       printf("\ndude found\n");
	}	
	else 
		printf("\ndude not found\n");	
}
int compareString(const void  *p, const void  *q){
	const char *p1 = (char*)p;
	const char *q1 = (char*)q;
	int val = 0;
       	int i = 0; 
	while(i < strlen(p)){
		if(*p1!=*q1)
			val = 1;
		q++;
		p++;
		i++;
	}
	
	return val; 
}
