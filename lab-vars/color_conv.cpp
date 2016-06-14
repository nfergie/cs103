#include <iostream>
#include <algorithm>
using namespace std;

/* Author: Nic Fergie
 * Program: color_conv
 * Description: Reads input as rgb colours and outputs 
 * CMYK values
 */

int main()
{
   // Enter your code here

	//defining vars
   double white;
   double cyan;
   double magenta;
   double yellow;

   int red;
   int green;
   int blue;
   double black;

   //user input
   cout << "Value for Red: ";
   cin >> red;

   cout << "Value for Green: ";
   cin >> green;

   cout << "Value for Blue: ";
   cin >> blue;
   
   //calculations
   white = max((red/255), max((green/255), (blue/255)));
   cyan = (white - (red/255))/ white;
   magenta = (white - (green/255))/white;
   yellow = (white - (blue/255))/white;
   black = 1- white;

   //output
   cout << "cyan: " << cyan << endl;
   cout << "magenta: " << magenta << endl;
   cout << "yellow: " << yellow << endl;
   cout << "black: " << black << endl;

   return 0;
}
