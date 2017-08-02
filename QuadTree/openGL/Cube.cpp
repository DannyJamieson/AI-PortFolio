/*
#include <glut.h>  


GLint giXRes = 800;
GLint giYRes = 800;



void drawCube() {
	glBegin(GL_QUADS);

	// Define vertices in counter-clockwise (CCW) order with normal pointing out
	glColor3f(0.0f, 1.0f, 0.0f);		// Green
	glVertex3f(1.0f, 1.0f, -1.0f);
	glVertex3f(-1.0f, 1.0f, -1.0f);
	glVertex3f(-1.0f, 1.0f, 1.0f);
	glVertex3f(1.0f, 1.0f, 1.0f);

	// Bottom face (y = -1.0f)
	glColor3f(1.0f, 0.5f, 0.0f);		// Orange
	glVertex3f(1.0f, -1.0f, 1.0f);
	glVertex3f(-1.0f, -1.0f, 1.0f);
	glVertex3f(-1.0f, -1.0f, -1.0f);
	glVertex3f(1.0f, -1.0f, -1.0f);

	// Front face  (z = 1.0f)
	glColor3f(1.0f, 0.0f, 0.0f);		// Red
	glVertex3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-1.0f, 1.0f, 1.0f);
	glVertex3f(-1.0f, -1.0f, 1.0f);
	glVertex3f(1.0f, -1.0f, 1.0f);

	// Back face (z = -1.0f)
	glColor3f(1.0f, 1.0f, 0.0f);		// Yellow
	glVertex3f(1.0f, -1.0f, -1.0f);
	glVertex3f(-1.0f, -1.0f, -1.0f);
	glVertex3f(-1.0f, 1.0f, -1.0f);
	glVertex3f(1.0f, 1.0f, -1.0f);

	// Left face (x = -1.0f)
	glColor3f(0.0f, 0.0f, 1.0f);		// Blue
	glVertex3f(-1.0f, 1.0f, 1.0f);
	glVertex3f(-1.0f, 1.0f, -1.0f);
	glVertex3f(-1.0f, -1.0f, -1.0f);
	glVertex3f(-1.0f, -1.0f, 1.0f);

	// Right face (x = 1.0f)
	glColor3f(1.0f, 0.0f, 1.0f);		// Magenta
	glVertex3f(1.0f, 1.0f, -1.0f);
	glVertex3f(1.0f, 1.0f, 1.0f);
	glVertex3f(1.0f, -1.0f, 1.0f);
	glVertex3f(1.0f, -1.0f, -1.0f);
	glEnd();

}


void display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Add perspective view
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, 1.0, 1.0, 9.0);

	// moving the camera and target the same relative distance, creates a pan
	gluLookAt(0.0, 6.0, 0.0, 0.0, 0.0, -7.0, 0, 1, 0);

	// Switch back to Model view
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glClearColor(1.0, 1.0, 1.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);

	glTranslatef(0.0f, 0.0f, -7.0f);

	drawCube();

	glutSwapBuffers();

	glutPostRedisplay();
}

void Timer(int iUnused)
{
	glutPostRedisplay();
	glutTimerFunc(1, Timer, 0);
}

void initGL() {
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClearDepth(1.0f);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glShadeModel(GL_SMOOTH);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
	glMatrixMode(GL_PROJECTION);
	glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
}

// Re-size event. Called back when the window first appears and
// whenever the window is re-sized with its new width and height 
void reshape(GLsizei width, GLsizei height) {		// GLsizei must be non-negative integer

													// Compute aspect ratio of the new window
	if (height == 0) height = 1;					// To prevent divide by 0
	GLfloat aspect = (GLfloat)width / (GLfloat)height;

	// Set the viewport to cover the new window
	glViewport(0, 0, width, height);

	// Set the aspect ratio of the clipping volume to match the viewport
	glMatrixMode(GL_PROJECTION);  // Enable the Projection matrix
	glLoadIdentity();             // Reset

								  // Enable perspective projection with fovy, aspect, zNear and zFar

}

// Main function: GLUT runs as a console application starting at main() 
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE);
	glutInitWindowSize(giXRes, giYRes);
	glutInitWindowPosition(50, 50);
	glutCreateWindow("Rotating Clipped Cube");
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	initGL();
	glutMainLoop();
	Timer(0);
	return 0;
}*/