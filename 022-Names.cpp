#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <utility>
#include <vector>
#include <cstring>
using namespace std;

const unsigned int n_names = 5163;

void load_map(map<char,int> &Map){
/*{{{*/
	char letter = 'A';
	for(unsigned int i=1; i<=26; i++){
		Map.insert( pair<char,int>(letter, i) );
		letter++;
	}

}/*}}}*/

unsigned int score(string const &word, map<char,int> const &Map){
/*{{{*/
	//map<char,int>::iterator iter;
	
	unsigned int val = 0;
	unsigned int max = word.length();
	for(unsigned int i=0; i<max; i++){
		char key = word[i];
		val += Map.find(key)->second;
		
	}

	return val;
}/*}}}*/

char* StringToChar(string const &word){
/*{{{*/
	unsigned int length = word.length();
	char *output = new char[length+1];
	word.copy(output, length);
	output[length] = '\0';
	return output;
}/*}}}*/

void AlphaBubbleSort(vector<string> &names){
/*{{{*/
	bool flag           = true;
	unsigned int length = names.size();
	
	for(unsigned int i=0; (i<length) && flag; i++){
		if(i%100==0) cout << "Bubble sort " << i << endl;

		flag = false;
	
		for(unsigned int j=0; j<(length-1); j++){
			string a    = names[j];
			string b    = names[j+1];
	
			//char *c_j   = StringToChar( names[j] );
			//char *c_jp1 = StringToChar( names[j+1] );
			char *c_j   = StringToChar( a );
			char *c_jp1 = StringToChar( b );
	
			int test = strcmp(c_j, c_jp1);

			delete[] c_j;
			delete[] c_jp1;

			if( test==0 ){
				printf("DANGER WILL ROBINSON!!!\n");
				cout << c_j << c_jp1 << endl;
			}
			if( test > 0){
				string tmp = names[j];
				names[j] = names[j+1];
				names[j+1] = tmp;
				flag = true;
			}
		}
		
	}
			
}/*}}}*/

int main(){
	vector<string> names;

	ifstream in;
	in.open("022-names.txt");

	for(unsigned int i=0; i<n_names; i++){
		string temp;
		in >> temp;
		names.push_back(temp);
	}
	in.close();

	AlphaBubbleSort(names);

	map<char,int> Map;
	load_map(Map);

	//string test = "ZACHARIAH";
	//cout << score(test, Map) << endl;


	/*
	ofstream out;
	out.open("tmp.txt");
	for(int i=0; i<n_names; i++)
		out << names[i] << endl;
	out.close();
	*/
	unsigned long long val = 0;
	unsigned long long tmp;
	cout << "Summing values....." << endl;
	for(unsigned int i=0; i<n_names; i++){
		tmp = score(names[i], Map);
		unsigned int multiplier = i+1;
		tmp = tmp*multiplier;
		val = val + tmp;
		//cout << names[i] << "\t" << score(names[i],Map) << "\t" << tmp << "\t" << val << endl;
		//if(i==937)
			//cout << names[i] << "\t" << tmp << endl;
	}

	cout << "Total score = " << val << endl;
		
	return 0;
}
