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
