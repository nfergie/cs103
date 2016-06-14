#include <iostream>
#include <cmath>

/* Author: Nic Fergie
 * Program: digits
 * Description: Digit extraction from inputed number
 */

 using namespace std;

int main(){

	//def vars
	int num;
	int one;
	int ten;
	int hund;
	int temp;

	//usr input
	cout << "Enter an integer between 0 and 999: ";
	cin >> num;

	//calcs
	hund = num / 100;
	temp = num % 100;

	ten = temp / 10;
	temp = temp % 10;

	one = temp;

	//output
	cout << "1's digit is " << one << endl;
	cout << "10's digit is " << ten << endl;
	cout << "100's digit is " << hund << endl;

	return 0;
}
