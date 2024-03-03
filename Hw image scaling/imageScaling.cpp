#include <iostream>
#include <sstream>
#include <fstream>
#include <cmath>
#include "functions.h"

using std::cout, std::endl, std::cin, std::string, std::stringstream;

int main() {
  // 2D array of pixels
  static Pixel sourceImage[MAX_WIDTH][MAX_HEIGHT];
  static Pixel targetImage[MAX_WIDTH][MAX_HEIGHT];  
  
  // initialize 2D array
  initializeImage(sourceImage);
  initializeImage(targetImage);

  // declare variables
  string filename;
  unsigned int sourceWidth = 0;
  unsigned int sourceHeight = 0;
  unsigned int targetWidth = 0;
  unsigned int targetHeight = 0;
  
  // accept filename
  cout << "Input filename: ";
  cin >> filename;

  try {
    // attempt to load image
    loadImage(filename, sourceImage, sourceWidth, sourceHeight);
    cout << "Detected image width: " << sourceWidth << endl;
    cout << "Detected image height: " << sourceHeight << endl;
  } catch (std::exception &ex) {
    cout << "Exception thrown: " << ex.what() << endl;
    return 1; // exit with error
  }

  // accept target dimensions
  cout << "Input target width: ";
  cin >> targetWidth;
  cout << "Input target height: ";
  cin >> targetHeight;

  // TODO: add code to validate input
  // Exit program with error if there are problems with 
  //   targetWidth or targetHeight





  // END input validation. Do not modify code beyond this point.
  cout << "Start image scaling..." << endl;
  scale_image(sourceImage, sourceWidth, sourceHeight,
              targetImage, targetWidth, targetHeight);

  // Final file output.
  try {
    // attempt to output image
    stringstream ss;
    ss << "Scaled" << targetWidth << "X" << targetHeight << ".ppm";
    outputImage(ss.str().c_str(), targetImage, targetWidth, targetHeight);
  } catch (std::exception &ex) {
    cout << "Exception thrown: " << ex.what() << endl;
    return 1; // exit with an error
  }

  cout << "Image output" << endl;

  return 0; // exit without errors
}

// int main(){
//   int source = 10;
//   int target = 100;
//   int coordinate = 98;
//   cout << map_coordinates(source, target, coordinate) << endl;
// }

