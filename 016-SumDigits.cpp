#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

using namespace std;

class BigInteger {
	public: 

	BigInteger(unsigned int n_digits);
	~BigInteger();

	//array to hold each digit
	short *Digits;
	
	//number of digits
	unsigned int size;

	//operations
	void Double(void);
};

int main(){
	printf("Which power of 2?\t");
	unsigned int power;
	scanf("%i",&power);

	BigInteger BigInt(power+10); 

	for(int i=1; i<=power; i++){
		BigInt.Double();
	}

	printf("\n\n");
	/*
	for(int i=power; i>=0; i--){
		printf("%i",BigInt.Digits[i]);
	}
	printf("\n\n");
	*/

	unsigned long sum = 0;

	for(int i=0; i<=power; i++){
		sum += BigInt.Digits[i];
	}

	printf("Sum of digits:\t%li\n",sum);	

	return 0;
}

void BigInteger::Double(void){
	bool carry = false;

	short temp[size];

	for(int i=0; i<size; i++){
		temp[i] = Digits[i]*2;
		if(carry) temp[i] += 1;
		
		if(temp[i]>=10){
			carry = true;
			temp[i] -= 10;
		}
		else carry = false;
	}

	for(int i=0; i<size; i++) Digits[i] = temp[i];
}


//constructor
BigInteger::BigInteger(unsigned int n_digits){
	Digits = new short[n_digits];
	size = n_digits;

	//initialize to 1
	Digits[0] = 1;
	for (unsigned int i=1; i<n_digits; i++){
		Digits[i] = 0;
	}

}

//destructor
BigInteger::~BigInteger(){
	delete[] Digits;
}
