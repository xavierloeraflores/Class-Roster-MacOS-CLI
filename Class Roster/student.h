//
//  student.h
//  Class Roster
//
//  Created by Xavier Loera Flores on 5/3/23.
//

#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
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
        int daysToCompleteCourses[3];
        DegreeProgram degreeProgram;
    public:
        Student(string _studentID, string _firstName, string _lastName, string _email, int _age, int _daysToCompleteCourses[], DegreeProgram _degreeProgram);
        string getStudentID();
        string getFirstName();
        string getLastName();
        string getEmail();
        int getAge();
        int * getDaysToCompleteCoursesPointer();
        int getDaysToCompleteCourse(int index);
        DegreeProgram getDegreeProgram();
        void setStudentID(string _studentID);
        void setFirstName(string _firstName);
        void setLastName(string _lastName);
        void setEmail(string _email);
        void setAge(int _age);
        void setDaysToCompleteCourses(int _daysToCompleteCourses[]);
        void setDaysToCompleteACourse(int _daysToCompleteCourse, int index);
        void setDegreeProgram(DegreeProgram _degreeProgram);
        void print();
};
#endif
