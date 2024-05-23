#include "pch.h"
#include "CppUnitTest.h"
#include <string>
#include <map>
#include "../Lab_13_2_2/Main.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

extern map<int, string> errorMessages;
extern string getErrorMessage(int errorCode);

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:

        TEST_METHOD(TestKnownErrorCodes)
        {
            Assert::AreEqual(string("File not found"), getErrorMessage(1));
            Assert::AreEqual(string("Access denied"), getErrorMessage(2));
            Assert::AreEqual(string("Disk full"), getErrorMessage(3));
            Assert::AreEqual(string("Illegal operation"), getErrorMessage(4));
            Assert::AreEqual(string("Unknown error"), getErrorMessage(5));
        }

        TEST_METHOD(TestUnknownErrorCode)
        {
            Assert::AreEqual(string("Error code not recognized"), getErrorMessage(999));
        }
    };
}
