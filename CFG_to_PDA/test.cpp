#include <iostream>
#include <cstring>
#include <string>
#include "test.h"

using namespace std;

// External functions and variables declared
extern void simulatePDA(const char* input, int pos, char* stack, int stackTop, int depth=0);
extern void parseCFG();
extern bool accepted;
extern char startSymbol;

// Function to test the PDA simulation with a given input string
void runTest(const string& input, bool expectedAccepted) {

    char stack[100];
    stack[0] = startSymbol;

    simulatePDA(input.c_str(), 0, stack, 0);

    // Check if result matches the expected outcome
    if (accepted == expectedAccepted) {
        cout << "Test passed for input: " << input << "\n";
    } else {
       cout << "Test failed for input: " << input << "\n";
    }
}

