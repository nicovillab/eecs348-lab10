#ifndef MATRIX_H
#define MATRIX_H

#include <string>

// Largest matrix size this program supports
const int MAX_SIZE = 100;

class Matrix {
private:
    int size;                        // the matrix is size x size
    int data[MAX_SIZE][MAX_SIZE];

public:
    Matrix(int n = 0);

    int getSize() const;
    int get(int row, int col) const;
    void set(int row, int col, int value);
    void print() const;

    // Operator overloading for addition and multiplication
    Matrix operator+(const Matrix& other) const;
    Matrix operator*(const Matrix& other) const;

    int mainDiagonalSum() const;
    int secondaryDiagonalSum() const;
};

// Reads N and two N x N matrices from a file. Returns false on any error.
bool readMatrices(const std::string& filename, Matrix& a, Matrix& b);

void printDiagonalSums(const Matrix& m);

// These take the Matrix by value, so the caller's matrix is never changed.
void swapRows(Matrix m, int row1 = 0, int row2 = 1);
void swapColumns(Matrix m, int col1 = 0, int col2 = 1);
void updateElement(Matrix m, int row = 0, int col = 0, int value = 100);

#endif
