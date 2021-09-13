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
* <hints>
*
*/

#include <iostream>
#include <cstring>
#include <ctime>
#include <algorithm>

#include "helpfulFuncs.hpp"
#include "hints.hpp"

void hint50_50(const string& fileName, const string& rightAnswer, const int& numberQuestion, const int& random) {

	vector<string> options = { "A", "B", "C", "D" };
	options.erase(remove(options.begin(), options.end(), rightAnswer), options.end());  //removing the correct answer from the vector with options, because we do not want to choose it randomly for elimination
	srand(time(0));

	//randomly choosing two of the remaining wrong options to eliminate 
	int removeIndex1 = rand() % options.size();
	string remove1 = options[removeIndex1];
	options.erase(remove(options.begin(), options.end(), remove1), options.end());
	int removeIndex2 = rand() % options.size();
	string remove2 = options[removeIndex2];

	//index1 and index2 are used to know how many lines below the line with the questiopn is the options we need to eliminate
	int index1, index2;
	if (remove1 == "A") {
		index1 = 1;
	}
	else if (remove1 == "B") {
		index1 = 2;
	}
	else if (remove1 == "C") {
		index1 = 3;
	}
	else index1 = 4;

	if (remove2 == "A") {
		index2 = 1;
	}
	else if (remove2 == "B") {
		index2 = 2;
	}
	else if (remove2 == "C") {
		index2 = 3;
	}
	else index2 = 4;

	system("cls");
	string line;
	cout << "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&" << endl;
	cout << numberQuestion << ".";
	for (int i = random + 1; i < random + 6; i++)
	{
		if (getLineFromFile(fileName, i) == getLineFromFile(fileName, random + 1 + index1)) {
			cout << endl;
			continue;
		}
		if (getLineFromFile(fileName, i) == getLineFromFile(fileName, random + 1 + index2)) {
			cout << endl;
			continue;
		}
		cout << getLineFromFile(fileName, i) << endl;
	}
	cout << endl;
	cout << "Unique Q code: ";
	cout << getLineFromFile(fileName, random - 1) << endl;

	cout << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << endl;
}

void hintCallAFriendSpecific(const string& fileName, const string& rightAnswer, const int& numberQuestion, const int& random, const int& percantage) {
	bool TrueFalse;
	srand(time(0));
	TrueFalse = (rand() % 100) < percantage;  //generating a random number between  0 and 99. If the number is < percantage TrueFalse = 1. Otherwise it equals 0.

	// if (TrueFalse == 1) the friend gives a correct answer. if (TrueFalse == 0) the friend gives a wrong answer
	cout << "I think the right answer is ";
	if (TrueFalse == 1) {
		cout << rightAnswer << endl;
	}
	else {
		vector<string> options = { "A", "B", "C", "D" };
		options.erase(remove(options.begin(), options.end(), rightAnswer), options.end());  //removing the correct answer from the vector with options, because we do not want to choose it randomly for elimination
		srand(time(0));
		int wrongOutputIndex = rand() % options.size();
		cout << options[wrongOutputIndex] << endl;
	}
}

void hintCallAFriendOverall(const string& fileName, const string& rightAnswer, const int& numberQuestion, const int& random) {
	if (fileName == "lvl1.txt" || fileName == "lvl2.txt" || fileName == "lvl3.txt") {
		hintCallAFriendSpecific(fileName, rightAnswer, numberQuestion, random, 70);  // for level of difficulty between 1 and 3 the friend has 70% chance to give right answer
	}
	else if (fileName == "lvl4.txt" || fileName == "lvl5.txt" || fileName == "lvl6.txt") {
		hintCallAFriendSpecific(fileName, rightAnswer, numberQuestion, random, 40);  // for level of difficulty between 4 and 6 the friend 40% chance for right answer
	}
	else {
		hintCallAFriendSpecific(fileName, rightAnswer, numberQuestion, random, 20); // for level of difficulty between 7 and 10 the friend 20% chance for right answer
	}
}

