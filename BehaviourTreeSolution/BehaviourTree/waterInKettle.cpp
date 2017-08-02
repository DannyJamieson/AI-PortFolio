#include "waterInKettle.h"



waterInKettle::waterInKettle()
{
}


waterInKettle::~waterInKettle()
{
}


Status waterInKettle::update() {
	if (currentStatus == BH_INVALID) {
		onInitialize();
	}



	return currentStatus;

}