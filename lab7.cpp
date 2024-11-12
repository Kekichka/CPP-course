#include <iostream>
#include "header.h"
using namespace std;

int main() {
    const int N = 100;
    double arr[N];
    int n;

    cout << "Enter the number of elements (max " << N << "): ";
    cin >> n;

    INPUT_ARRAY(arr, n);
    OUTPUT_ARRAY(arr, n);

    double minElement;
    FIND_MIN_ELEMENT(arr, n, minElement);
    cout << "Minimum element: " << minElement << endl;

    double sumBetweenPositives;
    SUM_BETWEEN_POSITIVES(arr, n, sumBetweenPositives);
    cout << "Sum of elements between first and last positive elements: " << sumBetweenPositives << endl;

    REARRANGE_ZEROES_FIRST(arr, n);
    cout << "Array after rearranging (zeroes first): ";
    OUTPUT_ARRAY(arr, n);

    return 0;
}
