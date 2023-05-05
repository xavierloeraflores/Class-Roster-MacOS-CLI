//
//  main.cpp
//  Class Roster
//
//  Created by Xavier Loera Flores on 5/2/23.
//

#include <iostream>
#include "roster.h"

using namespace std;

int main(int argc, const char * argv[]) {
    
    cout << "Scripting and Programming - Applications - C867" <<endl;
    cout << "C++" << endl;
    cout << "011037676" << endl;
    cout << "Xavier Loera Flores" << endl;

    
    const string studentData[] = {
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Xavier,Loera Flores,xavier@loeraflores.tech,23,5,7,15,SOFTWARE"
    };
    
    
    
    Roster classRoster(studentData);
    
    classRoster.printAll();
    classRoster.printInvalidEmails();
    
    //loop through classRosterArray and for each element:
    for(int i = 0; i<5; i++){
        string studentID = classRoster.classRosterArray[i] ->GetStudentID();
        classRoster.printAverageDaysInCourse(studentID);
    }
    
    classRoster.printByDegreeProgram(SOFTWARE);
    classRoster.remove("A3");
    classRoster.printAll();
    classRoster.remove("A3");
    
    
    
    return 0;
}
