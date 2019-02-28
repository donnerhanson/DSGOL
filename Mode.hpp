//================================================================
// Author      : Donner Hanson
// Date        : 02/27/2019
// Email       : hanso127@mail.chapman.edu
// Course      : Data Structures and Algorithms
// Course #    : CPSC-350-2
// Project Name: Game Of Life
// File Name   : Mode.h
// Assignment  : Assignment 2
// Version     : 0.3
// Instructor  : Rene German
// Description : Outline of functions/class to run the program
//================================================================

#ifndef Mode_hpp
#define Mode_hpp

#include <fstream>
#include <iostream>
#include <limits>
#include <memory>
#include <sstream>
#include <string>

#include "FileHandler.hpp"
#include "UserInterface.hpp"

using namespace std;
class Mode
{
public:
    Mode(int rows, int cols, int outputMode, string fullText, int gridMode): rows(rows),cols(cols), outputMode(outputMode), fullText(fullText), gridMode(gridMode){};
    
    void run();
    void run(FileHandler& out, const string &outFile);
private:
    int rows;
    int cols;
    int outputMode;
    int gridMode;
    string fullText;
};
void getEnter();
void getEnterToExit();
#endif /* ClassicMode_hpp */

