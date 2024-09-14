#include <iostream>

using namespace std;

int main(void) {

    //=======================================
    // Declaring variables
    double grade = 0;
    double userInput;
    double average;

    // Get user input for three assignments
    for (int i = 1; i < 4; i++) {
        do {
            cout << "Enter your grade on exercise " << i << ": ";
            cin >> userInput;
            // Error if not a digit and prompt for new input
            if (!(isdigit(userInput))) {
            cout << "Invalid output.";
            }
        } while (!(isdigit(userInput)));
        // Add input to grade
        grade += userInput;
    }

    // Get average grade
    average = grade / 3;

    cout << average;



    return 0;
}