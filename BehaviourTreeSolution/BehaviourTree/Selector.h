#pragma once
#include "Composite.h"

class Selector :public Composite
{
public:
	virtual Status update() override;
	Selector();
	~Selector();
};
