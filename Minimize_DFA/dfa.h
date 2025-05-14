#ifndef DFA_H
#define DFA_H

#include <string>
using namespace std;

const int MAX = 100;
extern string states[MAX];                 // State names
extern string symbols[MAX];                // Input symbols
extern string transitions[MAX][MAX];      // Transition table
extern int isFinal[MAX];                  // Final state flags
extern int stateCount, symbolCount;
extern string startState;                 // Start state

// Function declarations
int getStateIndex(string name);
int getSymbolIndex(string sym);
void inputDFA();
bool areEquivalent(int a, int b);
void minimizeDFA();

#endif // DFA_H
