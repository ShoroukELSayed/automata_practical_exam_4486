#include <iostream>
#include <cstring>

using namespace std;

// Function to increment a binary number represented as a character array
char* incrementBinary(char tape[])
{
    int len = 0;
    while (tape[len] != '\0') len++;

    static char newTape[100];
    newTape[0] = '_';
    for (int i = 0; i < len; i++)
    {
        newTape[i + 1] = tape[i]; // Copy original tape starting from position 1
    }
    newTape[len + 1] = '_';
    newTape[len + 2] = '\0';

    int head = len;

    int state = 0;

    // Simulate Turing machine logic to increment binary number
    while (state != 2)
    {
        char current = newTape[head];

        if (state == 0)
        {
            // If current bit is 1, change to 0 and move left
            if (current == '1')
            {
                newTape[head] = '0';
                head--;
                state = 1;
                // If current bit is 0, change to 1 and stop
            }
            else if (current == '0')
            {
                newTape[head] = '1';
                state = 2;
                // If we reached the boundary, insert 1
            }
            else if (current == '_')
            {
                newTape[head] = '1';
                state = 2;
            }

        }
        else if (state == 1)
        {
            if (current == '1')
            {
                newTape[head] = '0';
                head--;
            }
            else if (current == '0')
            {
                newTape[head] = '1';
                state = 2;
            }
            else if (current == '_')
            {
                newTape[head] = '1';
                state = 2;
            }
        }
    }


    int start = 0;
    while (newTape[start] == '_') start++;

    int end = len + 1;
    while (newTape[end] == '_' || newTape[end] == '\0') end--;

    newTape[end + 1] = '\0';

    return &newTape[start];
}
void runTests()
{
    struct TestCase
    {
        const char* input;
        const char* expected;
    };

    TestCase tests[] =
    {
        {"0", "1"},
        {"1", "10"},
        {"10", "11"},
        {"11", "100"},
        {"100", "101"},
        {"101", "110"},
        {"1111", "10000"},
        {"000", "001"},
        {"1001", "1010"},
        {"11111111", "100000000"}
    };

    int passed = 0;
    int total = sizeof(tests) / sizeof(TestCase);

    for (int i = 0; i < total; i++)
    {
        char buffer[100];
        strcpy(buffer, tests[i].input);

        char* result = incrementBinary(buffer);
        if (strcmp(result, tests[i].expected) == 0)
        {
            cout << "[PASS] " << tests[i].input << " -> " << result << endl;
            passed++;
        }
        else
        {
            cout << "[FAIL] " << tests[i].input << " -> " << result
                 << " (Expected: " << tests[i].expected << ")\n";
        }
    }

    cout << "\n" << passed << "/" << total << " test cases passed.\n";
}

int main()
{

    char input[100];
    cout << "Enter a binary number: ";
    cin >> input;


    int valid = 1;
    for (int i = 0; input[i] != '\0'; i++)
    {
        if (input[i] != '0' && input[i] != '1')
        {
            valid = 0;
            break;
        }
    }

    if (!valid)
    {
        cout << "Invalid binary number." << endl;
        return 1;
    }

    char* result = incrementBinary(input);
    cout << "Result after increment: " << result << endl << endl;

    runTests();
    return 0;
}
/*
int main() {
    for (int i = 1; i <= 5; i++) {
        char input[100];
        cout << "Enter a binary number: ";
        cin >> input;


        int valid = 1;
        for (int i = 0; input[i] != '\0'; i++) {
            if (input[i] != '0' && input[i] != '1') {
                valid = 0;
                break;
            }
        }

        if (!valid) {
            cout << "Invalid binary number." << endl;
            return 1;
        }

        char* result = incrementBinary(input);
        cout << "Result after increment: " << result << endl << endl;
    }

    return 0;
}

*/
