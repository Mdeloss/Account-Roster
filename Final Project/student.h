#pragma once
#include "degree.h"

class Student 
{
public:

	const static int daySizeArray = 3;

	Student(); // default constructor

	// second constructor
	Student(string studentID, string studentFirstName, string studentLastName, string studentEmailAddress,
		int studentAge, int daysLeft[daySizeArray], DegreeProgram degreeProgram);

	~Student(); // destructor

	// setters are here
	void setStudentID(string);
	void setFirstName(string);
	void setLastName(string);
	void setEmail(string);
	void setAge(int);
	void setDaysLeftArray(int[daySizeArray]);
	void setDegreeProgram(DegreeProgram);

	// getters are here
	string getStudentID();
	string getFirstName();
	string getLastName();
	string getEmail();
	int getAge();
	int* getDaysLeftArray();
	DegreeProgram getDegreeProgram();

	// prints THIS student
	void print();

private:
	string studentID = "";
	string FirstName = "";
	string LastName = "";
	string Email = "";
	int Age = 0;
	int daysLeftArray[3] = {0,0,0};
	DegreeProgram degreeProgram = DegreeProgram::SECURITY;
};