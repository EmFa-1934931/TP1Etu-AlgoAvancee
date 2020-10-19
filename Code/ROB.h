#pragma once
class ROB
{
public:
	ROB(Cube* cube);
	~ROB();
	void solvePathToExit();
	string getSolutionPathToExit();

private:
	Pile pathToEnd;
	Cube* cube;
};

