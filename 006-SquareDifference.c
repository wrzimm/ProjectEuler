#include <stdio.h>

#define ULL unsigned long long 

ULL SumOfSquares(int max){
	int i;
	ULL val = 0;
	for(i=1; i<=max; i++){
		val += i*i;
	}

	return val;
}

ULL SquareOfSum(int max){
	int i;
	ULL val = 0;
	for(i=1; i<=max; i++){
		val +=i;
	}

	return val*val;
}	

int main(int argc, char** argv){

	printf("Enter maximum natural number:\t");
	int max;
	scanf("%d",&max);

	ULL val = 0;
	
	val += SquareOfSum(max);
	val -= SumOfSquares(max);

	printf("Answer:\t%lli\n",val);

	return 0;
}	
