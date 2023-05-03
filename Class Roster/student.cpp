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
        int daysToCompleteCourses[3];
        DegreeProgram degreeProgram;
    public:
    string getStudentID(){
        return studentID;
    }
    string getFirstName(){
        return firstName;
    }
    string getLastName(){
        return lastName;
    }
    string getEmail(){
        return email;
    }
    int getAge(){
        return age;
    }
    // Returns a pointer to the daysToCompleteCourses array
    int * getDaysToCompleteCoursesPointer(){
        return daysToCompleteCourses;
    }
    // Returns an integer to the number of days to complete a course for a specific day
    int getDaysToCompleteCourse(int index){
        if( index>2 || index<0 ){
            return -1;
        };
        return daysToCompleteCourses[index];
    }
    
    
    
    
};
