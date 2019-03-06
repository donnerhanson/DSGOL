//================================================================
// Author      : Donner Hanson
// Date        : 02/27/2019
// Email       : hanso127@mail.chapman.edu
// Course      : Data Structures and Algorithms
// Course #    : CPSC-350-2
// Project Name: Game Of Life
// File Name   : UserInterface.cpp
// Assignment  : Assignment 2
// Version     : 0.3
// Instructor  : Rene German
// Description : General Questions to ask user and process input
//================================================================

#include <algorithm>
#include <iostream>
#include <string>

#include "UserInterface.hpp"

using namespace std;


// re-iterative questions
const string ASK_ONE_TWO = "Please enter 1 or 2...\n";
const string ASK_ONE_TWO_THREE = "Please enter 1, 2, or 3...\n";
// Direct Questions
const string ASK_MAP_OR_RAND = "Press:\n1: To provide your own map\n"
                                    "2: Randomly generate simulation\n"
                                    "Followed by return....\n";
const string ASK_MODE = "Press:\n1: Classic\n2: Doughnut\n3: Mirror\n"
                            "Followed by return...\n";
const string ASK_PAUSE = "Press:\n1: Pause between generations\n"
                            "2: Run simulation pressing enter between"
                            " generations\n3: Output to a file\n"
                            "Followed by return...\n";
const string MAP_FORMAT =  "File must contain formatting of height width "
                                "and map layout:\n5\n7\n---X--X\n-X--X--\n"
                                "-----XX\nX-X-X--\n-----XX\n";
const string ASK_FILE = "Enter file path....\n";

const string TEST_FILE_IN = "/Users/Donner/Documents/workspace1/"
                            "GameOfLife/GameOfLife/mapdonut.txt";
const string TEST_FILE_OUT = "/Users/Donner/Documents/workspace1"
                                "/GameOfLifeTwo/GameOfLifeTwo/GOLresults.txt";
string UserInterface::GetInFileName()
{
    string fileName;
    cout << ASK_FILE;
    getline(cin, fileName);
    // if the filename is greater than zero
    // if user dragged file sometimes there is
    // ending whitespace in string
    //fileName = TEST_FILE_IN;
    if (fileName.size() > 0 && isNotWS(fileName))
    {
        while(fileName.at(fileName.size()-1) == '\n' ||
              fileName.at(fileName.size()-1) == ' ')
        {
            // remove ending whitespace
            fileName.pop_back();
        }
    }
    cout << "entered file: " << fileName << "\n";
    return fileName;
}

string UserInterface::GetOutFileName()
{
    string fileName;
    cout << ASK_FILE;
    getline(cin, fileName);
    // if the filename is greater than zero
    // if user dragged file sometimes there is
    // ending whitespace in string
    // fileName = TEST_FILE_OUT;
    if (fileName.size() > 0 && isNotWS(fileName))
    {
        while(fileName.at(fileName.size()-1) == '\n' ||
              fileName.at(fileName.size()-1) == ' ')
        {
            // remove ending whitespace
            fileName.pop_back();
        }
    }
    cout << "entered file: " << fileName << "\n";
    return fileName;
}

bool UserInterface::CheckForOneTwo()
{
    string input = " ";
    char answer;
    try // if user presses newline without input -> false
    {
        // clear in stream
        cin.sync();
        getline(cin, input);
        answer = input.at(0);
        while (answer != '1' && answer != '2')
        {
            
            cin.sync();
            cout << ASK_ONE_TWO;
            getline(cin, input);
            answer = input.at(0);
        }
        if(input.at(0) == '1')
        {
            cin.sync();
            return true;
        }
        else
        {
            cin.sync();
            return false;
        }
    }
    catch(...)
    {
        cin.sync();
        return false;
    }
}
int UserInterface::CheckForOneTwoThree()
{
    string input = " ";
    char answer;
    try // if user presses newline without input -> false
    {
        // clear in stream
        cin.sync();
        getline(cin, input);
        answer = input.at(0);
        while (answer != '1' && answer != '2' && answer != '3')
        {
            
            cin.sync();
            cout << ASK_ONE_TWO_THREE;
            getline(cin, input);
            answer = input.at(0);
        }
        if(input.at(0) == '1')
        {
            cin.sync();
            return 1;
        }
        else if(input.at(0) == '2')
        {
            cin.sync();
            return 2;
        }
        else
        {
            cin.sync();
            return 3;
        }
    }
    catch(...)
    {
        cin.sync();
        return false;
    }
}

string UserInterface::Capitalize(string &str)
{
    // use algorithm to uppercase all input
    transform(str.begin(), str.end(), str.begin(), ::toupper);
    return str;
}
bool UserInterface::isNotWS(const string &str)
{
    return str.find_first_not_of(' ') != string::npos;
}
string UserInterface::RemoveErroneousChars(string& str)
{
    string temp;
    
    for (int i(0); i < str.length(); ++i)
    {
        // if a correct letter add to temp string
        if(str.at(i) == 'X' || str.at(i) == '-')
            temp+=str.at(i);
    }
    // the referenced str now is updated program wide
    str = temp;
    return str;
}

// Questions
void UserInterface::askMap()
{
    cout << ASK_MAP_OR_RAND;
}
void UserInterface::askMode()
{
    cout << ASK_MODE;
}
void UserInterface::askOutputMode()
{
    cout << ASK_PAUSE;
}
void UserInterface::displayProperFormat()
{
    cout << MAP_FORMAT;
}



