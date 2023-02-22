#ifndef roster_hpp
#define roster_hpp

#include <string>
#include "student.hpp"

class Roster {
public:
    // constructor and destructor
    Roster();
    ~Roster();
    
    void add(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);
    void remove(std::string studentID);
    void printAll();
    void printAverageDaysInCourse(std::string studentID);
    void printInvalidEmails();
    void printByDegreeProgram(DegreeProgram degreeProgram);
    Student* classRosterArray[5] = {nullptr, nullptr, nullptr, nullptr, nullptr};
    };

#endif /* roster_hpp */
