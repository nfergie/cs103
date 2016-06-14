/* 
shift.cpp

Author: Nicole Fergie

Short description of this file: This file shifts the input a certain amount of 
steps in order to encode it. The ouput is written to an output file.
*/

#include "caesarlib.h"
#include <cstdlib>
#include <iostream>

using namespace std;
   
int main(int argc, char* argv[]) {
   if (argc != 3) {
      cout << "Wrong number of arguments." << endl;
      cout << "Usage: shift message.txt shift_number" << endl;
      return 1;
   }
   
   // FILL this in:
   // read the arguments and print the shifted output
   int result = print_file_image(argv[1], atoi(argv[2])); // FILL in
   
   // return sensible error if the filename is wrong
   if (result != 0) {
      cout << "Couldn't open the input file." << endl;
      return 1;
   }
   return 0;
}
