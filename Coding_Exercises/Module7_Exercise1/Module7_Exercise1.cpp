//--------------------------------------------------------------------------------------
// SSE 550, Module 7 Exercise 1
// A program to calculate factorial.
// DEV: Due to C++ and Windows limitations, the signed integer limit is reached on very large factorials.
// To accomadate larger factorials, unsigned long int was used instead.
// Ref: https://www.tutorialspoint.com/cplusplus/cpp_data_types.htm
// https://stackoverflow.com/questions/236335/when-i-calculate-a-large-factorial-why-do-i-get-a-negative-number
//--------------------------------------------------------------------------------------
#include <iostream>

using namespace std;

int main(void) {
    //=======================================
    // Declaring variables
    int num;
    unsigned long int factorial = 1;
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

    cout << "The factorial of " << num << " (" << num << "!) is " << factorial;

    return 0;
}