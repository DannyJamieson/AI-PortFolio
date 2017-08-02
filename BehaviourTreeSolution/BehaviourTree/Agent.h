#pragma once
#include "Behaviours.h"
#include"BlackboardBaseType.h"
#include <map>

#pragma endregion

class Agent
{
public:
	Agent();
	Status currentTreeState;
	std::map<const char *, BlackboardBaseType*> blackboard;
	void update();
};

