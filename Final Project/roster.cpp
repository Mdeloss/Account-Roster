#include <iostream>
#include <string>
#include <sstream>
#include <ctype.h>
using namespace std;
#include "roster.h"

// Add method stays untouched
void Roster::add(string studentID, string firstName, string lastName, string emailAddress,
	int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram)
{
	int daysLeftArray[] = { daysInCourse1, daysInCourse2, daysInCourse3 };

	classRosterArray[++addPosition] = new Student(studentID, firstName, lastName, emailAddress,
		age, daysLeftArray, degreeprogram);


}

//Print all function
void Roster::printAll()
{
	int i = 0;
		classRosterArray[i]->print();

}
void Roster::parse1(string row)
{
	Roster classRoster;
	string studentString = row;
	
	    // Working parse with vector and add function
		vector<string> st;
		stringstream studentStream(studentString);
		while (studentStream.good()) // length of characters
		{
			string substr;
			getline(studentStream, substr, ',');
			st.push_back(substr); // back of vector
		}

		DegreeProgram degreeProgram = DegreeProgram::NETWORK;
		if (st.at(8).back() == 'Y')
			degreeProgram = DegreeProgram::SECURITY;
		if (st.at(8).back() == 'E')
			degreeProgram = DegreeProgram::SOFTWARE;
		int tempAge = 0;
		tempAge = stoi(st.at(4));
		int* tempArray = new int[3];
		tempArray[0] = stoi(st.at(5));
		tempArray[1] = stoi(st.at(6));
		tempArray[2] = stoi(st.at(7));

		
		classRoster.add(st.at(0), st.at(1), st.at(2), st.at(3), stoi(st.at(4)), stoi(st.at(5)), stoi(st.at(6)), stoi(st.at(7)), degreeProgram);

		   classRoster.printAll();

}

//Print average days left function
void Roster::printAverageDaysInCourse(string studentID)
{
	cout << "Average days left for " << studentID << ":\t";
	int i = 0;
		if (classRosterArray[i]->getStudentID() == studentID)
		{
			cout << ((double)classRosterArray[i]->getDaysLeftArray()[0]
				+ (double)classRosterArray[i]->getDaysLeftArray()[1]
				+ (double)classRosterArray[i]->getDaysLeftArray()[2]) / 3.0 << " days" << endl;
		}

}
void Roster::parse2(string row)
{
	Roster classRoster;
	string studentString = row;

	// Working parse with vector and add function
	vector<string> st;
	stringstream studentStream(studentString);
	while (studentStream.good()) // length of characters
	{
		string substr;
		getline(studentStream, substr, ',');
		st.push_back(substr); // back of vector
	}

	DegreeProgram degreeProgram = DegreeProgram::NETWORK;
	if (st.at(8).back() == 'Y')
		degreeProgram = DegreeProgram::SECURITY;
	if (st.at(8).back() == 'E')
		degreeProgram = DegreeProgram::SOFTWARE;
	int tempAge = 0;
	tempAge = stoi(st.at(4));
	int* tempArray = new int[3];
	tempArray[0] = stoi(st.at(5));
	tempArray[1] = stoi(st.at(6));
	tempArray[2] = stoi(st.at(7));


	classRoster.add(st.at(0), st.at(1), st.at(2), st.at(3), stoi(st.at(4)), stoi(st.at(5)), stoi(st.at(6)), stoi(st.at(7)), degreeProgram);

	int i = 0;
		classRoster.printAverageDaysInCourse(classRoster.classRosterArray[i]->getStudentID());
}

// Print invalid emails function
void Roster::printInvalidEmails()
{
	bool found = true;
	int i = 0;
	string email = (classRosterArray[i]->getEmail());
	int length = email.length();

	for (i = 0; i < length; ++i)
	{
		if (email.at(i) == '.')
		{
		 break;
		}
		else 
		{
			if (email.at(i) == email.at(length - 1))
			{
				cout << "Invalid email address: " << email << endl;
				break;
			}
		}
	}
	i = 0;
	for (i = 0; i < length; ++i)
	{
		if (email.at(i) == '@')
		{
			break;
		}
		else
		{
			if (email.at(i) == email.at(length - 1))
			{
				cout << "Invalid email address: " << email << endl;
				break;
			}
		}
	}
	i = 0;
			for (i = 0; i < length; ++i)
			{
				if (email.at(i) == ' ')
				{
					cout << "Invalid email address: " << email << endl;
					break;
				}
				else
				{
					if (email.at(i) == email.at(length - 1))
					{
						break;
					}
				}
	
	}
	

}
void Roster::parse3(string row)
{
	Roster classRoster;
	string studentString = row;

	// Working parse with vector and add function
	vector<string> st;
	stringstream studentStream(studentString);
	while (studentStream.good()) // length of characters
	{
		string substr;
		getline(studentStream, substr, ',');
		st.push_back(substr); // back of vector
	}

	DegreeProgram degreeProgram = DegreeProgram::NETWORK;
	if (st.at(8).back() == 'Y')
		degreeProgram = DegreeProgram::SECURITY;
	if (st.at(8).back() == 'E')
		degreeProgram = DegreeProgram::SOFTWARE;
	int tempAge = 0;
	tempAge = stoi(st.at(4));
	int* tempArray = new int[3];
	tempArray[0] = stoi(st.at(5));
	tempArray[1] = stoi(st.at(6));
	tempArray[2] = stoi(st.at(7));


	classRoster.add(st.at(0), st.at(1), st.at(2), st.at(3), stoi(st.at(4)), stoi(st.at(5)), stoi(st.at(6)), stoi(st.at(7)), degreeProgram);

	classRoster.printInvalidEmails();
}

