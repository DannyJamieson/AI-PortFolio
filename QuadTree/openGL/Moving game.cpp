/*/ include the GLUT header file so we can access all the GLUT calls
#include <glut.h>
int X = 50;
int Y = 50;

// Create a method to hold all our drawing calls
// This function must be declared before the MAIN call so that MAIN knows it exists
// NOTE: read the contents of MAIN first, before reading the DISPLAY method. It will make more sense that way !

void display(void)
{
	// glClear sets the colour of the window to the colour previously define by
	// glClearColor, glClearIndex, glClearDepth, glClearStencil, and glClearAccum
	glClear(GL_COLOR_BUFFER_BIT);
	// et the colour of any future objects we create
	// This colour will remain the active draw colour until we change it
	glColor3f(0.0, 0.0, 0.0);
	///////////////////////////////////////////////////
	//draw a line - START
	///////////////////////////////////////////////////
	//Start to crete a line primitive
	glPointSize(8);
	glBegin(GL_POINTS);
		// Now add in the vertices of the line
		glVertex2i(X, Y);
	glEnd(); 
	if(X<40 && X>10 && Y<30 && Y>10){ glColor3f(1.0, 0.0, 0.0); }
	else { glColor3f(0.0, 0.0, 1.0); }

	glBegin(GL_QUADS);
		// Now add in the vertices of the line
		glVertex2i(10, 10);
		glVertex2i(10, 30);
		glVertex2i(40, 30);
		glVertex2i(40, 10);
	glEnd();

	glutSwapBuffers();
}

void Timer(int iUnused)
{
	glutPostRedisplay();
	glutTimerFunc(1, Timer, 0);
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




// Create our windows applciation
void main(int argc, char *argv[])
{
	
	//Start the GLUT windowing system
	glutInit(&argc, argv);
	
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);



	// Define settings for the display
	// GLUT_SINGLE = use a single rerfesh buffer
	// GLUT_RGB = use the RGB colour space
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	// Set the dimensions of all future windows.
	glutInitWindowSize(500, 500);
	// Set the position of the window. Origin is top left of screen
	glutInitWindowPosition(100, 100);
	// Create a window with a title
	glutCreateWindow("My Quad");
	// Set the background colour of the window to white (red, green, blue, alpha)
	// RGB values in range of 0 to 1
	// Alpha channel used to blend two overlapping objects
	glClearColor(1.0, 1.0, 1.0, 0.0);
	// OpenGL assumes you are working with 3D graphcis by default
	// If we want to work in just 2D we have to tell OpenGL that we want to do this
	// We therefore tell OpenGL to 'project' the image onto a 2D plane.
	glMatrixMode(GL_PROJECTION);
	// Now setup the coordinate system for the projected image
	// (x min, x max, y min, y max)
	// Bottom left = (0,0) top right = (250,250)
	gluOrtho2D(0.0, 250.0, 0.0, 250.0);
	// Process the 'display' method and pass the results to DisplayFunc
	// which will pass the results to the display window, ready to be displayed.
	glutKeyboardFunc(keyboard);
	glutDisplayFunc(display);
	Timer(0);
	
	// The contents of the display window are not drawn immediately.
	// The following function displays the content.
	// This must be the last function in the program
	glutMainLoop();



}

*/