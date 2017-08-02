#include "Sequence.h"

Sequence::Sequence()
{
}


Sequence::~Sequence()
{
}


void Sequence::onTerminate(Status) {

}

Status Sequence::update() {
	if (currentStatus == BH_INVALID)
		onInitialize();
	// keep going until child says it is running
	while (true) {
		Status s = (*currentChild)->update();    
		// if a child is running or has failed, return the same
		if (s != BH_SUCCESS) return s;
		// keep going until we hit the end of the array
		if (++currentChild == Children.end())
			return BH_SUCCESS;
	}
	return BH_INVALID;
}

