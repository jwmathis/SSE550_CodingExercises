// Module7_Exercise2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cmath>

using namespace std;

//========================
// Global Variables
int divisor = -1;
//========================

//==================================================
// Declaring fucntions
bool isPrime(int num) {
    if (num == 2 || num == 3) return true;
    if (num % 2 == 0 || num % 3 == 0) {
        divisor = (num % 2 == 0) ? 2 : 3; //set the divisor
        return false;
    }
    // check for factors from 5 to sqrt(num)
    for (int i = 5; i <= sqrt(num); i += 6) {
        if (num % i == 0) {
            divisor = i;
            return false;
        }

        if (num % (i + 2) == 0) {
            divisor = i + 2;
            return false;
        }
    }

    return true;
}
//==================================================

int main()
{
    //===========================================
    // Declare variables
    int num;
    //===========================================
    
    // Get user input
    do {
        cout << "Enter a non-negative integer greater than 1: ";
        cin >> num;

        if (num < 1 || num == 1) {
            cout << "Invalid input. ";
        }
        else {
            break;
        }
    } while (true);

    // Check if input is prime
    if (isPrime(num)) {
        cout << "The number " << num << " is a prime number because there exists no positve integer divisors except 1 and " << num;
    }
    else {
        cout << "The number " << num << " is not a prime number becasue the number " << divisor << " is a divisor";
    }

    return 0;
}

