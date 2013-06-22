#include <stdlib.h>
#include <fstream>
#include <limits.h>

using namespace std;

int *array;

void load_data(void){
	fstream in;

	array = new int[15];
	
	in.open("018-triangle.dat");
	for (int i=0; i<15; i++){
		in >> array[i];
	}

}


int main(int argc, char** argv){

	load_data();

	unsigned int max_sum = 0;

	double best;

	for (unsigned int i=0; i<16384; i++){
	
		
	}
		

	delete[] array;
	array = NULL;
		
	return 0;	
}	
