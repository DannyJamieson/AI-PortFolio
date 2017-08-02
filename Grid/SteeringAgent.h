#pragma once
#include "BaseEntity.h"
class SteeringAgent :
	public BaseEntity
{
public:
	SteeringAgent();
	~SteeringAgent();
	void Think();
};

