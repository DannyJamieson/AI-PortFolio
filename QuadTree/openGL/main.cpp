#include <glut.h>
#include "Nodes.h"
#include "Targets.h"

int window1ID;
bool Start = false;

//std::vector<Nodes*> objectList;
//std::vector<Targets*> TargetList;

void Display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);
	for (auto &r : Targets::TargetList)
	{
		glBegin(GL_POINTS);

		glVertex2i(r->x, r->y);
		glEnd();



	}


	glColor3f(0.0, 1.0, 0.0);

	for (auto &r : Nodes::objectList)
	{
		glPointSize(8);
		glBegin(GL_LINES);

		glVertex2i(r->PosX, r->PosY);
		glVertex2i(r->PosX, r->PosY + r->size);

		glVertex2i(r->PosX, r->PosY + r->size);
		glVertex2i(r->PosX + r->size, r->PosY + r->size);

		glVertex2i(r->PosX + r->size, r->PosY + r->size);
		glVertex2i(r->PosX + r->size, r->PosY);

		glVertex2i(r->PosX + r->size, r->PosY);
		glVertex2i(r->PosX, r->PosY);
		glEnd();

		
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
	glutInitWindowSize(800, 800);
	glutInitWindowPosition(100, 100);
	window1ID = glutCreateWindow("Window 1");
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 250.0, 0.0, 250.0);
	Timer(0);
	if (!Start) {
		for (int i = 0; i < 4; i++) {
			Targets* Target = new Targets();
			Target->Make();
		}

		Start = true;
		Nodes* node = new Nodes();
		node->size = 250.0;
		node->depth = 0;
		node->PosX = 0;
		node->PosY =0;
		node->Think();
	}
	glutDisplayFunc(Display);//This is the part that draws to the window
	glutMainLoop();
}