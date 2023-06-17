#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

// Слова для угадывания
vector<string> words = {
    "apple",
    "banana",
    "orange",
    "strawberry",
    "kiwi",
    "grapefruit",
    "pineapple",
    "watermelon",
    "pear",
    "peach"
};

// Функция для выбора случайного слова
string getRandomWord()
{
    srand(static_cast<unsigned int>(time(0)));
    int randomIndex = rand() % words.size();
    return words[randomIndex];
}

// Функция для печати текущего состояния игры
void printGameStatus(const string& guessedWord, int remainingAttempts)
{
    cout << "Ugadanoe slovo: " << guessedWord << endl;
    cout << "Ostalos poputok: " << remainingAttempts << endl;
}

int main()
{
    string secretWord = getRandomWord();
    string guessedWord(secretWord.length(), '-');
    int remainingAttempts = 6;
    char guess;

    cout << "*** GAME \"Viselitsa\" ***" << endl;

    while (remainingAttempts > 0)
    {
        printGameStatus(guessedWord, remainingAttempts);

        cout << "Vvedi bykvy: ";
        cin >> guess;
        guess = tolower(guess);

        bool correctGuess = false;
        for (size_t i = 0; i < secretWord.length(); i++)
        {
            if (secretWord[i] == guess)
            {
                guessedWord[i] = guess;
                correctGuess = true;
            }
        }

        if (!correctGuess)
        {
            remainingAttempts--;
            cout << "Neverno!" << endl;
        }

        if (guessedWord == secretWord)
        {
            cout << "Vi egadali slovo \"" << secretWord << "\"! Posdravlyem!" << endl;
            break;
        }
    }

    if (remainingAttempts == 0)
    {
        cout << "You lose :( The hidden word was \"" << secretWord << "\"." << endl;
    }

    cout << "Game over." << endl;

    return 0;
}