#include "Selector.h"



Selector::Selector()
{
}


Selector::~Selector()
{
}

Status Selector::update() {
	if(currentStatus==BH_INVALID)
		onInitialize();
	// keep going until child says it is running
	Status s = (*currentChild)->update();
	// if a child is running or has failed, 
	// keep going until we hit the end of the array
	if(s==BH_RUNNING){}

	else if (s != BH_ABORTED && s != BH_INVALID) {
		if (++currentChild == Children.end())
			return BH_SUCCESS;
	}
	else {
		return s;
	}
}
