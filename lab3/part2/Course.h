#include <string>
#include <set>
#include "Assignment.h"

class Course { 
	public:
		Course();
		std::string getCourseName();
		void setCourseName(std::string courseName);
		std::set<Assignment*> getAssignmentSet();
		void addAssignment(Assignment* a);

	private: 
		std::set<Assignment*> mAssignmentSet;
		std::string mCourseName;
};