#include <math.h>
#include <iostream>
#include <fstream>
#include <limits.h>
#include <stdlib.h>

using namespace std;

double Number[100];

void load_data(void){

	ifstream in;
	in.open("Number.dat");
	
	for(int i=0; i<100; i++){
		in >> Number[i];

	}
	in.close();
}

int main(){
	
	load_data();

	double sum=0;
	
	for (int i=0; i<100; i++){
		sum += Number[i];
	}

	printf("Sum=\t%.10f\n",sum);

	return 0;
}	
