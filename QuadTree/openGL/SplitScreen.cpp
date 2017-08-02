/*#include <glut.h>
int X=10;
int Y=10;

int window1ID;
int window2ID;


void DrawWindow1(void) {
	glutSetWindow(window1ID);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 1.0, 0.0);
	glBegin(GL_QUADS);
		glVertex2i(X, Y);
		glVertex2i(X, Y + 10);
		glVertex2i(X + 10, Y + 10);
		glVertex2i(X + 10, Y);
	glEnd();
	glutSwapBuffers();
}

void DrawWindow2(void) {
	glutSetWindow(window2ID);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_QUADS);
		glVertex2i(X, Y);
		glVertex2i(X, Y+10);
		glVertex2i(X+10, Y+10);
		glVertex2i(X+10, Y);
	glEnd();
	glutSwapBuffers();
}


void keyboard(unsigned char key, int a, int b) {
	switch (key) {
	case 97://a
		if (X>0) { X = X -1; }
	break;
	case 100://d
		if (X<250) { X = X +1; }
	break;
	case 115://s
		if (Y>0) { Y--; }
	break;

	case 119: //w
		if (Y<250) { Y = Y + 1; }
	break;
	}
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
glutKeyboardFunc(keyboard);
gluOrtho2D(0.0, 250.0, 0.0, 250.0);

glutDisplayFunc(DrawWindow2);
Timer(0);



//glutSwapBuffers();
glutMainLoop();
}

*/