#include "Nodes.h"

Nodes* grid[5][5];
int main() {
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				Nodes* node = new Nodes();
				node->x = i;
				node->y = j;
				grid[i][j] = node;
			}
		}
}