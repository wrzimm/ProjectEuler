#include <stdio.h>
#include <stdlib.h>
#include <time.h>





bool PeterWins(){
	unsigned int score_c=0, score_p=0;


	//Peters Roll
	unsigned int rand_p[4];
	for(unsigned short i=0; i<4; i++){
		rand_p[i] = rand()%4 + 1;
		//printf("%i\n",rand_p[i]);
		score_p += rand_p[i];
	}

	//printf("\n\n");


	//Colin's Roll
	unsigned int rand_c[6];
	for(unsigned short i=0; i<6; i++){
		rand_c[i] = rand()%6 + 1;
		//printf("%i\n",rand_c[i]);
		score_c += rand_c[i];
	}


	//printf("Peter's score: %i\tColin's score: %i\n",score_p,score_c);

	if(score_p > score_c) return true;
	else return false;
	
}

int main(int argc, char** argv){
	//initialze random number generator
	srand( time(NULL) );
	
	unsigned long long max = atoi( argv[1] );
	unsigned long long wins = 0;
	
	for(unsigned long long i=1; i<=max; i++){
		if( PeterWins() )
			wins++;

		double fraction = ((double)wins)/((double)i);
		if(i%1000000 == 0)
			printf("Peter wins  %.7f of the time\n",fraction);

	}

	return 0;
}
