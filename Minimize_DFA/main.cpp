#include <iostream>
#include <string>
#include "dfa.h"

using namespace std;



string states[MAX];                 // State names
string symbols[MAX];                // Input symbols
string transitions[MAX][MAX];      // Transition table
int isFinal[MAX];                  // Final state flags
int stateCount, symbolCount;
string startState;                 // Start state

// Get index of a state name
int getStateIndex(string name) {
    for (int i = 0; i < stateCount; i++)
        if (states[i] == name)
            return i;
    return -1;
}

// Get index of a symbol
int getSymbolIndex(string sym) {
    for (int i = 0; i < symbolCount; i++)
        if (symbols[i] == sym)
            return i;
    return -1;
}

// Input DFA from user
void inputDFA() {
    cout << "Number of states: ";
    cin >> stateCount;
    cout << "Enter state names (space-separated): ";
    for (int i = 0; i < stateCount; i++) {
        cin >> states[i];
        isFinal[i] = 0;
    }


    cout << "\nNumber of input symbols: ";
    cin >> symbolCount;
    cout << "Enter symbols (space-separated):";
    for (int i = 0; i < symbolCount; i++)
        cin >> symbols[i];

    cout << "\nEnter start state: ";
    cin >> startState;

    int finalCount;
    cout << "\nNumber of final states: ";
    cin >> finalCount;

    cout << "Enter names of final states (space-separated):";
    for (int i = 0; i < finalCount; i++) {
        string name;
        cin >> name;
        int finalIndex = getStateIndex(name);
        if (finalIndex != -1) isFinal[finalIndex] = 1;
    }

    cout << "\nEnter transition table (currentState + symbol => nextState):\n";
    for (int i = 0; i < stateCount; i++) {
        for (int j = 0; j < symbolCount; j++) {
            string next;
            cout <<"\t"<< states[i] << " + " << symbols[j] << " => ";
            cin >> next;
            transitions[i][j] = next;
        }
    }
}

// Check if two states are equivalent
bool areEquivalent(int a, int b) {
    if (isFinal[a] != isFinal[b]) return false;
    for (int j = 0; j < symbolCount; j++) {
        if (transitions[a][j] != transitions[b][j])
            return false;
    }
    return true;
}

// Minimize the DFA and create a new simplified DFA
void minimizeDFA() {
    int group[MAX]; // Stores group number for each state
    for (int i = 0; i < stateCount; i++)
        group[i] = -1;

    int groupCount = 0;
    for (int i = 0; i < stateCount; i++) {
        if (group[i] != -1) continue;
        group[i] = groupCount;
        for (int j = i + 1; j < stateCount; j++) {
            if (areEquivalent(i, j))
                group[j] = groupCount;
        }
        groupCount++;
    }

    // Print merged groups
    cout << "\nEquivalent State Groups:\n";
    for (int g = 0; g < groupCount; g++) {
        cout << "Group " << g << ": { ";
        for (int i = 0; i < stateCount; i++) {
            if (group[i] == g) cout << states[i] << " ";
        }
        cout << "}\n";
    }

    // Build minimized DFA
    string newStates[MAX];
    string newTransitions[MAX][MAX];
    int newIsFinal[MAX] = {0};
    string newStart;

    for (int g = 0; g < groupCount; g++) {
        newStates[g] = "Q" + to_string(g); // Name for new merged state

        // Use a representative state from the group
        int rep = -1;
        for (int i = 0; i < stateCount; i++) {
            if (group[i] == g) {
                rep = i;
                break;
            }
        }

        if (rep != -1) {
            for (int j = 0; j < symbolCount; j++) {
                string dest = transitions[rep][j];
                int destIdx = getStateIndex(dest);
                int newGroup = group[destIdx];
                newTransitions[g][j] = "Q" + to_string(newGroup);
            }
            if (isFinal[rep]) newIsFinal[g] = 1;
        }

        // Check if this group contains the original start state
        if (states[rep] == startState)
            newStart = newStates[g];
    }

    // Print minimized DFA
    cout << "\n---------------- Minimized DFA -----------------\n";
    cout << "Start State: " << newStart << "\n";
    cout << "States: ";
    for (int i = 0; i < groupCount; i++)
        cout << newStates[i] << " ";
    cout << "\nFinal States: ";
    for (int i = 0; i < groupCount; i++)
        if (newIsFinal[i]) cout << newStates[i] << " ";
    cout << "\n\nTransitions:\n";
    for (int i = 0; i < groupCount; i++) {
        for (int j = 0; j < symbolCount; j++) {
            cout <<"\t"<< newStates[i] << " + " << symbols[j] << " => " << newTransitions[i][j] << "\n";
        }
    }
}
/*
int main() {
    inputDFA();
    minimizeDFA();
    return 0;
}

*/
