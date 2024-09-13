// Module5_Exercise1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;

int main()
{
    //============================================
    // Declare variables
    string noun;
    string adjective;
    string verb;
    string sentence;
    int choice;
    //============================================

    // Prompt the user for a noun
    cout << "Enter a noun: ";
    getline(cin, noun);
    
    // Prompt the user for an adjective
    cout << "Enter an adjective: ";
    getline(cin, adjective);

    // Prompt the user for a verb
    cout << "Enter a verb: ";
    getline(cin, verb);

    // Prompt the user for a sentence template
    cout << "Choose a sentence template:\n";
    cout << "1. [Adjective] [Noun] [Verb]\n";
    cout << "2. [Noun] [Verb] [Adjective]\n";
    cout << "3. [Verb] [Adjective] [Noun]\n";
    cout << "Enter the number of your choice: ";
    cin >> choice;

    // Concatenate the words to form a sentence
    switch (choice) {
    case 1:
        sentence = adjective + " " + noun + " " + verb;
        break;
    case 2:
        sentence = noun + " " + verb + " " + adjective;
        break;
    case 3:
        sentence = verb + " " + adjective + " " + noun;
        break;
    }
    // Output the concatenated sentence
    cout << sentence << endl;

    return 0;
}

