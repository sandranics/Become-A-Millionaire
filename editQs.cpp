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
* <editing a question>
*
*/

#include <iostream>
#include <fstream>
#include <cstring>

#include "addQs.hpp"
#include "helpfulFuncs.hpp";
#include "editQs.hpp"

//if the user inputs something different to "yes" or "no", the program wants the user to input again
void yes_noValidation(string& answer) {
	while (answer != "yes" && answer != "no") {
		cout << "Error! Enter yes or no: ";
		getline(cin, answer);
	}
}

void EditQuestion()
{
	string answer; // this is for the user to input if he wants to edit 
	int lastExistingQuestionCode = countLinesInFile("answers.txt");   // "answers.txt" contains number of lines equal to the last existing question code
	string lastQuestionCode = to_string(lastExistingQuestionCode);

	cout << "Enter the Unique Q code of the question you want to edit: ";
	bool isValid = false;   //isValid = true when the input is a number between  and the last exsisting question code
	string questionCode;

	do {
		getline(cin, questionCode);
		EmptyStringValidation(questionCode); //the user will be asked to input again if he presses Enter
		for (int i = 1; i <= lastExistingQuestionCode; i++) {
			if (questionCode == to_string(i)) {
				isValid = true;
			}
		}
		if (isValid == true) {
			break;
		}
		cout << "Error! A question with that code was not found." << endl;
		cout << "Try again: ";
	} while (isValid == false);

	ifstream myFile;
	string myFileName = fileContainingString((questionCode));   //finding the file containg the question we want to edit 
	myFile.open(myFileName);
	vector<int>line = findStringLines(myFileName, (questionCode));  // there will be only one element in that vector 

	cout << "We found the question you are looking for!" << endl;
	cout << endl;

	// ouputing the question who will be edited with the answers
	for (int i = 2; i < 7; i++) {
		cout << getLineFromFile(myFileName, line[0] + i) << endl;
	}
	cout << endl;

	string newQuestion = " ", newA = " ", newB = " ", newC = " ", newD = " ";

	cout << "Do you want to edit the question's content? yes/no: ";  // "question's content" means the question itself without the answers to it
	getline(cin, answer); // yes/no
	yes_noValidation(answer);
	if (answer == "yes") {
		cout << "Input the edited question below: " << endl;
		getline(cin, newQuestion);
		EmptyStringValidation(newQuestion);
	}

	cout << "Do you want to edit option A? yes/no: ";
	getline(cin, answer);  // yes/no
	yes_noValidation(answer);
	if (answer == "yes") {
		cout << "Input the edited option A below in fromat: A. ___: " << endl;
		cin.ignore();
		getline(cin, newA);
	}

	cout << "Do you want to edit option B? yes/no: ";
	getline(cin, answer);  // yes/no
	yes_noValidation(answer);
	if (answer == "yes") {
		cout << "Input the edited option B below in format: B. ___: " << endl;
		cin.ignore();
		getline(cin, newB);
	}

	cout << "Do you want to edit option C? yes/no: ";
	getline(cin, answer);  // yes/no
	yes_noValidation(answer);
	if (answer == "yes") {
		cout << "Input the edited option C below in format: C. ___: " << endl;
		cin.ignore();
		getline(cin, newC);
	}

	cout << "Do you want to edit option D? yes/no: ";
	getline(cin, answer);  // yes/no
	yes_noValidation(answer);
	if (answer == "yes") {
		cout << "Input the edited option D below in format: D. ___ " << endl;
		cin.ignore();
		getline(cin, newD);
	}

	string newRightAnswer;
	cout << "Do you want to edit the right answer? yes/no: ";
	getline(cin, answer);  // yes/no
	yes_noValidation(answer);
	if (answer == "yes") {
		cout << "Input the right answer below: (A/B/C/D):" << endl;
		getline(cin, newRightAnswer);
		while (newRightAnswer != "A" && newRightAnswer != "B" && newRightAnswer != "C" && newRightAnswer != "D") {
			cout << "Error! Input A, B, C or D: ";
			getline(cin, newRightAnswer);
		}

		string tempFileNameA = "tempA.txt";
		ofstream tempFileA(tempFileNameA);
		ifstream answersFile("answers.txt");
		int myFileLines = countLinesInFile("answers.txt");

		for (int i = 1; i <= myFileLines; i++) {
			if (i != stoi(questionCode)) {
				tempFileA << getLineFromFile("answers.txt", i) << endl;
			}
			else {
				tempFileA << newRightAnswer << endl;
			}
		}

		answersFile.close();
		tempFileA.close();

		const char* newName = "answers.txt";
		const char* oldName = "tempA.txt";
		remove(newName);
		rename(oldName, newName);

	}

	string tempFileName = "temp.txt";   // creating a temporary file for the editing file algorithm
	ofstream tempFile(tempFileName);

	int myFileLines = countLinesInFile(myFileName);
	vector<int> lines = findStringLines(myFileName, getLineFromFile(myFileName, line[0] + 2));  // lines[0] is the line we will change

	for (int i = 1; i <= myFileLines; i++) {
		if (i != lines[0]) {
			tempFile << getLineFromFile(myFileName, i) << endl;
		}
		else {
			if (newQuestion != " ") {
				tempFile << "  " << newQuestion << endl;
			}
			else tempFile << getLineFromFile(myFileName, i) << endl;

			if (newA != " ") {
				tempFile << "A" << newA << endl;
			}
			else tempFile << getLineFromFile(myFileName, i + 1) << endl;

			if (newB != " ") {
				tempFile << "B" << newB << endl;
			}
			else tempFile << getLineFromFile(myFileName, i + 2) << endl;

			if (newC != " ") {
				tempFile << "C" << newC << endl;
			}
			else tempFile << getLineFromFile(myFileName, i + 3) << endl;

			if (newD != " ") {
				tempFile << "D" << newD << endl;
			}
			else tempFile << getLineFromFile(myFileName, i + 4) << endl;

			i = i + 4;
		}
	}

	myFile.close();
	tempFile.close();

	//char* fileName is used as a pointer to the name of the file containing the edited question.
	char* fileName = new char[myFileName.size() + 1];
	std::copy(myFileName.begin(), myFileName.end(), fileName);
	fileName[myFileName.size()] = '\0';

	const char* newName = fileName;
	const char* oldName = "temp.txt";
	remove(newName);
	rename(oldName, newName);

	myFile.close();
	cout << "Question edited successfully!" << endl;
	system("pause");
	system("cls");
}