#pragma once
#include <vector>
#include "student.h"
using namespace std;


class Roster
{
public:
	// Array of pointers
	const static int numStudents = 5;
	Student* classRosterArray[numStudents] = {};

	// To hold data
	void add(string studentID, string firstName, string lastName, string emailAddress,
		int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram);

	void printAll();
	void parse1(string row);

	void printAverageDaysInCourse(string studentID);
	void parse2(string row);

	void printInvalidEmails();
	void parse3(string row);

	void printByDegreeProgram(DegreeProgram degreeProgram); 
	void parse4S(string row); // SECURITY
	void parse4SO(string row); // SOFTWARE
	void parse4N(string row); // NETWORK

	void remove(string studentID);
	void parse5(string row);
	
	~Roster();

private:
	int addPosition = -1;
	vector<string> parsedStudentInfo;
}; 