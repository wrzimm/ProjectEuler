#include <stdio.h>
#include <stdlib.h>

unsigned int E(unsigned int n){
	
	if(n == 1) return 1;:
}

unsigned int D(unsigned int n){
	
	unsigned int val = 0;
	
	for(unsigned int i=n; i>0; i--)
		val += E(i);

	return val;
}	

int main(int argc,  char** argv){

	unsigned int n = atoi( arg[1] );

	unsigned int val = D(n);

	printf("D(%u) = %u\n",n,val);

	return 0;
} 
