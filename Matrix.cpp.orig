#include "Arduino.h"
#include "Matrix.h"

int X_SIZE;
int Y_SIZE;
int X_START_PIN;
int Y_START_PIN;

Matrix::Matrix(int X_SIZE, int Y_SIZE, int X_START_PIN, int Y_START_PIN) {
  this->X_SIZE = X_SIZE;
  this->Y_SIZE = Y_SIZE;
  this->X_START_PIN = X_START_PIN;
  this->Y_START_PIN = Y_START_PIN;
}

void Matrix::led(int x, int y, int time) {
  x += X_START_PIN;
  y += Y_START_PIN;
  for(int i = X_START_PIN; i < X_START_PIN + X_SIZE; i++) {
    digitalWrite(i, x == i ? HIGH:LOW); 
  }
 for(int i = Y_START_PIN; i < Y_START_PIN + Y_SIZE; i++) {
  digitalWrite(i, y == i ? LOW:HIGH); 
 }
 
 delay(dly);
 
 for(int i = X_START_PIN; i < X_START_PIN + X_SIZE; i++) {
  digitalWrite(i, LOW); 
 }
 for(int i = Y_START_PIN; i < Y_START_PIN + Y_SIZE; i++) {
  digitalWrite(i, HIGH); 
 }
}
