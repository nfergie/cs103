#include "network.h"
#include <sstream>

using namespace std;

int main(int argc, char *argv[])
{

Network network = Network();
if((network.read_friends(argv[1])) != 0){
	cout << "ERROR READING FILE";
	return -1;
}

bool repeat = true;

while(repeat){
	cout << "1- Add User" << endl;
	cout << "2- Add Friend Connection" <<endl;
	cout << "3- Remove Friend Connection" << endl;
	cout << "4- Print Users" << endl;
	cout << "5- List Friends" << endl;
	cout << "6- Write to File" << endl;
	cout << "Enter any other number to quit" << endl;

	string line;
	cin >> line;
	stringstream ss;
	ss >> line;
	int option;
	
	if()

}


  return 0;
}
