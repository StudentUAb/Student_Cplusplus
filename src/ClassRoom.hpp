#pragma once

// C++ Standard Library
//Include Files

#include <fstream>
#include <string>
#include <vector>
#include "Student.hpp"

//ClassRoom class declaration
class ClassRoom {
    //Public methods
    public:
        //ClassRoom constructor
        void AddStudent(Student student);
        //ClassRoom method to remove a student
        bool RemoveStudent(const std::string &student_name);
        //ClassRoom method to search for a student
        bool Search(const std::string &student_name);
        //ClassRoom method to load students from a file
        void LoadFromFile(const std::string &filename);
        //ClassRoom method to print the students
        void Print();
    //Private methods
    private:
        //ClassRoom method to find a student
        std::vector<Student>::const_iterator FindStudent(const std::string &student_name);
    private:
        //Private data members
        std::vector<Student> students_;

};
