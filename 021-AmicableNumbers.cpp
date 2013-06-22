#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <vector>

		

unsigned int d(unsigned int n){

	std::vector<unsigned int> factors;

	for(unsigned int i=1; i<=n/2; i++){
		
		if(n%i == 0)
			factors.push_back(i);
	}

	double sum = 0;
	for(unsigned int j=0; j<factors.size(); j++)
		sum += factors[j];

	return sum;
}


int main(int argc, char** argv){
	
	unsigned int max = atoi( argv[1] );
	unsigned int sum = 0;
	

	for(unsigned int i=1; i<max; i++){
		unsigned int test = d(i);
		if( d(test)==i ){
			if(test !=i )
				sum += i;
			printf("%i and %i are amicable numbers\n",i,test);
		}
	}

	printf("Sum of all amicable  numbers below %i is %i\n",max,sum);
	//cout << "Sum of all amicable numbers below " << max << " is " << sum;

	return 0;
}
