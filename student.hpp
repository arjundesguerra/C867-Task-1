#include <string>
#include <array>
#include "degree.h"

class Student {
public:
    // constructor
    Student(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress,
            int age, std::array<int, 3> daysToComplete, DegreeProgram degreeProgram);
    // getter methods
    std::string getStudentID();
    std::string getFirstName();
    std::string getLastName();
    std::string getEmail();
    int getAge();
    std::array<int, 3> getDaysToComplete();
    DegreeProgram getDegreeProgram();
    
    // setter methods
    void setStudentID(std::string studentID);
    void setFirstName(std::string firstName);
    void setLastName(std::string lastName);
    void setEmail(std::string emailAddress);
    void setAge(int age);
    void setDaysToComplete(std::array<int, 3> daysToComplete);
    void setDegreeProgram(DegreeProgram degreeProgram);
    
    // other methods
    void print() const;
    
private:
    std::string studentID;
    std::string firstName;
    std::string lastName;
    std::string emailAddress;
    int age;
    std::array<int, 3> daysToComplete;
    DegreeProgram degreeProgram;
    
};
