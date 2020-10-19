#include "stdafx.h"

Pile::Pile()
{
	this->premierNoeud = NULL;
}


Pile::~Pile()
{
	while (this->premierNoeud != NULL)
		pop();
}

void Pile::push(Block* _block)
{
	Noeud* nextNoeud = new Noeud;
	(*nextNoeud).setSuivant(this->premierNoeud);
	(*nextNoeud).setBlock(_block);

	this->premierNoeud = nextNoeud;
}

Block* Pile::pop()
{

	Block* livre = NULL;

	if (premierNoeud != NULL)
		livre = premierNoeud->getBlock();
	else
		return NULL;

	Noeud* temp = premierNoeud->getSuivant();
	this->premierNoeud->~Noeud();
	premierNoeud = temp;

	return livre;
}

string Pile::reverseToString()
{
	if (this->premierNoeud == NULL)
		return NULL;
	else {
		Pile tempPile;

		
	}
}

Noeud* Pile::getPremierNoeud() {
	return this->premierNoeud;
}

