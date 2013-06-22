#include <stdio.h>
#include <stdbool.h>

inline bool IsFactor(unsigned long long number, int factor);

inline bool IsFactorAll(unsigned long long number);

int main(int argc, char** argv){
	unsigned long long val=20;

	do{
		if(val % 10000000 == 0)
			printf("Checked up to %lli.....\n",val);
		val +=20;
	} while( !IsFactorAll(val) );
	
	printf("Answer:\t %lli\n",val);	

	return 0;
}

inline bool IsFactor(unsigned long long number, int factor){
	if (number % factor == 0) return true;
	else return false;
}

inline bool IsFactorAll(unsigned long long number){
	bool result = true;

	int j;
	for( j=2; j<=20; j++){
		if( !IsFactor(number,j) ){
			result = false;
			break;
		}
	}
	
	return result;
}
	
