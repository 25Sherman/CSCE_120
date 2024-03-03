#ifndef FUNCTIONS_H
#define FUNCTIONS_H

// struct for Pixel (short is a 2 byte signed integer)
struct Pixel {
  short r; // red
  short g; // green
  short b; // blue
};

// maximum image dimensions (do not change)
const unsigned int MAX_WIDTH = 1920;
const unsigned int MAX_HEIGHT = 1080;

// already implemented
void initializeImage(Pixel image[][MAX_HEIGHT]);

// TODO: implement for image scaling
void loadImage(std::string filename, Pixel image[][MAX_HEIGHT], unsigned int& width, unsigned int& height);
void outputImage(std::string filename, Pixel image[][MAX_HEIGHT], unsigned int width, unsigned int height);
double map_coordinates(unsigned int source_dimension, unsigned int target_dimension, unsigned int pixel_coordinate);
Pixel bilinear_interpolation(Pixel image[][MAX_HEIGHT], unsigned int width, unsigned int height, double x, double y);
void scale_image(Pixel sourceImage[][MAX_HEIGHT], unsigned int sourceWidth, unsigned int sourceHeight,
                   Pixel targetImage[][MAX_HEIGHT], unsigned int targetWidth, unsigned int targetHeight);

#endif