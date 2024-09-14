// 14 September 2024
//Module 6 Exercise 2 - cpp program to calculate if inputted year form user is a leap year

#include <iostream>

using namespace std;

int main (void) {

    //====================================
    // Declaring variables
    int year;
    bool div_by_four, div_by_100, div_by_400;
    //===================================

    // Prompt user for input
    cout << "What year do you want me to evaluate? ";
    cin >> year;

    div_by_four = (year % 4 == 0);
    div_by_100 = (year % 100 == 0);
    div_by_400 = (year % 400 == 0);

    if ( div_by_four && (!div_by_100 || div_by_400) ) {
    // Output if year is a leap year or not
    cout << year << " is a leap year.";
    } 
    else {
        cout << year << " is not a leap year.";
    }

    return 0;
}