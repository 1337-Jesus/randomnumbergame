#include <iostream>

using namespace std;


int main(void) {
	char secret[]{ "caal" }; // here the secret word is stored

	int letters{ (int)sizeof(secret) };
	char* actual{ new char[letters] { } }; //here input from actual try is stored - first try of dynamic memory allocation - seems to work =)


	int tries{ 10 };

	char userinput{ 0 };

	for (int counter = 0; counter < letters -1; ++counter) {
		if (counter != letters)
			actual[counter] = '_';
		else
			actual[counter] = '\0';
	}

	for (int counter = letters - 1; counter > 0; --counter)
		cout << actual[counter];


	cout << "Welcome to the word guessing game!\n";
	cout << "The secret word has: " << letters - 1 << "\n";
	cout << "Start guessing: \n";

	while (tries > 0 && strcmp(actual, secret) != 0) {

	if (strcmp(actual, secret) != 0) {
		cout << "Enter a letter: \n";
		cin >> userinput;


		for (int counter = 0; counter < letters - 1; ++counter)
			if (userinput == secret[counter])
				actual[counter] = secret[counter];

		for (int counter = 0; counter < letters - 1; ++counter)
			cout << actual[counter];

		cout << "\n";
		--tries;
	}
	else {
		break;
	}

	}
	delete[] actual;
	cout << "You have found the secret word! You have won the Game";



}
/*
todo
input check
delete array and reinitialize after each run 
play again loop
array of word which is random choosen from - best with already used words removed or flagged
*/
