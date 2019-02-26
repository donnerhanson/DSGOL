//
//  ClassicMode.cpp
//  GameOfLife
//
//  Created by Donner Hanson on 2/20/19.
//  Copyright © 2019 Donner Hanson. All rights reserved.
//

#include <unistd.h> // sleep

#include "Mode.hpp"
#include "Map.hpp"

const int SLEEP = 1;
const int SLEEP_TIME = 2;

const int ENTER_TO_CONT = 2;

void Mode::run()
{
    // Run Simulation
    Map* map = new Map(rows,cols, mode);
    map->fillMap(fullText);
    
    //classic->calculateTotalNeighbors();
    cout << "Gen: 0\n";
    map->draw();
    cout << "\n\n";
    // take 2 d and compare strings
    string strOne = map->to_str();
    string strTwo = "0";
    int i(0);
    map->calculateTotalNeighbors();
    int preCheck(map->getTotalNeighbors());
    // check to see if there are any alive first
    if (!(preCheck == 0))
    {
        if (pause == 2)
        {    cout << "Press Enter to Continue\n";
            cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
        }
        
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
                cout << "\nLife has ceased to progress!\n";
                break;
            }
            
            // draw to screen
            cout << "Gen: " << ++i << "\n";
            map->draw();
            cout << "\n";
            
            map->calculateTotalNeighbors();
            if (map->getTotalNeighbors() == 0)
            {
                cout << "\nAll life has died!\n";
                break;
            }
            if (pause == SLEEP && !(strOne == strTwo))
            {
                sleep(SLEEP_TIME);
            }
            if (pause == ENTER_TO_CONT && !(strOne == strTwo))
            {    cout << "Press Enter to Continue\n";
                cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
            }
            
            // swap string data
            strOne = strTwo;
        }
    }
    else
    {
        cout << "One or less live cells were populated!\n";
    }
    delete map;
    {    cout << "Stabilized... Press enter to continue...\n";
        cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
    }
}

