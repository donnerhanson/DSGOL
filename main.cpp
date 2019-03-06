//================================================================
// Author      : Donner Hanson
// Date        : 02/27/2019
// Email       : hanso127@mail.chapman.edu
// Course      : Data Structures and Algorithms
// Course #    : CPSC-350-2
// Project Name: Game Of Life
// File Name   : main.cpp
// Assignment  : Assignment 2
// Version     : 0.4
// Instructor  : Rene German
// Description : main
//================================================================

#include <fstream>      // file out
#include <iterator>     // discreet distribution
#include <iostream>     // console io
#include <limits>       // numericlimits<streamsize>::max
#include <random>       // discreet distribution
#include <string>       // string

#include "FileHandler.hpp"
#include "Mode.hpp"
#include "UserInterface.hpp"



using namespace std;



string GenerateRand(int length, double frequencyAlive);

int main(int argc, const char * argv[])
{
    UserInterface ui;
    string fileName;
    ui.askMap();
    bool hasMap (ui.CheckForOneTwo());
    if (hasMap)
    {
        ui.displayProperFormat();
        fileName = ui.GetInFileName();
    }
    bool fOpenSuccess = false;
    FileHandler* fh = new FileHandler();
    // input file
    ifstream inFile;
    if ((fOpenSuccess  = fh->SafeOpenRead(inFile, fileName))
        || !hasMap)
    {
        // ask for classic, donut, or mirror
        ui.askMode();
        int gridMode(ui.CheckForOneTwoThree());
        // ask if console (pause or enter between) or file output
        ui.askOutputMode();
        int outputMode(ui.CheckForOneTwoThree());
        int rows, cols;
        string fullText;
        // Generate Maps
        delete fh;
        if (hasMap)
        {
            // read the dimensions of the 2 nums at top rows cols
            string line;
            getline(inFile, line);
            // get rows
            stringstream strToInt(line);
            strToInt >> rows;
            // clear strToInt
            strToInt.str("");
            strToInt.clear();
            // get cols
            getline(inFile, line);
            strToInt << line;
            strToInt >> cols;
            // clear strToInt
            strToInt.str("");
            strToInt.clear();
            // get rest of file input
            while(getline(inFile, line))
            {
                ui.RemoveErroneousChars(line); // get only symbols needed
                fullText+=line;
            }
            // For each line read
            cout << "\n";
            
        }
        else
        {
            cols = 0; rows = 0;
            // GENERATE RANDOM
            // prompt for the dimensions of the world
            cout << "enter rows: ";
            cin >> rows;
            cout << "\n";
            cout << "enter columns: ";
            cin >> cols;
            cout << "\n";
            // 3x2 = 6, 3x3 = 9 etc
            int length(rows*cols);
            float frequencyAlive;
            cout << "\n";
            // living is 'X' dead is '-'
            // prompt for a decimal value (greater than 0 and
            // less than or equal to 1)
            cout << "enter percentage to be alive (decimal greater than 0 and "
             << "less than or equal to 1): ";
            cin >> frequencyAlive;
            // ignore anything remaining in cin stream so 
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout <<"\n";
            // Randomly generate the initial cell configuration using the
            // dimension and density inputs.
            fullText = GenerateRand(length, frequencyAlive);
        }
        // non file out mode
        if (((fOpenSuccess && hasMap)||!(hasMap)) && (outputMode != 3))
            Mode(rows,cols,outputMode,fullText, gridMode).run();
        // file out mode
        else if (((fOpenSuccess && hasMap)||!(hasMap)) && (outputMode == 3))
        {
            FileHandler outHand;
            string outFile = ui.GetOutFileName();
            Mode(rows,cols,outputMode,fullText, gridMode).run(outHand, outFile);
        }
    }
    else if(hasMap)
    {
        getEnter();
        cout << "File not found....\n";
    }
    inFile.close();
    return 0;
}

/****************************************************************/
/*                            End Main                          */
/****************************************************************/


// weighted distribution of random numbers in c++
// idea derived from
// http://www.cplusplus.com/forum/general/69862/
string GenerateRand(int length, double frequencyAlive)
{
    
    double frequencyDead = 1 - frequencyAlive;
    
    random_device rd;
    mt19937 gen(rd());
    // generate the index number at weighted frequency
    // returns 0 for frequencyAlive or 1 for frequencyDead
    double weights[] = {frequencyAlive, frequencyDead};
    discrete_distribution<> d(begin(weights), end(weights));
    string fullText;
    int randNum;
    for(int i(0); i < length; ++i) {
        randNum = d(gen);
        if ( randNum != 1)
        {
            fullText+="X";
        }
        else if ( randNum == 1)
        {
            fullText+="-";
        }
    }
    return fullText;
}
