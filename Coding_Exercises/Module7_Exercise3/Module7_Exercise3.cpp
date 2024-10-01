// Module7_Exercise3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    //=============================================
    // Declare variables
    srand(time(0)); // seed the random number using current time
    int randomNumber = rand() % 100 + 1;
    int guess;
    int attempts = 0;
    const int maxAttempts = 10;
    //=============================================
    cout << "I'm thinkning of a number between 1 and 100. Can you guess it?\n";

    do {
        cout << "Enter your guess: ";
        cin >> guess;
        attempts++;

        if (guess > randomNumber) {
            cout << "Too high. Try again.\n";
        }
        else if (guess < randomNumber) {
            cout << "Too low. Try again.\n";
        }
        else {
            cout << "Congratulations! You guess the number.\n";
            break;
        }
    } while (attempts < maxAttempts);

    if (attempts == maxAttempts && guess != randomNumber) {
        cout << "You've exceeded the maximum number of guesses. The number was " << randomNumber;
    }
}

