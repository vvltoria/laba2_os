#include "functions_winapi.h"
#include <iostream>

DWORD WINAPI minmaxThread(LPVOID lpParam)
{
    ThreadData* data = static_cast<ThreadData*>(lpParam);
    const auto& arr = *(data->arr);

    int minVal = arr[0];
    int maxVal = arr[0];
    for (size_t i = 0; i < arr.size(); i++)
    {
        if (arr[i] < minVal)
            minVal = arr[i];
        if (arr[i] > maxVal)
            maxVal = arr[i];

        Sleep(7);
    }

    std::cout << "Min: " << minVal << ", Max: " << maxVal << std::endl;

    data->minVal = minVal;
    data->maxVal = maxVal;

    return 0;
}

DWORD WINAPI averageThread(LPVOID lpParam)
{
    ThreadData* data = static_cast<ThreadData*>(lpParam);
    const auto& arr = *(data->arr);

    double sum = 0;
    for (size_t i = 0; i < arr.size(); i++)
    {
        sum += arr[i];
        Sleep(12);
    }
    double avg = sum / arr.size();

    std::cout << "Average: " << avg << std::endl;

    data->average = avg;

    return 0;
}

std::vector<int> replaceMinMaxWinAPI(const std::vector<int>& arr, int minVal, int maxVal, double avg)
{
    std::vector<int> result = arr;
    for (auto& v : result)
    {
        if (v == minVal || v == maxVal)
        {
            v = static_cast<int>(avg);
        }
    }
    return result;
}
