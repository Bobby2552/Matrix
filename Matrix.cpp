#include "Arduino.h"
#include "Matrix.h"

//int X_SIZE;
//int Y_SIZE;
//int X_START_PIN;
//int Y_START_PIN;
//bool buffer[][];

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

    int size = X_SIZE * Y_SIZE * sizeof(bool);

    this->buffer = (bool*)malloc(size);
    memset(buffer, 0, size);
}

Matrix::~Matrix() {
    free(buffer);
}

void Matrix::led(int x, int y, int time) {
    x += X_START_PIN;
    y += Y_START_PIN;
    // for(int i = X_START_PIN; i < X_START_PIN + X_SIZE; i++) {
    //     digitalWrite(i, x == i ? HIGH:LOW);
    // }
    // for(int i = Y_START_PIN; i < Y_START_PIN + Y_SIZE; i++) {
    //     digitalWrite(i, y == i ? LOW:HIGH);
    // }

    // delay(time);

    // for(int i = X_START_PIN; i < X_START_PIN + X_SIZE; i++) {
    //     digitalWrite(i, LOW);
    // }
    // for(int i = Y_START_PIN; i < Y_START_PIN + Y_SIZE; i++) {
    //     digitalWrite(i, HIGH);
    // }
    
    setState(x, y, true);

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

bool Matrix::getState(int x, int y) const {
    int i = y * X_SIZE + x;
    return buffer[i];
}

void Matrix::setState(int x, int y, bool state) {
    int i = y * X_SIZE + x;
    buffer[i] = state;
}


