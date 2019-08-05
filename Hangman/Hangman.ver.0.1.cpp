#include <iostream>
#include <string>

using namespace std;
//initialize
string generateWord ()
{
    string str = "Hello";
    return str;
}

void renderGame (int guessLeft, string playerWord)
{

    cout << "You have " << guessLeft << " turn left." << endl;
    cout << "The word: " << playerWord << endl;
}

char readAGuess ()
{
    char playerGuessWord;
    cout << "Your guess: ";
    cin >> playerGuessWord;
    cout << endl;
    return playerGuessWord;
}

bool checkGame (string guessWord, char playerGuess)
{
    for (int i=0; i<(int)guessWord.length(); i++){
        if (playerGuess == guessWord[i]){
//            playerWord [i] = playerGuess;

            return true;
        }
    }
    return false;
}

string updateGuessWord (string guessWord, string playerWord, char playerGuess)
{
    for (int i=0; i<(int)guessWord.length(); i++){
        if (playerGuess == guessWord[i]){
            playerWord [i] = playerGuess;
        }
    }
    return playerWord;
}

void setupGame ()
{
    int guessLeft = 7;
    string guessWord = generateWord();
    string playerWord = string(guessWord.length(), '-');                // New structure!
    do {
        char playerGuess = readAGuess ();
        if (checkGame(guessWord, playerGuess)){
            playerWord = updateGuessWord(guessWord, playerWord, playerGuess);
        }
        else guessLeft --;

        renderGame(guessLeft, playerWord);

        if (guessWord == playerWord) {
            cout << "You Win" << endl;
            break;
        }
    } while (guessLeft != 0);
    if (guessWord != playerWord) cout << "You hanged!" << endl;
}

int main()
{
    char choice;
    do{
        setupGame();
        cout << "Play more? (y/n): ";
        cin >> choice;
    } while (choice == 'y');
    return 0;
}
