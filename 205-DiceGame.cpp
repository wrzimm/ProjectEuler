#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <time.h>

using namespace std;


int main(int argc, char** argv){

	unsigned int PetersRolls[4][4][4][4][4][4][4][4][4];
	unsigned int ColinsRolls[6][6][6][6][6][6];
	unsigned long long PetersWins = 0;
	unsigned long long Total = 0;

	for(int i=0; i<4; i++){
	for(int j=0; j<4; j++){
	for(int k=0; k<4; k++){
	for(int l=0; l<4; l++){
	for(int m=0; m<4; m++){
	for(int n=0; n<4; n++){
	for(int o=0; o<4; o++){
	for(int p=0; p<4; p++){
	for(int q=0; q<4; q++){
		PetersRolls[i][j][k][l][m][n][o][p][q] = i + j + k + l + m + n + o + p + q + 9;
	}}}}}}}}}

	for(int i=0; i<6; i++){
	for(int j=0; j<6; j++){
	for(int k=0; k<6; k++){
	for(int l=0; l<6; l++){
	for(int m=0; m<6; m++){
	for(int n=0; n<6; n++){
		ColinsRolls[i][j][k][l][m][n] = i + j + k + l + m + n + 6;
	}}}}}}

	for(int i=0; i<4; i++){
	for(int j=0; j<4; j++){
	for(int k=0; k<4; k++){
	for(int l=0; l<4; l++){
	for(int m=0; m<4; m++){
	for(int n=0; n<4; n++){
	for(int o=0; o<4; o++){
	for(int p=0; p<4; p++){
	for(int q=0; q<4; q++){
	
	
		for(int ii=0; ii<6; ii++){
		for(int jj=0; jj<6; jj++){
		for(int kk=0; kk<6; kk++){
		for(int ll=0; ll<6; ll++){
		for(int mm=0; mm<6; mm++){
		for(int nn=0; nn<6; nn++){

			Total++;

			if( PetersRolls[i][j][k][l][m][n][o][p][q] > ColinsRolls[ii][jj][kk][ll][mm][nn] )
				PetersWins++;

		}}}}}}
	}}}}}}}}}

	double fraction = ((double) PetersWins) / ((double) Total);

	cout << "Peter won " << PetersWins << " out of " << Total << endl;
	cout << "PetersWins/Total = " << setprecision(9) << fraction << endl;	
	return 0;
}
