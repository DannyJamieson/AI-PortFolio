#pragma once

#include "BaseEntity.h"

class Nodes : public BaseEntity
{
public:
	Nodes();
	~Nodes();
	int x;
	int y;
	float size;

public:
	void Think() {};
	void Initialize() override;
};



