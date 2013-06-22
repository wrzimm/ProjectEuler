#include <stdio.h>
#include <stdbool.h>

inline bool IsPrime(unsigned long number);


int main(int argc, char** argv){
	unsigned int count = 0;
	unsigned int nth;
	unsigned long i=1;
	
	printf("Which prime are you looking for?\t");
	scanf("%i",&nth);
	
	do{
		i+=1;
		if( IsPrime(i) ){
			count++;
			printf("%ith prime:\t%li\n",count,i);
		}
	} while( count < nth );

	return 0;
}
		


inline bool  IsPrime(unsigned long number){
	bool prime=true;
	unsigned long i;

	for (i=2; i<number; i++){
		if (number % i ==0){
			prime = false;
			break;
		}
	}
	
	return prime;
}
