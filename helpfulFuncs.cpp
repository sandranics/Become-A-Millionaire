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
* <helpful functions>
*
*/

#include <fstream>
#include <cstring>

#include "helpfulFuncs.hpp"
using namespace std;

int countLinesInFile(const string& fileName) {
	int numLines = 0;
	ifstream in(fileName);
	string unused;
	while (getline(in, unused)) {
		++numLines;
	}
	return numLines;
}

string getLineFromFile(const string& fileName, const int& certainLine) {
	ifstream myFile;

	myFile.open(fileName, ios::in);

	string line;
	int countLines = 1;
	while (getline(myFile, line)) {
		if (countLines == certainLine) {
			return line;
		}
		countLines++;
	}

	myFile.close();
}

//the lines from a specific file that are equal to a specific string are saved in a vector
vector<int> findStringLines(const string& fileName, const string& searchedString) {
	vector<int> foundLines;
	ifstream myFile;
	myFile.open(fileName, ios::in);
	string line;
	int countLines = 1;
	while (getline(myFile, line)) {
		if (line == searchedString) {
			foundLines.push_back(countLines);
		}
		countLines++;
	}
	myFile.close();

	return foundLines;
}

string fileContainingString(const string& searched) {
	ifstream myFile;
	string myFileName;
	int i;
	for (i = 1; i < 11; i++) {
		myFileName = "lvl" + to_string(i) + ".txt";
		myFile.open(myFileName, ios::in);

		string line;

		while (getline(myFile, line)) {
			if (line == searched) {
				return ("lvl" + to_string(i) + ".txt");
			}
		}
		myFile.close();
	}
}