#include <iostream>
using namespace std;

void swapRowsAndProduct(int** matrix, int n) {
    for (int j = 0; j < n; ++j) {
        swap(matrix[0][j], matrix[n - 1][j]);
    }

    int product = 1;
    for (int i = 0; i < n; ++i) {
        product *= matrix[i][i];
    }

    cout << "Modified matrix:" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << "Product of main diagonal elements: " << product << endl;
}

int main() {
    int n;
    cout << "Enter the size of the matrix (n): ";
    cin >> n;

    int** matrix = new int*[n];
    for (int i = 0; i < n; ++i) {
        matrix[i] = new int[n];
    }

    cout << "Enter the elements of the matrix:" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matrix[i][j];
        }
    }

    swapRowsAndProduct(matrix, n);

    for (int i = 0; i < n; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}
