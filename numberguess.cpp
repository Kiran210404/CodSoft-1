//Task-1

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class NumberGuessingGame {
private:
    int hiddennumber;
    int attempts;

public:
    
    NumberGuessingGame(int minRange, int maxRange) : attempts(0) {
        srand(static_cast<unsigned int>(time(0)));      // Seed the random number generator

        // Generate a random number within the specified range
        hiddennumber = rand() % (maxRange - minRange + 1) + minRange;
    }

    // Method to play the game
    void play() {
        int guess;
        cout << "Welcome to the Number Guessing Game!\n";
        cout << "Can you guess the number?\n";

        do {
            // Get a guess from the player
            cout << "Enter your guess: ";
            cin >> guess;

            // Increment the number of attempts
            attempts++;

            // Check if the guess is correct
            if (guess == hiddennumber) {
                cout << "Congratulations! You guessed the number " << hiddennumber << " in " << attempts << " attempts.\n";
            } else if (guess < hiddennumber) {
                cout << "Too low. Try again.\n";
            } else {
                cout << "Too high. Try again.\n";
            }

        } while (guess != hiddennumber);
    }
};

int main() {
    int minRange, maxRange;

    // Get difficulty level from the user and set the range accordingly
    cout << "Choose the difficulty level:\n";
    cout << "1. Easy (1-50)\n";
    cout << "2. Medium (1-100)\n";
    cout << "3. Hard (1-200)\n";
    int difficulty;
    cin >> difficulty;

    switch (difficulty) {
        case 1:
            minRange = 1;
            maxRange = 50;
            break;
        case 2:
            minRange = 1;
            maxRange = 100;
            break;
        case 3:
            minRange = 1;
            maxRange = 200;
            break;
        default:
            cout << "Invalid difficulty level.\n";
            return 1; // Exit with an error code
    }

    // Create an instance of the NumberGuessingGame class with the specified range
    NumberGuessingGame game(minRange, maxRange);

    // Play the game
    game.play();

    return 0;
}
