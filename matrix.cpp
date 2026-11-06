#include "matrix.h"
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

Matrix::Matrix(int n) {
    size = n;
    for (int i = 0; i < MAX_SIZE; i++) {
        for (int j = 0; j < MAX_SIZE; j++) {
            data[i][j] = 0;
        }
    }
}

int Matrix::getSize() const {
    return size;
}

int Matrix::get(int row, int col) const {
    return data[row][col];
}

void Matrix::set(int row, int col, int value) {
    data[row][col] = value;
}

// Prints each value in a column 4 characters wide so the columns line up
void Matrix::print() const {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << setw(4) << data[i][j];
        }
        cout << endl;
    }
}

// A + B: add the elements in the same position
Matrix Matrix::operator+(const Matrix& other) const {
    Matrix result(size);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            result.data[i][j] = data[i][j] + other.data[i][j];
        }
    }
    return result;
}

// A * B: each result[i][j] is row i of A "dotted" with column j of B,
// i.e. A[i][0]*B[0][j] + A[i][1]*B[1][j] + ... + A[i][n-1]*B[n-1][j]
Matrix Matrix::operator*(const Matrix& other) const {
    Matrix result(size);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            int sum = 0;
            for (int k = 0; k < size; k++) {
                sum += data[i][k] * other.data[k][j];
            }
            result.data[i][j] = sum;
        }
    }
    return result;
}

// Main diagonal: top-left to bottom-right, where row == col
int Matrix::mainDiagonalSum() const {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += data[i][i];
    }
    return sum;
}

// Secondary diagonal: top-right to bottom-left, where col == size - 1 - row
int Matrix::secondaryDiagonalSum() const {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += data[i][size - 1 - i];
    }
    return sum;
}

bool readMatrices(const string& filename, Matrix& a, Matrix& b) {
    ifstream file(filename.c_str());
    if (!file) {
        cout << "Error: could not open file '" << filename << "'." << endl;
        return false;
    }

    int n;
    if (!(file >> n) || n <= 0 || n > MAX_SIZE) {
        cout << "Error: invalid matrix size in file." << endl;
        return false;
    }

    a = Matrix(n);
    b = Matrix(n);

    int value;
    // Read the first matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!(file >> value)) {
                cout << "Error: not enough data for Matrix A." << endl;
                return false;
            }
            a.set(i, j, value);
        }
    }
    // Read the second matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!(file >> value)) {
                cout << "Error: not enough data for Matrix B." << endl;
                return false;
            }
            b.set(i, j, value);
        }
    }
    return true;
}

void printDiagonalSums(const Matrix& m) {
    cout << "Main diagonal sum: " << m.mainDiagonalSum() << endl;
    cout << "Secondary diagonal sum: " << m.secondaryDiagonalSum() << endl;
}

void swapRows(Matrix m, int row1, int row2) {
    int n = m.getSize();
    if (row1 < 0 || row1 >= n || row2 < 0 || row2 >= n) {
        cout << "Error: invalid row indices." << endl;
        return;
    }
    for (int j = 0; j < n; j++) {
        int temp = m.get(row1, j);
        m.set(row1, j, m.get(row2, j));
        m.set(row2, j, temp);
    }
    m.print();
}

void swapColumns(Matrix m, int col1, int col2) {
    int n = m.getSize();
    if (col1 < 0 || col1 >= n || col2 < 0 || col2 >= n) {
        cout << "Error: invalid column indices." << endl;
        return;
    }
    for (int i = 0; i < n; i++) {
        int temp = m.get(i, col1);
        m.set(i, col1, m.get(i, col2));
        m.set(i, col2, temp);
    }
    m.print();
}

void updateElement(Matrix m, int row, int col, int value) {
    int n = m.getSize();
    if (row < 0 || row >= n || col < 0 || col >= n) {
        cout << "Error: invalid row or column index." << endl;
        return;
    }
    m.set(row, col, value);
    m.print();
}
