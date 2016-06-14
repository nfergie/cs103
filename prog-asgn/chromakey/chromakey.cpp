/*********************************************************************
 File:     chromakey.cpp

 Author: Nicole Fergie

 Email address: fergiem@usc.edu

 Usage: program_name in.bmp background.bmp dist_threshold out1.bmp out2.bmp

 Notes:
 This program performs the chroma key operation on an input 
 using two different methods.

 Method 1 Utilize a user-defined distance threshold from the
          chromakey value as a discriminator

 Method 2 Devise a method that to determine the chromakey mask
          that doesn't require a user-input threshold

********************************************************************/

#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include "bmplib.h"

using namespace std;

// Prototypes
// IMPORTANT: you must exactly use these input types, function names, and 
// return types. Otherwise the grader can't test them.
void method1(unsigned char inImage[][SIZE][RGB], 
        bool mask[][SIZE],
        double threshold);

void method2(unsigned char inImage[][SIZE][RGB], 
        bool mask[][SIZE]);

void replace(bool mask[][SIZE],
        unsigned char inImage[][SIZE][RGB],
        unsigned char bgImage[][SIZE][RGB],
        unsigned char outImage[][SIZE][RGB]);

int main(int argc, char *argv[])
{
  // Image data array
  // Note:  DON'T use the static keyword except where we expressly say so.
  //        It puts the large array in a separate, fixed, area of memory. 
  //        It is bad practice. But useful until we have dynamic allocation.
  static unsigned char inputImage[SIZE][SIZE][RGB];
  static unsigned char bgrndImage[SIZE][SIZE][RGB];
  static unsigned char outputImage[SIZE][SIZE][RGB];
  static bool chromaMask[SIZE][SIZE];

  double threshold;

  if (argc < 6) {
    cerr << "usage: program_name in.bmp background.bmp dist_threshold " 
         << "out1.bmp out2.bmp" << endl;
    return 0;
  }
   
  if (readRGBBMP(argv[1], inputImage)) {
    cerr << "Error reading file: " << argv[1] << endl;
    return 1;
  }

  if (readRGBBMP(argv[2], bgrndImage)) {
    cout << "Error reading file: " << argv[2] << endl;
    return 1;
  }
  
  // Write code to convert the threshold (argv[3])
  //  from string format to a double and assign the 'threshold'
  threshold= atof(argv[3]);

  // Call Method 1 Function
  method1(inputImage, chromaMask, threshold);

  // Produce the output by calling replace()
  replace(chromaMask, inputImage, bgrndImage, outputImage);

  // Write the output image to a file using the filename argv[4]
  if (writeRGBBMP(argv[4], outputImage)) {
    cout << "Error writing file: " << argv[4] << endl;
    exit(1);
  }   

  // Call Method 2 Function
  method2(inputImage, chromaMask);

  // Produce the output by calling replace()
  replace(chromaMask, inputImage, bgrndImage, outputImage);

  // Write the output image to a file using the filename argv[5]
  if (writeRGBBMP(argv[5], outputImage)) {
    cout << "Error writing file: " << argv[5] << endl;
    exit(1);
  }   

  return 0;
}



// Use user-provided threshold for chroma-key distance
// The "output" of this method is to produce a valid mask array
//  where entries in the mask array are 1 for foreground image
//  and 0 for 'background'
void method1(unsigned char inImage[][SIZE][RGB], 
        bool mask[][SIZE],
        double threshold)
{
   //In this section of code we are identifying the average RGB value
   //from the first three rows of the picture
   double averageR;
   double averageG;
   double averageB;
   double counter = 0.0;
   int sumR = 0;
   int sumG=0;
   int sumB=0;
   for(int i=0; i<3; i++){
      for(int j=0; j<256; j++){
         sumR = sumR + inImage[i][j][0];
         sumG = sumG + inImage[i][j][1];
         sumB = sumB + inImage[i][j][2];
         counter++;
      }
   }

   //we must cast the sums to doubles so the average is a double.
   //the average must be a double to have a greater accuracy in our 
   //distance calculation.
   averageR = static_cast<double>(sumR)/counter;
   averageG = static_cast<double>(sumG)/counter;
   averageB = static_cast<double>(sumB)/counter;

   //in this section of code we identify wether a pixel is within the
   //threshold for the chromakey and if it is we set the corresponding
   //mask location to 0 if not we set to 1.
   double distance;
   int red;
   int green;
   int blue;
   for(int k=0; k<256; k++){
      for(int l=0; l<256; l++){
         red = inImage[k][l][0];
         green = inImage[k][l][1];
         blue = inImage[k][l][2];
         distance = sqrt(static_cast<double>(pow((averageR-red),2) 
            + pow((averageG-green), 2) + pow((averageB-blue), 2)));
         if(distance > threshold){
            mask[k][l] = 1;
         }else{
            mask[k][l]=0;
         }
      }
   }

}

// Devise a method to automatically come up with a threshold
//  for the chroma key determination
// The "output" of this method is to produce a valid mask array
//  where entries in the mask array are 1 for foreground image
//  and 0 for 'background'
void method2(unsigned char inImage[][SIZE][RGB], 
        bool mask[][SIZE])  
{


}

// If mask[i][j] = 1 use the input image pixel for the output image
// Else if mask[i][j] = 0 use the background image pixel
void replace(bool mask[SIZE][SIZE],
        unsigned char inImage[SIZE][SIZE][RGB],
        unsigned char bgImage[SIZE][SIZE][RGB],
        unsigned char outImage[SIZE][SIZE][RGB])
{
  // Create the output image using the mask to determine
  //  whether to use the pixel from the Input or Background image
   
   //here quite simply if in the mask a value is one take the pixel from
   //the input if it is 0 take it from the bground.
   for(int i =0; i<256; i++){
      for(int j=0; j<256; j++){
         if(mask[i][j] == 1){
            for(int k =0; k<3; k++){
               outImage[i][j][k] = inImage[i][j][k];
            }
         }
         else{
            for(int l=0; l<3;l++){
               outImage[i][j][l] = bgImage[i][j][l];
            }
         }
      }
   }
}
