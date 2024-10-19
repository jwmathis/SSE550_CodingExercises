//--------------------------------------------------------------------------------------
// SSE 550, Module 7 Exercise 1
// A program to calculate factorial.
//--------------------------------------------------------------------------------------
#include <iostream>

using namespace std;

int main(void) {
    //=======================================
    // Declaring variables
    int num;
    int factorial = 1;
    // Prompt user for input 
    do {
        cout << "Enter a number to calculate the factorial: ";
        cin >> num;

        if(num < 0) {
            cout << "Invalid output. Please enter a non-negative integer. ";
        }
        else {
            break;
        }
    } while (true); // Repeat prompt if invalid

    for (int i = 1; i <= num; i++) {
        factorial *= i;
    }

    cout << "The factorial of " << num << " is " << factorial;

    return 0;
}