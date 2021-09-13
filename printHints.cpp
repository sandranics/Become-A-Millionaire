/**
*
* Solution to course project # 1
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2020/2021
*
* @author Aleksandra Radeva
* @idnumber 62541
* @compiler VC
*
* <printing hints>
*
*/

#include <iostream>
#include <cstring>
#include <string>
#include <iostream>

#include "helpfulFuncs.hpp"
#include "hints.hpp"
#include "printHints.hpp"

bool h1 = 1, h2 = 1, h3 = 1; //so that hints are available at the beginning

void UsedHints(const string& hintChoice, bool& h1, bool& h2, bool& h3) {
	if (hintChoice == "1") {
		h1 = 0;
	}
	else if (hintChoice == "2") {
		h2 = 0;
	}
	else h3 = 0;
}

//h1 = 1 means 50/50 is not used. h1 = 0 means 50/50 is used
//h2 = 1 means Call a friend is not used. h2 = 0 means Call a friend is used.
//h3 = 1 means Ask the public is not used. h3 = 0 means Ask the public is used.

void hint1(const string& fileName, const string& line, const int& numberQuestion, const int& rand) {
	UsedHints("1", h1, h2, h3);
	system("cls");
	hint50_50(fileName, getLineFromFile("answers.txt", stoi(getLineFromFile(fileName, rand - 1))), numberQuestion, rand);

}

void hint2(const string& fileName, const string& line, const int& numberQuestion, const int& rand) {
	UsedHints("2", h1, h2, h3);
	hintCallAFriendOverall(fileName, getLineFromFile("answers.txt", stoi(getLineFromFile(fileName, rand - 1))), numberQuestion, rand);
}

void hint3(const string& fileName, const string& line, const int& numberQuestion, const int& rand) {
	UsedHints("3", h1, h2, h3);
	hintAskThePublicOverall(fileName, getLineFromFile("answers.txt", stoi(getLineFromFile(fileName, rand - 1))), numberQuestion, rand);
}

void printHints(const string& fileName, const int& numberQuestion, const int& rand) {
	if (numberQuestion == 1) {
		h1 = 1;
		h2 = 1;
		h3 = 1;
	}
	cout << "Do you want to use a hint? (yes/no): ";
	string answerhint;

	getline(cin, answerhint);
	while (answerhint != "yes" && answerhint != "no") {
		cout << "Error! Enter again: ";
		getline(cin, answerhint);
	}

	if (answerhint == "yes") {

		if (h1 == 1 && h2 == 1 && h3 == 1) {
			cout << "Available hints: 1. 50/50, 2. Call a friend, 3. Ask the public" << endl;
			cout << "Enter your choice: ";

			string hintChoice;
			getline(cin, hintChoice);
			while (hintChoice != "1" && hintChoice != "2" && hintChoice != "3") {
				cout << "Error! Enter again: ";
				getline(cin, hintChoice);
			}

			if (hintChoice == "1") {
				hint1(fileName, getLineFromFile("answers.txt", stoi(getLineFromFile(fileName, rand - 1))), numberQuestion, rand);
			}
			if (hintChoice == "2") {
				hint2(fileName, getLineFromFile("answers.txt", stoi(getLineFromFile(fileName, rand - 1))), numberQuestion, rand);
			}
			if (hintChoice == "3") {
				hint3(fileName, getLineFromFile("answers.txt", stoi(getLineFromFile(fileName, rand - 1))), numberQuestion, rand);
			}
		}

		else if (h1 == 0 && h2 == 1 && h3 == 1) {
			cout << "Available hints:  2. Call a friend, 3. Ask the public" << endl;
			cout << "Enter your choice: ";

			string hintChoice;
			getline(cin, hintChoice);
			while (hintChoice != "2" && hintChoice != "3") {
				cout << "Error! Enter again: ";
				getline(cin, hintChoice);
			}
			if (hintChoice == "2") {
				hint2(fileName, getLineFromFile("answers.txt", stoi(getLineFromFile(fileName, rand - 1))), numberQuestion, rand);
			}
			if (hintChoice == "3") {
				hint3(fileName, getLineFromFile("answers.txt", stoi(getLineFromFile(fileName, rand - 1))), numberQuestion, rand);
			}
		}

		else if (h1 == 1 && h2 == 0 && h3 == 1) {
			cout << "Available hints:  1. 50/50, 3. Ask the public" << endl;
			cout << "Enter your choice: ";

			string hintChoice;
			getline(cin, hintChoice);
			while (hintChoice != "1" && hintChoice != "3") {
				cout << "Error! Enter again: ";
				getline(cin, hintChoice);
			}

			if (hintChoice == "1") {
				hint1(fileName, getLineFromFile("answers.txt", stoi(getLineFromFile(fileName, rand - 1))), numberQuestion, rand);
			}

			if (hintChoice == "3") {
				hint3(fileName, getLineFromFile("answers.txt", stoi(getLineFromFile(fileName, rand - 1))), numberQuestion, rand);
			}
		}
		else if (h1 == 1 && h2 == 1 && h3 == 0) {
			cout << "Available hints:  1. 50/50, 2. Call a friend" << endl;
			cout << "Enter your choice: ";

			string hintChoice;
			getline(cin, hintChoice);
			while (hintChoice != "1" && hintChoice != "2") {
				cout << "Error! Enter again: ";
				getline(cin, hintChoice);
			}

			if (hintChoice == "1") {
				hint1(fileName, getLineFromFile("answers.txt", stoi(getLineFromFile(fileName, rand - 1))), numberQuestion, rand);
			}

			if (hintChoice == "2") {
				hint2(fileName, getLineFromFile("answers.txt", stoi(getLineFromFile(fileName, rand - 1))), numberQuestion, rand);
			}
		}
		else if (h1 == 1 && h2 == 0 && h3 == 0) {
			cout << "Available hints:  1. 50/50" << endl;
			cout << "Enter your choice: ";

			string hintChoice;
			getline(cin, hintChoice);
			while (hintChoice != "1") {
				cout << "Error! Enter again: ";
				getline(cin, hintChoice);
			}
			hint1(fileName, getLineFromFile("answers.txt", stoi(getLineFromFile(fileName, rand - 1))), numberQuestion, rand);
		}

		else if (h1 == 0 && h2 == 1 && h3 == 0) {
			cout << "Available hints:  2. Call a friend" << endl;
			cout << "Enter your choice: ";

			string hintChoice;
			getline(cin, hintChoice);
			while (hintChoice != "2") {
				cout << "Error! Enter again: ";
				getline(cin, hintChoice);
			}
			hint2(fileName, getLineFromFile("answers.txt", stoi(getLineFromFile(fileName, rand - 1))), numberQuestion, rand);
		}

		else if (h1 == 0 && h2 == 0 && h3 == 1) {
			cout << "Available hints:  3. Ask the public" << endl;
			cout << "Enter your choice: ";

			string hintChoice;
			getline(cin, hintChoice);
			while (hintChoice != "3") {
				cout << "Error! Enter again: ";
				getline(cin, hintChoice);
			}
			hint3(fileName, getLineFromFile("answers.txt", stoi(getLineFromFile(fileName, rand - 1))), numberQuestion, rand);
		}

		else if (h1 == 0 && h2 == 0 && h3 == 0) {
			cout << "No available hints" << endl;
		}
	}
}