#include <iostream>
#include <string>
using namespace std;
#include "student.h"


// Default constructor
Student::Student()
{
	studentID = "none";
	FirstName = "none";
	LastName = "none";
	Email = "none";
	Age = 0;
	daysLeftArray[0] = 0;
	daysLeftArray[1] = 0;
	daysLeftArray[2] = 0;
	DegreeProgram degreeProgram = DegreeProgram::SOFTWARE;
};

// second constructor
Student::Student(string studentID, string FirstName, string LastName, string Email,
	int Age, int daysLeftArray[daySizeArray], DegreeProgram degreeProgram)
{
	this->studentID = studentID;
	this->FirstName = FirstName;
	this->LastName = LastName;
	this->Email = Email;
	this->Age = Age;
	this->daysLeftArray[0] = daysLeftArray[0];
	this->daysLeftArray[1] = daysLeftArray[1];
	this->daysLeftArray[2] = daysLeftArray[2];
	this->degreeProgram = degreeProgram;
};

// destructor here
Student::~Student() {}

// setters are here
void Student::setStudentID(string studentID) { this->studentID = studentID; }
void Student::setFirstName(string FirstName) { this->FirstName = FirstName; }
void Student::setLastName(string LastName) { this->LastName = LastName; }
void Student::setEmail(string Email) { this->Email = Email; }
void Student::setAge(int Age) { this->Age = Age; }
void Student::setDaysLeftArray(int daysLeftArray[daySizeArray]) {
	this->daysLeftArray[0] = daysLeftArray[0];
	this->daysLeftArray[1] = daysLeftArray[1];
	this->daysLeftArray[2] = daysLeftArray[2];;
}
void Student::setDegreeProgram(DegreeProgram degreeProgram) { this->degreeProgram = degreeProgram; }

// Getters are here
string Student::getStudentID() { return studentID; }
string Student::getFirstName() { return FirstName; }
string Student::getLastName() { return LastName; }
string Student::getEmail() { return Email; }
int Student::getAge() { return Age; }
int* Student::getDaysLeftArray() { return daysLeftArray; } // Array cannot be returned, Return as pointer
DegreeProgram Student::getDegreeProgram() { return  degreeProgram; }

// Print objects here
void Student::print()
{

	cout << "ID: " << studentID << '\t';
	cout << "F:" << FirstName << '\t';
	cout << "L:" << LastName << '\t';
	cout << "E:" << Email << '\t';
	cout << "A:" << Age << '\t';
	cout << "DAYS:" << daysLeftArray[0] << ',';
	cout << daysLeftArray[1] << ',';
	cout << daysLeftArray[2] << ',' << '\t';
	cout << "DEGREE:" << DegreeProgramName[(int)degreeProgram] << endl;

}
