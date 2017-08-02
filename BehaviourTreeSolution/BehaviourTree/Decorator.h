#pragma once
#include "Behaviours.h"

class Decorator:public Behaviour
{
public:
	Decorator();
	~Decorator();
	void AddChild(Behaviour*);
	Behaviour* child; 
};

