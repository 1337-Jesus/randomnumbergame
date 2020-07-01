#include <iostream>

//cloned from github repo and commited


void sayHello() {
	std::cout << "Hello and welcome to the random number guessing game\n";
}

void congratulation() {
	std::cout << "Congratulations, you have guessed the secret number!\n";
}

unsigned int setRandomNumber() {
	unsigned int randomNumber = 1234;
	return randomNumber;
}

unsigned int setTryCount() {
	unsigned int tryCount = 6;
	return tryCount;
}



unsigned int userGuess() {
	unsigned int userGuess{};
	std::cout << "Enter a non negativ number and press return: \n";
	std::cin >> userGuess;
	return userGuess;
}


int main(void) {
	//Welcome player and init game state
	sayHello();
	char againSwitch{ 'y' };
	do {
		unsigned int numberToGuess{ setRandomNumber() };
		unsigned int tries{ setTryCount() };

		//player starts guessing
		unsigned int guess{ 0 };
		while (tries > 0)
		{
			unsigned int guess{ userGuess() };
			if (guess == numberToGuess)
			{
				congratulation();
				break;
			}
			else
			{
				--tries;
				if (tries > 0)
				{
					std::cout << "Try it again, you have " << tries << " tries left.\n";
					if (guess < numberToGuess)
						std::cout << "The secret number is higher than the value you have entered.\n";
					else
						std::cout << "The secret number is lower than the value you have entered.\n";
				}
				else
					std::cout << "You have no tries left. Game Over!\n";
			}
		}
		std::cout << "Do you want to play again? press \'y\' for yes or any key for no.\n ";
		std::cin >> againSwitch;
	}
	while (againSwitch == 'y');
	return 0;
}
