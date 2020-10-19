#include "stdafx.h"

Cube::Cube(string cubePath)
{
	ifstream streamInput;
	streamInput.open(cubePath);
	string currentLine;

	if (!streamInput)
	{
		string exceptionCaption = "Le fichier " + cubePath + " n'existe pas.";
		//Cette exception doit être gérée
		throw invalid_argument(exceptionCaption);
	}
	
	for (int z = 0; z < 5; z++ )
	{
		//on "brule" le caractère "+" ici, ceci ne fait que passer par dessus.
		getline(streamInput, currentLine);

		for (int y = 4; y >= 0; y--)
		{
			getline(streamInput, currentLine);

			for (int x = 0; x < 5; x++)
			{
				//Allocation des blocs dans le tableau 3D
				Block* block = new Block();
				block->x = x; 
				block->y = y;
				block->z = z; 

				block->value = currentLine[x];

				this->tabBlocks[x][y][z] = block;

				if (block->value == 'S')
					this->startBlock = block;

				//Logique des chaînages
				if (x > 0)
					block->leftBlock = tabBlocks[x - 1][y][z];
				if (x < 5)
					block->rightBlock = tabBlocks[x + 1][y][z];
				if (y > 0)
					block->behindBlock = tabBlocks[x][y + 1][z];
				if (y < 4)
					block->frontBlock = tabBlocks[x][y - 1][z];
				if (block->value == 'U')
					block->upBlock = tabBlocks[x][y][z + 1];
				else if (block->value == 'D')
					block->downBlock = tabBlocks[x][y][z - 1];
			}
		}
	}
	streamInput.close();
}

Cube::~Cube()
{
	//suppression du contenu de chaque bloc
	for (int z = 0; z < 5; z++)
	{
		for (int y = 4; y >= 0; y--)
		{
			for (int x = 0; x < 5; x++)
			{
				this->tabBlocks[x][y][z] = NULL;
			}
		}
	}
}

Block* Cube::GetStartBlock()
{
	if (this->startBlock == NULL)
		return NULL;

	return this->startBlock;
}