#include "Assignment.h"
#include <iostream>

using namespace std;

Assignment::Assignment() {
	mName = "";
	mPoints = 0;
	mTotalPoints = 1;
	mComplete = false;
	mPriority = 0;
}

Assignment::~Assignment() {

}

void Assignment::setName(std::string name) {
	mName = name;
}

std::string Assignment::getName() {
	return mName;
}

std::string Assignment::getType() {
	return "Assignment";
}

bool Assignment::isComplete() {
	return mComplete;
}

void Assignment::complete() {
	mComplete = true;
}

std::string Essay::getType() {
	return "Essay";
}

std::string Essay::getPrompt() {
	return mPrompt;
}

std::string Exam::getType() {
	return "Exam";
}

std::string Homework::getType() {
	return "Homework";
}
