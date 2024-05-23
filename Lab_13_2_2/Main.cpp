#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

map<int, string> errorMessages = {
    {1, "File not found"},
    {2, "Access denied"},
    {3, "Disk full"},
    {4, "Illegal operation"},
    {5, "Unknown error"}
};

string getErrorMessage(int errorCode) {
    if (errorMessages.find(errorCode) != errorMessages.end())
        return errorMessages[errorCode];
    else
        return "Error code not recognized";
}

void printErrorMessage(int errorCode, const string& errorMessage) {
    cout << "Error code " << errorCode << ": " << errorMessage << endl;
}

template <typename... Args>
void generateErrorMessages(Args... args) {
    vector<int> errorCodes = { args... };

    for (int errorCode : errorCodes) {
        if (errorMessages.find(errorCode) != errorMessages.end())
            printErrorMessage(errorCode, errorMessages[errorCode]);
        else
            printErrorMessage(errorCode, "Error code not recognized");
    }
}

int main() {
    cout << "Generating error messages based on error codes" << endl;

    generateErrorMessages(1, 2, 5, 7);

    cin.get();
    return 0;
}
