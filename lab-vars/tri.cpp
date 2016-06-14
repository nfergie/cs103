#include <iostream>
#include <cmath>
#include <string>
using namespace std;

/* Author: Nic Fergie
 * Program: tri
 * Description: prints right triangle 
 */

 int main(){
 	//def vars
 	int h = 30;
 	double theta;
 	int b;

 	//usr input
 	cout << "Please enter theta value: ";
 	cin >> theta;

 	//calculations
 	theta = theta * (M_PI/180);

 	for(int i =0; i < h; i++){
 		b = static_cast<int>(floor(i * tan(theta)));
 		if(b >= 20 && b <= 30){
 			for (int l = 0; l <20; l++){
 				cout << "*";
 			}
 			cout << endl;
 		}else{
 			for(int j = 0; j < b; j++){
 			cout << "*";
 			}
 			cout << endl;
 		}

 	}
}