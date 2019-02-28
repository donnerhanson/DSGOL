//================================================================
// Author      : Donner Hanson
// Date        : 02/27/2019
// Email       : hanso127@mail.chapman.edu
// Course      : Data Structures and Algorithms
// Course #    : CPSC-350-2
// Project Name: Game Of Life
// File Name   : UserInterface.cpp
// Assignment  : Assignment 2
// Version     : 0.3
// Instructor  : Rene German
// Description : General Questions to ask user and process input
//               outline
//================================================================

#ifndef UserInterface_hpp
#define UserInterface_hpp

#include <stdio.h>
#include <string>

using namespace std;



class UserInterface{
public:
    bool CheckForOneTwo();
    int CheckForOneTwoThree();
    string GetInFileName();
    string GetOutFileName();
    // string manipulation
    string Capitalize(string &str);
    bool isNotWS(const string &str);
    string RemoveErroneousChars(string& str);
    
    // Questions
    void askMap();
    void askMode();
    void askOutputMode();
    void displayProperFormat();
    
private:
};

#endif /* UserInterface_hpp */

