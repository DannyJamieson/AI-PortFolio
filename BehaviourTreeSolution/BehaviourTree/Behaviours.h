#pragma once
#include "BlackboardBaseType.h"
#include <map>
enum Status
	/**
	* Return values of and valid states for behaviors.
	*/
{
	BH_INVALID,
	BH_SUCCESS,
	BH_FAILURE,
	BH_RUNNING,
	BH_ABORTED
};

class Behaviour
{
public:
	Behaviour() : currentStatus(BH_INVALID){
		currentStatus = BH_RUNNING;
	};
	~Behaviour(){};
	virtual void onInitialize(){}
	virtual Status update() = 0;
	virtual void onTerminate(Status) {}
	Status currentStatus;
};