#include <iostream>
#include <limits.h>

using namespace std;

int main(){
	unsigned long long sum = 1;
	unsigned int val       = 1;
	const int max          = 1001;

	for(int i=3; i<=max; i += 2){	
		for(int j=0; j<4; j++){
			val += i-1;
			sum += val;		
		}
		if( val > ULLONG_MAX*0.9) 
			cout << "DANGER WILL ROBINSON!!!" << endl;
	}

	cout << sum << endl;

	return 0;
}
