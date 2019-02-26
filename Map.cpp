//
//  Map.cpp
//  GameOfLifeTwo
//
//  Created by Donner Hanson on 2/25/19.
//  Copyright © 2019 Donner Hanson. All rights reserved.
//

#include "Map.hpp"


#include <iostream>

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
    Cell ** ptr = new Cell*[row+1];
    for(int i = 0; i <= row; i++)
    {
        ptr[i] = new Cell[col];
    }
    return ptr;
}
void Map::Destroy_2D(Cell** ptr, int row, int col)
{
    for(int i = 0; i < row+1; i++)
    {
        delete [] ptr[i];
    }
    delete [] ptr;
}

void Map::fillMap(string& line)
{
    int num = 0;
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
    for (int i (0); i < rows; i++)
    {
        for (int j (0); j < cols; j++)
        {
            TD_Array[i][j].setNumNeighbors(0);
        }
    }
    //cout << "\ntotal neighbors before calculations: " << totalNeighbors << "\n\n";
    
    
    for (int currRow(0); currRow < rows; currRow++)
    {
        // Row Directions
        int up(currRow - 1), down(currRow + 1), bottom(rows - 1), top(0);
        // Column Directions
        
        for (int currCol(0); currCol < cols; currCol++)
        {
            int farLeft(0), farRight(cols - 1) ,left(currCol - 1), right(currCol + 1);
            {
                /**************************************************/
                /*                      DONUT                     */
                /**************************************************/
                if (mode == 2)
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
                                //cout << "left top corner alive\n";
                                currentNeighbors++;
                            }
                            
                            // left top one row down [1][0]
                            if (TD_Array[1][farLeft].checkIsAlive())
                            {
                                //                                cout << "left top corner down one row alive\n";
                                currentNeighbors++;
                            }
                            // check left bottom corner[rows-1][0],
                            if (TD_Array[bottom][farLeft].checkIsAlive())
                            {
                                //                                cout << "left bottom corner alive\n";
                                currentNeighbors++;
                            }
                            // right bottom corner [rows - 1][ cols - 1]
                            if (TD_Array[bottom][farRight].checkIsAlive())
                            {
                                //                                cout << "right bottom corner alive\n";
                                currentNeighbors++;
                            }
                            // right bottom corner over one [rows - 1][cols - 2]
                            if (TD_Array[bottom][farRight- 1].checkIsAlive())
                            {
                                //                                cout << "right bottom corner over one alive\n";
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
                // cout << currentNeighbors;
                /***************************************************/
                /*                 END - DONUT                     */
                /***************************************************/
                /***************************************************/
                /*                 START - MIRROR                  */
                /***************************************************/
                if(mode == 3)
                {
                    // MIRRORS AFFECT THE CELLS AROUND IT
                    // [vertical][horizontal]
                    
                    // if alive is edge top +1              [0][j]
                    if (currRow == top && TD_Array[top][currCol].checkIsAlive())
                    {
                        currentNeighbors+=MIRROR_EDGE;
                    }
                    
                    // if alive is edge top next to current right +1              [0][j+1]
                    if (currCol < farRight)
                        if (currRow == top && TD_Array[top][right].checkIsAlive())
                        {
                            currentNeighbors+=MIRROR_EDGE;
                        }
                    // if mirror reflection alive is edge top next to current right +1              [0][j-1]
                    if (currCol > farLeft)
                        if (currRow == top && TD_Array[top][left].checkIsAlive())
                        {
                            currentNeighbors+=MIRROR_EDGE;
                        }
                    
                    
                    // if alive is edge side left +1        [i][0]
                    if (currCol == farLeft && TD_Array[currRow][farLeft].checkIsAlive())
                    {
                        currentNeighbors+=MIRROR_EDGE;
                    }
                    // if mirror reflection is alive above
                    if (currRow > top)
                        if (currCol == farLeft && TD_Array[up][farLeft].checkIsAlive())
                        {
                            currentNeighbors+=MIRROR_EDGE;
                        }
                    // if mirror reflection is alive below
                    if (currRow < bottom)
                        if (currCol == farLeft && TD_Array[down][farLeft].checkIsAlive())
                        {
                            currentNeighbors+=MIRROR_EDGE;
                        }
                    
                    
                    
                    // if alive is edge bottom +1           [rows - 1][j]
                    if (currRow == bottom && TD_Array[bottom][currCol].checkIsAlive())
                    {
                        currentNeighbors+=MIRROR_EDGE;
                    }
                    // check left reflection
                    if (currCol > farLeft)
                        if (currRow == bottom && TD_Array[bottom][left].checkIsAlive())
                        {
                            currentNeighbors+=MIRROR_EDGE;
                        }
                    // check right reflection
                    if (currCol < farRight)
                        if (currRow == bottom && TD_Array[bottom][right].checkIsAlive())
                        {
                            currentNeighbors+=MIRROR_EDGE;
                        }
                    
                    
                    // if alive is edge side right +1       [i][cols - 1]
                    if (currCol == farRight && TD_Array[currRow][farRight].checkIsAlive())
                    {
                        currentNeighbors+=MIRROR_EDGE;
                    }
                    // check up
                    if (currRow > top)
                        if (currCol == farRight && TD_Array[up][farRight].checkIsAlive())
                        {
                            currentNeighbors+=MIRROR_EDGE;
                        }
                    // check down
                    if (currRow < bottom)
                        if (currCol == farRight && TD_Array[down][farRight].checkIsAlive())
                        {
                            currentNeighbors+=MIRROR_EDGE;
                        }
                    
                }
                //cout << "\n";
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
                        if (TD_Array[up][left].checkIsAlive()) // left upper corner
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
                        if(TD_Array[up][right].checkIsAlive()) // right upper corner
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
                        if(TD_Array[down][left].checkIsAlive()) // left lower corner
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
                    if (TD_Array[down][right].checkIsAlive()) // right lower corner
                    {
                        currentNeighbors++;
                    }
                }
                /***************************************************/
                /*                 END - NORMAL                    */
                /***************************************************/
                TD_Array[currRow][currCol].setNumNeighbors(currentNeighbors);
                //cout << currentNeighbors;
                TD_Array[currRow][currCol].setWillLive();
                totalNeighbors += currentNeighbors;
                currentNeighbors = 0;
            }
        }
        //cout << "\n";
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

string Map::to_str()
{
    string str;
    for (int i (0); i < rows; i++)
    {
        for (int j (0); j < cols; j++)
        {
            str+=TD_Array[i][j].getLiveVal();
        }
    }
    return str;
}
