#include <iostream>
//#include <stdlib.h>
#include <fstream>
#include <math.h>
#include <limits.h>

using namespace std;

int grid[20][20];

void load_data(void){

	ifstream in;
	in.open("Grid.dat");
	
	for(int i=0; i<20; i++){
		for(int j=0; j<20; j++){
			in >> grid[i][j];
		}
	}
	in.close();
}


int main(){
	load_data();

	unsigned int max = 0;

	for(int x=0; x<20; x++){
		for(int y=0; y<20; y++){
			unsigned int val=1;
			
			//4 to the right
			if(x<17){
				for(int i=x; i<x+4; i++){
					val*=grid[i][y];
				}
			}

			if(val>max){
				max = val;
				printf("Maximum Product:\t%i\n",max);
			}

			//4 down
			val=1;
			if(y<17){
				for(int j=y; j<y+4; j++){
					val*=grid[x][j];
				}
			}
			if(val>max){
				max = val;
				printf("Maximum Product:\t%i\n",max);
			}

			//4 diagonally down and right
			val=1;
			if(x<17 && y<17){
				for(int ij=0; ij<4; ij++){
					val*=grid[x+ij][y+ij];
				}
			}
			if(val>max){
				max = val;
				printf("Maximum Product:\t%i\n",max);
			}

			//4 diagonally down and left
			val=1;
			if(x>=3 && y<17){
				for(int ij=0; ij<4; ij++){
					val*=grid[x-ij][y+ij];
				}
			}
			if(val>max){
				max = val;
				printf("Maximum Product:\t%i\n",max);
			}
		}
	}

	return 0;
}

