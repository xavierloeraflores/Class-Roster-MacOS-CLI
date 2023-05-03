//
//  student.cpp
//  Class Roster
//
//  Created by Xavier Loera Flores on 5/3/23.
//
#include <string>
#include "student.h"
#include "degree.h"

using namespace std;

class Student {
private:
    string studentID;
    string firstName;
    string lastName;
    string email;
    int age;
    int daysToCompleteCourse[3];
    DegreeProgram degreeProgram;
};
