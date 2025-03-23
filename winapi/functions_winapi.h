#ifndef FUNCTIONS_WINAPI_H
#define FUNCTIONS_WINAPI_H

#include <vector>
#include <utility>
#include <windows.h>

struct ThreadData
{
    const std::vector<int>* arr;

    int minVal;
    int maxVal;
    double average;
};

DWORD WINAPI minmaxThread(LPVOID lpParam);

DWORD WINAPI averageThread(LPVOID lpParam);

std::vector<int> replaceMinMaxWinAPI(const std::vector<int>& arr, int minVal, int maxVal, double avg);

#endif // FUNCTIONS_WINAPI_H
