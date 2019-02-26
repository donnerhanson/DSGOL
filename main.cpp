//================================================================
// Author      : Donner Hanson
// Date        : 03/05/2019
// Email       : hanso127@mail.chapman.edu
// Course      : Data Structures and Algorithms
// Course #    : CPSC-350-2
// Project Name: Game Of Life
// File Name   : main.cpp
// Assignment  : Assignment 2
// Version     : 0
// Instructor  : Rene German
// Description : main
//================================================================

#include <random> // discreet distribution
#include <iterator> // discreet distribution

#include <fstream>
#include <iostream>
#include <limits>
#include <memory>
#include <sstream>
#include <string>





#include "FileHandler.hpp"
#include "Mode.hpp"
#include "UserInterface.hpp"



using namespace std;


// weighted distribution of random numbers in c++
// http://www.cplusplus.com/forum/general/69862/
string GenerateRand(int length, double frequencyAlive)
{
    
    double frequencyDead = 1 - frequencyAlive;
    
    std::random_device rd;
    std::mt19937 gen(rd());
    // generate the index number at weighted frequency
    // returns 0 for frequencyAlive or 1 for frequencyDead
    double weights[] = {frequencyAlive, frequencyDead};
    std::discrete_distribution<> d(std::begin(weights), std::end(weights));
    string fullText;
    int randNum;
    for(int i(0); i < length; ++i) {
        randNum = d(gen);
        //cout << "i: " << i << ", randNum: "<< randNum << " ";
        if ( randNum != 1)
        {
            fullText+="X";
            //cout << "alive\n";
        }
        else if ( randNum == 1)
        {
            fullText+="-";
            //cout << "dead\n";
        }
    }
    
    
    return fullText;
}

int main(int argc, const char * argv[])
{
    UserInterface ui;
    string fileName;
    ui.askMap();
    bool hasMap (ui.CheckForOneTwo());
    if (hasMap)
    {
        ui.displayProperFormat();
        fileName = ui.GetFileName();
    }
    ui.askMode();
    int mode(ui.CheckForOneTwoThree());
    ui.askPause();
    int pause(ui.CheckForOneTwoThree());
    int rows, cols;
    string fullText;
    // Generate Maps
    bool fOpenSuccess = false;
    if (hasMap)
    {
        FileHandler* fh = new FileHandler();
        // input file
        ifstream inFile;
        fOpenSuccess  = fh->SafeOpenRead(inFile, fileName);
        // read the dimensions of the 2 nums at top rows cols
        string line;
        getline(inFile, line);
        stringstream strToInt(line);
        strToInt >> rows;
        getline(inFile, line);
        strToInt.str("");
        strToInt.clear();
        strToInt << line;
        strToInt >> cols;
        while(getline(inFile, line))
        {
            ui.RemoveErroneousChars(line); // get only symbols needed
            fullText+=line;
        }
        //cout << fullText;
        inFile.close();
        // For each line read
        cout << "\n";
        delete fh;
    }
    else
    {
        cols = 0; rows = 0;
        // GENERATE RANDOM
        cout << "enter rows: ";
        cin >> rows;
        cout << "\n";
        cout << "enter columns: ";
        cin >> cols;
        cout << "\n";
        int length(rows*cols); // 3x2 = 6, 3x3 = 9 etc
        float frequencyAlive;
        cout << "\n";
        // living is 'X' dead is '-'
        cout << "enter percentage to be alive (decimal greater than 0 and less than or equal to 1): ";
        cin >> frequencyAlive;
        cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
        cout <<"\n";
        
        // cout << "rows, cols, decVal, length: \n" << " " << rows << " " << cols << " " << frequencyAlive << " " << length << "\n";
        
        // prompt for the dimensions of the world
        // prompt for a decimal value (greater than 0 and less than or equal to 1)
        // Randomly generate the initial cell configuration using the dimension and density inputs.
        fullText = GenerateRand(length, frequencyAlive);
        //cout << "fullText: \n" << fullText << "\n";
    }
if ((fOpenSuccess && hasMap)||!(hasMap))
        Mode(rows,cols,pause,fullText, mode).run();
    return 0;
}



