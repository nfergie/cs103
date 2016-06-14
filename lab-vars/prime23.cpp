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
 	//vars def
 	int num;
 	int n;
 	string ans;
 	int count2=0;
 	int count3=0;

 	//usr input
 	cout << "Please enter an integer: ";
 	cin >>n;

 	//calculations
 	num = n;
 	while(num % 2 == 0 || num % 3 == 0){
 		if(num % 2 == 0){
 			num /= 2;
 			count2++;
 		}
 		else{
 			num /= 3;
 			count3++;
 		}
 	}
 	if(num == 1){
 		cout << "Twos = " << count2 << ", Threes = " <<count3<<endl;
 	}else{
 		cout << n << "No" <<endl;
 	}
 }