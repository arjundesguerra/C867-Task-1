#include <iostream>
#include <vector>
#include <sstream>
#include "roster.hpp"

int main() {
    std::cout << "Course Title: C867 Scripting and Programming - Applications" << std::endl;
    std::cout << "Programming Language Used: C++" << std::endl;
    std::cout << "WGU Student ID: 010801965" << std::endl;
    std::cout << "Name: Arjun Esguerra" << std::endl;
    
    const std::string studentData[] = {
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Arjun,Esguerra,aesgue5@wgu.edu,20,19,24,14,SOFTWARE"};
    
    Roster classRoster;
     
     for (const std::string& data : studentData) {
     std::istringstream iss(data);
     std::vector<std::string> tokens;
     std::string token;
     
     while (std::getline(iss, token, ',')) {
     tokens.push_back(token);
     }
     
     DegreeProgram degreeProgram;
     
     if (tokens[8] == "SECURITY") {
     degreeProgram = DegreeProgram::SECURITY;
     } else if (tokens[8] == "NETWORK") {
     degreeProgram = DegreeProgram::NETWORK;
     } else if (tokens[8] == "SOFTWARE") {
     degreeProgram = DegreeProgram::SOFTWARE;
     } else {
         degreeProgram = DegreeProgram::NONE;
     }
     
     classRoster.add(tokens[0], tokens[1], tokens[2], tokens[3], std::stoi(tokens[4]), std::stoi(tokens[5]), std::stoi(tokens[6]), std::stoi(tokens[7]), degreeProgram);
     }
     
    std::cout << std::endl << "Printing all student data:\n";
     classRoster.printAll();
      
     
     std::cout << std::endl << "Printing invalid email addresses:\n";
     classRoster.printInvalidEmails();
     
     for (int i = 0; i < 5; i++) {
     std::string studentId = classRoster.classRosterArray[i]->getStudentID();
     classRoster.printAverageDaysInCourse(studentId);
     }
     
     std::cout << std::endl << "Printing student data for software degree program:\n";
     classRoster.printByDegreeProgram(DegreeProgram::SOFTWARE);
     
     std::cout << std::endl << "Removing student with ID A3\n";
     classRoster.remove("A3");
     
     std::cout << std::endl << "Printing all student data after removing student:\n";
     classRoster.printAll();
     
    std::cout << std::endl << "Removing student with ID A3\n";
    classRoster.remove("A3");
     
     };
     
