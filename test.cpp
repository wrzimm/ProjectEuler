#include "BigInteger.h"

int main(){

	while(1){
		BigInteger *n = new BigInteger(10000,1);
		delete n;
	}


	return 0;
}
