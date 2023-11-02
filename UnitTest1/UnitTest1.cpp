#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab 6.4 it/Lab 6.4 it.cpp" 

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:

        TEST_METHOD(TestFindMinIndex)
        {
            double arr[] = { 3.0, -5.0, 2.0, 7.0, -1.0 };
            int n = sizeof(arr) / sizeof(arr[0]);
            int expected = 1;

            int result = findMinIndex(arr, n);
            Assert::AreEqual(expected, result);
        }
    };
};