vector<int> Generate100() {

	vector<int> percentages;
	int perc1 = rand() % (97) + 1; // generating random number between 1 and 97
	int perc2 = rand() % (98 - perc1) + 1; // generating random number between 1 and 98 - the previous number
	int perc3 = rand() % (99 - (perc1 + perc2)) + 1; //generating random number between 1 and 99 - the sum of the two previous numbers
	int perc4 = 100 - (perc1 + perc2 + perc3); // the last number is equal to 100 - the sum of the three previous numbers

	percentages.push_back(perc1);
	percentages.push_back(perc2);
	percentages.push_back(perc3);
	percentages.push_back(perc4);

	sort(percentages.begin(), percentages.end());

	return percentages;
}

void hintAskThePublicSpecific(const string& fileName, const string& rightAnswer, const int& numberQuestion, const int& percantage) {
	bool TrueFalse;
	srand(time(0));
	TrueFalse = (rand() % 100) < percantage;  //if TrueFalse = 1 the public is right. if TrureFalse = 0 the public is wrong. 

	//if the public is right, the percantage of the right answer will be the biggest percantage, if not - there will be bigger
	//generating four random numbers so that there sum is equal to 100 using Generate100()

	vector<int> percentages = Generate100();

	if (TrueFalse == 1) {
		vector<string> options = { "A", "B", "C", "D" };
		cout << "The public has voted:" << endl;
		cout << percentages[3] << "% for " << rightAnswer << "." << endl; //giving the right answer the biggest percantages (the vector is ascending so the last number is the biggest)

		//removing the correct answer from the vector
		options.erase(remove(options.begin(), options.end(), rightAnswer), options.end());

		int index = rand() % options.size();
		cout << percentages[2] << "% for " << options[index] << "." << endl;

		options.erase(remove(options.begin(), options.end(), options[index]), options.end());

		index = rand() % options.size();
		cout << percentages[1] << "% for " << options[index] << "." << endl;

		options.erase(remove(options.begin(), options.end(), options[index]), options.end());
		cout << percentages[0] << "% for " << options[0] << "." << endl;
	}

	if (TrueFalse == 0) {
		vector<string> options = { "A", "B", "C", "D" };
		options.erase(remove(options.begin(), options.end(), rightAnswer), options.end());
		int index = rand() % options.size();
		cout << percentages[3] << "% for " << options[index] << "." << endl;

		options.erase(remove(options.begin(), options.end(), options[index]), options.end()); //removing the outputed option
		options.push_back(rightAnswer); // adding the right answer back 

		index = rand() % options.size();
		cout << percentages[2] << "% for " << options[index] << "." << endl;

		options.erase(remove(options.begin(), options.end(), options[index]), options.end());

		index = rand() % options.size();
		cout << percentages[1] << "% for " << options[index] << "." << endl;

		options.erase(remove(options.begin(), options.end(), options[index]), options.end());
		cout << percentages[0] << "% for " << options[0] << "." << endl;
	}
}

void hintAskThePublicOverall(const string& fileName, const string& rightAnswer, const int& numberQuestion, const int& random) {
	if (fileName == "lvl1.txt" || fileName == "lvl2.txt" || fileName == "lvl3.txt") {
		hintAskThePublicSpecific(fileName, rightAnswer, numberQuestion, 70);  // for level of difficulty between 1 and 3 the friend has 70% chance to give right answer
	}
	else if (fileName == "lvl4.txt" || fileName == "lvl5.txt" || fileName == "lvl6.txt") {
		hintAskThePublicSpecific(fileName, rightAnswer, numberQuestion, 40);  // for level of difficulty between 4 and 6 the friend 40% chance for right answer
	}
	else {
		hintAskThePublicSpecific(fileName, rightAnswer, numberQuestion, 20); // for level of difficulty between 7 and 10 the friend 20% chance for right answer
	}
}