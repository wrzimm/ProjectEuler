#include <stdio.h>
#include <stdbool.h>

#define MIN 900

inline bool IsPalindrome(long int number){
	long int n, Reverse=0;
	long int Digit;
	n = number;
	while (number>0){
		Digit = number % 10;
		Reverse = Reverse*10 + Digit;
		number = number/10;
	}
	
	if (Reverse == n)
		return true;
	else 
		return false;
}	
		
	

int main(int argc, char** argv){
	/*
	long int number;
	printf("enter a number:\t");
	scanf("%ld",&number);
	
	if( IsPalindrome(number) )
		printf("\nPalindrome\n");
	else
		printf("\nNot a Palindrome\n");
	*/

	int x;
	int y;

	unsigned int MaxPalindrome = 0;

	for(x=999; x>=MIN; x--){
		for(y=999; y>=MIN; y--){

			unsigned int val = x*y;
			if( IsPalindrome(val) ){
				if(val > MaxPalindrome){
					MaxPalindrome = val;
					printf("Largest found palindrome:\t%i x %i = %i\n",x,y,MaxPalindrome);
				}
			}
		}
	}

	return 0;
}

