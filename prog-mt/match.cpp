//NICOLE FERGIE

#include <iostream>
#include <string>
#include "matchlib.h"
using namespace std;

/**
 * Main program to count how many DNA-matches each string in
 * the input file has.  Your program will be given a filename
 * as the first command line argument. First try to read the strings 
 * from the file into an array. If the file doesn't exist
 * you should output "Error" to 'cout' and end the program gracefully 
 * (no memory leaks, etc.) returning 0.  
 * Once you successfully read the DNA strings,
 * try to answer the question whether all strings
 * in the input file have at least 1 DNA-match to another string
 * in the file.  To do this, you should count exactly how many
 * matches each string has and output the string and that count
 * to 'cout' on a line.  Do this for all  strings.
 * Finally output "Yes" if all strings had at least 1 match
 * and "No" otherwise
 * The output should have formatting like:
 *   ATG 2
 *   TAC 1
 *   TAC 1
 *   Yes
 */
int main(int argc, char* argv[])
{
	int* size;
	string* mystrings = read_words(argv[1], size)
	if(mystrings == NULL){
		cout << "Error"
		return 1;
	}

	int min_match = 0;

	for(int i = 0; i < size; i++){
		int matches=0;
		for(int j = 0; j < size; j++){
			if(mystrings[i].compare(mystrings[j]) != 0){
				if(dna_match(mystrings[i], mystrings[j])){
					matches = matches + 1;
				}
			}
		}
		if(matches > 0){
			min_match = min_match + 1;
		}
		cout << mystrings[i] << matches << endl;
	}
	if (min_match == size){
		cout << "Yes";
	}
   delete[] mystrings;
	return 0;
}
