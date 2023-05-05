//
//  roster.cpp
//  Class Roster
//
//  Created by Xavier Loera Flores on 5/3/23.
//

#include <stdio.h>
#include <iostream>
#include <string>
#include "roster.h"
#include "student.h"

using namespace std;

Roster::Roster(){
    
}

Roster::Roster(const string* studentData){
    for(int i = 0; i < 5; i++){
        string studentString = studentData[i];
        size_t leftPos = 0;
        size_t rightPos = 1;
        size_t difference = rightPos - leftPos;
        //"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        
        
        //Parse studentID
        rightPos = studentString.find(',', leftPos);
        difference = rightPos - leftPos;
        string studentID = studentString.substr(leftPos, difference);
        //Parse firstName
        leftPos = rightPos+1;
        rightPos = studentString.find(',', leftPos);
        difference = rightPos - leftPos;
        string firstName = studentString.substr(leftPos, difference);
        
        //Parse lastName
        leftPos = rightPos+1;
        rightPos = studentString.find(',', leftPos);
        difference = rightPos - leftPos;
        string lastName = studentString.substr(leftPos, difference);
        
        //Parse email
        leftPos = rightPos+1;
        rightPos = studentString.find(',', leftPos);
        difference = rightPos - leftPos;
        string email = studentString.substr(leftPos, difference);
        
        //Parse age
        leftPos = rightPos+1;
        rightPos = studentString.find(',', leftPos);
        difference = rightPos - leftPos;
        int age = stoi(studentString.substr(leftPos, difference));
        
        //Parse daysInCourse1
        leftPos = rightPos+1;
        rightPos = studentString.find(',', leftPos);
        difference = rightPos - leftPos;
        int daysInCourse1 = stoi(studentString.substr(leftPos, difference));
        
        //Parse daysInCourse2
        leftPos = rightPos+1;
        rightPos = studentString.find(',', leftPos);
        difference = rightPos - leftPos;
        int daysInCourse2 = stoi(studentString.substr(leftPos, difference));
        
        //Parse daysInCourse3
        leftPos = rightPos+1;
        rightPos = studentString.find(',', leftPos);
        difference = rightPos - leftPos;
        int daysInCourse3 = stoi(studentString.substr(leftPos, difference));
        
        //Parse degreeProgram
        leftPos = rightPos+1;
        rightPos = studentString.find(',', leftPos);
        difference = rightPos - leftPos;
        string degreeProgramString = studentString.substr(leftPos, difference);
        DegreeProgram degreeProgram;
        if (degreeProgramString == "SOFTWARE") {
            degreeProgram = SOFTWARE;
        }else if (degreeProgramString == "SECURITY"){
            degreeProgram = SECURITY;
        }else if (degreeProgramString == "NETWORK"){
            degreeProgram = NETWORK;
        }else{
            degreeProgram = SOFTWARE;
        }
        add(studentID, firstName, lastName, email, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram);
    }
}

void Roster::parse(string studentData){
    string studentString = studentData;
    size_t leftPos = 0;
    size_t rightPos = 1;
    size_t difference = rightPos - leftPos;
    
    
    //Parse studentID
    rightPos = studentString.find(',', leftPos);
    difference = rightPos - leftPos;
    string studentID = studentString.substr(leftPos, difference);
    
    //Parse firstName
    leftPos = rightPos+1;
    
    rightPos = studentString.find(',', leftPos);
    difference = rightPos - leftPos;
    string firstName = studentString.substr(leftPos, difference);
    cout << firstName <<endl;
     
    
    
    //Parse lastName
    leftPos = rightPos+1;
    rightPos = studentString.find(',', leftPos);
    difference = rightPos - leftPos;
    string lastName = studentString.substr(leftPos, difference);
    cout << lastName <<endl;
    
    
    
    //Parse email
    leftPos = rightPos+1;
    rightPos = studentString.find(',', leftPos);
    difference = rightPos - leftPos;
    string email = studentString.substr(leftPos, difference);
    cout <<  email <<endl;
    
    
    //Parse age
    leftPos = rightPos+1;
    rightPos = studentString.find(',', leftPos);
    difference = rightPos - leftPos;
    int age = stoi(studentString.substr(leftPos, difference));
    cout << age <<endl;
    
    
    //Parse daysInCourse1
    leftPos = rightPos+1;
    rightPos = studentString.find(',', leftPos);
    difference = rightPos - leftPos;
    int daysInCourse1 = stoi(studentString.substr(leftPos, difference));
    cout << daysInCourse1 <<endl;
    
    //Parse daysInCourse2
    leftPos = rightPos+1;
    rightPos = studentString.find(',', leftPos);
    difference = rightPos - leftPos;
    int daysInCourse2 = stoi(studentString.substr(leftPos, difference));
    cout << daysInCourse2 <<endl;
    
    //Parse daysInCourse3
    leftPos = rightPos+1;
    rightPos = studentString.find(',', leftPos);
    difference = rightPos - leftPos;
    int daysInCourse3 = stoi(studentString.substr(leftPos, difference));
    cout << daysInCourse3 <<endl;
    
    
    //Parse degreeProgram
    leftPos = rightPos+1;
    rightPos = studentString.find(',', leftPos);
    difference = rightPos - leftPos;
    string degreeProgramString = studentString.substr(leftPos, difference);
    DegreeProgram degreeProgram;
    if (degreeProgramString == "SOFTWARE") {
        degreeProgram = SOFTWARE;
    }else if (degreeProgramString == "SECURITY"){
        degreeProgram = SECURITY;
    }else if (degreeProgramString == "NETWORK"){
        degreeProgram = NETWORK;
    }else{
        degreeProgram = SOFTWARE;
    }
    add(studentID, firstName, lastName, email, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram);
}

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram){
    
    int daysInCourse[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };
    Student student(studentID, firstName, lastName,  emailAddress, age, daysInCourse,degreeProgram);
    
};

void Roster::remove(string studentID){
    bool found = false;
    
    for (int i = 0; i < 5; i ++){
        string _studentID = classRosterArray[i] -> GetStudentID();
        if(_studentID == studentID){
            found = true;
            delete classRosterArray[i];
        }
    }
    
    
    
    if(!found){
        cout << "Error: Student with studentID:" << studentID << " not found.";
    }
    
}

void Roster::printAll(){
    for(int i = 0; i < 5; i++){
        classRosterArray[i] -> print();
    }
}

void Roster::printAverageDaysInCourse(string studentID){
    int sum = 0;
    bool found = false;
    for(int i = 0; i < 5; i++){
        string _studentID = classRosterArray[i] -> GetStudentID();
        if (_studentID == studentID ){
            found = true;
            sum += classRosterArray[i] -> GetDaysInCourse(0);
            sum += classRosterArray[i] -> GetDaysInCourse(1);
            sum += classRosterArray[i] -> GetDaysInCourse(2);
        }
    }
    if(!found){
        cout << -1;
    }
    double solution = sum / 3.0;
    cout << solution;
}

void Roster::printInvalidEmails(){
    
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram){
    for(int i = 0; i < 5; i++){
        DegreeProgram _degreeProgram = classRosterArray[i] -> GetDegreeProgram();
        if (_degreeProgram == degreeProgram ){
            classRosterArray[i] -> print();
        }
    }
}

