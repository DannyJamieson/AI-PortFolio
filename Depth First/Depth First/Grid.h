#pragma once
#include <vector>
#include <iostream>
class Grid
{
public:
	Grid();
	~Grid();
	virtual void AddNeighbour(int NewNeighb, float Dist);
	virtual void AddNew(int Neighb, float Dist);
	virtual void Search(int Searching);
	virtual void Route();
	virtual void Distance();

	static std::vector<Grid*> RouteNodes;
	static std::vector<Grid*> Neighbours;
	static bool Found;
	static bool Finished;
	int x, y, MyInt, Parent, Finding;
	float Distances[6];

	std::vector<Grid*> MyNeighbours;
	bool Starter;
	bool Checked;


};

