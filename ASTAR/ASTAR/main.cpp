#include <glut.h>
#include "Grid.h"
#include <vector>
int window1ID;
bool Start = false;

struct Vector2 {
	int x, y;
};

Vector2 Current;
Vector2 Previous = { 0,0 };



void Display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);
	for (int i = 0;i < 8;i++) {
		glBegin(GL_LINES);
		glVertex2i(2 * i, 0);
		glVertex2i(2 * i, 16);
		glEnd();
	}
	for (int j = 0;j < 8;j++) {
		glBegin(GL_LINES);
		glVertex2i(0, 2 * j);
		glVertex2i(16, 2 * j);
		glEnd();
	}
	for (auto &r : Grid::Neighbours)
	{
		glColor3f(0.0, 0.0, 1.0);//Draws the nodes
		glPointSize(4);
		glBegin(GL_POINTS);
		glVertex2i((r->x), (r->y));
		glEnd();
		glColor3f(0.0, 0.0, 0.0);
		for (auto &s : r->MyNeighbours) {//Draws the path between nodes
			glBegin(GL_LINES);
			glVertex2i(r->x, r->y);
			glVertex2i(s->x, s->y);
			glEnd();
		}

	}
	glColor3f(0.0, 1.0, 0.0);
	if (Grid::Finished) {//draws the lines of the finished route. 
		bool Draw = false;
		Previous = { 0,0 };
		Current = { 0,0 };
		for (auto &r : Grid::RouteNodes) {

			Previous = Current;
			if (Previous.x != 0) {
				Draw = true;
			}
			else {
				Draw = false;
			}
			Current = { r->x,r->y };
			if (Draw) {
				glBegin(GL_LINES);
				glVertex2i(Current.x, Current.y);
				glVertex2i(Previous.x, Previous.y);
				glEnd();
			}
		}

	}
	glutSwapBuffers();
}


void Timer(int iUnused)
{
	glutPostRedisplay();
	glutTimerFunc(1, Timer, 0);
}


void main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(100, 100);
	window1ID = glutCreateWindow("Window 1");
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 16.0, 0.0, 16.0);

	if (!Start) {
		Start = true;
		Grid* A = new Grid();//Node set up
		A->x = 1;
		A->y = 9;
		A->MyInt = 1;
		A->Starter = false;
		A->Checked = false;
		Grid* B = new Grid();
		B->x = 3;
		B->y = 25;
		B->MyInt = 2;
		B->Starter = false;
		B->Checked = false;
		Grid* C = new Grid();
		C->x = 5;
		C->y = 3;
		C->MyInt = 3;
		C->Starter = false;
		C->Checked = false;
		Grid* D = new Grid();
		D->x = 7;
		D->y = 13;
		D->MyInt = 4;
		D->Starter = false;
		D->Checked = false;
		Grid* E = new Grid();
		E->x = 7;
		E->y = 7;
		E->MyInt = 5;
		E->Starter = false;
		E->Checked = false;
		Grid* F = new Grid();
		F->x = 13;
		F->y = 9;
		F->MyInt = 6;
		F->Starter = false;
		F->Checked = false;

		A->AddNeighbour(2);//Neighbours
		A->AddNeighbour(3);
		B->AddNeighbour(4);
		C->AddNeighbour(5);
		D->AddNeighbour(5);
		D->AddNeighbour(6);
		E->AddNeighbour(6);

		A->Starter = true;//Select starting node
		A->CurrentDistance = 0;
		A->NodeMovementTotal = FLT_MAX;
		A->Search(6);//Select searched for node.
		
	}
	Timer(0);//timer to prevent frame tearing
	glutDisplayFunc(Display);//This is the part that draws to the window
	glutMainLoop();//Loops
}