#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include "Block.h"

using namespace std;

class Cube
{
public:
	Cube(string cubePath);
    ~Cube();	
	Block* GetStartBlock();

private:
	Block* startBlock;
	Block* tabBlocks[5][5][5];
};