#include <iostream>
#include <string>
#include <sstream>
using namespace std;
  #include "roster.h"

int main()
{ 
    
    Roster classRoster;
    string classRosterArray[] =
    {
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        // Criteria for A
        "A5,Mariano,De Los Santos,mdelo17@my.wgu.edu,26,20,20,20,SOFTWARE"
    };

    // Project title and header
    cout << "Course: C867 Scripting and Programming - Applications" << endl;
    cout << "Programming Language: C++" << endl;
    cout << "Student ID: 001523416" << endl;
    cout << "Name: Mariano De Los Santos" << endl;
    cout << endl;

    // Print all function
    cout << endl;
    cout << "Displaying all students:" << endl;
    for (int i = 0; i < 5; i++) // each string
    {
        // Print all function
        classRoster.parse1(classRosterArray[i]);
    }
   
    cout << endl; // Extra line
    cout << endl; // Extra line

  // Print invalid emails function
    cout << "Displaying invalid email addresses:" << endl;
    for (int i = 0; i < 5; i++)
    {
        // Print invalid emails function
        classRoster.parse3(classRosterArray[i]);
    }

    cout << endl; // Extra line
    cout << endl; // Extra line

    // Print average course days left function
    cout << "Displaying average days left for each student ID:" << endl;
    for (int i = 0; i < 5; i++)
    {
        // Print average course days left function
        classRoster.parse2(classRosterArray[i]);
    }
    
    cout << endl; // Extra line
    cout << endl; // Extra line

    // Print by degree function
    cout << "Displaying student by degree program:" << endl;
    //cout << endl; 
    cout << "SECURITY:" << endl; // SECURITY
    for (int i = 0; i < 5; i++)
    {
        classRoster.parse4S(classRosterArray[i]);
    }
    
    cout << endl;
    cout << "SOFTWARE:" << endl; //SOFTWARE
    for (int i = 0; i < 5; i++)
    {
        classRoster.parse4SO(classRosterArray[i]);
    }

    cout << endl;
    cout << "NETWORK" << endl; //NETWORK
    for (int i = 0; i < 5; i++)
    {
        classRoster.parse4N(classRosterArray[i]);
    }

    cout << endl; // Extra line
    cout << endl; // Extra line

    // Remove student functions
    cout << "Removing student: A3" << endl;
    for (int i = 0; i < 5; i++)
    {
        vector<string> st;
        string studentString = classRosterArray[i];
        stringstream studentStream(classRosterArray[i]);
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
    }
    classRoster.remove("A3"); // Removed
    cout << endl;

    // Print all function again without "A3"
    cout << "Displaying all students:" << endl;
    for (int i = 0; i < 5; i++) // each string of student
    {
        // Skip student
        if (i == 2) {
            continue;
        }
        // Print all function
        else {
            classRoster.parse1(classRosterArray[i]);
        }
        }

    cout << endl;


    cout << "Removing student: A3" << endl;
    classRoster.remove("A3"); // Removed

    return 0;
}