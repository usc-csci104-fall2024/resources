#include "Schedule.h"
#include "gtest/gtest.h"

using namespace std;

class ScheduleTest : public testing::Test {
protected:
	Schedule* s;
	Assignment* a1;
	Course* c;
	Course* c2;

	ScheduleTest() {
		s = new Schedule("Tommy Trojan");
		a1 = new Essay();
		c = new Course();
 		c->setCourseName("Theory of Computation");
 		c2 = new Course();
 		c2->setCourseName("Programming Languages");
	}

	virtual ~ScheduleTest() {
		delete s;
		delete a1;
		delete c;
		delete c2;	
	}
};

TEST_F(ScheduleTest, TypeCheck) {
	EXPECT_EQ("Essay", a1->getType());
}

TEST_F(ScheduleTest, AddCourse) {
	
 	if (!s->addCourse(c)) { // should be able to add
 		FAIL();
 	}

 	if (s->addCourse(c)) { // should not be able to add again
 		FAIL();
 	}

 	EXPECT_EQ(1, s->getCourses().size());
}

TEST_F(ScheduleTest, DropCourse) {

 	s->addCourse(c);

 	if (s->dropCourse(c2->getCourseName())) { // should not be able to drop yet
 		FAIL();
 	}

 	s->addCourse(c2);

 	EXPECT_EQ(2, s->getCourses().size());

 	if (!s->dropCourse(c2->getCourseName())) { // should be able to drop now
 		FAIL();
 	}

 	EXPECT_EQ(1, s->getCourses().size());
}

TEST_F(ScheduleTest, Printing) {

 	Assignment* a1 = new Essay();
	a1->setName("On LR(k) grammars and languages");
	a1->complete();
	Assignment* a2 = new Exam();
	a2->setName("Midterm 1");
	Assignment* a3 = new Homework();
	a3->setName("Problem Set 3");
	a3->complete();

	c->addAssignment(a1);
	c->addAssignment(a2);
	c->addAssignment(a3);

	s->addCourse(c);

	Assignment* a4 = new Exam();
	a4->setName("Midterm 1");
	Assignment* a5 = new Exam();
	a5->setName("Midterm 2");
	Assignment* a6 = new Homework();
	a6->setName("Project 1");
	a6->complete();

	c2->addAssignment(a4);
	c2->addAssignment(a5);
	c2->addAssignment(a6);

	s->addCourse(c2);

	s->printAllAssignments();

	// delete assignments
	delete a1;
	delete a2;
	delete a3;
	delete a4;
	delete a5;
	delete a6;
}
