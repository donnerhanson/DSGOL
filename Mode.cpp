//================================================================
// Author      : Donner Hanson
// Date        : 02/27/2019
// Email       : hanso127@mail.chapman.edu
// Course      : Data Structures and Algorithms
// Course #    : CPSC-350-2
// Project Name: Game Of Life
// File Name   : Mode.cpp
// Assignment  : Assignment 2
// Version     : 0.3
// Instructor  : Rene German
// Description : Runs Program in given mode
//================================================================

#include <fstream>      // file io
#include <iostream>     // console io
#include <limits>       // numericlimits<streamsize>::max
#include <unistd.h>     // sleep

#include "FileHandler.hpp"
#include "Mode.hpp"
#include "Map.hpp"

void getEnter()
{
    cout << "Press Enter to continue....\n";
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
}

void getEnterToExit()
{
    cout << "Press Enter to exit....\n";
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
}

const int SLEEP = 1;
const int SLEEP_TIME = 2;
const int ENTER_TO_CONT = 2;

const int MAX_FILE_ITERATIONS = 3000;


// no file output
void Mode::run()
{
    // Run Simulation
    // display mode at top
    if (gridMode == 1)
        cout << "Classic\n";
    if (gridMode == 2)
        cout << "Donut\n";
    if (gridMode == 3)
        cout << "Mirror\n";
    Map* map = new Map(rows,cols, gridMode);
    map->fillMap(fullText);
    cout << "\nGen: 0\n";
    cout << *map << "\n";
    // take 2 d and compare strings
    string strOne = map->to_str();
    string strTwo = "0";
    int i(0);
    map->calculateTotalNeighbors();
    int preCheck(map->getTotalNeighbors());
    // check to see if there are any alive first
    if (!(preCheck == 0))
    {
        if (outputMode == SLEEP)
        {
            sleep(SLEEP_TIME);
        }
        if (outputMode == 2)
            getEnter();
        
        // RUN TO INFINITY UNLESS DEAD OR STAGNANT
        // break cases in loop
        while(true)
        {
            // calculate
            map->calculateTotalNeighbors();
            
            // adjust life
            map->playGod();
            strTwo = map->to_str();
            if (strOne == strTwo)
            {
                cout << "\nLife has ceased to progress!\n\n";
                break;
            }
            
            // draw to screen
            cout << "Gen: " << ++i << "\n";
            cout << *map << "\n";
            
            // check to see if all dead
            map->calculateTotalNeighbors();
            if (map->getTotalNeighbors() == 0)
            {
                cout << "\nAll life has died!\n";
                break;
            }
            if (outputMode == SLEEP && !(strOne == strTwo))
            {
                sleep(SLEEP_TIME);
            }
            if (outputMode == ENTER_TO_CONT && !(strOne == strTwo))
                getEnter();
            
            // swap string data
            strOne = strTwo;
        }
    }
    else
    {
        cout << "One or less live cells were populated!\n";
    }
    delete map;
    cout << "Stabilized...\n";
    getEnterToExit();
}
void Mode::run(FileHandler& out, const string& outFileName)
{
    // open file
    fstream outFile;
    outFile.open(outFileName, ios::out);
    if (outFile.is_open())
    {
        // display mode at top
        if (gridMode == 1)
            outFile << "Classic\n";
        if (gridMode == 2)
            outFile << "Donut\n";
        if (gridMode == 3)
            outFile << "Mirror\n";
        // Run Simulation
        Map* map = new Map(rows,cols, gridMode);
        map->fillMap(fullText);
        outFile << "\nGen: 0\n";
        outFile << *map << "\n";
        // take 2 d and compare strings
        string strOne (map->to_str());
        string strTwo ("0");
        int i(0);
        map->calculateTotalNeighbors();
        int preCheck(map->getTotalNeighbors());
        // check to see if there are any alive first
        if (!(preCheck == 0))
        {
            
            // RUN TO INFINITY UNLESS DEAD OR STAGNANT
            // break cases in loop -
            // swap this for non infinite
            // (while (i < MAX_FILE_ITERATIONS))
            while(true)
            {
                // calculate
                map->calculateTotalNeighbors();
                
                // adjust life
                map->playGod();
                strTwo = map->to_str();
                if (strOne == strTwo)
                {
                    outFile << "\nLife has ceased to progress!\n";
                    break;
                }
                
                // draw to screen
                outFile << "Gen: " << ++i << "\n";
                outFile << *map;
                outFile << "\n";
                
                map->calculateTotalNeighbors();
                if (map->getTotalNeighbors() == 0)
                {
                    outFile << "\nAll life has died!\n";
                    break;
                }
                
                // swap string data
                strOne = strTwo;
            }
        }
        else
        {
            outFile << "One or less live cells were populated!\n";
        }
        delete map;
        outFile << "Stabilized...\n\n";
        outFile.close();
        cout << "file closed\n";
    }
    else
    {
        cout << "failed to open file...\n";
    }
}

