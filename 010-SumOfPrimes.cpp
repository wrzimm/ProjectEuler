#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <math.h>
#include <limits.h>

using namespace std;


inline bool IsPrime(unsigned int number){
	if (number >= UINT_MAX){
		printf("ERROR: number is larger than UINT_MAX\n");
		exit(1);
	}
	bool prime=true;
	unsigned int i;

	unsigned int max = (unsigned int) sqrt((double)number);

	for (i=2; i<=max*2; i++){
		if (i >= UINT_MAX){
			printf("ERROR: i is larger than UINT_MAX\n");
			exit(1);
		}
		if (number % i ==0){
			prime = false;
			break;
		}
	}
	
	return prime;
}


int main(){
	
	unsigned int max;

	printf("Summing all primes below what number?\t");
	scanf("%i",&max);
	if (max >= UINT_MAX){
		printf("ERROR: max is larger than UINT_MAX\n");
		exit(1);
	}

	unsigned long long sum = 2;

	unsigned int i;
	
	for(i=3; i<=max; i+=2){
		if( IsPrime(i) ) 
			sum += i;
			if (sum >= ULLONG_MAX){
				printf("ERROR: sum is larger than ULLONG_MAX\n");
				exit(1);
			}
	}

	printf("Sum of all primes up to %i is:\t%lli\n",max,sum);

	return 0;

}	
