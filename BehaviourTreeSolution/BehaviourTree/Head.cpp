#include "Head.h"



Head::Head()
{
}


Head::~Head()
{
}

Status Head::update() {
	for (auto &child : Children) {
		child->update();
	}
	return BH_SUCCESS;
}
