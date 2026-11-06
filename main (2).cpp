#include "matrix.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
    string filename;
    cout << "Enter input filename: ";
    if (!(cin >> filename)) {
        cout << endl << "Error: no filename entered." << endl;
        return 1;
    }
    cout << endl;

    // Practice 1: read and display both matrices
    Matrix A, B;
    if (!readMatrices(filename, A, B)) {
        return 1;
    }

    cout << "Matrix A:" << endl;
    A.print();
    cout << endl;

    cout << "Matrix B:" << endl;
    B.print();
    cout << endl;

    // Practice 2: addition with the overloaded + operator
    Matrix sum = A + B;
    cout << "A + B:" << endl;
    sum.print();
    cout << endl;

    // Practice 3: multiplication with the overloaded * operator
    Matrix product = A * B;
    cout << "A * B:" << endl;
    product.print();
    cout << endl;

    // Practice 4: diagonal sums
    cout << "Diagonal sums for Matrix A:" << endl;
    printDiagonalSums(A);
    cout << endl;

    // Practice 5: swap rows (A is passed by value, so it does not change)
    cout << "Problem 5 - Rows 0 and 2 swapped:" << endl;
    swapRows(A, 0, 2);
    cout << endl;

    // Practice 6: swap columns
    cout << "Problem 6 - Columns 0 and 2 swapped:" << endl;
    swapColumns(A, 0, 2);
    cout << endl;

    // Practice 7: update one element
    cout << "Problem 7 - Updated matrix:" << endl;
    updateElement(A, 1, 2, 99);

    return 0;
}
