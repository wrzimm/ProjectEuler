#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#define SUM 1000

inline bool Is_int(float c){
	
	if( (c - (int)c) == 0) return true;
	
	else return false;
}

int main(int argc, char** argv){
	
	int a, b;
	float c;
	
	for(a=0; a<=SUM; a++){
		for(b=0; b<=SUM; b++){

		double temp = a*a + b*b;
		c = sqrt(temp);
		
		if( Is_int(c) ){
			if( a+b+c == SUM ){
			
			printf("Answer:\t a=%i b=%i c=%i\t abc=%f\n",a,b,(int)c,a*b*c);
				}
		}
		}
	}

	return 0;
}
