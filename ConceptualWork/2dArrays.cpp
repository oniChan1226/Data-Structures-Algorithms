#include <iostream>
using namespace std;

void transpose(int** A, int rows, int cols, int** B) {
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            B[j][i] = A[i][j];
}

int main() {
    int rows = 4, cols = 4; // Example dimensions
    int** A = new int*[rows];
    for (int i = 0; i < rows; ++i)
        A[i] = new int[cols];

    // Initialize the matrix
    int value = 1;
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            A[i][j] = value++;

    // Create a matrix to store the transpose
    int** B = new int*[cols];
    for (int i = 0; i < cols; ++i)
        B[i] = new int[rows];

    transpose(A, rows, cols, B);

    cout << "Result matrix is:\n";
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++)
            cout << " " << B[i][j];
        cout << "\n";
    }

    // Deallocate memory
    for (int i = 0; i < rows; ++i)
        delete[] A[i];
    delete[] A;

    for (int i = 0; i < cols; ++i)
        delete[] B[i];
    delete[] B;

    return 0;
}
