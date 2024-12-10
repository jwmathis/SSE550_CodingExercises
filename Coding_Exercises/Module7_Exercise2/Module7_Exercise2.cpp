//--------------------------------------------------------------------------------------
// SSE 550, Module 7 Exercise 2
// A program to calculate if a number is prime or not.
// Ref: https://math.stackexchange.com/questions/3980707/identifying-a-prime-number-why-only-check-for-factors-up-to-sqrtn
//--------------------------------------------------------------------------------------

#include <iostream>
#include <cmath>

using namespace std;

//========================
// Global Variables
int divisor = -1;
//========================

//==================================================
// Declaring functions
bool isPrime(int num) {
    if (num == 2) return true;
    if (num % 2 == 0) {
        divisor = 2; //set the divisor
        return false;
    }
    // check for factors from 5 to sqrt(num)
    for (int i = 3; i <= sqrt(num); i += 2) {
        if (num % i == 0) {
            divisor = i;
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
            cout << "Invalid input.\n";
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

