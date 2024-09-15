#include <string>

class Assignment {

public:
	Assignment();
	virtual ~Assignment();
	void setName(std::string name);
	std::string getName();
	double getPoints();
	int getTotalPoints();
	void setPoints(double points);
	void setTotalPoints(int totalPoints);
	bool isComplete();
	void complete();
	std::string getType();

private:
	std::string mName;
	double mPoints;
	int mTotalPoints;
	bool mComplete;
	int mPriority;
};

class Essay : public Assignment {

public:
	std::string getType();
	std::string getPrompt();
private:
	std::string mPrompt;
};

class Exam : public Assignment {

public:
	std::string getType();
};	

class Homework : public Assignment {

public:
	std::string getType();
};	