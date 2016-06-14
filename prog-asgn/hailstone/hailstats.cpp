#include <iostream>
#include <cmath>
#include <climits>

using namespace std;

int main(){
	//vars
	int hi;
	int low;
	int counter;
	int num;
	int minLength = INT_MAX;
	int minNum = INT_MAX;
	int maxLength = -1;
	int maxNum = -1;

	//usr input
	cout << "Enter the range you want to search: ";
	cin >> low >> hi;

	if(hi < low){
		cout << "Invalid range";
	}
	else{
		for(int i = low; i <= hi; i++){
			num = i;
			counter = 0;
			while(num != 1){
				if((num % 2) == 0){
					num = (num / 2);
				}
				else{
					num = (num * 3) + 1;
				}
			counter++;
			}
			if(counter < minLength){
				minLength = counter;
				minNum = i;
			}else if(counter > maxLength){
				maxLength = counter;
				maxNum = i;
			}
		}

	}

	cout << "Minimum length: " << minLength << endl;
	cout << "Achieved by: " << minNum << endl;
	cout << "Maximum length: " << maxLength << endl;
	cout << "Achieved by: " << maxNum << endl;

	return 0;
}