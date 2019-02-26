//
//  Map.hpp
//  GameOfLife
//
//  Created by Donner Hanson on 2/19/19.
//  Copyright © 2019 Donner Hanson. All rights reserved.
//

#ifndef Map_hpp
#define Map_hpp

#include "Cell.hpp"

// base abstract/virtual class map
class Map
{
public:
    Map(int rows, int cols, int mode) : rows(rows), cols(cols), previousTotalNeighbors(0), totalNeighbors(1), mode(mode)
    {
        TD_Array = Allocate(rows, cols);
    }
    // Destructor
    ~Map()
    {
        Destroy_2D(TD_Array, rows, cols);
    }
    void draw(); // draws a map
    int getTotalNeighbors(){return totalNeighbors;}
    bool cellExists();
    Cell** Allocate(int row, int col);
    void Destroy_2D(Cell** ptr, int row, int col);
    void fillMap(string& line);
    void calculateTotalNeighbors();
    
    void playGod();
    
    string to_str();
private:
    int totalNeighbors;
    int previousTotalNeighbors;
    Cell **TD_Array;
    int rows;
    int cols;
    int mode;
    
};

#endif /* Map_hpp */

