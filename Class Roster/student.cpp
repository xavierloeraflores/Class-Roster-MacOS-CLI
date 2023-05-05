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


    Student::Student(string _studentID, string _firstName, string _lastName, string _email, int _age, int _daysInCourse[], DegreeProgram _degreeProgram){
        studentID = _studentID;
        firstName = _firstName;
        lastName =  _lastName;
        email = _email;
        age = _age;
        degreeProgram = _degreeProgram;
        for (int i = 0; i < 3; i++){
            daysInCourse[i] = _daysInCourse[i];
        }
        
    };
    string Student::GetStudentID(){
        return studentID;
    };
    string Student::GetFirstName(){
        return firstName;
    };
    string Student::GetLastName(){
        return lastName;
    };
    string Student::GetEmailAddress(){
        return email;
    };
    int Student::GetAge(){
        return age;
    };
    int * Student::GetDaysInCoursePointer(){
        return daysInCourse;
    };
    int Student::GetDaysInCourse(int index){
        if( index>2 || index<0 ){
            return -1;
        };
        return daysInCourse[index];
    };
    DegreeProgram Student::GetDegreeProgram(){
        return degreeProgram;
    };
    void Student::SetStudentID(string _studentID){
        studentID = _studentID;
    };
    void Student::SetFirstName(string _firstName){
        firstName = _firstName;
    };
    void Student::SetLastName(string _lastName){
        lastName = _lastName;
    };
    void Student::SetEmailAddress(string _email){
        email = _email;
    };
    void Student::SetAge(int _age){
        age = _age;
    };
    void Student::SetDaysInCourse(int _daysInCourse[]){
        for (int i = 0; i < 3; i++){
            daysInCourse[i] = _daysInCourse[i];
        }
    };
    void Student::SetDaysInCourse(int _daysInCourse, int index){
        if( index<=2 && index>=0 ){
            daysInCourse[index] = _daysInCourse;
        };
    };
    void Student::SetDegreeProgram(DegreeProgram _degreeProgram){
        degreeProgram = _degreeProgram;
    };
    void Student::print(){
        cout << studentID << "\tFirst Name: "<< firstName<<"\tLast Name: " << lastName <<"\t\tAge: "<< age << "\t";
        cout <<"daysInCourse: " <<"{"<<daysInCourse[0]<<"," <<daysInCourse[1] << ","<<daysInCourse[2]<<"} \t";
        if (degreeProgram == SOFTWARE){
            cout << "Degree Program: SOFTWARE" << endl;
        }else if(degreeProgram == NETWORK){
            cout << "Degree Program: NETWORK" << endl;
        }else if ( degreeProgram == SECURITY){
            cout << "Degree Program: SECURITY" << endl;
        }else{
            cout << "Degree Program: None" << endl;
        }
        
    };
    
    
    

