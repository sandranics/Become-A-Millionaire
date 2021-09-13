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
* <homescreen menus>
*
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

bool homeScreenValidation(const string& input) {
	if (input != "1" && input != "2" && input != "3" && input != "4") {
		return false; // in case of incorrect input
	}
	else return true; // in case of correct input
}

bool answerValidation(const string& input) {
	if (input != "A" && input != "B" && input != "C" && input != "D") {
		return false; // in case of incorrect input
	}
	else return true; // in case of correct input
}

void homeScreen(string& choice) {
	cout << "$$$$$$$$$$$$$$$$$$$$$$$$$ Become a milionaire $$$$$$$$$$$$$$$$$$$$$$$$$$$" << endl;
	cout << endl;
	cout << "                       New Game         (choose 1)" << endl;
	cout << "                       Add New Question (choose 2)" << endl;
	cout << "                       Edit Question    (choose 3)" << endl;
	cout << "                       Exit             (choose 4)" << endl;
	cout << endl;
	cout << "note: remember question's unique code if you want to edit it later!"<<endl;
	cout << endl;
	cout << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << endl;
	cout << endl;
	cout << "Your choice: ";


	getline(cin, choice);
	if (homeScreenValidation(choice) == 1) {
		cout << endl;
	}
	else {
		while (homeScreenValidation(choice) == 0) {
			cout << "Error! Choose 1, 2, 3 or 4: ";
			getline(cin, choice);
		}
	}
}

void pickCategory(string& choice) {
	cout << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << endl;
	cout << endl;
	cout << "                       Choose a category:                               " << endl;
	cout << "                       Biology        (choose 1)                        " << endl;
	cout << "                       Celebrities    (choose 2)                        " << endl;
	cout << "                       Trivia         (choose 3)                        " << endl;
	cout << "                       All categories (choose 4)                        " << endl;
	cout << endl;
	cout << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << endl;
	cout << "Your choice: ";

	getline(cin, choice);
	if (homeScreenValidation(choice) == true) {
		cout << endl;
	}
	else {
		while (homeScreenValidation(choice) == false) {
			cout << "Error! Choose 1, 2, 3 or 4: ";
			getline(cin, choice);
		}
	}
}