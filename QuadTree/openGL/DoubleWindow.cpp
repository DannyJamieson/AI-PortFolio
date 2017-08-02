/*#include <glut.h>

int window1ID;
int window2ID;


void DrawWindow1(void) {
	glutSetWindow(window1ID);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 0.0);
	glBegin(GL_QUADS);
	glVertex2i(10, 10);
	glVertex2i(10, 200);
	glVertex2i(25, 200);
	glVertex2i(25, 10);
	glEnd();
	glutSwapBuffers();
}

void DrawWindow2(void) {
	glutSetWindow(window2ID);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 0.0);
	glBegin(GL_QUADS);
	glVertex2i(10, 10);
	glVertex2i(10, 200);
	glVertex2i(25, 200);
	glVertex2i(25, 10);
	glEnd();
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
	glutInitWindowSize(400, 400);
	glutInitWindowPosition(100, 100);
	window1ID = glutCreateWindow("Window 1");
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 250.0, 0.0, 250.0);
	glutDisplayFunc(DrawWindow1);


	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(400, 400);
	glutInitWindowPosition(500, 100);
	window2ID = glutCreateWindow("Window 2");
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 250.0, 0.0, 250.0);

	glutDisplayFunc(DrawWindow2);
	Timer(0);



	//glutSwapBuffers();
	glutMainLoop();
}

*/