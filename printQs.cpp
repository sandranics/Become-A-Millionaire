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
* <printing questions>
*
*/

#include <iostream>
#include <ctime>
#include <cstring>

#include "helpfulFuncs.hpp"
#include "hints.hpp"
#include "printHints.hpp"
#include "printQs.hpp"
#include "homeScreen.hpp"

void printQ(const string& level, const string& category, int& check, int numberQuestion, int& prev, int& rem) {
	string prizeScale[15] = { "$100", "$500", "$1,000", "$2,500", "$5,000", "$7,500", "$10,000", "$25,000",
							 "$50,000", "$75,000", "$100,000", "$250,000", "$500,000", "$750,000", "$1 MILLION" };   //on question number i from the game the player wins prizeScale[i-1] if his answer is correct
	system("cls");
	check = 1;
	string answerChoice;
	string fileName = "lvl" + level + ".txt";
	vector<int> a = findStringLines(fileName, category);
	a.erase(remove(a.begin(), a.end(), rem), a.end());
	srand(time(0));

	int randomNumber = rand() % a.size();
	int rand = a[randomNumber];
	prev = rand;

	cout << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << endl;
	cout << numberQuestion << ".";
	for (int i = rand + 1; i < rand + 6; i++) {
		cout << getLineFromFile(fileName, i) << endl;
	}
	cout << endl;
	cout << "Unique Q code: ";
	cout << getLineFromFile(fileName, rand - 1) << endl;

	cout << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << endl;

	printHints(fileName, numberQuestion, rand);

	cout << "Your choice: ";
	getline(cin, answerChoice);
	while (answerValidation(answerChoice) == false) {
		cout << "Error! Enter A, B, C or D: "; getline(cin, answerChoice);
	}

	string questionID =getLineFromFile(fileName, rand - 1);
	rem = prev;
	string rightAnswer = getLineFromFile("answers.txt", stoi(questionID));
	system("cls");

	if (answerChoice == rightAnswer) {
		cout << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << endl;
		cout << "                          Correct answer!" << endl;
		cout << "                    Your current prize is:" << prizeScale[numberQuestion - 1] << endl;
		cout << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << endl;
		system("pause");
	}
	else {
		system("cls");
		cout << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << endl;
		cout << "                     Your answer was wrong." << endl;
		cout << "                    The correct answer was:";
		cout << endl;

		//printing the right answer
		if (rightAnswer == "A") {
			cout << "                          ";
			cout << getLineFromFile(fileName, rand + 2) << endl; //If the answer is A -> print the line 2 lines below the category line
		}

		else if (rightAnswer == "B") {
			cout << "                          ";
			cout << getLineFromFile(fileName, rand + 3) << endl;
		}

		else if (rightAnswer == "C") {
			cout << "                          ";
			cout << getLineFromFile(fileName, rand + 4) << endl;
		}
		else {
			cout << "                          ";
			cout << getLineFromFile(fileName, rand + 5) << endl;
		}

		cout << endl;
		cout << "                        END OF GAME!" << endl;
		cout << endl;

		if (numberQuestion == 1) {
			cout << "                        You won: $0" << endl;
		}
		else {
			cout << "                       You won: ";
			cout << prizeScale[numberQuestion - 2] << endl; //the player ends the game with the money earned from the previous question
		}
		cout << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << endl;
		system("pause");
		check = 0;
	}
}

void printAllQs(string category) {
	int check = 1;
	int questionLevels[15] = { 1, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 7, 8, 9, 10 };
	int i = 0; int prev; int rem;
	do {
		printQ(to_string(questionLevels[i]), category, check, i + 1, prev, rem);
		i++;
		if (i == 15) {
			break;
		}
	} while (check != 0);
	system("cls");
	if (i == 15) {
		cout << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << endl;
		cout << endl;
		cout << "                       Congratulattions!" << endl;
		cout << "                      You won $1 MILLION!" << endl;
		cout << endl;
		cout << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << endl;
		system("pause");
		system("cls");
	}
}

void printAllQsForAllCategories() {
	int check = 1;
	string categories[3] = { "Biology", "Celebrities" ,"Trivia" };
	int questionLevels[15] = { 1, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 7, 8, 9, 10 };
	int i = 0;
	int prev;
	int rem;

	do {
		srand(time(0));                 // helps to generate a different number each time rand() is executed
		int randomNumber = rand() % 3;  // generates a random number between 0 and 2
		printQ(to_string(questionLevels[i]), categories[randomNumber], check, i + 1, prev, rem);
		i++;
		if (i == 15) {
			break;
		}
	} while (check != 0);
	system("cls");
	if (i == 15) {
		cout << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << endl;
		cout << endl;
		cout << "                       Congratulattions!" << endl;
		cout << "                      You won $1 MILLION!" << endl;;
		cout << endl;
		cout << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << endl;
		system("pause");
		system("cls");
	}
}