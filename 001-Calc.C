#include<iostream>

#define MIN 1
#define MAX 1000
void Calc(void){
	Int_t val = 0;

	for(Int_t i=MIN; i<MAX; i++){
		//printf("\ni=%i\n",i);
		if( i % 3 == 0){ 
			val += i;
			//printf("Divisible by 3...\n");
		}
		else if ( i % 5 ==0){
			val +=i;
			//printf("Divisible by 5...\n");
		}
		//printf("val=%i\n\n",val);
	}

	printf("Sum between %i and %i is %i\n",MIN,MAX,val);
}
			
