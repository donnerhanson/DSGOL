//================================================================
// Author      : Donner Hanson
// Date        : 03/05/2019
// Email       : hanso127@mail.chapman.edu
// Course      : Data Structures and Algorithms
// Course #    : CPSC-350-2
// Project Name: Game Of Life
// File Name   : FileHandler.cpp
// Assignment  : Assignment 2
// Version     : 0.3
// Instructor  : Rene German
// Description : functions to open and close a file
//================================================================

#include <iostream>
#include <fstream>
#include <string>

#include "FileHandler.hpp"

using namespace std;


bool FileHandler::SafeOpenRead(ifstream& inFile, string fileName)
{
    inFile.open(fileName, ios::in);
    
    if(inFile.is_open() && !fileIsBlank(inFile))
    {
        cout << "file opened successfully\n";
        return true;
    }
    return false;
}
fstream& FileHandler::SafeOpenOutput(fstream& outFile, string fileName)
{
    outFile.open(fileName, ios::out);
    
    if(outFile.is_open())
    {
        cout << "File opened successfully\n";
        
    }
    else
        cout << "Failed to open file or file was empty!\n";
    return outFile;
}

bool FileHandler::fileIsBlank(ifstream& inFile)
{
    return inFile.peek() == ifstream::traits_type::eof();
}

bool FileHandler::isNotWS(const string &str)
{
    return str.find_first_not_of(' ') != string::npos;
}