// Print by degree function
void Roster::printByDegreeProgram(DegreeProgram degreeProgram)
{
	int i = 0;
	if (classRosterArray[i]->getDegreeProgram() == degreeProgram)
	{
		classRosterArray[i]->print();
	}
}

// Security Degree
void Roster::parse4S(string row)
{
	Roster classRoster;
	string studentString = row;

	// Working parse with vector and add function
	vector<string> st;
	stringstream studentStream(studentString);
	while (studentStream.good()) // length of characters
	{
		string substr;
		getline(studentStream, substr, ',');
		st.push_back(substr); // back of vector
	}

	DegreeProgram degreeProgram = DegreeProgram::NETWORK;
	if (st.at(8).back() == 'Y')
		degreeProgram = DegreeProgram::SECURITY;
	if (st.at(8).back() == 'E')
		degreeProgram = DegreeProgram::SOFTWARE;
	int tempAge = 0;
	tempAge = stoi(st.at(4));
	int* tempArray = new int[3];
	tempArray[0] = stoi(st.at(5));
	tempArray[1] = stoi(st.at(6));
	tempArray[2] = stoi(st.at(7));


	classRoster.add(st.at(0), st.at(1), st.at(2), st.at(3), stoi(st.at(4)), stoi(st.at(5)), stoi(st.at(6)), stoi(st.at(7)), degreeProgram);

	classRoster.printByDegreeProgram(DegreeProgram::SECURITY);

}

// Software Degree
void Roster::parse4SO(string row)
{
	Roster classRoster;
	string studentString = row;

	// Working parse with vector and add function
	vector<string> st;
	stringstream studentStream(studentString);
	while (studentStream.good()) // length of characters
	{
		string substr;
		getline(studentStream, substr, ',');
		st.push_back(substr); // back of vector
	}

	DegreeProgram degreeProgram = DegreeProgram::NETWORK;
	if (st.at(8).back() == 'Y')
		degreeProgram = DegreeProgram::SECURITY;
	if (st.at(8).back() == 'E')
		degreeProgram = DegreeProgram::SOFTWARE;
	int tempAge = 0;
	tempAge = stoi(st.at(4));
	int* tempArray = new int[3];
	tempArray[0] = stoi(st.at(5));
	tempArray[1] = stoi(st.at(6));
	tempArray[2] = stoi(st.at(7));


	classRoster.add(st.at(0), st.at(1), st.at(2), st.at(3), stoi(st.at(4)), stoi(st.at(5)), stoi(st.at(6)), stoi(st.at(7)), degreeProgram);

	classRoster.printByDegreeProgram(DegreeProgram::SOFTWARE);

}

// Network Degree
void Roster::parse4N(string row)
{
	Roster classRoster;
	string studentString = row;

	// Working parse with vector and add function
	vector<string> st;
	stringstream studentStream(studentString);
	while (studentStream.good()) // length of characters
	{
		string substr;
		getline(studentStream, substr, ',');
		st.push_back(substr); // back of vector
	}

	DegreeProgram degreeProgram = DegreeProgram::NETWORK;
	if (st.at(8).back() == 'Y')
		degreeProgram = DegreeProgram::SECURITY;
	if (st.at(8).back() == 'E')
		degreeProgram = DegreeProgram::SOFTWARE;
	int tempAge = 0;
	tempAge = stoi(st.at(4));
	int* tempArray = new int[3];
	tempArray[0] = stoi(st.at(5));
	tempArray[1] = stoi(st.at(6));
	tempArray[2] = stoi(st.at(7));


	classRoster.add(st.at(0), st.at(1), st.at(2), st.at(3), stoi(st.at(4)), stoi(st.at(5)), stoi(st.at(6)), stoi(st.at(7)), degreeProgram);

	classRoster.printByDegreeProgram(DegreeProgram::NETWORK);

}


// Remove student function
void Roster::remove(string studentID)
{
	bool found = false;
	for (int i = 0; i <= addPosition; i++)
	{
		if (classRosterArray[i]->getStudentID() == studentID)
		{
			found = true; // if found
			{
				Student* temp = classRosterArray[i]; // swap with last student
				classRosterArray[i] = classRosterArray[addPosition];
				classRosterArray[numStudents - 1] = temp;
				cout << studentID << " has been removed from roster. \n";
				addPosition--;
			}
		}
	}
	if (!found)
		cout << "Student: " << studentID << " not found. \n";

}



Roster::~Roster()
{
	//DESTRUCTOR CALLED 
	for (int i = 0; i < numStudents; i++)
	{
		delete classRosterArray[i];
		classRosterArray[i] = nullptr;
	} 
}