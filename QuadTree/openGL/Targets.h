#pragma once

#include<vector>

class Targets
{
public:
	Targets();
	~Targets();

	static std::vector<Targets*> TargetList;
	float x,y;

	
public:
	virtual void Make();
};

