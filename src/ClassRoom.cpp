//Include Files
#include <algorithm>
#include "ClassRoom.hpp"

//ClassRoom constructor
void ClassRoom::AddStudent(Student student) {
    //Add the student to the vector
    students_.emplace_back(student);
}//end AddStudent

//ClassRoom method to remove a student
bool ClassRoom::RemoveStudent(const std::string &student_name) {
    //Find the student
    auto it = FindStudent(student_name);
    //Check if the student was found
    if (it == students_.end()) {
        return false;//Return false
    }//end if
    //Remove the student from the vector
    students_.erase(it);
    return true;//Return true
}//end RemoveStudent

//ClassRoom method to search for a student
bool ClassRoom::Search(const std::string &student_name) {
    return (FindStudent(student_name) != students_.end());
}//end Search

//ClassRoom method to load students from a file
void ClassRoom::LoadFromFile(const std::string &filename) {
    //Open the file
    std::ifstream in;
    in.open(filename);
    //Check if the file was opened
    std::string line;
    //Read the file line by line
    while(std::getline(in, line)) {
        //Add the student to the vector
        AddStudent(Student{ line });
    }//end while
}//end LoadFromFile

//ClassRoom method to find a student
std::vector<Student>::const_iterator ClassRoom::FindStudent(const std::string &student_name) {
    //Find the student
    auto it = std::find_if(std::begin(students_)
                         , std::end(students_)
                         , [student_name](const auto &student) {
                        //Compare the student name
        return (student.GetName() == student_name);
    });//end find_if
    return it;//Return the iterator
}//end FindStudent

//ClassRoom method to print the students
void ClassRoom::Print() {
    //Print the students
    std::cout << "Class Room" << std::endl;
    std::cout << "==========" << std::endl;
    //Loop through the students
    for(const auto student : students_) {
        //Print the student
        std::cout << "\t" << student << std::endl;
    }//end for
    std::cout << std::endl;//Print a new line
}//end Print
