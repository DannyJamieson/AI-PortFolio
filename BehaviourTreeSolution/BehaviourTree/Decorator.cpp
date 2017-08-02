#include "Decorator.h"



Decorator::Decorator()
{
}


Decorator::~Decorator()
{
}

void Decorator::AddChild(Behaviour* childPointer){
	child = childPointer;
}
