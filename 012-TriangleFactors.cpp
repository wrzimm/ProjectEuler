#include <math.h>
#include <limits.h>
#include <iostream>
#include <stdlib.h>
#include <fstream>

using namespace std;

int NumberOfFactors(unsigned int n){
	
	int n_factors = 2;

	for(unsigned int i=2; i*i<=n; i++){

		if(n % i == 0){
			if( i*i == n)
				n_factors++;
			else
				n_factors+=2;
		}
	}

	return n_factors;
}

int main(){
	printf("Looking for first triangle number with how many factors?\n");
	int min_factors;
	scanf("%i",&min_factors);
	
	int n_factors=0;
	unsigned int triangle=1;
	int n = 1;

	while(n_factors < min_factors){
		n++;
		triangle += n;
		n_factors = NumberOfFactors(triangle);
		
		//if(n % 10 == 0)
			//printf("n=%i\ttriangle=%i\tn_factors=%i\n",n,triangle,n_factors);
	}
		

	printf("Triangle number %i has %i factors\n",triangle,n_factors);

	return 0;
}
