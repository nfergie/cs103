#include <string>
#include <vector>
#include "bigint.h"

// importing a whole namespace in a header is frowned upon
// this will at least let us write 'string'/'vector' below
using std::string;
using std::vector;

// convert string to BigInt
BigInt::BigInt(string s){
   int size = s.length();
   for(int i = size -1; i >= 0; i--){
      data.push_back((int)s[i] - 48);
   }
}   

 // get string representation
string BigInt::to_string(){
   string s = "";
   int size = data.size();
   for(int i = size -1; i >= 0; i--){
      s += (char)(data[i] + 48);
   }
   return s;
}


void BigInt::add(BigInt b){
   int alen = data.size();
   int blen = b.data.size();

   if(alen > blen){
      int zeros = alen -blen;
      for(int i = 0; i < zeros; i++){
         b.data.push_back(0);
      }
   }
   else if(blen > alen){
      int zeros = blen -alen;
      for(int i = 0; i < zeros; i++){
         data.push_back(0);
      }
   }

   int carry = 0;
   for(int i = 0; i < alen; i++){
      if((data[i] + b.data[i] + carry) > 9){
         data[i] = (data[i] + b.data[i] +carry) - 10;
         carry = 1;
      }
      else{
         data[i] = data[i] + b.data[i] + carry;
         carry = 0;
      }
   }
   if(carry == 1){
      data.push_back(1);
   }
}