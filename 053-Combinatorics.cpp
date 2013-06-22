#include "BigInteger.h"

BigInteger Factorial(unsigned n){

	unsigned int i;
	unsigned long result = 1;

	for(i=2; i<=n; i++){
		result *= i;
	}

	return result;
}

unsigned long nPickm(unsigned n, unsigned m){
	
	}
