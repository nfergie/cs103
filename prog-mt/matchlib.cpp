//NICOLE FERGIE

#include <iostream>
#include <fstream>
#include <string>
#include "matchlib.h"

using namespace std;

/**
 * opens the text file indicated by filename,
 * reads an integer, n, from the beginning of the file
 * then reads n strings from the file (separated by 
 * whitespace whether that be a space, tab, or newline). 
 * Returns a pointer to the array of
 * strings containing the words and copies n to the 
 * integer pointed to by size.  If the file is 
 * unable to be opened (doesn't exist) return NULL and
 * set the integer to 0 that is pointed to by size. 
 * If the file is successfully opened then you may
 * assume there are no formatting errors. 
 */

// Add your implementation of read_words here
std::string* read_words(char* filename, int* size){
	ifstream in_file;
	in_file.open(filename);
   if(in_file.fail()){
      return NULL;
   }else{
      string myline;
      int n;
      getline(in_file, myline);
      stringstream ss(myline);
      ss >> n;
      size = n;
      while(getline(in_file, myline)){
         string seq;
         ss >> seq;
      }
   }
}




/**
 * Checks whether two strings are a DNA match
 * A DNA-match is defined as two strings such that:
 *  1. Both strings are the same length
 *  2. An 'A' or 'T' at a given location in one string
 *     should have a 'T' or 'A' (respectively) in the
 *     same location in the other string  ...OR...
 *     A 'C' or 'G' at a given location in one string
 *     should have a 'G' or 'C' (respectively) in the
 *     same location in the other string
 * You may assume all strings are made of upper case letters.
 */ 

// Add your implementation of dna_match here

bool dna_match(std::string s1, std::string s2){
   bool result = true;
   if(s1.length() != s2.length()){
      result = false;
   }else{
      int len = s1.length();
      for(int i = 0; i < len; i++){
         if((s1.substr(i,1) == "A") && (s2.substr(i,1) != "T")){
            result = false;
         }
         else if((s1.substr(i,1) == "T") && (s2.substr(i,1) != "A")){
            result = false;
         }
         else if((s1.substr(i,1) == "C") && (s2.substr(i,1) != "G")){
            result = false;
         }
         else if((s1.substr(i,1) == "G") && (s2.substr(i,1) != "C")){
            result = false;
         }
      }
   }
   return result;
}



