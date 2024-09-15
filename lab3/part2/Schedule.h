#include <string>
#include "Course.h"
#include <set>
#include <map>

class Schedule {

public:
	Schedule(std::string name);
	// return true if course was succesfully dropped
	bool dropCourse(std::string name);
	// return true if course was sucessfully added
	bool addCourse(Course* c);
	void printAllAssignments();
	std::map<std::string, Course*> getCourses();

private:
	std::string mName;
	double mGrade;
	bool mComplete;
	int mPriority;
	std::map<std::string, Course*> courseMap;
};