#ifndef ARRAY_MACROS_H
#define ARRAY_MACROS_H
using namespace std;
#include <iostream>

#define INPUT_ARRAY(arr, n)               \
    for (int i = 0; i < n; ++i) {         \
        cout << "Enter element " << i + 1 << ": "; \
        cin >> arr[i];                    \
    }

#define OUTPUT_ARRAY(arr, n)              \
    cout << "Array elements: ";           \
    for (int i = 0; i < n; ++i) {         \
        cout << arr[i] << " ";            \
    }                                     \
    cout << endl;

#define FIND_MIN_ELEMENT(arr, n, minElem) \
    minElem = arr[0];                     \
    for (int i = 1; i < n; ++i) {         \
        if (arr[i] < minElem) {           \
            minElem = arr[i];             \
        }                                 \
    }

#define SUM_BETWEEN_POSITIVES(arr, n, sum)    \
    sum = 0;                                  \
    int firstPosIndex = -1;                   \
    int lastPosIndex = -1;                    \
    for (int i = 0; i < n; ++i) {             \
        if (arr[i] > 0) {                     \
            if (firstPosIndex == -1) {        \
                firstPosIndex = i;            \
            }                                 \
            lastPosIndex = i;                 \
        }                                     \
    }                                         \
    if (firstPosIndex != -1 && lastPosIndex != -1 && firstPosIndex != lastPosIndex) { \
        for (int i = firstPosIndex + 1; i < lastPosIndex; ++i) { \
            sum += arr[i];                    \
        }                                     \
    }

#define REARRANGE_ZEROES_FIRST(arr, n)        \
    int zeroIndex = 0;                        \
    for (int i = 0; i < n; ++i) {             \
        if (arr[i] == 0) {                    \
            swap(arr[i], arr[zeroIndex]);     \
            zeroIndex++;                      \
        }                                     \
    }

#endif
#pragma once
