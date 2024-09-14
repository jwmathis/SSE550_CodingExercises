//14 September 2024
// Module5_Exercise2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;

int main()
{
//================================================
	// Declaring variables
	string name, name_without_characters;
	int length_of_name = 0;
	bool has_digit = false;
//================================================

	// Get user input and check if user entered input
	do {
		cout << "Enter a name: ";
		getline(cin, name); // Get the entire input entered by user
		length_of_name = name.length();
		if (length_of_name == 0) {
			cout << "Invalid input. ";
		}
	} while (length_of_name == 0);

	// Get name with only letters
	for (char c : name) {
		if ( (c != ' ') && (c != '\'') && !(isdigit(c)) ) {
			name_without_characters += c;
		}
	}

	length_of_name = name_without_characters.length(); // Update length of name
	
	// Output first letter
	if (length_of_name == 1) { // name has only 1 letter
		cout << name << " is only one letter.\n";
	}
	else if (length_of_name > 1) { // name has more than 1 letter
		cout << name << " begins with " << name[0] << "\n";
		cout << "There are " << length_of_name << " letters in the name.";
	}
	else { // name has 0 letters
		cout << "There are no letters in this name.\n";
	}

	// Output how many letters to write name five times
	cout << "To write " << name << " five times uses " << (length_of_name * 5) << " letters" << endl;

	return 0;

}


