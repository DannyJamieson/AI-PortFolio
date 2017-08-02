#pragma once
#include "Behaviours.h"
#include "BlackboardBaseType.h"
#include <map>
class Leaf:public Behaviour
{
public:
	Leaf();
	~Leaf();
	void onInitialize() override {currentStatus = BH_RUNNING;};
};

