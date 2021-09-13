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

#pragma once

#include <string>
using namespace std;

bool homeScreenValidation(const string& input);
bool answerValidation(const string& input);
void homeScreen(string& choice);
void pickCategory(string& choice);