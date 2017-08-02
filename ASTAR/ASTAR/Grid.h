#pragma once
#include <vector>
class Grid
{
public:
	Grid();
	~Grid();
	void AddNeighbour(int NewNeighb);
	void Search(int Searching);
	void Route();
	void Distance();

	float DistToEnd(int Search);
	static std::vector<Grid*> RouteNodes;
	static std::vector<Grid*> Neighbours;
	static bool Found;
	static bool Finished;
	bool Checked;
	int x, y, MyInt, Parent, Finding;

	std::vector<Grid*> MyNeighbours;
	bool Starter;
	float CurrentDistance;
	float NodeMovementTotal;
	int MovementNode;
};

