/* 
crack.cpp

Author: Nicole Fergie

Short description of this file: this file compiles a score from the frequency
of letters in english in order to crack things encoded by shift.cpp.
it outputs the result to an output file.
*/

#include "caesarlib.h"
#include <fstream>
#include <iostream>

using namespace std;

// frequencies of letters in a large sample of English
const double enfreq[26] = {0.0793, 0.0191, 0.0392, 0.0351, 0.1093,
   0.0131, 0.0279, 0.0238, 0.0824, 0.0024, 0.0103, 0.0506, 0.0277,
   0.0703, 0.0602, 0.0274, 0.0019, 0.0705, 0.1109, 0.0652, 0.0321,
   0.0098, 0.0093, 0.0026, 0.0156, 0.0040};

// return score when ch is shifted (if ch not letter, return 0)
double char_score(char ch, int shift) {
   if(is_letter(ch)){
      int scoreInt = (int)image(ch, shift);
      if(scoreInt > 96){
         return enfreq[scoreInt - 97];
      }else{
         return enfreq[scoreInt - 65];
      }
   }else{
      return 0;
   }
}

// return score when contents of entire file are shifted
double file_score(const char filename[], int shift) {
   double fileSc = 0.0;
   ifstream in_file;
   in_file.open(filename);
   if(in_file.fail()){
      return 1;
   }else{
      char ch;
      while(in_file.get(ch)){
         fileSc = fileSc + char_score(ch, shift);
      }
   }
   return fileSc;

}

/*
// crack.cpp test main
int main() { 
   cout << char_score('A', 3) << " ";
   cout << char_score('x', 10) << " ";
   cout << char_score('?', 3) << endl;
   cout << file_score("secret.txt", 0) << " ";
   cout << file_score("secret.txt", 1) << endl;
   return 0;
}
*/

// actual main
int main(int argc, char* argv[]) {
   if (argc != 2) {
      cout << "Wrong number of arguments." << endl;
      cout << "Usage: decrypt ciphertext.txt" << endl;
      return 1;
   }
   double scoreMax = 0;
   int shiftMax = 0;
   for(int i = 0; i < 26; i++){
      if(file_score(argv[1], i) > scoreMax){
         shiftMax = i;
         scoreMax = file_score(argv[1], i);
      }
   }

   print_file_image(argv[1], shiftMax);
}

   
