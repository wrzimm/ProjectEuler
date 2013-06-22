#include <iostream>
#include <cstdlib>
#include "math.h"
#include "ProgressBar.h"
#include "IsPrime.h"

bool CircularPrime(unsigned int num, unsigned int ndigits);

int main(int argc, char** argv){
	using std::cout;
	using std::endl;

	if( argc != 2){
		cout << "Usage: ./a.out <n max>" << endl;
		exit(1);
	}

	unsigned int nmax = static_cast<unsigned int>( atoi( argv[1] ) );

	cout << "nmax = " << nmax << endl;

	unsigned int nPrimes = 1; //assume 2

	for(unsigned int i=3; i<=nmax; i+=2){

		unsigned int ndigits = 1;
		unsigned int mult    = 10;
		while( (i / mult) != 0){
			++ndigits;
			mult *= 10;
		}

		//cout << "i=" << i << "\tndigits=" << ndigits << endl;

		if( CircularPrime(i, ndigits) ){
			//cout << i << " is Circular Prime\n";
			++nPrimes;
		ProgressBar(i, nmax);
		}

	}

	cout << endl << endl;
	cout << nPrimes << " circular primes below " << nmax << endl;
	cout << endl << endl;

	return 0;
}
	
		


bool CircularPrime(unsigned int num, unsigned int ndigits){
	
	if( !IsPrime(num) )
		return false;
	
	if(ndigits == 1)
		return true;


	if(ndigits == 2){
		unsigned int combA = 10 * (num % 10) + num / 10;
		if( IsPrime(combA) )
			return true;
		else
			return false;
	}

	unsigned int digits[ndigits];

	for(unsigned int i=0; i<ndigits; ++i){
		digits[i]  = num % static_cast<unsigned int>(pow(10,ndigits-i));
		digits[i] /= static_cast<unsigned int>(pow(10,ndigits-i-1));
		if(digits[i] % 2 == 0)
			return false;
	}

	if(ndigits == 3){

		unsigned int combA  = 100*digits[1] + 10*digits[2] + digits[0];
		unsigned int combB  = 100*digits[2] + 10*digits[0] + digits[1];

		if( IsPrime(combA) &&
		    IsPrime(combB) )
			return true;
		else
			return false;

	}
	if(ndigits == 4){

		unsigned int combA  = 1000*digits[1] + 100*digits[2] + 10*digits[3] + digits[0];
		unsigned int combB  = 1000*digits[2] + 100*digits[3] + 10*digits[0] + digits[1];
		unsigned int combC  = 1000*digits[3] + 100*digits[0] + 10*digits[1] + digits[2];

		if( IsPrime(combA) &&
		    IsPrime(combB) &&
		    IsPrime(combC) )
			return true;
		else
			return false;

	}
	if(ndigits == 5){

		unsigned int combA  = 10000*digits[1] + 1000*digits[2] + 100*digits[3] + 10*digits[4] + digits[0];
		unsigned int combB  = 10000*digits[2] + 1000*digits[3] + 100*digits[4] + 10*digits[0] + digits[1];
		unsigned int combC  = 10000*digits[3] + 1000*digits[4] + 100*digits[0] + 10*digits[1] + digits[2];
		unsigned int combD  = 10000*digits[4] + 1000*digits[0] + 100*digits[1] + 10*digits[2] + digits[3];

		if( IsPrime(combA) &&
		    IsPrime(combB) &&
		    IsPrime(combC) &&
		    IsPrime(combD) )
			return true;
		else
			return false;

	}
	if(ndigits == 6){

		unsigned int combA  = 100000*digits[1] + 10000*digits[2] + 1000*digits[3] + 100*digits[4] + 10*digits[5] + digits[0];
		unsigned int combB  = 100000*digits[2] + 10000*digits[3] + 1000*digits[4] + 100*digits[5] + 10*digits[0] + digits[1];
		unsigned int combC  = 100000*digits[3] + 10000*digits[4] + 1000*digits[5] + 100*digits[0] + 10*digits[1] + digits[2];
		unsigned int combD  = 100000*digits[4] + 10000*digits[5] + 1000*digits[0] + 100*digits[1] + 10*digits[2] + digits[3];
		unsigned int combE  = 100000*digits[5] + 10000*digits[0] + 1000*digits[1] + 100*digits[2] + 10*digits[3] + digits[4];

		if( IsPrime(combA) &&
		    IsPrime(combB) &&
		    IsPrime(combC) &&
		    IsPrime(combD) &&
		    IsPrime(combE) )
			return true;
		else
			return false;

	}

	

		
		
}





