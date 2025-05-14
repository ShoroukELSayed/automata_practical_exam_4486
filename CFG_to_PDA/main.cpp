#include <iostream>
#include <cstring>
#include "test.h"

using namespace std;

const int MAX_RULES = 20;
const int MAX_PRODUCTIONS = 10;
const int MAX_LEN = 10;

char nonTerminals[MAX_RULES];
char productions[MAX_RULES][MAX_PRODUCTIONS][MAX_LEN];
int productionCount[MAX_RULES];
int ruleCount = 0;

char startSymbol;
bool accepted = false;

// Function to add a production rule for a given non-terminal
void addRule(char nonTerminal, const char* rhs)
{
    int idx = -1;
    // Search if the non-terminal already exists in the rule list
    for (int i = 0; i < ruleCount; i++)
    {
        if (nonTerminals[i] == nonTerminal)
        {
            idx = i;
            break;
        }
    }
    if (idx == -1) // If non-terminal not found, add it to the list
    {
        idx = ruleCount;
        nonTerminals[ruleCount++] = nonTerminal;
    }

    // Add the production to the corresponding non-terminal
    int p = productionCount[idx]++;
    strncpy(productions[idx][p], rhs, MAX_LEN);
}

// Function to parse the input CFG and build the rules
void parseCFG()
{
    int n;
    cout << "Enter number of production rules: ";
    cin >> n;
    cin.ignore(); // Ignore the newline character after reading the number

    cout << "Enter production rules (like S -> aA | b) and Use i to represent epsilon (empty string):\n";
    for (int i = 0; i < n; ++i)
    {
        cout<<"Enter the " <<i+1<<" rule :"<<endl;
        char line[100];
        cin.getline(line, 100); // Read the production rule line

        char lhs = line[0];
        if (i == 0) startSymbol = lhs;

        // Find the arrow "->" which separates the non-terminal and production
        char* arrow = strstr(line, "->");
        if (!arrow) continue;

        char* rhs = arrow + 2;
        while (*rhs == ' ') rhs++;

        // Split the right-hand side productions by "|"
        char* token = strtok(rhs, "|");
        while (token)
        {
            while (*token == ' ') token++;
            int len = strlen(token);
            while (len > 0 && (token[len - 1] == ' ' || token[len - 1] == '\n'))
                token[--len] = '\0';

            addRule(lhs, token);
            token = strtok(NULL, "|");
        }
    }
}

// Function to find the index of a rule for a given non-terminal
int findRuleIndex(char nonTerminal)
{
    for (int i = 0; i < ruleCount; i++)
        if (nonTerminals[i] == nonTerminal)
            return i;
    return -1;
}

// Function to simulate the pushdown automaton (PDA) on an input string
void simulatePDA(const char* input, int pos, char* stack, int stackTop, int depth = 0)
{
    if (accepted || depth > 1000) return;

     // If the input is consumed and the stack is empty, the input is accepted
    if (input[pos] == '\0' && stackTop == -1)
    {
        accepted = true;
        return;
    }

    if (stackTop == -1) return;  // If stack is empty and input is not finished, reject the input

    char top = stack[stackTop];
    stackTop--;

    // Find the production rule for the top symbol
    int ruleIdx = findRuleIndex(top);
    if (ruleIdx == -1)
    {
        if (input[pos] != '\0' && input[pos] == top)
            simulatePDA(input, pos + 1, stack, stackTop, depth + 1);
    }
    else
    {
        // Iterate through all productions for the current non-terminal
        for (int i = 0; i < productionCount[ruleIdx]; ++i)
        {
            const char* prod = productions[ruleIdx][i];
            char newStack[100];
            memcpy(newStack, stack, 100);

            int newTop = stackTop;
            if (strcmp(prod, "i") != 0)
            {
                // Push the production symbols onto the stack in reverse order
                for (int j = strlen(prod) - 1; j >= 0; --j)
                    newStack[++newTop] = prod[j];
            }
             // Recursively simulate PDA with the updated stack
            simulatePDA(input, pos, newStack, newTop, depth + 1);
        }
    }
}

// Function to print the PDA description and transitions
void printPDA()
{
    cout << "\n--- PDA Description ---\n";
    cout << "Start symbol: " << startSymbol << "\n";
    cout << "Accepting condition: empty stack\n";
    cout << "\nTransitions:\n";

    for (int i = 0; i < ruleCount; ++i)
    {
        for (int j = 0; j < productionCount[i]; ++j)
        {
            const char* prod = productions[i][j];
            cout << "o(q, ";
            if (strcmp(prod, "i") == 0)
            {
                cout << "i, " << nonTerminals[i] << ") -> (q, i)\n";
            }
            else
            {
                cout << prod[0] << ", " << nonTerminals[i] << ") -> (q, ";
                for (int k = strlen(prod) - 1; k >= 0; --k)
                    cout << prod[k];
                cout << ")\n";
            }
        }
    }
    cout << "------------------------\n";
}

int main()
{
    parseCFG();

    printPDA();

    // Run tests on different input strings
    runTest("aaab", true);
    runTest("a", false);
    runTest("b", true);
    runTest("ab", true);

    /*
    char input[100];
    cout << "\nEnter input string to simulate: ";
    cin >> input;

    char stack[100];
    stack[0] = startSymbol;

    simulatePDA(input, 0, stack, 0);

    if (accepted)
        cout << "The input string is ACCEPTED by the PDA.\n";
    else
        cout << "The input string is REJECTED by the PDA.\n";
    */
    return 0;
}


