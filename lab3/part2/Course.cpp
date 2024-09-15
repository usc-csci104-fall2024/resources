#include <iostream>
#include "Course.h"

using namespace std;

Course::Course() {}

void Course::setCourseName(string courseName) {
	mCourseName = courseName;
}

string Course::getCourseName() {
	return mCourseName;
}

set<Assignment*> Course::getAssignmentSet() {
	return mAssignmentSet;
}

void Course::addAssignment(Assignment* a) {
	mAssignmentSet.insert(a);
}