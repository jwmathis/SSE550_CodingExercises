// Module6_Exercise4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

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
    cout << "Enter the Boolean expression using variables A, B, C, operators (&&, ||, !) and parentheses: ";
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

        bool result = A; // Start with the value of A for simplicity
        char lastOperator = ' '; // Keep track of the last operator

        for (size_t i = 0; i < expression.length(); i++) {
            if (expression[i] == 'A') {
                result = A;
            }
            else if (expression[i] == 'B') {
                if (lastOperator == '&') {
                    result = result && B;
                }
                else if (lastOperator == '|') {
                    result = result || B;
                }
            }
            else if (expression[i] == 'C') {
                if (lastOperator == '&') {
                    result = result && C;
                }
                else if (lastOperator == '|') {
                    result = result || C;
                }
            }
            else if (expression[i] == '&') {
                lastOperator = '&'; // Found an AND operator
            }
            else if (expression[i] == '|') {
                lastOperator = '|'; // Found an OR operator
            }
            else if (expression[i] == '!') {
                if (i + 1 < expression.length() && expression[i + 1] == 'A') {
                    result = !A;
                }
                else if (i + 1 < expression.length() && expression[i + 1] == 'B') {
                    result = !B;
                }
                else if (i + 1 < expression.length() && expression[i + 1] == 'C') {
                    result = !C;
                }
                i++; // Skip the next character (A, B, or C) since it's negated
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

