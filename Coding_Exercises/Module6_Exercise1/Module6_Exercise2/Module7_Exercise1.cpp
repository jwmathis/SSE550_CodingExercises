#include <iostream>

using namespace std;

int main(void) {
    //=======================================
    // Declaring variables
    int num;
    int factorial;
    // Prompt user for input 
    do {
        cout << "Enter a number to calculate the factorial: ";
        cin >> num;

        // Check if input is negative or a letter
        if(num < 0 || isalpha(num)) {
            cout << "Invalid output. ";
        }
    } while (num < 0); // Repeat prompt if invalid

    for (int i = num; i != 0; i--) {
        factorial *= num;
    }

    cout << "The factorial of " << num << " is " << factorial;

    return 0;
}