//--------------------------------------------------------------------------------------
//11 September 2024
//SSE 550, Module 3 Exercise 1 
//A simple program that prompts the user for input and then displays that information, then
// prompts ths user to verify the data.
//--------------------------------------------------------------------------------------


#include <iostream>
#include <string>
using namespace std;

int main() {

    //========================================================================
        //  Declaration of constants
    const int SINGLE = 1;
    const int MARRIED_FILING_JOINTLY = 2;
    const int MARRIED_FILING_SEPARATELY = 3;
    const int HEAD_OF_HOUSEHOLD = 4;

    // Tax rates
    const float TAX_RATE_SINGLE = 0.22;
    const float TAX_RATE_MARRIED = 0.30;
    const float TAX_RATE_HEAD_OF_HOUSEHOLD = 0.25;

    // Declaration of variables
    string first_name, last_name, full_name, nickName, userName;
    char middle_initial;
    int filing_status;
    double income;
    int num_of_dependents;
    float tax_rate;
    bool isValid;
    char userInput;
    //=======================================================================


        //Display welcome message
    cout << "***************Welcome to the Tax Data Program***************\n\n";

    // Get user's name
    cout << "Please type your first name to begin: ";
    cin >> first_name;

    cout << "Please type your last name: ";
    cin >> last_name;

    cout << "Please type your middle initial (or enter 'N' if none): ";
    cin >> middle_initial;

    cout << "Please type your preferred name (or hit \"Enter\" key to proceed to next step): ";
    cin.ignore();
    getline(cin, nickName);

    if (nickName.empty()) {
        userName = first_name;
    }
    else {
        userName = nickName;
    }

    cout << "\n\n***************************************************************************\n";
    cout << "Hi " << userName << "! I'll need you to answer a few questions. Let's begin!\n\n";

    // Get filing status
    cout << "First question, will you be filing:\n"
        << "1. Single\n"
        << "2. Married filing jointly\n"
        << "3. Married filing seperately\n"
        << "4. Head of Household\n";
    cin >> filing_status;
    // Check if valid input
    isValid = (filing_status == SINGLE || filing_status == MARRIED_FILING_JOINTLY || filing_status == MARRIED_FILING_SEPARATELY || filing_status == HEAD_OF_HOUSEHOLD);
    if (!isValid) {
        cout << "Invalid filing status selected.\n";
        return 1;
    }

    // Get number of dependents
    cout << "Second question, how many dependents do you have? ";
    cin >> num_of_dependents;
    // Check if valid input
    if (num_of_dependents < 0) {
        cout << "\nYou entered a negative number!";
        return 1;
    }

    // Get income level
    cout << "Third question, what is your income level? ";
    cin >> income;

    // Output tax rate based on filing status
    if (filing_status == SINGLE) {
        tax_rate = TAX_RATE_SINGLE;
    }
    else if (filing_status == MARRIED_FILING_JOINTLY || filing_status == MARRIED_FILING_SEPARATELY) {
        tax_rate = TAX_RATE_MARRIED;
    }
    else if (filing_status == HEAD_OF_HOUSEHOLD) {
        tax_rate = TAX_RATE_HEAD_OF_HOUSEHOLD;
    }

    // Print out collected information for verification
    cout << "\n\n\n\n**************Data Verification****************\n";
    cout << "Name: " << first_name << " ";
    if (middle_initial != 'N' && middle_initial != 'n') {
        cout << middle_initial << ". ";
    }
    cout << last_name << "\n";

    cout << "Filing Status: " <<
        (filing_status == SINGLE ? "Single" :
            filing_status == MARRIED_FILING_JOINTLY ? "Married Filing Jointly" :
            filing_status == MARRIED_FILING_SEPARATELY ? "Married Filing Separately" :
            filing_status == HEAD_OF_HOUSEHOLD ? "Head of Household" :
            "Unknown");
    cout << "\n";

    cout << "Income: $" << income << "\n";
    cout << "Number of Dependents: " << num_of_dependents << "\n";
    cout << "Applicable Tax Rate: " << tax_rate << "\n";

    cout << "Is this information correct? (Y/N) ";
    cin >> userInput;

    if (userInput == 'Y' || userInput == 'y') {
        cout << "\nThanks for using the app!";
    }
    else {
        cout << "\nWe're sorry we got it wrong.";
    }

    return 0;
}