/*#include <glut.h>
#include <iostream>
#include "LoadIdentity.h"

GLfloat elems[] ={	2.0, 0.0, 0.0, 0.0,
					0.0, 2.0, 0.0, 0.0,
					0.0, 0.0, 2.0, 0.0,
					0.0, 0.0, 0.0, 1.0 };

GLfloat i = 1;
GLint tester=1;

void display(void){

	//glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);

	//if(tester==5){
		glLoadIdentity();
		//tester=1;
	//}
	glColor3f(0,0,1);
	glBegin(GL_QUADS);
	//for(i; i < 10; i++)
	
		
			glVertex2i(5, 5);
			glVertex2i(5, 10);
			glVertex2i(10, 10);
			glVertex2i(10, 5);

	glEnd();

	glMultiMatrixf(elems);
	
	
	glutSwapBuffers();
	//tester = tester + 1;
}

void timer(int a)
{
	glutPostRedisplay();
	glutTimerFunc(1000, timer, 0);
}

void main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

	glutInitWindowSize(500, 500);

	glutInitWindowPosition(100, 100);

	glutCreateWindow("Mystical boxes");

	glClearColor(1.0, 1.0, 1.0, 0.0);


	glMatrixMode(GL_PROJECTION);
	glMatrixMode(GL_MODELVIEW);


	gluOrtho2D(0.0, 250.0, 0.0, 250.0);


	glutDisplayFunc(display);
	timer(0);

	glutMainLoop();
}
*/

