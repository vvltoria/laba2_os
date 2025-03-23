#include <iostream>
#include <windows.h>
#include <vector>
#include "functions_winapi.h"

int main()
{
    std::cout << "enter the size of the vector: ";
    int n;
    std::cin >> n;

    std::vector<int> arr(n);
    std::cout << "enter the elements:" << std::endl;
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    ThreadData data;
    data.arr = &arr;
    data.minVal = 0;
    data.maxVal = 0;
    data.average = 0.0;

    HANDLE hMinMaxThread = CreateThread(
        NULL,
        0,
        minmaxThread,
        &data,
        0,
        NULL
    );

    HANDLE hAverageThread = CreateThread(
        NULL,
        0,
        averageThread,
        &data,
        0,
        NULL
    );

    WaitForSingleObject(hMinMaxThread, INFINITE);
    WaitForSingleObject(hAverageThread, INFINITE);

    int minVal = data.minVal;
    int maxVal = data.maxVal;
    double avg = data.average;

    std::vector<int> newArr = replaceMinMaxWinAPI(arr, minVal, maxVal, avg);

    std::cout << "new vector: ";
    for (int v : newArr)
        std::cout << v << " ";
    std::cout << std::endl;

    CloseHandle(hMinMaxThread);
    CloseHandle(hAverageThread);

    return 0;
}
