#include <iostream>
#include <vector>
#include <time.h>
#include <algorithm>
using namespace std;

// Returns a vector of positions of letter s in vector of letters v
vector<int> PositionsInWord(char s, vector<char> v)
{
	vector<int> vIndices;
	for (int i = 0; i < v.size(); i++)
	{
		if (s == v[i])
			vIndices.push_back(i);
	}

	return vIndices;
}

int main()
{
	vector<string> vWords =
	{
		"grenadine", "hefty", "gladiolus", "effeminate", "concretize", "manikin", "canvass", "lubbrly",
		"cordial", "jocular", "utopian", "tamp", "ecstasy", "obbligato", "woodsy", "stevedore",
		"effervescence", "bromidic", "canoodle", "congeries", "twain", "polysemy", "madrigal",
		"parvenu", "bowdlerize", "mountebank",  "hauteur", "paleobotany", "tribunal", "ague",
		"humiliating", "subsequently", "massacre", "civilian", "revolt", "revered", "regime",
		"triumphantly", "culminate", "upsurge", "suffrage", "insurgency", "ambiguity", "anent",
		"felicitous", "stringent", "famine", "eradicate", "tapestry", "pendulum",
		"floccinaucinihilipilification"
	};

	// Choosing a random word to be guessed each time
	srand(time(NULL));
	string sRandomWord = vWords[rand() % vWords.size()];
	vector<char> vLetters;

	for (auto i : sRandomWord)
	{
		vLetters.push_back(i);
	}

	vector<char> vBlanks;

	bool bGuessed = false;
	int nGuessCount = 0;
	int nMaxGuesses = 15; // Only allow a maximum of 15 failed attempts

	for (int i = 0; i < vLetters.size(); i++)
	{
		vBlanks.push_back('_');
	}

	while (!bGuessed && nGuessCount != nMaxGuesses)
	{
		// Display the current state of the game
		for (int i = 0; i < vLetters.size(); i++)
			cout << vBlanks[i] << ' ';


		// Getting User Input
		bool bIsInWord = false;
		char sGuess;
		cout << endl;
		cout << "Enter your guess" << "["<< nMaxGuesses - nGuessCount << " guesses left]: ";
		cin >> sGuess;

		if (PositionsInWord(sGuess, vLetters).size() != 0)
		{
			bIsInWord = true;
			for (int i = 0; i < PositionsInWord(sGuess, vLetters).size(); i++)
			{
				vBlanks[PositionsInWord(sGuess, vLetters)[i]] = sGuess;
			}
		}
		
		// Increment fail counter if guess is not in word
		if (!bIsInWord)
			nGuessCount++;

		if (find(vBlanks.begin(), vBlanks.end(), '_') == vBlanks.end())
			bGuessed = true;
	}

	cout << endl;
	if (bGuessed)
		cout << "You guessed it!";
	else
		cout << "Better luck next time!";
	
	return 0;
}