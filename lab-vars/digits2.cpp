#include <iostream>
#include <cmath>

/* Author: Nic Fergie
 * Program: digits
 * Description: Digit extraction from inputed number
 * with while loop
 */

 using namespace std;

 int main(){
 	//vars
 	int num;

 	//usr input
	cout << "Enter an integer between 0 and 999: ";
	cin >> num;

	while(num > 0){
		cout << num % 10;
		num = num /10;
	}
	cout << endl;
 	return 0;
 }