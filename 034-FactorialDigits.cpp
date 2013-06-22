#include <iostream>

using namespace std;

unsigned int Factorial(unsigned int n){
	unsigned int val = 1;
	for(unsigned int i=n; i>=2; i--)
		val *= i;

	return val;
}

bool GoodNumber(unsigned int m, unsigned int max){
	
	unsigned int val = 0;
	unsigned int n   = m;

	for(int divider=max; divider>=1; divider/=10){
		unsigned short digit = n/divider;	
		if(digit != 0){
			val += Factorial(digit);
		}
		n = n%divider;
	}
	

	if( val==m )
		return true;
	else 
		return false;
}


int main(){

	unsigned int sum = 0;

	unsigned int max = 1e9;
	

	for(unsigned int i=3; i<=max; i++){
		if( GoodNumber(i,max) ){
			cout << i << endl;
			sum += i;
		}
		cout << i*100/max << "%" << "\r";
	}

	cout << sum << endl;

	return 0;
}
	
