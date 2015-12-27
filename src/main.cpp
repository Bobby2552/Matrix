
#include "Arduino.h"
#include "matrix.hpp"

Matrix mat(30, 2, 10, 5);

void setup() {
    mat[0][0] = HIGH;
    mat[0][1] = HIGH;
}

void loop() {
    mat.write();
}
