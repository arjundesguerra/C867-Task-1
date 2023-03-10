#include <iostream>
#include "student.hpp"
// constructor
Student::Student(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, std::array<int, 3> daysToComplete, DegreeProgram degreeProgram)
{
    this->studentID = studentID;
    this->firstName = firstName;
    this->lastName = lastName;
    this->emailAddress = emailAddress;
    this->age = age;
    this->daysToComplete = daysToComplete;
    this->degreeProgram = degreeProgram;
};

// getter methods
std::string Student::getStudentID() { return studentID; }
std::string Student::getFirstName() { return firstName; }
std::string Student::getLastName() { return lastName; }
std::string Student::getEmail() { return emailAddress; }
int Student::getAge() { return age; }
std::array<int, 3> Student::getDaysToComplete() { return daysToComplete; }
DegreeProgram Student::getDegreeProgram() { return degreeProgram; }

// setter methods
void Student::setStudentID(std::string studentID) { this->studentID = studentID; }
void Student::setFirstName(std::string firstName) { this->firstName = firstName; }
void Student::setLastName(std::string lastName) { this->lastName = lastName; }
void Student::setEmail(std::string emailAddress) { this->emailAddress = emailAddress; }
void Student::setAge(int age) { this->age = age; }
void Student::setDaysToComplete(std::array<int, 3> daysToComplete) { this->daysToComplete = daysToComplete; }
void Student::setDegreeProgram(DegreeProgram degreeProgram) { this->degreeProgram = degreeProgram; }

// print
void Student::print() {
    std::cout << studentID << "\t"
    << "First Name: " << firstName << "\t"
    << "Last Name: " << lastName << "\t"
    << "Age: " << age << "\t"
    << "daysInCourse: {" << daysToComplete[0] << ", " << daysToComplete[1] << ", " << daysToComplete[2] << "}" <<
    "\t" << "Degree Program: ";
    switch (degreeProgram) {
        case DegreeProgram::SECURITY:
            std::cout << "Security" << "\t";
            break;
        case DegreeProgram::NETWORK:
            std::cout << "Networking" << "\t";
            break;
        case DegreeProgram::SOFTWARE:
            std::cout << "Software" << "\t";
            break;

    }
    std::cout << std::endl;

}
