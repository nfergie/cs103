#include <iostream>
#include "bmplib.h"

using namespace std;
unsigned char image[SIZE][SIZE];

int main(){
	//create a blank canvass
	for(int d=0; d < SIZE; d++){
		for(int i=0; i <d+1; i++){
			image[d-i][i] =d;
			image[SIZE -1 - (d-i)][(SIZE - 1) -i]=d;
		}
	}

	showGSBMP(image);
	writeGSBMP("gradient.bmp", image);
	return 0;
}