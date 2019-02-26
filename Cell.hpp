//
//  Cell.hpp
//  GameOfLife
//
//  Created by Donner Hanson on 2/19/19.
//  Copyright © 2019 Donner Hanson. All rights reserved.
//

#ifndef Cell_hpp
#define Cell_hpp

#include <string>

using namespace std;

class Cell
{
    friend ostream& operator << (ostream& out, const Cell& cell);
    friend bool operator==(const Cell &cellOne, const Cell &cellTwo);
    friend bool operator!=(const Cell &cellOne, const Cell &cellTwo);
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
bool operator==(const Cell& cellOne, const Cell& cellTwo);
bool operator!=(const Cell& cellOne, const Cell& cellTwo);
ostream& operator << (ostream& out, const Cell& cell);

#endif /* Cell_hpp */

