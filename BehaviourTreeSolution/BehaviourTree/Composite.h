#pragma once
#include "Behaviours.h"
#include <vector>

class Composite:public Behaviour
{


public:
	Composite();
	~Composite();
	virtual void onInitialize() override;
	std::vector <Behaviour*> Children;
	std::vector <Behaviour*>::iterator currentChild;
	void AddChild(Behaviour*);
	void RemoveChild(Behaviour*);

};

