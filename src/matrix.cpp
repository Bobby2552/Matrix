
#include "matrix.hpp"
#include "Arduino.h"

Matrix::Matrix(int startX, int startY, int width, int height) : startX(startX), startY(startY), width(width), height(height) {
    for (int x = startX; x < startX + width; x++) {
        for (int y = startY; y < startY + height; y++) {
            pinMode(y, OUTPUT);
        }
        pinMode(x, OUTPUT);
    }

    buffer = new bool[width * height];

    clear();
}

bool* Matrix::operator[] (int row) {
    return &buffer[row * width];
}

void Matrix::clear() {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            (*this)[y][x] = LOW;
        }
    }
}

void Matrix::preparePins() {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            digitalWrite(x + startX, LOW);
        }
        digitalWrite(y + startY, HIGH);
    }
}

void Matrix::write() {
    for (int x = 0; x < width; x++) {
        for (int y = 0; y < height; y++) {
            bool state = buffer[(y * width) + x];

            if (state) {
                digitalWrite(x + startX, HIGH);
                digitalWrite(y + startY, LOW);

                delay(1);
            }

            digitalWrite(x + startX, LOW);
            digitalWrite(y + startY, HIGH);
        }
    }
}
