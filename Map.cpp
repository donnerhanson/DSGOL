//================================================================
// Author      : Donner Hanson
// Date        : 02/27/2019
// Email       : hanso127@mail.chapman.edu
// Course      : Data Structures and Algorithms
// Course #    : CPSC-350-2
// Project Name: Game Of Life
// File Name   : Map.cpp
// Assignment  : Assignment 2
// Version     : 0.4
// Instructor  : Rene German
// Description : Map calculations and draw to board etc
//================================================================

#include <iostream>
#include <sstream>

#include "Map.hpp"

const int MIRROR_EDGE = 1;

using namespace std;

void Map::draw()
{
    int num = 0;
    for (int i(0); i < rows; i++, num++)
    {
        for (int j(0); j < cols; j++, num++)
        {
            // output each cell in a grid
            cout << TD_Array[i][j];
        }
        cout << "\n";
    }
}
Cell** Map::Allocate(int row, int col)
{
    Cell** ptr = new Cell*[row+1];
    for(int i(0); i <= row; i++)
    {
        ptr[i] = new Cell[col];
    }
    return ptr;
}
void Map::Destroy_2D(Cell** ptr, int row, int col)
{
    for(int i (0); i <= row; i++)
    {
        delete [] ptr[i];
    }
    delete [] ptr;
}
void Map::fillMap(string& line)
{
    int num(0);
    for (int i(0); i < rows; i++)
        for (int j(0); j < cols; j++, num++)
        {
            // if char is X alive if char is - D-E-D dead!
            TD_Array[i][j].setIsAlive(line.at(num));
        }
}
void Map::calculateTotalNeighbors()
{
    // reset/calculate neighbors
    int currentNeighbors(0);
    totalNeighbors = currentNeighbors;
    // reset the number of neighbors in each cell
    for (int i(0); i < rows; i++)
    {
        for (int j(0); j < cols; j++)
        {
            TD_Array[i][j].setNumNeighbors(0);
        }
    }
    for (int currRow(0); currRow < rows; currRow++)
    {
        // Row Directions
        int up(currRow - 1), down(currRow + 1), bottom(rows - 1), top(0);
        for (int currCol(0); currCol < cols; currCol++)
        {
            // Column Directions
            int farLeft(0), farRight(cols - 1) ,
                left(currCol - 1), right(currCol + 1);
            {
                /**************************************************/
                /*                      DONUT                     */
                /**************************************************/
                if (gridMode == 2)
                {
                    // CHECK TOP ROW
                    if (currRow == 0)
                    {
                        // LEFT TOP CORNER [0][0]
                        if (currCol == 0)
                        {
                            //isCorner = true;
                            // right top corner[0][cols-1],
                            if (TD_Array[top][farRight].checkIsAlive())
                            {
                                currentNeighbors++;
                            }
                            // right top down one row[1][cols-1]
                            if (TD_Array[1][farRight].checkIsAlive())
                            {
                                currentNeighbors++;
                            }
                            // check right bottom corner[rows - 1][cols - 1]
                            if (TD_Array[bottom][farRight].checkIsAlive())
                            {
                                currentNeighbors++;
                            }
                            // left bottom corner[rows-1][0]
                            if (TD_Array[bottom][farLeft].checkIsAlive())
                            {
                                currentNeighbors++;
                            }
                            // left bottom corner over one col [rows-1][1]
                            if (TD_Array[bottom][1].checkIsAlive())
                            {
                                currentNeighbors++;
                            }
                        }
                        // TOP EDGE NOT CORNER
                        //if top i.e. [i][j] = [0][0 <j < cols-1]
                        if(currCol > 0 && currCol < cols - 1)
                        {
                            // check bottom same column [rows - 1][j]
                            if (TD_Array[bottom][currCol].checkIsAlive())
                            {
                                currentNeighbors++;
                            }
                            // check bottom one to the left [rows - 1][j-1]
                            if (TD_Array[bottom][left].checkIsAlive())
                            {
                                currentNeighbors++;
                            }
                            // check bottom one to the right [rows - 1][j+1]
                            if (TD_Array[bottom][right].checkIsAlive())
                            {
                                currentNeighbors++;
                            }
                        }
                        // RIGHT TOP CORNER [rows - 1][cols - 1]
                        if (currCol == cols - 1)
                        {
                            // left top corner[0][0]
                            if (TD_Array[top][farLeft].checkIsAlive())
                            {
                                currentNeighbors++;
                            }
                            
                            // left top one row down [1][0]
                            if (TD_Array[1][farLeft].checkIsAlive())
                            {
                                currentNeighbors++;
                            }
                            // check left bottom corner[rows-1][0],
                            if (TD_Array[bottom][farLeft].checkIsAlive())
                            {
                                currentNeighbors++;
                            }
                            // right bottom corner [rows - 1][ cols - 1]
                            if (TD_Array[bottom][farRight].checkIsAlive())
                            {
                                currentNeighbors++;
                            }
                            // right bottom corner over one [rows - 1][cols - 2]
                            if (TD_Array[bottom][farRight- 1].checkIsAlive())
                            {
                                currentNeighbors++;
                            }
                        }
                    }
                    // CHECK IN BETWEEN ROW SIDES
                    if ((currRow > top && currRow < bottom)&&
                        (currCol == farLeft || currCol == farRight))
                    {
                        // if left i.e. [i][j] = [i][0]
                        if (currCol == farLeft)
                        {
                            // check right same row [i][cols - 1]
                            if (TD_Array[currRow][farRight].checkIsAlive())
                            {
                                currentNeighbors++;
                            }
                            
                            // check right one up   [i - 1][cols - 1]
                            if (TD_Array[up][farRight].checkIsAlive())
                            {
                                currentNeighbors++;
                            }
                            // check right one down [i+1][cols - 1]
                            if (TD_Array[down][farRight].checkIsAlive())
                            {
                                currentNeighbors++;
                            }
                        }
                        // if right i.e. [i][j] = [i][cols - 1]
                        if (currCol == farRight)
                        {
                            // check left same row [i][0]
                            if (TD_Array[currRow][farLeft].checkIsAlive())
                            {
                                currentNeighbors++;
                            }
                            // check left one up   [i - 1][0]
                            if (TD_Array[up][farLeft].checkIsAlive())
                            {
                                currentNeighbors++;
                            }
                            // check left one down [i+1][0]
                            if (TD_Array[down][farLeft].checkIsAlive())
                            {
                                currentNeighbors++;
                            }
                        }
                    }
                    // CHECK BOTTOM ROW
                    if (currRow == bottom)
                    {
                        // LEFT BOTTOM CORNER [rows-1][0]
                        if (currCol == farLeft)
                        {
                            // right bottom corner[rows - 1][ cols - 1],
                            if (TD_Array[bottom][farRight].checkIsAlive())
                            {
                                currentNeighbors++;
                            }
                            // right bottom up one row[rows - 2][cols - 1]
                            if (TD_Array[bottom - 1][farRight].checkIsAlive())
                            {
                                currentNeighbors++;
                            }
                            // check right top corner [0][cols - 1],
                            if (TD_Array[top][farRight].checkIsAlive())
                            {
                                currentNeighbors++;
                            }
                            // left top corner[0][0]
                            if (TD_Array[top][farLeft].checkIsAlive())
                            {
                                currentNeighbors++;
                            }
                            // left top over one column [0][1]
                            if (TD_Array[top][farLeft + 1].checkIsAlive())
                            {
                                currentNeighbors++;
                            }
                        }
                        // NON-CORNERS
                        // if bottom i.e. [i][j] = [rows - 1][j]
                        if (currCol > farLeft && currCol < farRight)
                        {
                            // check top one to the left [0][j-1]
                            if (TD_Array[top][left].checkIsAlive())
                            {
                                currentNeighbors++;
                            }
                            // check top same column [0][j]
                            if (TD_Array[top][currCol].checkIsAlive())
                            {
                                currentNeighbors++;
                            }
                            // check top one to the right [0][j+1]
                            if (TD_Array[top][right].checkIsAlive())
                            {
                                currentNeighbors++;
                            }
                        }
                        // RIGHT BOTTOM CORNER [rows-1][cols-1]
                        if(currCol == farRight)
                        {   // left bottom corner[rows - 1][0],
                            if (TD_Array[bottom][farLeft].checkIsAlive())
                            {
                                currentNeighbors++;
                            }
                            // left bottom plus up one row [rows - 2][0]
                            if (TD_Array[bottom - 1][farLeft].checkIsAlive())
                            {
                                currentNeighbors++;
                            }
                            // check left top corner[0][0]
                            if (TD_Array[top][farLeft].checkIsAlive())
                            {
                                currentNeighbors++;
                            }
                            // right top corner[0][cols - 1]
                            if (TD_Array[top][farRight].checkIsAlive())
                            {
                                currentNeighbors++;
                            }
                            // right top down one[1][cols - 1]
                            if (TD_Array[top + 1][farRight].checkIsAlive())
                            {
                                currentNeighbors++;
                            }
                        }
                    }
                }
                /***************************************************/
                /*                 END - DONUT                     */
                /***************************************************/
                /***************************************************/
                /*                 START - MIRROR                  */
                /***************************************************/
                if(gridMode == 3)
                {
                    // MIRRORS AFFECT THE CELLS AROUND IT
                    // [vertical][horizontal]
                    
                    // if alive is edge top +1 [0][j]
                    if (currRow == top && TD_Array[top][currCol].checkIsAlive())
                    {
                        currentNeighbors+=MIRROR_EDGE;
                    }
                    // if alive is edge top next to current right +1   [0][j+1]
                    if (currCol < farRight)
                        if (currRow == top &&
                            TD_Array[top][right].checkIsAlive())
                        {
                            currentNeighbors+=MIRROR_EDGE;
                        }
                    // if mirror reflection alive is edge top next to
                    // current right +1 [0][j-1]
                    if (currCol > farLeft)
                        if (currRow == top &&
                            TD_Array[top][left].checkIsAlive())
                        {
                            currentNeighbors+=MIRROR_EDGE;
                        }
                    // if alive is edge side left +1 [i][0]
                    if (currCol == farLeft &&
                        TD_Array[currRow][farLeft].checkIsAlive())
                    {
                        currentNeighbors+=MIRROR_EDGE;
                    }
                    // if mirror reflection is alive above
                    if (currRow > top)
                        if (currCol == farLeft &&
                            TD_Array[up][farLeft].checkIsAlive())
                        {
                            currentNeighbors+=MIRROR_EDGE;
                        }
                    // if mirror reflection is alive below
                    if (currRow < bottom)
                        if (currCol == farLeft &&
                            TD_Array[down][farLeft].checkIsAlive())
                        {
                            currentNeighbors+=MIRROR_EDGE;
                        }
                    // if alive is edge bottom +1 [rows - 1][j]
                    if (currRow == bottom &&
                        TD_Array[bottom][currCol].checkIsAlive())
                    {
                        currentNeighbors+=MIRROR_EDGE;
                    }
                    // check left reflection
                    if (currCol > farLeft)
                        if (currRow == bottom &&
                            TD_Array[bottom][left].checkIsAlive())
                        {
                            currentNeighbors+=MIRROR_EDGE;
                        }
                    // check right reflection
                    if (currCol < farRight)
                        if (currRow == bottom &&
                            TD_Array[bottom][right].checkIsAlive())
                        {
                            currentNeighbors+=MIRROR_EDGE;
                        }
                    // if alive is edge side right +1 [i][cols - 1]
                    if (currCol == farRight &&
                        TD_Array[currRow][farRight].checkIsAlive())
                    {
                        currentNeighbors+=MIRROR_EDGE;
                    }
                    // check up
                    if (currRow > top)
                        if (currCol == farRight &&
                            TD_Array[up][farRight].checkIsAlive())
                        {
                            currentNeighbors+=MIRROR_EDGE;
                        }
                    // check down
                    if (currRow < bottom)
                        if (currCol == farRight &&
                            TD_Array[down][farRight].checkIsAlive())
                        {
                            currentNeighbors+=MIRROR_EDGE;
                        }
                }
                /***************************************************/
                /*                 END - MIRROR                    */
                /***************************************************/
                /***************************************************/
                /*                 BEGIN - NORMAL                  */
                /***************************************************/
                if (currRow >= 1)
                {
                    if (currCol >= 1)
                    {
                        // left upper corner
                        if (TD_Array[up][left].checkIsAlive())
                        {
                            currentNeighbors++;
                        }
                    }
                    if (TD_Array[up][currCol].checkIsAlive())   // up
                    {
                        currentNeighbors++;
                    }
                    if (currCol < farRight)
                    {
                        // right upper corner
                        if(TD_Array[up][right].checkIsAlive())
                        {
                            currentNeighbors++;
                        }
                    }
                }
                if (currCol > farLeft)
                {
                    if (TD_Array[currRow][left].checkIsAlive()) // left
                    {
                        currentNeighbors++;
                    }
                }
                if (currCol < farRight)
                    if(TD_Array[currRow][right].checkIsAlive()) // right
                    {
                        currentNeighbors++;
                    }
                
                if (currRow < bottom)
                {
                    if (currCol > farLeft)
                    {
                        // left lower corner
                        if(TD_Array[down][left].checkIsAlive())
                        {
                            currentNeighbors++;
                        }
                    }
                    if (TD_Array[down][currCol].checkIsAlive()) // down
                    {
                        currentNeighbors++;
                    }
                }
                if (currRow < bottom && currCol < farRight )
                {
                    // right lower corner
                    if (TD_Array[down][right].checkIsAlive())
                    {
                        currentNeighbors++;
                    }
                }
                /***************************************************/
                /*                 END - NORMAL                    */
                /***************************************************/
                TD_Array[currRow][currCol].setNumNeighbors(currentNeighbors);
                TD_Array[currRow][currCol].setWillLive();
                totalNeighbors += currentNeighbors;
                currentNeighbors = 0;
            }
        }
    }
}
void Map::playGod()
{
    // set value to value determined if willLive
    for (int i (0); i < rows; i++)
    {
        for (int j (0); j < cols; j++)
        {
            TD_Array[i][j].setIsAlive(TD_Array[i][j].getWillLive());
        }
    }
}
string Map::to_str() const
{
    string str;
    for (int i (0); i < rows; i++)
    {
        for (int j (0); j < cols; j++)
        {
            str+=TD_Array[i][j].getLiveVal();
        }
        str+="\n";
    }
    return str;
}
ostream& operator << (ostream& out, const Map &map)
{
    out << map.to_str();
    return out;
}
