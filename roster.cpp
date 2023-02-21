#include <iostream>
#include <string>
#include "roster.hpp"

Roster::Roster() {}
Roster::~Roster() {
    for (int i = 0; i < 5; i++) {
        delete classRosterArray[i];
        classRosterArray[i] = nullptr;
    }
}

void Roster::add(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {
    
    std::array<int, 3> days = { daysInCourse1, daysInCourse2, daysInCourse3 };
    
    for (int i = 0 ; i < 5; i++) {
        if (classRosterArray[i] == nullptr) {
            classRosterArray[i] = new Student(studentID, firstName, lastName, emailAddress, age, days, degreeProgram);
        }
    }
    
};

void Roster::remove(std::string studentID) {
    bool found = false;
    for (int i = 0; i < 5; i++) {
        Student* student = classRosterArray[i];
        if (student != nullptr && student->getStudentID() == studentID) {
            delete student;
            classRosterArray[i] = nullptr;
            found = true;
        }
        if (!found) {
            std::cout << "Student " << studentID << "not found" << std::endl;
        }
    }
};

void Roster::printAll() {
    for (int i = 0; i < 5; i++) {
        Student* student = classRosterArray[i];
        if (student != nullptr) {
            student->print();
        }
    }
};

void Roster::printAverageDaysInCourse(std::string studentID) {
    int totalDays = 0;
    int completedCourses = 0;
    
    for (int i = 0; i < 5; i++) {
        if (classRosterArray[i]->getStudentID() == studentID) {
            auto days = classRosterArray[i]->getDaysToComplete();
            totalDays = days[0] + days[1] + days[2];
            completedCourses = 3;
        }
    }
    if (completedCourses > 0) {
        float averageDays = (float)totalDays / (float)completedCourses;
        std::cout << "Student " << studentID << " has an average of " << averageDays << " days in each course over the last three courses." << std::endl;
    }   
    else {
        std::cout << "Error: Student " << studentID << " not found in roster." << std::endl;
    }
};

void Roster::printInvalidEmails() {
    bool anyInvalidEmails = false;
    for (int i = 0; i < 5; i++) {
        Student* student = classRosterArray[i];
        if (student != nullptr) {
            std::string emailAddress = student->getEmail();
            if (emailAddress.find(' ') != std::string::npos || emailAddress.find('@') == std::string::npos || emailAddress.find('.') == std::string::npos) {
                anyInvalidEmails = true;
                std::cout << emailAddress << " is an invalid email address for student " << student->getStudentID() << std::endl;
            }
        }
    }
    if (!anyInvalidEmails) {
        std::cout << "All student email addresses are valid." << std::endl;
    }
};

void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
    for (int i = 0; i < 5; i++) {
        Student* student = classRosterArray[i];
        if (student != nullptr && student->getDegreeProgram() == degreeProgram) {
            student->print();
        }
    }
};







