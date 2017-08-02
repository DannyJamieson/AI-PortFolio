#include "Grid.h"
#include <vector>
//#include <math.h>

int MyInt;
int Parent;
bool Starter;
float CurrentDist;
std::vector<Grid*> Grid::Neighbours;
std::vector<Grid*> MyNeighbours;
std::vector<Grid*> Grid::RouteNodes;
std::vector<Grid*> Grid::Active;
bool Grid::Found;
bool Grid::Finished;
float Distances[6];

Grid::Grid()
{
	Neighbours.push_back(this);
	for (int i = 0; i < 6; i++) {
		Grid::Distances[i] = 0.0f;
	}
}

Grid::~Grid()
{
}

void Grid::AddNeighbour(int NewNeighb, float Dist) {
	for (auto &r : Grid::Neighbours)
	{
		if (r->MyInt == NewNeighb) {
			MyNeighbours.push_back(r);
			Distances[NewNeighb - 1] = Dist;
			break;
		}
	}
}

void Grid::Search(int Searching) {
	std::cout << "Searching Around " << MyInt << "\n";
	if (Searching == MyInt) {
		std::cout << "Found Node " << MyInt << "\n";
		Grid::Found = true;
		Route();
	}
	else {//are my neighbours closer with me?
		for (auto &r : Grid::MyNeighbours) {
			if (CurrentDist + Distances[r->MyInt - 1] < r->CurrentDist) {
				r->Parent = MyInt;//make parent
				r->CurrentDist = CurrentDist + Distances[r->MyInt - 1];//change distance
				r->PushToActive();//make them active
				std::cout << "Adding " << r->MyInt << " To active" << "\n";
			}
		}
		Active.erase(Active.begin(), Active.begin()+1);//take me out of the array
	}
}

void Grid::PushToActive() {
	int Counter = 0;
	for (auto &r : Grid::Active) {
		if (r->CurrentDist >= CurrentDist) { break; }
		Counter++;
	}
	Active.insert(Grid::Active.begin() + Counter, 1, this);
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
		Grid::Distance();//Called on starter
	}
}


void Grid::Distance() {
	float Total = 0;
	bool Add = false;

	for (auto &r : Grid::RouteNodes) {
		//through RouteNodes. r
		for (auto &s : Grid::RouteNodes) {


			if (s->MyInt == r->Parent) {
				Total += s->Grid::Distances[r->MyInt - 1];
				break;
			}
		}
	}
	std::cout << "Total is: " << Total << "\n";
}
