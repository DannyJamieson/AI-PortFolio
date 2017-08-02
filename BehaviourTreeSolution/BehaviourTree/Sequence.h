#pragma once
#include "Composite.h"
class Sequence:public Composite
{
public:
	virtual Status update();
	virtual void onTerminate(Status) override;
	virtual void AddChild(Behaviour*);
	Sequence();
	~Sequence();
};

