//
//  Cell.cpp
//  GameOfLife
//
//  Created by Donner Hanson on 2/19/19.
//  Copyright © 2019 Donner Hanson. All rights reserved.
//

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
bool operator==(const Cell& cellOne, const Cell& cellTwo)
{
    // return if the same address
    return cellOne.getNumNeighbors() == cellTwo.getNumNeighbors();
}
bool operator!=(const Cell& cellOne, const Cell& cellTwo)
{
    return !(cellOne==cellTwo);
}
ostream& operator << (ostream& out, const Cell &cell)
{
    out << cell.lifeVal;
    return out;
}

