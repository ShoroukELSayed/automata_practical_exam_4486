#include <iostream>
#include <string>
#include <cassert>
#include "dfa.h"

using namespace std;

void testGetStateIndex() {
    // Test the state index function
    assert(getStateIndex("A") == 0);
    assert(getStateIndex("B") == 1);
    assert(getStateIndex("C") == 2);
    assert(getStateIndex("D") == 3);
    assert(getStateIndex("E") == 4);
    assert(getStateIndex("F") == -1);  // Non-existing state
}

void testGetSymbolIndex() {
    // Test the symbol index function
    assert(getSymbolIndex("0") == 0);
    assert(getSymbolIndex("1") == 1);
    assert(getSymbolIndex("2") == -1);  // Non-existing symbol
}

void testAreEquivalent() {
    // Test the equivalence function
    assert(areEquivalent(0, 1) == false);
    assert(areEquivalent(1, 2) == false);
    assert(areEquivalent(0, 2) == true);
}

int main() {
    // Call inputDFA() to simulate the DFA setup
    inputDFA();

    // Run all unit tests
    testGetStateIndex();
    testGetSymbolIndex();
    testAreEquivalent();
    cout << "All tests passed successfully!" << endl;

    minimizeDFA();

    return 0;
}
