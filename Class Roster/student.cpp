//
//  student.cpp
//  Class Roster
//
//  Created by Xavier Loera Flores on 5/3/23.
//
#include <iostream>
#include <string>
#include "student.h"

using namespace std;


    Student::Student(string _studentID, string _firstName, string _lastName, string _email, int _age, int _daysToCompleteCourses[], DegreeProgram _degreeProgram){
        studentID = _studentID;
        firstName = _firstName;
        lastName =  _lastName;
        email = _email;
        age = _age;
        degreeProgram = _degreeProgram;
        for (int i = 0; i < 3; i++){
            daysToCompleteCourses[i] = _daysToCompleteCourses[i];
        }
        
    };
    string Student::getStudentID(){
        return studentID;
    };
    string Student::getFirstName(){
        return firstName;
    };
    string Student::getLastName(){
        return lastName;
    };
    string Student::getEmail(){
        return email;
    };
    int Student::getAge(){
        return age;
    };
    // Returns a pointer to the daysToCompleteCourses array
    int * Student::getDaysToCompleteCoursesPointer(){
        return daysToCompleteCourses;
    };
    // Returns an integer to the number of days to complete a course for a specific day
    int Student::getDaysToCompleteCourse(int index){
        if( index>2 || index<0 ){
            return -1;
        };
        return daysToCompleteCourses[index];
    };
    DegreeProgram Student::getDegreeProgram(){
        return degreeProgram;
    };
    void Student::setStudentID(string _studentID){
        studentID = _studentID;
    };
    void Student::setFirstName(string _firstName){
        firstName = _firstName;
    };
    void Student::setLastName(string _lastName){
        lastName = _lastName;
    };
    void Student::setEmail(string _email){
        email = _email;
    };
    void Student::setAge(int _age){
        age = _age;
    };
    void Student::setDaysToCompleteCourses(int _daysToCompleteCourses[]){
        for (int i = 0; i < 3; i++){
            daysToCompleteCourses[i] = _daysToCompleteCourses[i];
        }
    };
    void Student::setDaysToCompleteACourse(int _daysToCompleteCourse, int index){
        if( index<=2 && index>=0 ){
            daysToCompleteCourses[index] = _daysToCompleteCourse;
        };
    };
    void Student::setDegreeProgram(DegreeProgram _degreeProgram){
        degreeProgram = _degreeProgram;
    };
    void Student::print(){
        cout << "hello";
    };
    
    
    

