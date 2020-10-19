#pragma once
#include "stdafx.h"

class Noeud
{
public:
	Noeud();
	~Noeud();
	Noeud* getSuivant();
	void setSuivant(Noeud* _suivant);
	Block* getBlock();
	void setBlock(Block* _block);

private:
	Block* block;
	Noeud* suivant;
};

