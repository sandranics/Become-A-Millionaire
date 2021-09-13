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

#pragma once

#include <string>
using namespace std;

void printQ(const string& level, const string& category, int& check, int numberQuestion, int& prev, int& rem);
void printAllQs(string category);
void printAllQsForAllCategories();
