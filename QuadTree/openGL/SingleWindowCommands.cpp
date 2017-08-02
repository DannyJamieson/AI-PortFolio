/*#include <glut.h>
bool FullScreen=false;

int window1ID;

void DrawWindow1(void){
glClear(GL_COLOR_BUFFER_BIT);
glColor3f(1.0, 0.0, 0.0);
glPointSize(10);
glBegin(GL_POINTS);
glVertex2i(10, 10);
glEnd(); 
glutSwapBuffers();
}

void keyboard(unsigned char key, int a, int b) {
	switch (key) {
	case 97://a Change Title
		glutSetWindowTitle("Changed title");
		break;

	case 98://b Reposition Window
		glutPositionWindow(300, 300);
		break;
	case 99://c Full Screen Toggle
		if(FullScreen==false){ 
		glutFullScreen(); 
		}

		else if (FullScreen == true) { 
		glutReshapeWindow(400, 400); 
		glutPositionWindow(100, 100);
		}

		FullScreen = !FullScreen;
		break;
	case 100://d Iconify and title change
		glutIconifyWindow();

		glutSetIconTitle("Hidden");

		break;
	case 101://e Push
		glutPushWindow();

		break;
	case 102://f Pop
		glutPopWindow();

		break;
	case 103://g DESTROY
		glutDestroyWindow(window1ID);
		break;
	case 104://h

		break;
	case 105://i

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
	glutKeyboardFunc(keyboard);
	gluOrtho2D(0.0, 250.0, 0.0, 250.0);
	Timer(0);
	glutDisplayFunc(DrawWindow1);
	glutMainLoop();
}





*/