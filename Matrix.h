#ifndef Matrix_h
#define Matrix_h

#include "Arduino.h"

class Matrix {
  //Variables described in constructor
  int X_SIZE;
  int Y_SIZE;
  int X_START_PIN;
  int Y_START_PIN;
  
 public:
  //Most basic constructor. Assumes no shift register.
  //Size variables are the size of matrix. Start_pin variables are for the first pin of
  //the anodes and cathodes.
  //******EXAMPLE*****//
  //5x5 matrix with anodes plugged into pins 2-6, and cathodes plugged into pins 7-11
  //Matrix(5, 5, 2, 7);
  Matrix(int X_SIZE, int Y_SIZE, int X_START_PIN, int Y_START_PIN);
  //Lights a single LED for a set amount of time (ms)
  //int x - x value of led to light (zero indexed)
  //int y - y value of led to light (zero indexed)
  //int time - time (ms) to light led
  void led(int x, int y, int time);
}

#endif
