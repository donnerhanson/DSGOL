//================================================================
// Author      : Donner Hanson
// Date        : 02/27/2019
// Email       : hanso127@mail.chapman.edu
// Course      : Data Structures and Algorithms
// Course #    : CPSC-350-2
// Project Name: Game Of Life
// File Name   : Cell.cpp
// Assignment  : Assignment 2
// Version     : 0.3
// Instructor  : Rene German
// Description : Cell class outline
//================================================================

#ifndef Cell_hpp
#define Cell_hpp

#include <iostream>
#include <string>

using namespace std;

class Cell
{
    friend ostream& operator << (ostream& out, const Cell& cell);
public:
    Cell(bool willLive)
    {
        setIsAlive(willLive);
        setNumNeighbors(0);
    }
    Cell()
    {
        setIsAlive(false);
        setNumNeighbors(0);
    }
    Cell& operator=(const Cell& current)
    {
        this->setIsAlive(current.isAlive);
        this->numNeighbors = current.numNeighbors;
        return *this; // copy
    }
    void setWillLive();
    bool getWillLive(){return willLive;}
    int getNumNeighbors()const;
    void setNumNeighbors(int num);
    bool checkIsAlive(); // return if alive
    void setIsAlive(bool breathing); // also calls setLifeVal
    void setIsAlive(const char& breathing); // also calls setLifeVal
    void setLifeVal(); // if alive set char to X else -
    char getLiveVal();
private:
    bool willLive;
    bool isAlive;
    int numNeighbors;
    char lifeVal;
};
ostream& operator << (ostream& out, const Cell& cell);

#endif /* Cell_hpp */

