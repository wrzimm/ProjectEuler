#include <iostream>
#include <fstream>

using namespace std;


int main(){

	int number[1000];

	ifstream in;
	in.open("Number.dat");
	for(int i=0; i<1000; i++){
		in >> number[i];
	}
	in.close();

	
	unsigned int max = 0;

	for(int i=0; i<=995; i++){
		unsigned int val=1;
		
		for(int j=i; j<=i+4; j++){
			val *= number[j];
		}

		if( val>max ){
			max = val;
			printf("Found new largest product:\t%i\n",max);
		}
	}	
	

	return 0;
}


	
