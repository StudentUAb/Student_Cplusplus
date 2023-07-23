//Include Files
#include "Student.hpp"

//Student method to print the student name
std::ostream &operator<<(std::ostream &os, const Student &other) { //Overload the << operator for the Student class 
    os << other.GetName(); //Print the student name
    return os; //Return the output stream
}

//Student constructor
Student::Student(const std::string &name) : name_{name} {
    //Empty
}

//Setters and Getters

//Student method to set the student name
void Student::SetName(const std::string &name) {
    name_ = name; //Set the student name
}

//Student method to get the student name
const std::string Student::GetName() const {
    return name_; //Return the student name
}

