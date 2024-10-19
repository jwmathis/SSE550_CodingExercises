//--------------------------------------------------------------------------------------
// SSE 550, Module 6 Exercise 3
// A program to calculate letter grade and average grade based on number grade of three 
// assignments.
//--------------------------------------------------------------------------------------
#include <iostream>

using namespace std;

int main(void) {

    //=======================================
    // Declaring variables
    double grade = 0;
    double userInput;
    double average;
    char letterGrade;
    //=======================================
    
    // Get user input for three assignments
    for (int i = 1; i <= 3; i++) {
        do {
            cout << "Enter your grade on exercise " << i << ": ";
            cin >> userInput;

            if (userInput < 0 || userInput > 100) {
                cout << "Invalid output. Please enter a number between 0 and 100. ";
            }
            else {
                break; // Exit while loop
            }
        } while (true);

        // Add input to grade
        grade += userInput;
    }

    // Get average grade
    average = grade / 3;

    if (average >= 90) {
        letterGrade = 'A';
    }
    else if (average >= 80) {
        letterGrade = 'B';
    }
    else if (average >= 70) {
        letterGrade = 'C';
    }
    else if (average >= 60) {
        letterGrade = 'D';
    }
    else {
        letterGrade = 'F';
    }

    cout << "Your grade is " << average << " and letter grade " << letterGrade << endl;

    return 0;
}