#include <stdio.h> 

int gcd(int n1, int n2); 
int gcd(int n1, int n2){
	int gcdval = 1; 
	int limit; 
	if(n1 > n2){
		limit = n2; 
	}
	else{
		limit = n1; 
	}
	for(int i = 2; i <= limit; i++)
		if( n1%i ==0 && n2%i ==0){
			gcdval = i; 
		}
	return gcdval; 
}


