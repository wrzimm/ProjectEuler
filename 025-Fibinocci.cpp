#include "BigInteger.h"
#include <iostream>

BigInteger *NthFibinocci(unsigned int n){ 
	
	BigInteger *current  = new BigInteger(2000,1);
	BigInteger *previous = new BigInteger(2000,1);

	for(unsigned int i=3; i<=n; i++){
		BigInteger tmp(*current);	
		current->Add(*previous);
	
		delete previous; previous = NULL;

		previous = new BigInteger(tmp);
	}

	return current;
}


int main(int argc, char **argv){
	unsigned int ndigits = atoi( argv[1] );
	unsigned int n = atoi( argv[2] );	

	BigInteger *test = new BigInteger(2000,1);


	do{
		//if(1){
		if(test != NULL){
			delete test;	
			test = NULL;	
		}

		n++;
		std::cout << n << std::endl;
		test = NthFibinocci(n);
	} while(test->Digits[ndigits-1] == 0);

	std::cout << n << "th Fibinocci first with " << ndigits << " digits" << std::endl;

	delete test;	test=NULL;



	return 0;
}		
