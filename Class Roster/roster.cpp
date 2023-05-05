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
Roster::~Roster(){
    cout << "Roster Destructor" << endl;
    for(int i = 0; i < 5; i++){
        delete classRosterArray[i];
    }
}


void Roster::parse(const string* studentData){
    for(int i = 0; i < 5; i++){
        string studentString = studentData[i];
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

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram){
    int daysInCourse[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };
    Student *student = new Student(studentID, firstName, lastName,  emailAddress, age, daysInCourse,degreeProgram);
    
    int i = 0;
    bool setStudent = false;
    while(!setStudent && i<5){
        if(classRosterArray[i] == nullptr){
            classRosterArray[i] = student;
            setStudent = true;
        }
        else{
            i++;
        }
    }
    
};

void Roster::remove(string studentID){
    bool found = false;
    cout << "A call has been made to remove(): " << studentID << endl;
    for (int i = 0; i < 5; i ++){
        if(classRosterArray[i]!=nullptr){
            string _studentID = classRosterArray[i] -> GetStudentID();
            if(_studentID == studentID){
                found = true;
                cout << "Found & Removing: "<< studentID<<endl;
                delete classRosterArray[i];
                classRosterArray[i] = nullptr;
                for (int j = i; j < 4; ++j){
                    classRosterArray[j] = classRosterArray[j + 1];
                }
            }
        }
    }
    if(found){
        classRosterArray[4] = nullptr;
    }
    
    if(!found){
        cout << "Error: Student with studentID:" << studentID << " not found." << endl;;
    }
    
}

void Roster::printAll(){
    cout << "A call to the printAll() function has been made"<<endl;;
    for(int i = 0; i < 5; i++){
        if(classRosterArray[i] != nullptr){
            classRosterArray[i] -> print();
        }
        else{
            cout << "Null Pointer in classRosterArray at index:" << i <<""<< endl;
        }
        
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
    cout << studentID << " Average: " <<solution<<endl;
}

void Roster::printInvalidEmails(){
    cout << "Invalid Emails: " << endl;
    for(int i = 0; i < 5; i++){
        string email = classRosterArray[i] -> GetEmailAddress();
        bool invalid = false;
        if(email.find(" ")){
            invalid = true;
        }
        if (!email.find(".")){
            invalid = true;
        }
        if(!email.find("@")){
            invalid = true;
        }
        
        if (invalid ){
            cout << email<< endl;;
        }
    }
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram){
    for(int i = 0; i < 5; i++){
        DegreeProgram _degreeProgram = classRosterArray[i] -> GetDegreeProgram();
        if (_degreeProgram == degreeProgram ){
            classRosterArray[i] -> print();
        }
    }
}

