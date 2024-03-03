#include <iostream>
#include <sstream>
#include <fstream>
#include <cmath>
#include "functions.h"

using namespace std;

void initializeImage(Pixel image[][MAX_HEIGHT]) {
  // iterate through columns
  for (unsigned int col = 0; col < MAX_WIDTH; col++) {
    // iterate through rows
    for (unsigned int row = 0; row < MAX_HEIGHT; row++) {
      // initialize pixel
      image[col][row] = {0, 0, 0};
    }
  }
}

void loadImage(string filename, Pixel image[][MAX_HEIGHT], unsigned int& width, unsigned int& height) {
  // TODO: implement image loading

}


void outputImage(string filename, Pixel image[][MAX_HEIGHT], unsigned int width, unsigned int height) {
  // TODO: implement writing image to file

}

double map_coordinates(unsigned int source_dimension, unsigned int target_dimension, unsigned int pixel_coordinate){
  // TODO: implement mapping function.
  
}

Pixel bilinear_interpolation(Pixel image[][MAX_HEIGHT], unsigned int width, unsigned int height, double x, double y) {
  // TODO: Implement bilinear interpolation

}

void scale_image(Pixel sourceImage[][MAX_HEIGHT], unsigned int sourceWidth, unsigned int sourceHeight,
                   Pixel targetImage[][MAX_HEIGHT], unsigned int targetWidth, unsigned int targetHeight){
  // TODO: add loops to calculate scaled images

}