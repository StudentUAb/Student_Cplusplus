#pragma once
// C++ Standard Library
//Include Files
#include <memory>
#include <map>
#include "ClassRoom.hpp"

//Menu class declaration
class Menu {
    //Public methods
    public:
        //Menu constructor
        Menu(std::shared_ptr<ClassRoom> room);
        //Menu method to show the menu
        void Show();
    //Private methods
    private:
        //Menu method to draw the menu
        int DrawMenu();
        //Menu method to add a student
        void AddStudentMenuItem();
        //Menu method to remove a student
        void RemoveStudentMenuItem();
        //Menu method to search for a student
        void SearchStudentMenuItem();
        //Menu method to load students from a file
        void LoadFromFileMenuItem();
        //Menu method to print the students
        void PrintStudentMenuItem();
        //Menu method to quit the program
        void QuitMenuItem();
    //Private data members
        bool quit_{false};//Flag to quit the program
        std::shared_ptr<ClassRoom> room_; //Shared pointer to a ClassRoom object
};