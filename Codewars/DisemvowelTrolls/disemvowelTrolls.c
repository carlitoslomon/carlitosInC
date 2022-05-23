#include <string.h>
#include <stdlib.h>
#include <stdio.h>
char *disemvowel(const char *str)
{
  
  int len = strlen(str) + 1;
  char *c = (char*) malloc(len);
  int y = 0;
  for(int i =0; i < len-1; i++){  
    if( str[i] == 'A' || str[i] == 'a')
          ;
      
    else if( str[i] == 'E' || str[i]== 'e')
       ;
    else if(str[i] == 'I' || str[i] == 'i')
       ;
    else if(str[i] == 'O' || str[i] == 'o')
      ;  
    else if(str[i] == 'U' || str[i] == 'u')
       ;
    else{
      c[y] = str[i];
      y++;
    }
  }
  c[y] = '\0';
  return c;
  
}
int main(){  
  const char *val = "I will make your company work bitch";
  printf("\n %s", val);
  char *retVal = disemvowel(val);
  printf("\n %s",retVal);
  free(retVal);
  return 0;
}

