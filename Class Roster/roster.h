//
//  roster.h
//  Class Roster
//
//  Created by Xavier Loera Flores on 5/3/23.
//

#ifndef ROSTER_H
#define ROSTER_H
#include "degree.h"
#include "student.h"

using namespace std;

class Roster {
    private:
//        Student *classRosterArray[5];  
    public:
        Student *classRosterArray[5] = {nullptr};
        Roster ();
        void parse(string studentData);
        void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);
        void remove(string studentID);
        void printAll();
        void printAverageDaysInCourse(string studentID);
        void printInvalidEmails();
        void printByDegreeProgram(DegreeProgram degreeProgram);
};
#endif
