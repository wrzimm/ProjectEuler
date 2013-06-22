#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

int n_letters[30];



int NumberOfLetters(int number){
n_letters[0] = 3; //and
n_letters[1] = 3; //one
n_letters[2] = 3; //two
n_letters[3] = 5; //three
n_letters[4] = 4; //four
n_letters[5] = 4; //five
n_letters[6] = 3; //six
n_letters[7] = 5; //seven
n_letters[8] = 5; //eight
n_letters[9] = 4; //nine
n_letters[10] = 3; //ten
n_letters[11] = 6; //eleven
n_letters[12] = 6; //twelve
n_letters[13] = 8; //thirteen
n_letters[14] = 8; //fourteen
n_letters[15] = 7; //fifteen
n_letters[16] = 7; //sixteen
n_letters[17] = 9; //seventeen
n_letters[18] = 8; //eighteen
n_letters[19] = 8; //nineteen
n_letters[20] = 6; //twenty
n_letters[21] = 6; //thirty
n_letters[22] = 5; //forty
n_letters[23] = 5; //fifty
n_letters[24] = 5; //sixty
n_letters[25] = 7; //seventy
n_letters[26] = 6; //eighty
n_letters[27] = 6; //ninety
n_letters[28] = 7; //hundred
n_letters[29] = 8; //thousand
	int letters=0;

	if(number/1000 != 0){ //thousands
		//printf("Adding thousands\n");
		letters += n_letters[29]; //thousand
		letters += n_letters[ number/1000 ]; //number of thousands
	}
	
	int UpToHundreds = number%1000;

	if(UpToHundreds/100 != 0){ //hundreds
		//printf("Adding hundreds\n");
		letters += n_letters[28]; //hundred
		letters += n_letters[ (number%1000)/100 ]; //number of hundreds
		if(number % 100 != 0){
			letters += n_letters[0]; //and if there are tens or ones
			//printf("Adding and\n");
		}
	}

	int UpToTens = (number%1000)%100;
	int UpToOnes = UpToTens%10;

	if( (UpToTens/10 != 0) && (UpToTens >=20) ){ //tens not counting the teens
		//printf("Adding tens (no teens)\n");
		if( UpToTens/10 == 9 ) letters += n_letters[27]; //ninety 
		if( UpToTens/10 == 8 ) letters += n_letters[26]; //eighty
		if( UpToTens/10 == 7 ) letters += n_letters[25]; //seventy
		if( UpToTens/10 == 6 ) letters += n_letters[24]; //sixty
		if( UpToTens/10 == 5 ) letters += n_letters[23]; //fifty
		if( UpToTens/10 == 4 ) letters += n_letters[22]; //forty
		if( UpToTens/10 == 3 ) letters += n_letters[21]; //thirty
		if( UpToTens/10 == 2 ) letters += n_letters[20]; //twenty
	}

	if( (UpToTens/10 != 0) && (UpToTens < 20) ){ //teens
		//printf("Adding  teens\n");
		if( UpToOnes == 9 ) letters += n_letters[19];
		else if( UpToOnes == 8 ) letters += n_letters[18];
		else if( UpToOnes == 7 ) letters += n_letters[17];
		else if( UpToOnes == 6 ) letters += n_letters[16];
		else if( UpToOnes == 5 ) letters += n_letters[15];
		else if( UpToOnes == 4 ) letters += n_letters[14];
		else if( UpToOnes == 3 ) letters += n_letters[13];
		else if( UpToOnes == 2 ) letters += n_letters[12];
		else if( UpToOnes == 1 ) letters += n_letters[11];
		else if( UpToTens/10 == 1 ) letters += n_letters[10]; //ten
	} else if(UpToOnes != 0){ //ones
		letters += n_letters[UpToOnes];
	}

	return letters;
}


	
	

		

int main(){
	//printf("Enter number for letter sum:\t");
	printf("Enter maximum number in sequence to be summed:\t");
	int max;
	scanf("%i",&max);

	//printf("%i\n",NumberOfLetters(max));

	int sum = 0;

	for(int i=1; i<=max; i++){
		sum += NumberOfLetters(i);
	}

	printf("Sequence up to %i has %i letters\n",max,sum);

	return 0;
}
