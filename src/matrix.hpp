#pragma once

struct Matrix {
    bool* buffer;

    int startX;
    int startY;

    int width;
    int height;
 
    Matrix(int startX, int startY, int width, int height);

    bool* operator[] (int row);

    void clear();
    void preparePins();
    void write(); 
};
