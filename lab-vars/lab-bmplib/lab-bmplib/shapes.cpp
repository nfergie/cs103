#include <iostream>
#include <cmath>
#include "bmplib.h"

using namespace std;

// global variable. bad style but ok for this lab
unsigned char image[SIZE][SIZE];

// Fill in this function:
void draw_rectangle(int top, int left, int height, int width) {
	for (int i=0; i<SIZE; i++){
		for(int j=0; j<SIZE; j++){
			if(i == top){
				if(j >= left && j <= (left + width)){
					image[i][j] = 0;
				}
			}
			else if(i == top + height){
				if(j >= left && j <= (left + width)){
					image[i][j] = 0;
				}
			}
			else if((i > top) && (i < (top + height))){
				if(j == left || j == (left + width)){
					image[i][j] = 0;
				}
			}
		}
	}
}

// Fill in this function:
void draw_ellipse(int cy, int cx, int height, int width) {
	for(double t = 0.0; t <= (2*M_PI); t+=0.01){
		int x = ((width/2.0)*cos(t)) + cx;
		int y = ((height/2.0)*sin(t)) + cy;
		if((x >=0 && x <= 255) && (y >= 0 && y <=255)){
			image[y][x]=0;
		}
	}
}


int main() {
   	// initialize the image to all white pixels
   	for (int i=0; i < SIZE; i++) {
      	for (int j=0; j < SIZE; j++) {
        	image[i][j] = 255;
      	}
   	}

   
   	// Main program loop here
   	int com;
   	int a;
   	int b;
   	int c;
   	int d;
   	bool quit = false;
   	cout << "To Draw a rectangle, enter: 0 top left height width" << endl;
   	cout << "To Draw an ellipse, enter: 1 cy cx height width" << endl;
   	cout << " To save your drawing as 'output.bmp' and quit, enter 2"<< endl;

   	while(quit == false){
   		cin >> com;
   		if(com ==2){
   			quit = true;
   		}
   		else if( com == 0){
   			cin >> a>> b>>c>>d;
   			draw_rectangle(a, b, c, d);
   		}
   		else if(com == 1){
   			cin >> a>>b>>c>>d;
   			draw_ellipse(a, b, c, d);
   		}
   		else{
   			cout << "Enter Valid number"<< endl;
   		}
   	}


   // Write the resulting image to the .bmp file
    writeGSBMP("output.bmp", image);
   
   return 0;
}
