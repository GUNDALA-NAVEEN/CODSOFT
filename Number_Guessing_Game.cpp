#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    srand(time(0));

    int randomNumber = rand() % 100 + 1;
    int guess = 0;

    cout << "I have generated a random number between 1 and 100" << endl;
    cout << "Can you guess what it is?" << endl;

    while (guess != randomNumber) {
        cout << "Enter your guess: ";
        cin >> guess;

        if (guess < randomNumber) {
            cout << "Your guess is too low! Try again..." << endl;
        } else if (guess > randomNumber) {
            cout << "Your guess is too high! Try again..." << endl;
        } else {
            cout << "You guessed it correct! Congrats..." << endl;
        }
    }

    return 0;
}
