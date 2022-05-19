#include <math.h>
#include <stdio.h> 
int prime(int n);

int prime(int n){
	int val = 0; 
	double x = sqrt(n);
	for(int j = 2; j < x; j++){
		if(n%j == 0 ){
			val = 1; 
		}
	}
	return val;
}


