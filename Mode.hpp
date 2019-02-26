//
//  ClassicMode.hpp
//  GameOfLife
//
//  Created by Donner Hanson on 2/20/19.
//  Copyright © 2019 Donner Hanson. All rights reserved.
//

#ifndef Mode_hpp
#define Mode_hpp

#include <fstream>
#include <iostream>
#include <limits>
#include <memory>
#include <sstream>
#include <string>

#include "FileHandler.hpp"
#include "UserInterface.hpp"

using namespace std;
class Mode
{
public:
    Mode(int rows, int cols, int pause, string fullText, int mode): rows(rows),cols(cols), pause(pause), fullText(fullText), mode(mode){};
    
    void run();
private:
    int rows;
    int cols;
    int pause;
    int mode;
    string fullText;
};

#endif /* ClassicMode_hpp */

