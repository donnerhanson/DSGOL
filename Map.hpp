//================================================================
// Author      : Donner Hanson
// Date        : 02/27/2019
// Email       : hanso127@mail.chapman.edu
// Course      : Data Structures and Algorithms
// Course #    : CPSC-350-2
// Project Name: Game Of Life
// File Name   : Map.cpp
// Assignment  : Assignment 2
// Version     : 0.3
// Instructor  : Rene German
// Description : Outline of map calculation and draw functions
//================================================================

#ifndef Map_hpp
#define Map_hpp

#include "Cell.hpp"
#include <iostream>

// base abstract/virtual class map
class Map
{
    friend ostream& operator << (ostream& out, const Map &map);
public:
    Map(int rows, int cols, int gridMode) : rows(rows), cols(cols), previousTotalNeighbors(0), totalNeighbors(1), gridMode(gridMode)
    {
        TD_Array = Allocate(rows, cols);
    }
    // Destructor
    ~Map()
    {
        Destroy_2D(TD_Array, rows, cols);
    }
    void draw(); // draws a map
    void draw(fstream& out); // draw passed string
    int getTotalNeighbors(){return totalNeighbors;}
    bool cellExists();
    Cell** Allocate(int row, int col);
    void Destroy_2D(Cell** ptr, int row, int col);
    void fillMap(string& line);
    void calculateTotalNeighbors();
    
    void playGod();
    
    string to_str()const;
private:
    int totalNeighbors;
    int previousTotalNeighbors;
    Cell **TD_Array;
    int rows;
    int cols;
    int gridMode;
    
};
ostream& operator << (ostream& out, const Map &map);

#endif /* Map_hpp */

