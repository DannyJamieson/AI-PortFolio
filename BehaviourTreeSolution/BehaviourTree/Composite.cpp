#include "Composite.h"

Composite::Composite()
{
}



Composite::~Composite()
{
}

void Composite::onInitialize() {
	currentStatus = BH_RUNNING;
	currentChild=Children.begin();
}


void Composite::AddChild(Behaviour* Child){
	Children.push_back(Child);
}

void Composite::RemoveChild(Behaviour* Child){
	int Counter=0;
	for (auto &ChildPointer : Children) {
		if (ChildPointer == Child) {
			break;
		}
		Counter++;
	}
	Children.erase(Children.begin() + Counter);
}

