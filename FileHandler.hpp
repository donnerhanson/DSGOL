//================================================================
// Author      : Donner Hanson
// Date        : 03/05/2019
// Email       : hanso127@mail.chapman.edu
// Course      : Data Structures and Algorithms
// Course #    : CPSC-350-2
// Project Name: Game Of Life
// File Name   : FileHandler.cpp
// Assignment  : Assignment 2
// Version     : 0.4
// Instructor  : Rene German
// Description : header functions to open and close a file
//================================================================

#ifndef FileHandler_hpp
#define FileHandler_hpp

#include <fstream>
#include <iostream>
#include <string>


using namespace std;

class FileHandler{
public:
    bool SafeOpenRead(ifstream& inFile, string fileName);
    bool fileIsBlank(ifstream& inFile);
    bool isNotWS(const string &str);
    fstream& SafeOpenOutput(fstream& inFile, string fileName);
private:
};

#endif /* FileHandler_hpp */

