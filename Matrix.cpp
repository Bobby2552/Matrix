#include "Arduino.h"
#include "Matrix.h"

int X_SIZE;
int Y_SIZE;
int X_START_PIN;
int Y_START_PIN;
bool[][] buffer;

Matrix::Matrix(int X_SIZE, int Y_SIZE, int X_START_PIN, int Y_START_PIN) {
    this->X_SIZE = X_SIZE;
    this->Y_SIZE = Y_SIZE;
    this->X_START_PIN = X_START_PIN;
    this->Y_START_PIN = Y_START_PIN;
    for (int x = X_START_PIN; x < X_START_PIN + X_SIZE; x++) {
      pinMode(x, OUTPUT);
    }
    for (int y = Y_START_PIN; y < Y_START_PIN + Y_SIZE; y++) {
      pinMode(y, OUTPUT);
    }
    buffer = malloc(X_SIZE * Y_SIZE * sizeof(bool*));
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

    delay(time);

    for(int i = X_START_PIN; i < X_START_PIN + X_SIZE; i++) {
        digitalWrite(i, LOW);
    }
    for(int i = Y_START_PIN; i < Y_START_PIN + Y_SIZE; i++) {
        digitalWrite(i, HIGH);
    }


}

void Matrix::led(int x, int y, int time, int bright) {
    x += X_START_PIN;
    y += Y_START_PIN;
    for(int i = X_START_PIN; i < X_START_PIN + X_SIZE; i++) {
        analogWrite(i, x == i ? bright:0);
    }
    for(int i = Y_START_PIN; i < Y_START_PIN + Y_SIZE; i++) {
        digitalWrite(i, y == i ? LOW:HIGH);
    }

    delay(time);

    for(int i = X_START_PIN; i < X_START_PIN + X_SIZE; i++) {
        digitalWrite(i, LOW);
    }
    for(int i = Y_START_PIN; i < Y_START_PIN + Y_SIZE; i++) {
        digitalWrite(i, HIGH);
    }


}

    void Matrix::randomLed(int time) {
      led(random(0, X_SIZE), random(0, Y_SIZE), time);
    }
