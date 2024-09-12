//--------------------------------------------------------------------------------------
//11 September 2024
//SSE 550, Module 4 Exercise 
//A simple program that prompts the user for input and then displays that information, 
// then prompts the user to verify the data. Using income, filing status, 
// and number of dependents, the amount of taxes owed is calculated.
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

    // Tax brackets
    const float TAX_BRACKET1 = 0.10;
    const float TAX_BRACKET2 = 0.24;
    const float TAX_BRACKET3 = 0.37;

    // Bracket thresholds for SINGLE filers
    const double BRACKET1_LIMIT_SINGLE = 11000.00;
    const double BRACKET2_LIMIT_SINGLE = 182100.00;
    const double BRACKET3_LIMIT_SINGLE = 578126.00;

    // Bracket thresholds for MARRIED FILING JOINTLY filers
    const double BRACKET1_LIMIT_MFJ = 22000.00;
    const double BRACKET2_LIMIT_MFJ = 364200.00;
    const double BRACKET3_LIMIT_MFJ = 693751.00;

    // Bracket thresholds for MARRIED FILING SEPARATELY filers
    const double BRACKET1_LIMIT_MFS = 11000.00;
    const double BRACKET2_LIMIT_MFS = 182100.00;
    const double BRACKET3_LIMIT_MFS = 346876.00;

    // Bracket thresholds for HEAD OF HOUSEHOLD filers
    const double BRACKET1_LIMIT_HOH = 15700.00;
    const double BRACKET2_LIMIT_HOH = 182100.00;
    const double BRACKET3_LIMIT_HOH = 578101.00;

    // Tax credit for dependents
    const double TAX_CREDIT_PER_DEPENDENT = 500.00;
    // Declaration of variables
    string first_name, last_name, full_name, nickName, userName;
    char middle_initial;
    int filing_status;
    double income;
    int num_of_dependents;
    float effective_tax_rate;
    bool isValid;
    char userInput;
    double tax_owed;
    double tax_credit;
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
    if (income < 0) { // Error handling
        cout << "Income entered was negative.";
        return 1;
    }

    // Print out collected information for verification
    cout << "\n\n\n\n**************Data Verification****************\n";
    cout << "Name: " << first_name << " ";
    if (middle_initial != 'N' && middle_initial != 'n') { // Error handling
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

    cout << "Is this information correct? (Y/N) ";
    cin >> userInput;

    if (userInput == 'N' || userInput == 'n') {
        cout << "\nWe're sorry we got it wrong.";
        return 1;
    }

    // Calculate taxes owed
    switch (filing_status) {
    case SINGLE:
        if (income <= BRACKET1_LIMIT_SINGLE) {
            tax_owed = income * TAX_BRACKET1;
        }
        else if (income <= BRACKET2_LIMIT_SINGLE) {
            tax_owed = (BRACKET1_LIMIT_SINGLE * TAX_BRACKET1) + ((income - BRACKET1_LIMIT_SINGLE) * TAX_BRACKET2);
        }
        else {
            tax_owed = (BRACKET1_LIMIT_SINGLE * TAX_BRACKET1) + ((BRACKET2_LIMIT_SINGLE - BRACKET1_LIMIT_SINGLE) * TAX_BRACKET2) + ((income - BRACKET2_LIMIT_SINGLE) * TAX_BRACKET3);
        }
        break;

    case MARRIED_FILING_JOINTLY:
        if (income <= BRACKET1_LIMIT_MFJ) {
            tax_owed = income * TAX_BRACKET1;
        }
        else if (income <= BRACKET2_LIMIT_MFJ) {
            tax_owed = (BRACKET1_LIMIT_MFJ * TAX_BRACKET1) + ((income - BRACKET1_LIMIT_MFJ) * TAX_BRACKET2);
        }
        else {
            tax_owed = (BRACKET1_LIMIT_MFJ * TAX_BRACKET1) + ((BRACKET2_LIMIT_MFJ - BRACKET1_LIMIT_MFJ) * TAX_BRACKET2) + ((income - BRACKET2_LIMIT_MFJ) * TAX_BRACKET3);
        }
        break;

    case MARRIED_FILING_SEPARATELY:
        if (income <= BRACKET1_LIMIT_MFS) {
            tax_owed = income * TAX_BRACKET1;
        }
        else if (income <= BRACKET2_LIMIT_MFS) {
            tax_owed = (BRACKET1_LIMIT_MFS * TAX_BRACKET1) + ((income - BRACKET1_LIMIT_MFS) * TAX_BRACKET2);
        }
        else {
            tax_owed = (BRACKET1_LIMIT_MFS * TAX_BRACKET1) + ((BRACKET2_LIMIT_MFS - BRACKET1_LIMIT_MFS) * TAX_BRACKET2) + ((income - BRACKET2_LIMIT_MFS) * TAX_BRACKET3);
        }
        break;

    case HEAD_OF_HOUSEHOLD:
        if (income <= BRACKET1_LIMIT_HOH) {
            tax_owed = income * TAX_BRACKET1;
        }
        else if (income <= BRACKET2_LIMIT_HOH) {
            tax_owed = (BRACKET1_LIMIT_HOH * TAX_BRACKET1) + ((income - BRACKET1_LIMIT_HOH) * TAX_BRACKET2);
        }
        else {
            tax_owed = (BRACKET1_LIMIT_HOH * TAX_BRACKET1) + ((BRACKET2_LIMIT_HOH - BRACKET1_LIMIT_HOH) * TAX_BRACKET2) + ((income - BRACKET2_LIMIT_HOH) * TAX_BRACKET3);
        }
        break;

    default:
        cout << "You owe a quadrillion dollars in taxes";
        return 1;
    }

    // Adjust tax owed for dependents
    tax_credit = num_of_dependents * TAX_CREDIT_PER_DEPENDENT;
    tax_owed = tax_owed - tax_credit;
    if (tax_owed < 0) {
        tax_owed = 0.0;
    }

    effective_tax_rate = (tax_owed / income) * 100;
    if (num_of_dependents != 0) {
        cout << "\nBecause you have " << num_of_dependents << " dependent(s), you get a tax credit of $" << tax_credit;
    }
    cout << "\nYou owe: $" << tax_owed;
    cout << "\nYour effective tax rate is: " << effective_tax_rate;
    return 0;
}