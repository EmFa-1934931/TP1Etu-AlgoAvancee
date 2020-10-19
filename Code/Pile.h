#include "stdafx.h"
#include "Block.h"
#include "Noeud.h"
#pragma once
using namespace std;

class Pile
{
public:
	Pile();
	~Pile();
	void push(Block* _block);
	Block* pop();
	string reverseToString();

private:
	Noeud* getPremierNoeud();
	Noeud* premierNoeud;
};
