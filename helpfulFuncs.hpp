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

#pragma once

#include <string>
#include <vector>
using namespace std;

int countLinesInFile(const string& fileName); 
string getLineFromFile(const string& fileName, const int& certainLine);
vector<int> findStringLines(const string& fileName, const string& searchedString);
string fileContainingString(const string& searched);

