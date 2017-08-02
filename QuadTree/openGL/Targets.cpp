#include "Targets.h"
#include "UtilRandom.h"
#include <vector>

std::vector<Targets*> Targets::TargetList;

float x;
float y; 




Targets::Targets()
{
	TargetList.push_back(this);
}


Targets::~Targets()
{
}

void Targets::Make() {
	x = UtilRandom::instance()->GetRange(0, 250.0);
	y = UtilRandom::instance()->GetRange(0, 250.0);
}
