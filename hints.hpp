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

#pragma once

#include <vector>

void hint50_50(const string& fileName, const string& rightAnswer, const int& numberQuestion, const int& random);
void hintCallAFriendSpecific(const string& fileName, const string& rightAnswer, const int& numberQuestion, const int& random, const int& percantage);
void hintCallAFriendOverall(const string& fileName, const string& rightAnswer, const int& numberQuestion, const int& random);
vector<int> Generate100();
void hintAskThePublicSpecific(const string& fileName, const string& rightAnswer, const int& numberQuestion, const int& percantage);
void hintAskThePublicOverall(const string& fileName, const string& rightAnswer, const int& numberQuestion, const int& random);
