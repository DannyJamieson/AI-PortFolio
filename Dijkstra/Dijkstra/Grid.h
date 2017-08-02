#pragma once
#include <vector>
#include <iostream>
struct Vector2 {
	int x, y;
};

class Grid
{
public:
	Grid();
	~Grid();
	void AddNeighbour(int NewNeighb, float Dist);

	virtual void Search(int Searching);
	virtual void Route();
	virtual void Distance();
	virtual void PushToActive();



	static std::vector<Grid*> RouteNodes;
	static std::vector<Grid*> Neighbours;
	static std::vector<Grid*> Active;
	static bool Found;
	static bool Finished;
	int x, y, MyInt, Parent;
	float CurrentDist;
	float Distances[6];

	std::vector<Grid*> MyNeighbours;
	bool Starter;
	bool Checked;


};

