#include "Nodes.h"
#include "Targets.h"

float PosX, depth, PosY;
float size;
std::vector<Nodes*> Nodes::objectList;


void Nodes::Think(){
	for (auto &r : Targets::TargetList){
		if(r->x > PosX && r->x <(PosX + size) && r->y > PosY &&r->y < (PosY+size)){//if the target is inside me
			Split();
			break;
	
		}
	}
}

Nodes::Nodes()
{
	objectList.push_back(this);
}




void Nodes::Split(){
	if (depth <6) {
	int k=0;
		for (int i = 0; i < 2; i++){
			for (int j = 0; j < 2; j++){
				Nodes* node = new Nodes();
				node->size = size / 2;
				node->depth = depth + 1;
				node->PosX = PosX + ((size / 2) * j);
				node->PosY = PosY + ((size / 2) * i);
				node->Think();
				children[k] = node;
				k++;

			}
		}
	}
}
