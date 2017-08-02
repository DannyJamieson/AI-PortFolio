#pragma once

#include<vector>

class Nodes
{
public:
	Nodes();
	~Nodes();

	static std::vector<Nodes*> objectList;

	float PosX, depth, PosY;
	float size;

	Nodes* children[4];

public:
	virtual void Think();
	virtual void Split();
};