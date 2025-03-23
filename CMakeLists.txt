cmake_minimum_required(VERSION 3.10)
project(Lab2Threads)

set(CMAKE_CXX_STANDARD 17)


add_executable(Lab2Threads_nonwinapi
    non_winapi/main.cpp
    non_winapi/functions.cpp
    non_winapi/functions.h
)


if(WIN32)
    add_executable(Lab2Threads_winapi
        winapi/main_winapi.cpp
        winapi/functions_winapi.cpp
        winapi/functions_winapi.h
    )
endif()


include(FetchContent)

FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/release-1.12.1.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(UnitTests
    tests/test_main.cpp 
    non_winapi/functions.cpp
    non_winapi/functions.h
)
target_link_libraries(UnitTests gtest_main)

include(GoogleTest)
gtest_discover_tests(UnitTests)


if(WIN32)
    add_executable(WinApiTests
        tests/test_winapi.cpp
        winapi/functions_winapi.cpp
        winapi/functions_winapi.h
    )
    target_link_libraries(WinApiTests gtest_main)

    gtest_discover_tests(WinApiTests)
endif()
