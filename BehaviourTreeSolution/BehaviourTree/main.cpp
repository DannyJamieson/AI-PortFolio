#include <glut.h>
#include <string>
#include "Agent.h"
#include "Head.h"
#include "SleepAction.h"
#include "SleepCondition.h"
#include "SleepSelector.h"

void DrawWindow(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 0.0, 0.0);
	glutSwapBuffers();
}

void Timer(int iUnused)
{
	glutPostRedisplay();
	glutTimerFunc(1, Timer, 0);
}

void main(int argc, char *argv[])
{



	Agent *agent = new Agent();
	Head  *head = new Head();
	head->agent = agent;
	SleepSelector *sleep = new SleepSelector();
	head->AddChild(sleep);

	SleepAction *sleepAction = new SleepAction();

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(800, 600);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Window 1");
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 250.0, 0.0, 250.0);
	Timer(0);
	glutDisplayFunc(DrawWindow);
	glutMainLoop();
}