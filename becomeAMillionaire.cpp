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
* <main file>
*
*/

#include <iostream>
#include <windows.h>
#include "homeScreen.hpp"
#include "printQs.hpp"
#include "editQs.hpp"
#include "addQs.hpp"

using namespace std;

int main()
{
	HANDLE console_color;
	console_color = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(console_color, 2);

	string choice;
	do {

		homeScreen(choice);

		if (choice == "1") {
			system("cls");
			string categoryChoice;
			string category;
			pickCategory(categoryChoice);
			system("cls");

			if (categoryChoice == "1") {
				printAllQs("Biology");
			}
			else if (categoryChoice == "2") {
				printAllQs("Celebrities");
			}
			else if (categoryChoice == "3") {
				printAllQs("Trivia");
			}
			if (categoryChoice == "4") {
				printAllQsForAllCategories();
			}
		}

		if (choice == "2") {
			system("cls");
			AddNewQuestion();
		}

		if (choice == "3") {
			system("cls");
			EditQuestion();
		}

	} while (choice != "4");

	return 0;
}