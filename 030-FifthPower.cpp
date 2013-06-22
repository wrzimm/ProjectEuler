#include <iostream>

using namespace std;

unsigned int FifthPower(unsigned int n){
	return n*n*n*n*n;
}

bool GoodNumber(unsigned int m, unsigned int max){
	
	unsigned int val = 0;
	unsigned int n   = m;

	for(int divider=max; divider>=1; divider/=10){
		unsigned short digit = n/divider;	
		if(digit != 0){
			val += FifthPower(digit);
		}
		//cout << divider << " digit = " << digit << "\t"<< val << endl;
		n = n%divider;
	}
	
	//cout <<"val=" << val << "\tn=" << m << endl;

	if( val==m )
		return true;
	else 
		return false;
}


int main(){

	unsigned int sum = 0;

	unsigned int max = 1e6;
	

	for(unsigned int i=2; i<=max; i++){
		if( GoodNumber(i,max) ){
			cout << i << endl;
			sum += i;
		}
		//if(i%(max/10) == 0)
			//cout << i << endl;
	}

	cout << sum << endl;

	return 0;
}
	
