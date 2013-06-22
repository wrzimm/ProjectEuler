#ifndef BIGINTEGER_H
#define BIGINTEGER_H

#include <stdlib.h>
#include <iostream>

class BigInteger {
	public: 

	BigInteger(unsigned int n_digits, unsigned long long value=1);
	BigInteger(const BigInteger&);
	~BigInteger();

	//array to hold each digit
	short *Digits;

	//print number
	void Print() const;
	void Print(unsigned int ndigits) const;

	//sum digits
	unsigned long SumDigits() const;
	
	//number of digits
	unsigned int size;

	//operations
	void Double();
	void Multiply(unsigned int n);
	void Power(unsigned int n);
	void Add(BigInteger const &n);
};


unsigned long BigInteger::SumDigits() const{
	unsigned long sum = 0;

	for(unsigned int i=0; i<size; i++)
		sum += Digits[i];

	return sum;
}

void BigInteger::Print() const{
	for(int i=size-1; i>=0; i--){
		std::cout << Digits[i];
	}
	std::cout << std::endl;
}

void BigInteger::Print(unsigned int ndigits) const{
	for(int i=ndigits-1; i>=0; i--){
		std::cout << Digits[i];
	}
	std::cout << std::endl;
}

void BigInteger::Add(BigInteger const &n){
	unsigned short carry = 0;

	unsigned short temp[size];

	for(unsigned int i=0; i<size; i++){
		if( i< n.size )
			temp[i]  = Digits[i] + n.Digits[i];
		else 
			temp[i]  = Digits[i];

		temp[i] += carry;	

		if( temp[i]>=10 ){
			carry   = temp[i] / 10;
			temp[i] = temp[i] % 10;
		} else
			carry   = 0;
		
	}
	
	for(unsigned int i=0; i<size; i++)
			Digits[i] = temp[i];
}


void BigInteger::Multiply(unsigned int n){
	unsigned short carry = 0;

	unsigned short temp[size];

	unsigned int exp = 0;
	while( n>=10 ){
		n /= 10;
		exp++;
	}


	for(unsigned int i=0; i<size; i++){
		temp[i]  = Digits[i]*n;
		temp[i] += carry;	
		Digits[i]= 0;

		if( temp[i]>=10 ){
			carry   = temp[i] / 10;
			temp[i] = temp[i] % 10;
		} else
			carry   = 0;
		
	}
	
	for(unsigned int i=exp; i<size; i++)
			Digits[i] = temp[i-exp];
}

void BigInteger::Double(){
	bool carry = false;

	short temp[size];

	for(unsigned int i=0; i<size; i++){
		temp[i] = Digits[i]*2;
		if(carry) temp[i] += 1;
		
		if(temp[i]>=10){
			carry = true;
			temp[i] -= 10;
		}
		else carry = false;
	}

	for(unsigned int i=0; i<size; i++) Digits[i] = temp[i];
}


//constructor
BigInteger::BigInteger(unsigned int n_digits, unsigned long long value){
	Digits = new short[n_digits];
	size = n_digits;

	for(unsigned int i=0; i<n_digits; i++){
		Digits[i] = value % 10;
		value     = value / 10;
	}

}
BigInteger::BigInteger(const BigInteger &original){
	unsigned int n_digits = original.size;
	size                  = n_digits;
	Digits                = new short[n_digits];

	for(unsigned int i=0; i<n_digits; i++)
		Digits[i] = original.Digits[i];
}

//destructor
BigInteger::~BigInteger(){
	delete[] Digits;
}
#endif
