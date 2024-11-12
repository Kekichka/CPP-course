#include <iostream>
using namespace std;

int main() {
    int i, j;
    const int n = 4, m = 4;
    int matr[n][m], sum = 0;

    cout << "Input matrix:\n";
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            cin >> matr[i][j];
        }
    }

    for (i = 1; i < n; i++) {  
        for (j = n - i; j < m; j++) {  
            if (matr[i][j] > 0 && matr[i][j] % 2 != 0) { 
                sum += matr[i][j];
            }
        }
    }

    cout << "Sum of positive odd numbers below the secondary diagonal: " << sum << endl;

    return 0;
}
