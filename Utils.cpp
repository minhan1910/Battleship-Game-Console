#include <iostream>
#include "Utils.h"

const int IGNORE_CHARS = 256;

char GetCharacter(const char* prompt, const char* error) {
	bool failure;
	char input;

	do {
		failure = false;
		std::cout << prompt;
		std::cin >> input;

		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(IGNORE_CHARS, '\n');
			std::cout << error << std::endl;
			failure = true;
		}
		else {
			std::cin.ignore(IGNORE_CHARS, '\n');

			if (isalpha(input)) {
				input = tolower(input);
			}
			else {
				std::cout << error << std::endl;
				failure = true;
			}
		}
	} while (failure);

	return input;
}

char GetCharacter(const char* prompt, const char* error, const char validInput[], const int validInputLength, CharacterCaseType characterCaseType) {
	bool failure;
	char input;

	do {
		failure = false;
		std::cout << prompt;
		std::cin >> input;

		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(IGNORE_CHARS, '\n');
			std::cout << error << std::endl;
			failure = true;
		}
		else {
			std::cin.ignore(IGNORE_CHARS, '\n');

			if (isalpha(input)) {
				if (characterCaseType == CC_LOWER_CASE) {
					input = tolower(input);
				}
				else if (characterCaseType == CC_UPPER_CASE) {
					input = toupper(input);
				}

				for (int i = 0; i < validInputLength; ++i) {
					if (input == validInput[i]) {
						return input;
					}
				}

				std::cout << error << std::endl;
				failure = true;
			}
		}
	} while (failure);

	return input;
}

int GetInteger(const char* prompt, const char* error, const int validInput[], const int validInputLength) {
	int input;
	bool inputFailure;

	do
	{
		inputFailure = false;

		std::cout << prompt;
		std::cin >> input;

		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(IGNORE_CHARS, '\n');
			std::cout << error << std::endl;
			inputFailure = true;
		}
		else {
			for (int i = 0; i < validInputLength; ++i) {
				if (validInput[i] == input) {
					return input;
				}
			}

			std::cout << error << std::endl;
			inputFailure = true;
		}

	} while (inputFailure);

	return input;
}

void ClearScreen() {
	system("CLS");
}

void WaitForKeyPress() {
	system("pause");
}