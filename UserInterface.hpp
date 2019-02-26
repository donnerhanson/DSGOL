//
//  UserInterface.hpp
//  GameOfLife
//
//  Created by Donner Hanson on 2/19/19.
//  Copyright © 2019 Donner Hanson. All rights reserved.
//

#ifndef UserInterface_hpp
#define UserInterface_hpp

#include <stdio.h>
#include <string>

using namespace std;



class UserInterface{
public:
    bool CheckForOneTwo();
    int CheckForOneTwoThree();
    string GetFileName();
    // string manipulation
    string Capitalize(string &str);
    bool isNotWS(const string &str);
    string RemoveErroneousChars(string& str);
    
    // Questions
    void askMap();
    void askMode();
    void askPause();
    void displayProperFormat();
    
private:
};

#endif /* UserInterface_hpp */

