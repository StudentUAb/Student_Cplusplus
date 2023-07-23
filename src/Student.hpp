#pragma once
// C++ Standard Library
//Include Files
#include <iostream>
#include <string>

//Student class declaration
class Student {
    //Public methods
    public:
        //Student constructor
        explicit Student(const std::string &name);
        //Student method to print the student name
        void SetName(const std::string &name);
        //Student method to get the student name
        const std::string GetName() const;
    //Private data members
    private:
        std::string name_;
};
//Student method to print the student name
std::ostream &operator<<(std::ostream &os, const Student &other);
