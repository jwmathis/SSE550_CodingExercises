// Module4_Exercise2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <sstream>

using namespace std;

int main()
{
    //=====================================================
    // Declare variables
    string fraction1, fraction2;
    int num1, denom1, num2, denom2;
    int resultNumerator, resultDenominator;
    char slash;
    int a, b, temp, gcd;
    //=====================================================

    // Get user input 
    cout << "Enter a fraction (e.g. 1/2): ";
    getline(cin, fraction1);

    cout << "Enter another fraction (e.g. 3/4): ";
    getline(cin, fraction2);

    // Parse first fraction
    istringstream stream1(fraction1);
    stream1 >> num1 >> slash >> denom1;

    // Parse second fraction
    istringstream stream2(fraction2);
    stream2 >> num2 >> slash >> denom2;

    if (denom1 == 0 || denom2 == 0) {
        cout << "Denominator cannot be zero." << endl;
        return 1;
    }

    // Multiply fractions
    resultNumerator = num1 * num2;
    resultDenominator = denom1 * denom2;
    a = resultNumerator;
    b = resultDenominator;

    // Find greatest common denominator
    while (b != 0) {
        temp = b;
        b = a % b;
        a = temp;
    }
    gcd = a;

    // Simplify fraction
    resultNumerator /= gcd;
    resultDenominator /= gcd;


    // Display result to screen
    cout << "The result of multiplying these fractions is " << resultNumerator << "/" << resultDenominator << "." << endl;
    
    
    return 0;
}


