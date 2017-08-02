#include "Grid.h"
#include <vector>
#include <math.h>

int MyInt;
int Parent;
bool Starter = false;
bool Checked = false;
std::vector<Grid*> Grid::Neighbours;
std::vector<Grid*> MyNeighbours;
std::vector<Grid*> Grid::RouteNodes;
bool Grid::Found;
bool Grid::Finished;
int Finding;
float Distances[6];

Grid::Grid()
{
	Neighbours.push_back(this);
	for (int i = 0; i < 6; i++) {
		Grid::Distances[i] = 100.0f;
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
			r->AddNew(MyInt, Dist);
			Distances[NewNeighb - 1] = Dist;
			break;
		}
	}
}

void Grid::AddNew(int Neighb, float Dist) {
	for (auto &r : Grid::Neighbours)
	{
		if (r->MyInt == Neighb) {
			MyNeighbours.push_back(r);
			Distances[Neighb - 1] = Dist;
			break;
		}
	}
}

void Grid::Search(int Searching) {
	Checked = true;
	if (Searching == MyInt) {
		std::cout << "Found Node " << MyInt << "\n";
		Grid::Found = true;
		Route();
	}
	else {
		for (auto &r : Grid::MyNeighbours) {
			if (Grid::Found) { break; }
			if (r->Checked == false) {
				std::cout << "Searching around " << MyInt << "\n";
				std::cout << "Moving to " << r->MyInt << "\n";
				r->Parent = MyInt;
				r->Search(Searching);
			}
		}
		if (!Finished) {
			std::cout << "Not found at " << MyInt << ". Returning to Parent: " << Parent << "\n";
		}
	}
}

void Grid::Route() {
	std::cout << "I am Part of the route: " << MyInt << "\n";
	RouteNodes.push_back(this);
	if (Starter == false) {
		for (auto &r : Grid::MyNeighbours)
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
				Total += r->Grid::Distances[s->MyInt - 1];
				break;
			}
		}



	}
	std::cout << "Total is: " << Total << "\n";
}
