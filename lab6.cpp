#include <iostream>
#include <fstream>

using namespace std;

const int MAX_SIZE = 10;

int sumRowsWithNegative(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    int totalSum = 0;
    for (int i = 0; i < rows; i++) {
        bool hasNegative = false;
        int rowSum = 0;
        for (int j = 0; j < cols; j++) {
            rowSum += matrix[i][j];
            if (matrix[i][j] < 0) {
                hasNegative = true;
            }
        }
        if (hasNegative) {
            totalSum += rowSum;
        }
    }
    return totalSum;
}

void findSaddlePoints(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int element = matrix[i][j];
            bool isMinInRow = true;
            bool isMaxInCol = true;

            for (int k = 0; k < cols; k++) {
                if (matrix[i][k] < element) {
                    isMinInRow = false;
                    break;
                }
            }

            for (int k = 0; k < rows; k++) {
                if (matrix[k][j] > element) {
                    isMaxInCol = false;
                    break;
                }
            }

            if (isMinInRow && isMaxInCol) {
                cout << "Saddle point found at row " << i + 1 << ", column " << j + 1 << " with value " << element << endl;
            }
        }
    }
}

int main() {
    int matrix[MAX_SIZE][MAX_SIZE];
    int rows, cols;

    ifstream inputFile("matrix.txt");
    if (!inputFile) {
        cerr << "Cannot open file" << endl;
        return 1;
    }

    inputFile >> rows >> cols;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            inputFile >> matrix[i][j];
        }
    }
    inputFile.close();

    cout << "Matrix elements:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    int sumNegativeRows = sumRowsWithNegative(matrix, rows, cols);
    cout << "Sum of rows with at least one negative element: " << sumNegativeRows << endl;

    findSaddlePoints(matrix, rows, cols);

    return 0;
}
