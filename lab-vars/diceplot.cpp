#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

int roll();
void printHistogram(int counts[]);
int experiment();

int main(){
	srand(time(0));
	int n;
	int counts[21] = {0};

	cout << "Please enter a number: ";
	cin >> n;

	for(int i=0; i <n; i++){
		int result = experiment();
		counts[result -4]++;
		cout <<result << endl;
	}


	printHistogram(counts);

}

int roll(){
	return (rand() % 6 + 1);
}

void printHistogram(int counts[]){
	for (int i=0; i <21; i++){
		cout << (i + 4) << ": " <<string(counts[i], 'X')<<endl;
	}
}

int experiment(){
	int sum = 0;
	for (int i = 0; i<4; i++){
		sum = sum + roll();
	}
	return sum;
}