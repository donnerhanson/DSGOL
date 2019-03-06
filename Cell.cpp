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
// Description : Cell class implementation
//================================================================

#include <iostream>

#include "Cell.hpp"

using namespace std;

void Cell::setWillLive()
{
    if (getNumNeighbors() <= 1)
        willLive = false;
    if (getNumNeighbors() == 2) // if two neighbors remain stable
    {
        if (checkIsAlive() == true)
            willLive = true;
        if (checkIsAlive() == false)
            willLive = false;
    }
    if (getNumNeighbors() == 3) // if three live
    {
        willLive = true;
    }
    if (getNumNeighbors() >= 4) // ya dead
    {
        willLive = false;
    }
}

void Cell::setNumNeighbors(int num)
{
    numNeighbors = num;
}
// return if alive
bool Cell::checkIsAlive()
{
    return isAlive;
}
void Cell::setIsAlive(bool breathing)
{
    isAlive = breathing;
    setLifeVal();
}
void Cell::setIsAlive(const char& breathing)
{
    if (breathing == 'X')
        isAlive = true;
    else if (breathing == '-')
        isAlive = false;
    else
        cout << "error reading cell: " << breathing << "\n";
    setLifeVal();
}
// if alive set char to X else -
void Cell::setLifeVal()
{
    if (isAlive)
        lifeVal = 'X';
    else
        lifeVal = '-';
}
char Cell::getLiveVal()
{
    return lifeVal;
}
int Cell::getNumNeighbors()const
{
    return numNeighbors;
}
ostream& operator << (ostream& out, const Cell &cell)
{
    out << cell.lifeVal;
    return out;
}

