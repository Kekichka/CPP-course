#include <iostream>
using namespace std;

int main() {
    const int N = 4; 
    int matrix[N][N] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    int sum = 0;

    for (int i = 1; i < N; ++i) {
        for (int j = 0; j < N - i; ++j) {
            if (matrix[i][j] > 0 && matrix[i][j] % 2 != 0) {  
                sum += matrix[i][j];
            }
        }
    }

    cout << "Sum: " << sum << endl;

    return 0;
}
