#include "stdafx.h"
#include "ROB.h"

ROB::ROB(Cube* cube) {
    cube = this->cube;
}

ROB::~ROB() {
    cube->~Cube();
}

void ROB::solvePathToExit()
{
    bool pathFound = false;
    Block* currentBlock = cube->GetStartBlock();
    currentBlock->visited = true;

    //trouve le chemin vers la sortie E et met chaque déplacement dans une pile
    while (!pathFound) {
        if (currentBlock->value == 'E') {
            pathFound = true;
        }
        //ROB regarde si un bloc autour de lui n'a pas été visité
        else if (currentBlock->upBlock != nullptr) {
            currentBlock = currentBlock->upBlock;
            this->pathToEnd.push(currentBlock);
            currentBlock->visited = true;
        }
        else if (currentBlock->downBlock != nullptr) {
            currentBlock = currentBlock->downBlock;
            this->pathToEnd.push(currentBlock);
            currentBlock->visited = true;
        }
        else if (currentBlock->leftBlock->value != '*' && !currentBlock->leftBlock->visited) {
            currentBlock = currentBlock->leftBlock;
            this->pathToEnd.push(currentBlock);
            currentBlock->visited = true;
        }
        else if (currentBlock->rightBlock->value != '*' && !currentBlock->rightBlock->visited) {
            currentBlock = currentBlock->rightBlock;
            this->pathToEnd.push(currentBlock);
            currentBlock->visited = true;
        }
        else if (currentBlock->frontBlock->value != '*' && !currentBlock->leftBlock->visited) {
            currentBlock = currentBlock->frontBlock;
            this->pathToEnd.push(currentBlock);
            currentBlock->visited = true;
        }
        else if (currentBlock->behindBlock->value != '*' && !currentBlock->leftBlock->visited) {
            currentBlock = currentBlock->frontBlock;
            this->pathToEnd.push(currentBlock);
            currentBlock->visited = true;
        }
        //Si ROB est bloqué, il recule d'un bloc et sort le dernier déplacement de la pile
        else {
            currentBlock->visited = true;
            currentBlock = this->pathToEnd.pop();
        }
    }
}

string ROB::getSolutionPathToExit()
{
    //appelle la fonction qui inverse les éléments d'une pile
    //prend chaque élément de la pile et les met dans un string
    return string();
}
