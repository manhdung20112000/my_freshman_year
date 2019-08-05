#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <vector>
#include <cstdlib>

using namespace std;
//initialize
string generateWord ()
{
    vector <string> text;
    ifstream input("text.txt");
    while (!input.eof()) {
        string line;
        input >> line;
        if (input) {
            text.push_back(line);
        }
    }
    int idx = rand() % text.size();
//    cout << text[idx];
    return text[idx];
}

void renderGame (int guessLeft, string playerWord)
{

    //cout << "You have " << guessLeft << " turn left." << endl;
    cout << "Guessed Word:  " << playerWord << endl;


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
    cout << "The word: " << playerWord << endl
         << "You only got 7 chances, let's go!" << endl;
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
    srand(time(0));
    char choice;
    do{
        setupGame();
        cout << "Play more? (y/n): ";
        cin >> choice;
    } while (choice == 'y');
    return 0;
}
