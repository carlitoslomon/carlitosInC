#include "gcd.h" 
#include "prime.h"
#include <math.h>
#include <stdio.h> 
void primeHelper(int n1, int n2);  
void gcdHelper(int n1, int n2); 

int main(){ 
	int n1, n2; 
	printf("Enter two integers\n"); 
	scanf("%d %d", &n1, &n2);
	double x = (n1+n2)/2.0;
	printf("You entered %d and %d\n", n1, n2);
	printf("The average of %d and %d is %f\n", n1, n2, x);  
	primeHelper(n1, n2); 
	gcdHelper(n1, n2); 
	return 0; 
}
void primeHelper(int n1, int n2){
	int x = prime(n1); 
	int y = prime(n2); 
	if(x == 0 && y == 0){
		printf("Both %d and %d are prime\n", n1, n2); 
	}
	else if(x == 0 && y == 1){
		printf("%d is prime and %d is composite\n", n1, n2);
	}
	else if(x == 1 && y == 0){
		printf("%d is composite and %d is prime\n", n1, n2); 
	}
	else{
		printf("Both %d and %d are composite\n", n1, n2);
	}
}

void gcdHelper(int n1, int n2){
	int val = gcd(n1, n2); 
	if(val == 1){
		printf("%d and %d are comprime since their gcd is 1\n", n1, n2); 
	}
	else{
		printf(" %d and %d are relatively composite since their GCD is %d\n", n1, n2, val); 
	}
}
