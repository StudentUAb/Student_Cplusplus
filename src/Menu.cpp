//Include Files
#include <iostream>
#include <string>
#include "Menu.hpp"

//Menu constructor with a shared pointer to a ClassRoom object
Menu::Menu(std::shared_ptr<ClassRoom> room) : room_{room} {
}

//Menu destructor
void Menu::AddStudentMenuItem() {
    //Add a student
    std::string name; //Create a string to hold the student name
    std::cout << "Adicionar novo estudante, Introduzir o nome: ";
    std::cin >> name; //Read the student name
    //Create a Student object and pass the name
    room_->AddStudent(Student{name}); //Call the AddStudent() method on the ClassRoom object
}//end AddStudentMenuItem

//Menu method to remove a student
void Menu::RemoveStudentMenuItem() {
    //Remove a student
    std::string name; //Create a string to hold the student name
    std::cout << "Remover estudante, Introduzir nome a remover: ";
    std::cin >> name; //Read the student name
    //Check if the student was removed
    if (room_->RemoveStudent(name)) {  //Call the RemoveStudent() method on the ClassRoom object
        std::cout << name << " Eliminado estudante da turma" << std::endl; //Print the result
    } else { //The student was not removed
        std::cout << name << " nao existe na turma" << std::endl; //Print the result 
    }//end if
}//end RemoveStudentMenuItem

//Menu method to search for a student
void Menu::SearchStudentMenuItem() {
    //Search for a student
    std::string name; //Create a string to hold the student name
    std::cout << "Buscar estudante, introduzir nome: ";
    std::cin >> name; //Read the student name
    bool result = room_->Search(name); //Call the Search() method on the ClassRoom object
    std::cout << "Estudante " << name << (result ? " " : " not ") << "Encontrado!" << std::endl; //Print the result
}//end SearchStudentMenuItem

//Menu method to print the students
void Menu::PrintStudentMenuItem() {
    room_->Print();//Call the Print() method on the ClassRoom object
}

//Menu method to load students from a file
void Menu::LoadFromFileMenuItem() { 
    //Load students from a file
    const std::string kFilename{"Dados.txt"}; //Create a string to hold the filename
    room_->LoadFromFile(kFilename); //Call the LoadFromFile() method on the ClassRoom object
}//end LoadFromFileMenuItem

//Menu method to quit the program
void Menu::QuitMenuItem() {
    quit_ = true; //Set the quit flag
}//end QuitMenuItem

//Menu method to draw the menu
int Menu::DrawMenu() {
    //Draw the menu
    int option{0};//Create an integer to hold the option
    //Print the menu
    std::cout << "Sala de estudantes Menu" << std::endl;
    std::cout << "==============" << std::endl;
    //Print the menu options
    std::cout << "1. Adicionar Estudante" << std::endl;
    std::cout << "2. Remover Estudante" << std::endl;
    std::cout << "3. Encontrar Estudante" << std::endl;
    std::cout << "4. Carregar lista desde um ficheiro txt" << std::endl;
    std::cout << "8. Imprimir Turma de alunos" << std::endl;
    std::cout << "9. Sair" << std::endl;
    //Read the option
    std::cout << "Opção: ";
    std::cin >> option;

    return option;//Return the option
}//end DrawMenu

//Menu method to show the menu
void Menu::Show() {
    //Show the menu
    while(!quit_) {
        //Draw the menu
        int option{DrawMenu()};
        //Check the option
        switch(option) {
            case 1:
                AddStudentMenuItem(); //Call the AddStudentMenuItem() method
                break;
            case 2:
                RemoveStudentMenuItem(); //Call the RemoveStudentMenuItem() method
                break;
            case 3:
                SearchStudentMenuItem(); //Call the SearchStudentMenuItem() method
                break;
            case 4:
                LoadFromFileMenuItem(); //Call the LoadFromFileMenuItem() method
                break;
            case 8:
                PrintStudentMenuItem(); //Call the PrintStudentMenuItem() method
                break;
            case 9:
                quit_ = true; //Set the quit flag
                break; //Break out of the switch statement
            default: //The option is invalid
                std::cout << "Opção invalida, tentar novamente" << std::endl;
        }//end switch
    }//end while
    //Print a message
    std::cout << "Obrigado por utilizar esta aplicação"
              << std::endl << std::endl;
}//end Show
