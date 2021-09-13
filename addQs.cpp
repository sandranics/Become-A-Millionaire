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
* <adding a question>
*
*/

#include <iostream>
#include <fstream>
using namespace std;

#include "helpfulFuncs.hpp"
#include "addQs.hpp"


void EmptyStringValidation(string& input) {
	while (input.length() == 0) {
		cout << "Try again: ";
		getline(cin, input);
	}
}

void AddNewQuestion() {
	ofstream myFile;
	string category, question, answerA, answerB, answerC, answerD, correctAnswer, levelOfDifficulty;

	cout << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << endl;
	cout << "                         Add new question                               " << endl;
	cout << "                         Pick a category:                              " << endl;
	cout << "                    Biology, Celebrities, Trivia                        " << endl;
	cout << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << endl;

	cout << "Your choice: ";
	getline(cin, category);
	while (category != "Biology" && category != "Celebrities" && category != "Trivia") {
		cout << "Error! Choose a valid category: ";
		getline(cin, category);
	}

	cout << "Enter level of difficulty (between 1 and 10): ";
	getline(cin, levelOfDifficulty);
	while (levelOfDifficulty != "1" && levelOfDifficulty != "2" && levelOfDifficulty != "3" && levelOfDifficulty != "4" && levelOfDifficulty != "5" && levelOfDifficulty != "6" && levelOfDifficulty != "7" && levelOfDifficulty != "8" && levelOfDifficulty != "9" && levelOfDifficulty != "10") {
		cout << "Error! Choose a difficulty between 1 and 10: ";
		getline(cin, levelOfDifficulty);
	}

	cout << "Enter question: ";
	getline(cin, question);
	EmptyStringValidation(question);

	cout << "Enter option A: ";
	getline(cin, answerA);
	EmptyStringValidation(answerA);

	cout << "Enter option B: ";
	getline(cin, answerB);
	EmptyStringValidation(answerB);

	cout << "Enter option C: ";
	getline(cin, answerC);
	EmptyStringValidation(answerC);

	cout << "Enter option D: ";
	getline(cin, answerD);
	EmptyStringValidation(answerD);

	cout << "Enter correct answer (A/B/C/D): ";
	getline(cin, correctAnswer);
	while (correctAnswer != "A" && correctAnswer != "B" && correctAnswer != "C" && correctAnswer != "D") {
		cout << "Error! Choose a valid answer (A/B/C/D): ";
		getline(cin, correctAnswer);
	}

	int questionIDNumber = countLinesInFile("answers.txt") + 1; //the number of lines in "answers.txt" is equal to the last added unique Q number; 
															 // so the new unique Q number is equal to it + 1  

	string myFileName = "lvl" + levelOfDifficulty + ".txt";

	myFile.open(myFileName, ios::app); // app is used to append instead of overwrite
	myFile << endl;
	myFile << questionIDNumber << endl;
	myFile << category << endl;
	myFile << question << endl;
	myFile << "A. " << answerA << endl;
	myFile << "B. " << answerB << endl;
	myFile << "C. " << answerC << endl;
	myFile << "D. " << answerD << endl;
	myFile << " "; // we do that in order for each question's unique Q number to be exactly 8 rows below the previous one, because we use that exact distance when outputing the questions
	myFile.close();

	myFile.open("answers.txt", ios::app);
	myFile << endl;
	myFile << correctAnswer;
	myFile.close();

	system("cls");
	cout << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << endl;
	cout << "	Your question has been added successfully with question code: ";
	cout << questionIDNumber << endl;
	cout << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << endl;

	system("pause");
	system("cls");
}