#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include "BigInteger.h"


int main(int argc, char** argv){
	unsigned int max = atoi( argv[1] );
	
	BigInteger factorial(100000);
	unsigned int i;
	for(i=2; i<=max; i++)
		factorial.Multiply(i);

	//factorial.Print();

	unsigned int sum = factorial.SumDigits();

	printf("Sum of the digits of %u! is %u\n",max,sum);

	return 0;
}
