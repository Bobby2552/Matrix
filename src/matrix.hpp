#pragma once

/**
 * Interface to a LED matrix
 * Doesn't support shift register based matrices currently
 * Assumes LEDs are connected in sequential ports
 */
struct Matrix {
    bool* buffer;

    int startX;
    int startY;

    int width;
    int height;
 
    Matrix(int startX, int startY, int width, int height);

    // Allows for indexing as such: myMatrix[row][col]
    bool* operator[] (int row);

    // Turns all values in "buffer" off
    void clear();

    // Used By "write" to physicially turn off LEDs
    void preparePins();

    // Updates physical LED matrix
    // Doesn't keep the matrix powered on after being called
    // Call in "loop" or equivalent function to keep matrix powered on
    void write(); 
};
