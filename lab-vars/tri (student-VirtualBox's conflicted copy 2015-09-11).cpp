#include <iostream>
#include <cmath>
#include <string>
using namespace std;

/* Author: Nic Fergie
 * Program: prime23
 * Description: determines wether input has only 2 or 3 as 
 * as prime factors
 */

 int main(){
 	//def vars
 	int h = 30;
 	double theta;
 	int x;

 	//usr input
 	cout << "Please enter theta value: ";
 	cin >> theta;

 	//calculations
 	theta = theta * (M_PI/180);
 	x = floor(h * tan(theta));
 	for(int i = 0; i < h; i++){
 		while(i < x){
 			for(int j = 0; j < i; j++){
 				cout << "*";
 			}
 			cout << endl;
 		}
 		for(int j = 0; j < x; j++){
 			cout << "*";
 		}
 			cout <<endl;
 		}

 }