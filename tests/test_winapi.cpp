#include <vector>
#include "gtest/gtest.h"
#include "../winapi/functions_winapi.h"

TEST(WinApiMinMaxTest, BasicTest) {
    std::vector<int> arr = { 10, 3, 7, 2, 9 };

    ThreadData data;
    data.arr = &arr;
    data.minVal = 0;
    data.maxVal = 0;
    data.average = 0.0;

    HANDLE hMinMax = CreateThread(NULL, 0, minmaxThread, &data, 0, NULL);
    WaitForSingleObject(hMinMax, INFINITE);
    CloseHandle(hMinMax);

    EXPECT_EQ(data.minVal, 2);
    EXPECT_EQ(data.maxVal, 10);
}

TEST(WinApiAverageTest, BasicTest) {
    std::vector<int> arr = { 1, 2, 3, 4 };

    ThreadData data;
    data.arr = &arr;
    data.minVal = 0;
    data.maxVal = 0;
    data.average = 0.0;

    HANDLE hAvg = CreateThread(NULL, 0, averageThread, &data, 0, NULL);
    WaitForSingleObject(hAvg, INFINITE);
    CloseHandle(hAvg);

    EXPECT_NEAR(data.average, 2.5, 1e-6);
}


TEST(WinApiReplaceMinMaxTest, BasicTest) {
    std::vector<int> arr = { 10, 3, 7, 2, 9 };

    auto newArr = replaceMinMaxWinAPI(arr, 2, 10, 6.0);

    for (int val : newArr) {
        ASSERT_TRUE(val != 2 && val != 10) << "Min or max not replaced!";
    }
}


int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
