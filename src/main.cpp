
#include "Arduino.h"
#include "matrix.hpp"

#define COUNT(arr) (sizeof(arr) / sizeof(*arr))

Matrix mat(30, 2, 10, 5);

double benSin(double x) {
    return (2.5 * sin(x)) + 2;
}

double benSqrt(double x) {
    return sqrt(x);
}

double benSquared(double x) {
    x -= 5;
    return x * x;
}

typedef double (*function)(double);

function fns[] = { benSin, benSqrt, benSquared };

int i = COUNT(fns);
int timeToDisplay = 2000;

void setup() {

}

void loop() {
    if ((millis() - timeToDisplay * i) < 100) {
        i++;
    }

    function f = fns[i % COUNT(fns)];

    for (int x = 0; x < 10; x++) {
        for (int y = 0; y < 5; y++) {
            mat[y][x] = y == (int)f(x) ? HIGH:LOW;
        }
    }

    mat.write();
}
