#include <iostream>
#include <cstdlib> // Necessary for rand() and srand() functions
#include <ctime>   // Necessary for time() function to seed the randomizer

using namespace std;

int main() {
    // Display welcome message to the user
    cout << "\nWelcome to the Number Guessing Game!\n";
    cout << "Guess a number between 1 and 100. You have limited attempts based on difficulty level.\n";

    // Main game loop - keeps the program running until the user chooses to exit
    while (true) {
        cout << "\nChoose a difficulty level:\n";
        cout << "1. Easy (10 attempts)\n";
        cout << "2. Medium (7 attempts)\n";
        cout << "3. Hard (5 attempts)\n";
        cout << "0. Exit\n";

        int difficulty, maxAttempts;
        cin >> difficulty;

        // Termination condition: exit the loop if the user enters 0
        if (difficulty == 0) {
            cout << "Thanks for playing! Goodbye.\n";
            break;
        }

        // Difficulty logic: mapping the user choice to the maximum number of attempts allowed
        if (difficulty == 1) maxAttempts = 10;
        else if (difficulty == 2) maxAttempts = 7;
        else if (difficulty == 3) maxAttempts = 5;
        else {
            // Error handling for invalid inputs
            cout << "Invalid choice. Please select a valid option.\n";
            continue;
        }

        // Random Number Generation: 
        // srand(time(0)) seeds the random number generator using the current system time
        srand(time(0));
        int secretNumber = rand() % 100 + 1; // Generates a number between 1 and 100

        int guess, attemptsLeft = maxAttempts;
        bool guessedCorrectly = false;

        // Nested loop for the guessing process within a single round
        while (attemptsLeft > 0) {
            cout << "\nEnter your guess: ";
            cin >> guess;

            // Comparison logic to provide feedback to the player
            if (guess == secretNumber) {
                cout << "Congratulations! You guessed the correct number: " << secretNumber << "\n";
                guessedCorrectly = true;
                break; // Exit the guessing loop early upon success
            }
            else if (guess > secretNumber) {
                cout << "Too high! Try a smaller number.\n";
            }
            else {
                cout << "Too low! Try a larger number.\n";
            }

            attemptsLeft--; // Decrement the remaining attempts
            cout << "Attempts left: " << attemptsLeft << "\n";
        }

        // End of round: check if the user failed to guess the number
        if (!guessedCorrectly) {
            cout << "You ran out of attempts! The correct number was: " << secretNumber << "\n";
        }
    }

    return 0; // Standard exit code for C++ programs
}