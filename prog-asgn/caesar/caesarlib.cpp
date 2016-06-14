/* 
caesarlib.cpp

Author: Nicole Fergie

Short description of this file: This file defines a couple key functions
to the rest of the program.
The last print_file_image function depends on the image function which 
in turn depends on the is_letter function.
*/

#include <fstream>
#include <iostream>
#include "caesarlib.h"

using namespace std;

// is this char an English letter?
bool is_letter(char ch) {
   if((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')){
      return true;
   }
   else{
      return false;
   }
}

// return shifted image of ch (if ch not letter, don't shift)
// assumes 0 <= steps < 26
char image(char ch, int steps) {
   if(!is_letter(ch)){
      return ch;
   }
   else{
      if(ch>= 'A' && ch <= 'Z'){
         if((int)ch + steps > 90){
            return (char)((((int)ch + steps) - 90) + 64);
         }
         else{
            return (char)((int)ch+steps);
         }
      }
      else{
         if((int)ch + steps > 122){
            return (char)((((int)ch + steps) - 122) + 96);
         }
         else{
            return (char)((int)ch+steps);
         }
      }
   }
}

// shift all characters in this file and print it to cout
// return 1 if error (file couldn't be opened), 0 if no error
int print_file_image(const char filename[], int steps) {
   ifstream in_file;
   in_file.open(filename);
   if(in_file.fail()){
      return 1;
   }else{
      char ch;
      while(in_file.get(ch)){
         cout << image(ch, steps);
      }
      in_file.close();
      return 0;
   }
}

