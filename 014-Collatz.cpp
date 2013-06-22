#include <iostream>
#include <fstream>
#include <math.h>
#include <limits.h>
#include <stdlib.h>

using namespace std;

unsigned int NIterations(unsigned int number){
	unsigned int n=0;

	unsigned int val = number;
	while(val != 1){
		if( val % 2 == 0 )
			val = val/2;
		else 
			val = 3*val + 1;

		if(n+1 < UINT_MAX)
			n++;
		else{
			printf("ERROR: n bigger than UINT_MAX");
			exit(1);
		}
	}

	return n;
}

int main(){
	printf("Maximum number to check?\n");
	unsigned int max;
	scanf("%i",&max);

	unsigned int LongestChain=0;
	for(unsigned int i=2; i<=max; i++){
		unsigned int n_iterations = NIterations(i);
		
		if (n_iterations > LongestChain){
			LongestChain = n_iterations;
			printf("%i has a chain %i iterations long\n",i,LongestChain);
		}
	}


	return 0;
}	
