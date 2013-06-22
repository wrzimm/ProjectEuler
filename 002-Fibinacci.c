#include <stdlib.h>
#include <stdio.h>

#define MAX 4000000
//#define MAX 35

int main(int argc, char** argv){
	
	int fib[2] = {0,1};	

	int val = 0;

	while(fib[1] <= MAX){
		int old[2] = {fib[0],fib[1]};

		fib[0] = old[1];
		fib[1] += old[0];

		if (fib[1] % 2 == 0){
			val += fib[1];
		}
	}

	printf("%i\n",val);

	return 0;
}
		
