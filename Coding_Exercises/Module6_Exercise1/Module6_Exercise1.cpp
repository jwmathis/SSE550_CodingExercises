//--------------------------------------------------------------------------------------
// SSE 550, Module 6 Exercise 1
// A program to greet user based on time of day and to provide fortune based on user's 
// favorite color.
//--------------------------------------------------------------------------------------

#include <iostream>
#include <ctime>
#include <string>
#include <random>

using namespace std;

int main()
{
    //==============================================
    // Declare variables
    time_t now = time(0); // gets current time (in seconds) since the unix epoch (Jan 1, 1970, 00:00:00 UTC)
    struct tm local_time; // Declare a tm structure to hold the local time
    errno_t err = localtime_s(&local_time, &now); // Convert to local time in a thread-safe manner
    if (err) {
        cout << "Error converting time" << endl;
        return 1;  // Exit on failure
    }
    int hour = local_time.tm_hour; // Extract the current hour (0-23) for determining morning, afternoon, or evening
    string color;

    const string RED_PRED_ARRAY[] = {
        "Passion and energy will infuse your life with new excitement; embrace the change",
        "A bold decision will lead to unexpected opportunities. Trust your instincts.",
        "You will soon experience a burst of creativity. Let your imagination run wild" 
    };

    const string BLUE_PRED_ARRAY[] = {
        "A calm and seren phase is approaching; embrace the tranquility.",
        "Your loyalty and trustworthiness will bring you unexpected rewards soon.",
        "An opportunity for growth will arise; be ready to seize it with confidence."
    };

    const string YELLOW_PRED_ARRAY[] = {
        "A burst of optimisim will brighten your day and open doors to new possibilities.",
        "You will soon find joy in an unexpected place; let your curiosity guide you.",
        "A positive attitude will attract like-minded people into you life. Embrace new friendships."
    };

    const string GREEN_PRED_ARRAY[] = {
        "A period of growth and renewal is on the horizon. Embrace the changes that come your way.",
        "You will find balance and harmony in an unexpected situation. Trust the process.",
        "An opportunity for healing, both physical and emontional, is approaching. Be open to it."
    };

    const string PINK_PRED_ARRAY[] = {
        "A wave of affection and kindness will brighten your day. Embrace the love that surrounds you.",
        "An opportunity for creativity and self-expression is on the horizon. Let your imagination flow.",
        "A romantic gesture or heartfelt conversation will bring joy and warmth into your life soon."
    };

    const string BROWN_PRED_ARRAY[] = {
        "Stability and grounding will be your focus; embrace the solid foundation that supports you.",
        "A practical solution to a long-standing issue wil son present itself. Trust in the process.",
        "You will find comfort and clarity in simplifying your life and focusing on what truly matters."
    };
    
    const string COLOR_PRED_ARRAY[] = {
        "Change is on the horizon; embrace it with an open heart and mind.",
        "A moment of clarity will help you make an important decision. Trust your intuition.",
        "Rules are for the obedience of fools and the guidance of the wise."
    };
    //==============================================

    // Greet user based on time of day
    if (hour < 12) {
        cout << "Good morning, ";
    }
    else if (hour < 18) {
        cout << "Good afternoon, ";
    }
    else {
        cout << "Good evening, ";
    }

    // Ask user for favorite color
    cout << "what is your favorite color? (Red, Blue, Green, Yellow): ";
    getline(cin, color);

    //convert user input to all lower case
    for (char &c : color) {
        c = tolower(c);
    }

    random_device rd; // Get random number from hardware
    mt19937 gen(rd()); // Seed the generator
    uniform_int_distribution<> dis(0, 2); // Define the range

    int randomIndex = dis(gen); // Generate random index

    // Give quote baed on color
    if (color == "red") {
        cout << RED_PRED_ARRAY[randomIndex];
    }
    else if (color == "blue") {
        cout << BLUE_PRED_ARRAY[randomIndex];
    }
    else if (color == "yellow") {
        cout << YELLOW_PRED_ARRAY[randomIndex];
    }
    else if (color == "green") {
        cout << GREEN_PRED_ARRAY[randomIndex];
    }
    else if (color == "pink") {
        cout << PINK_PRED_ARRAY[randomIndex];
    }
    else if (color == "brown") {
        cout << BROWN_PRED_ARRAY[randomIndex];
    }
    else { // for any other color
        cout << COLOR_PRED_ARRAY[randomIndex];
    }

    return 0;
}

