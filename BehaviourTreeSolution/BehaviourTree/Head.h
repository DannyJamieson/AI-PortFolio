#pragma once
#include "Sequence.h"
#include "Agent.h"
class Head : Sequence
{
public:
	Head();
	~Head();
	Status update() override;
	Agent *agent;
	virtual void AddChild(Behaviour*);
};

