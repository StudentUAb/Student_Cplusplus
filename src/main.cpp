/*
**============================================================================
** UC: 21093 - Programação por Objectos - 03
** e-fólio Global  2022-23 (efolioGlobal.cpp)
**
** Aluno: 2100927 - Ivo Baptista
** Name        : student.cpp
** Author      : Ivo Baptista
** Version     : 1.1
** Copyright   : IvoNet
** Description : Program Students in C++17, Ansi-style
**============================================================================
** Created on 05-02-2023
** Created by:
**                                                                                                                        
 _|_|_|                               _|_|_|                             _|       _|                _|                 
   _|     _|      _|     _|_|         _|    _|     _|_|_|   _|_|_|     _|_|_|_|          _|_|_|   _|_|_|_|     _|_|_|  
   _|     _|      _|   _|    _|       _|_|_|     _|    _|   _|    _|     _|       _|   _|_|         _|       _|    _|  
   _|       _|  _|     _|    _|       _|    _|   _|    _|   _|    _|     _|       _|       _|_|     _|       _|    _|  
 _|_|_|       _|         _|_|         _|_|_|       _|_|_|   _|_|_|         _|_|   _|   _|_|_|         _|_|     _|_|_|  
                                                            _|                                                         
                                                            _|                                                         
** ===========================================================================
*/

#include <iostream>
#include <memory>
#include <string>
//Include the header files
#include "Menu.hpp"
#include "Student.hpp"
#include "ClassRoom.hpp"

//Main function
int main(int argc, char **argv) {
    //Create a shared pointer to a ClassRoom object
    std::shared_ptr<ClassRoom> room = std::make_shared<ClassRoom>();
    //Create a Menu object and pass the shared pointer to the ClassRoom object
    Menu menu{room};
    //Call the Show() method on the Menu object
    menu.Show();
    return EXIT_SUCCESS; //Exit the program
}