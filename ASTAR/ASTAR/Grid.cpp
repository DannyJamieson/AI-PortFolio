#include "Grid.h"
#include <iostream>
#include <math.h>

int MyInt;
int Parent;
bool Starter = false;
std::vector<Grid*> Grid::Neighbours;
std::vector<Grid*> MyNeighbours;
std::vector<Grid*> Grid::RouteNodes;
bool Grid::Found;
bool Grid::Finished;
int Finding;
float CurrentDistance;
float NodeMovementTotal;
int MovementNode;
bool Checked;

Grid::Grid()
{
	Neighbours.push_back(this);
}


Grid::~Grid()
{
}

void Grid::AddNeighbour(int NewNeighb) {
	for (auto &r : Grid::Neighbours)
	{
		if (r->MyInt == NewNeighb) {
			MyNeighbours.push_back(r);
			break;
		}
	}
}


void Grid::Search(int Searching) {
	int NeighboursSearched=0;
	Checked = true;
	float temp;
	float temp2;
	float temp3;
	float temp4;



	if (Searching == MyInt) {
		std::cout << "Found Node " << MyInt << "\n";
		Grid::Found = true;
		Route();
		std::cout << "Total is: " << CurrentDistance << "\n";
	}
	else {
		while(!Found){

	

			if(MyNeighbours.size() ==0 || NeighboursSearched == MyNeighbours.size()){
				std::cout << "Break away from " << MyInt;
				break;
			}

			std::cout << "Searching around " << MyInt << "\n";
			for (auto &r : Grid::MyNeighbours) {
				if (Grid::Found) { 
					break; 
				}
			
				if(!(r->Checked)){
					temp2 = CurrentDistance;
					temp3 = (r->Grid::DistToEnd(Searching));
					temp4 = sqrt(pow(x - r->x, 2) + pow(y - r->y, 2));
					temp = temp2 += temp3 +=temp4;
					if (NodeMovementTotal > temp) {
						NodeMovementTotal = temp;
						MovementNode = r->MyInt;
					}
			
				}
			}
				temp = 0;
				std::cout << "Moving to " << MovementNode << "\n";
				for (auto &r : Grid::MyNeighbours) {
					if (r->MyInt == MovementNode) {
						r->Parent = MyInt;
						r->NodeMovementTotal = FLT_MAX;
						r->CurrentDistance = CurrentDistance + temp4;
						r->Search(Searching);
						NodeMovementTotal= FLT_MAX;
						MovementNode = NULL;
						NeighboursSearched++;
					}
			}
		}	
	}
}




float Grid::DistToEnd(int Search) {
	for (auto &r : Grid::Neighbours) {
		if (r->MyInt == Search) {
			return sqrt(pow(x - r->x, 2) + pow(y - r->y, 2));
		}
	}
}

void Grid::Route() {
	std::cout << "I am Part of the route: " << MyInt << "\n";
	RouteNodes.push_back(this);
	if (Starter == false) {
		for (auto &r : Grid::Neighbours)
		{
			if (r->MyInt == Parent) {
				r->Route();
			}
		}
	}
	else {
		Grid::Finished = true;
		
	}
}

