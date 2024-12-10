//--------------------------------------------------------------------------------------
// SSE 550, Module 6 Exercise 4
// A program to print truth table from given input.
// Ref: ChatGPT was used during debugging of logic flow.
// https://www.geeksforgeeks.org/std-find-in-cpp/
//--------------------------------------------------------------------------------------

#include <iostream>
#include <string>

using namespace std;

int main()
{
    //====================================================
    // Declare Variables
    string expression;
    bool result = 0;

    // Truth table for A and B (if C is not used)
    bool truthValuesAB[4][2] = {
        {0, 0},
        {0, 1},
        {1, 0},
        {1, 1}
    };

    bool truthValues[8][3] = {
        {0, 0, 0},
        {0, 0, 1},
        {0, 1, 0},
        {0, 1, 1},
        {1, 0, 0},
        {1, 0, 1},
        {1, 1, 0},
        {1, 1, 1}
    };
    bool A = 0;
    bool B = 0;
    bool C = 0;
    //====================================================

    // Get user input
    cout << "Enter the Boolean expression using variables A, B, C, operators (&&, ||, !) and parentheses: "; //works for doing only in order (e.g. A && B works but A && C doesn't)
    getline(cin, expression);

    // Check if user input contains C
    bool usesC = (expression.find('C') != string::npos);

    // Print truth table header
    if (usesC) {
        cout << "\nTruth Table:\n";
        cout << "A | B | C | " << expression << "\n";
        cout << "------------------------------\n";
    }
    else {
        cout << "\nTruth Table:\n";
        cout << "A | B | " << expression << "\n";
        cout << "--------------------------\n";
    }

    // Generate and print the truth table
    for (int i = 0; i < 8; i++) {

        if (usesC) {
            A = truthValues[i][0];
            B = truthValues[i][1];
            C = truthValues[i][2];
        }
        else {
            if (i == 4) { break; } // Break out of For loop early since fewer values
            A = truthValuesAB[i][0];
            B = truthValuesAB[i][1];
        }

        result = A; // Start with the value of A for simplicity
        char lastOperator = ' '; // Keep track of the last operator

        for (size_t j = 0; j < expression.length(); j++) {
            if (expression[j] == 'A') {
                result = A;
            }
            else if (expression[j] == 'B') {
                if (lastOperator == '&') {
                    result = result && B;
                }
                else if (lastOperator == '|') {
                    result = result || B;
                }
            }
            else if (expression[j] == 'C') {
                if (lastOperator == '&') {
                    result = result && C;
                }
                else if (lastOperator == '|') {
                    result = result || C;
                }
            }
            else if (expression[j] == '&') {
                lastOperator = '&'; // Found an AND operator
            }
            else if (expression[j] == '|') {
                lastOperator = '|'; // Found an OR operator
            }
            else if (expression[j] == '!') {
                if (j + 1 < expression.length() && expression[j + 1] == 'A') {
                    if (lastOperator == '&') {
                        result = result && !A;
                    }
                    else if (lastOperator == '|') {
                        result = result || !A;
                    }
                    else {
                        result = !A;
                    }
                }
                else if (j + 1 < expression.length() && expression[j + 1] == 'B') {
                    if (lastOperator == '&') {
                        result = result && !B;
                    }
                    else if (lastOperator == '|') {
                        result = result || !B;
                    }
                    else {
                        result = !B;
                    }
                }
                else if (j + 1 < expression.length() && expression[j + 1] == 'C') {
                    if (lastOperator == '&') {
                        result = result && !C;
                    }
                    else if (lastOperator == '|') {
                        result = result || !C;
                    }
                    else {
                        result = !C;
                    }
                }
                j++; // Skip the next character (A, B, or C) since it's negated
            }

        }

        // Output the truth table
        if (usesC) {
            cout << A << " | " << B << " | " << C << " | " << result << "\n";
        }
        else {
            cout << A << " | " << B << " | " << result << "\n";
        }
    }

    return 0;
}

