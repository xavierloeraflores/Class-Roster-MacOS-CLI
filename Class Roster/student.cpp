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
    Student(string _studentID, string _firstName, string _lastName, string _email, int _age, array<int, 3>& _daysToCompleteCourses, DegreeProgram _degreeProgram){
        studentID = _studentID;
        firstName = _firstName;
        lastName =  _lastName;
        email = _email;
        age = _age;
        degreeProgram = _degreeProgram;
        for (int i = 0; i < 3; i++){
            daysToCompleteCourses[i] = _daysToCompleteCourses[i];
        }
        
    }
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
    DegreeProgram getDegreeProgram(){
        return degreeProgram;
    }
    void setStudentID(string _studentID){
        studentID = _studentID;
    }
    void setFirstName(string _firstName){
        firstName = _firstName;
    }
    void setLastName(string _lastName){
        lastName = _lastName;
    }
    void setEmail(string _email){
        email = _email;
    }
    void setAge(int _age){
        age = _age;
    }
    void setDaysToCompleteCourses(array<int, 3>& _daysToCompleteCourses){
        for (int i = 0; i < 3; i++){
            daysToCompleteCourses[i] = _daysToCompleteCourses[i];
        }
    }
    void setDaysToCompleteACourse(int _daysToCompleteCourse, int index){
        if( index<=2 && index>=0 ){
            daysToCompleteCourses[index] = _daysToCompleteCourse;
        };
    }
    void setDegreeProgram(DegreeProgram _degreeProgram){
        degreeProgram = _degreeProgram;
    }
    
    
    
    
    
    
};
