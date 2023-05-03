//
//  student.h
//  Class Roster
//
//  Created by Xavier Loera Flores on 5/3/23.
//

#ifndef STUDENT_H
#define STUDENT_H
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
        string GetStudentID();
        string GetFirstName();
        string GetLastName();
        string GetEmailAddress();
        int GetAge();
        int * GetDaysToCompleteCoursesPointer();
        int GetDaysToCompleteCourse(int index);
        DegreeProgram GetDegreeProgram();
        void SetStudentID(string _studentID);
        void SetFirstName(string _firstName);
        void SetLastName(string _lastName);
        void SetEmailAddress(string _email);
        void SetAge(int _age);
        void SetDaysToCompleteCourses(int _daysToCompleteCourses[]);
        void SetDaysToCompleteACourse(int _daysToCompleteCourse, int index);
        void SetDegreeProgram(DegreeProgram _degreeProgram);
        void print();
};
#endif
