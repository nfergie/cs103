#include <iostream>
#include <cmath>

using namespace std;

int main(){
   //vars def
   int num;
   int counter = 0;

   //usr input
   cout << "Enter a number: ";
   cin >> num;

   //calcs
   while(num != 1){
      if((num % 2) == 0){
         num = (num / 2);
         cout << num << " ";
      }
      else{
         num = (num * 3) + 1;
         cout << num << " ";
      }
      counter++;
   }
    cout << endl << "Length: " << counter << endl;

   return 0;
}
