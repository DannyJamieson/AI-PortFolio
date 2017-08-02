/*#include <glut.h>

int window1ID;


void DrawWindow1(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 1.0, 0.0);
	glPointSize(10);
	glBegin(GL_POINTS);
		glVertex2i(20, 20);
	glEnd();
	glBegin(GL_LINE_LOOP);
	// Now add in the vertices of the line
	glVertex2i(1, 1);
	glVertex2i(9, 1);
	glVertex2i(9, 9);
	glVertex2i(1, 9);
	glEnd();
	glViewport(0, 0, 10, 10);//Y U NO WORK?
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
	Timer(0);	
	glutMainLoop();
}

*/