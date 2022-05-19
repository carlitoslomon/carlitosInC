/*
 * Name: Carlos López 
 *UNI: cal2266
 *Lab 2 part 1
 * This fie sorts an array of n integers allocating some memory in malloc 
 */
#include <stdio.h> 
#include <stdlib.h>
#include <time.h>
#include <string.h>
int*  mkarr(int n); 
void sort_integer_array(int *begin, int *end, int ascending); 
void printarr( int *arr, int n);
void copyarrs(int *main, int *copy1, int *copy2, int n);
int comparatorA(const void *p, const void *q);
int comparatorD(const void *p, const void *q);
void isort(int n);
int main(){
  int n; 
  printf("Enter an integer N \n"); 
  scanf("%d", &n);
  printf("\n You entered %d ok!\n", n);
  isort(n);
  return 0; 

}

void isort(int n){
	int *arr1 = mkarr(n);
	int *arr2 = mkarr(n); 
	int *arr3 = mkarr(n);
	copyarrs(arr1, arr2, arr3, n);
	sort_integer_array(arr2, &(*(arr2+n-1)), 1); // array name is equivalent to &arr[0]
	sort_integer_array(arr3, &(*(arr3+n-1)), 0); // array name is equivalent to &arr[0]
	printf("\n\noriginal: ");
	printarr(arr1, n);
	printf("\n\nascending: "); 
	printarr(arr2, n); 
	printf("\n\ndescending: "); 
	printarr(arr3, n);
	printf("\n");
}

int*  mkarr(int n){
  int *p = (int*)malloc(n*sizeof(int));
  if(p==NULL){
    perror("malloc returned null"); 
    exit(1); 
  } 
  return p;
}

void sort_integer_array(int *begin,int *end, int ascending){ 
	int len =(int) (end - begin+1); // basically lenth of array
	qsort(begin, len, sizeof(int),(int (*)(const void *, const void *))(ascending ? comparatorA:comparatorD)); //used modified qsort from the textbook
       //check README.txt for refrences	
}
void printarr(int *arr, int n){
	int i =0; 
	while(i < n){
		printf(" %d  ",arr[i]);
		i++; 
	}
	free(arr);
}

void copyarrs(int *main, int *copy1,int *copy2, int n ){
    srand((unsigned) time(NULL));
    for(int i = 0; i < n; i++){ 
      *(main+i)= (random()%99 +1); 
      //*(copy1+i) = *(main+i);
      //*(copy2+i) = *(main+i); 
  } 
  
  for(int j = 0; j< n; j++){
	  *(copy1+j) = *(main + j);
	  *(copy2 +j) = *(main+j);

      
  }

}
int comparatorA(const void *p, const void *q)
{  //A for ascending 
    int l = *( int *)p;
    int r = *(int *)q;
    if(l < r){
      return -1;
    }
    else if(l > r){
      return 1;
    }
    else{
      return 0; 
    }
} 
int comparatorD(const void *p, const void *q)
{//D for descending 
    int l = *(int *)p;
    int r = *( int *)q;
    if(l < r){
      return 1;
    }
    else if(l > r){
      return -1; 
    }
    else{
      return 0;
    }
}
