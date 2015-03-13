#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>

short rightbuttonpressed = 0;
double r = 1.0, g = 0.0, b = 0.0;

void display(void)
{
	glClearColor(r, g, b, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_LINES);
		glVertex2f(-1.0, 0.0); glVertex2f(0.0, 0.0);
	glEnd();
	glFlush();
}
void keyboard(unsigned char key, int x, int y)
{
	switch(key)
	{
	case 'r':
		r = 1.0; g = b = 0.0;
		glutPostRedisplay();
		break;
	case 'g':
		g = 1.0; r = b = 0.0;
		glutPostRedisplay();
		break;
	case 'b':
		b = 1.0; r = g = 0.0;
		glutPostRedisplay();
		break;
	case 'q':
		exit(0);
	}
}
void mousepress(int button, int state, int x, int y)
{
	if((button == GLUT_LEFT_BUTTON) && (state == GLUT_DOWN))
		printf("*** The left mouse button was pressed at (%d, %d).\n", x, y);
	else if((button == GLUT_RIGHT_BUTTON) && (state == GLUT_DOWN))
		rightbuttonpressed = 1;
	else if((button == GLUT_RIGHT_BUTTON) && (state == GLUT_UP))
		rightbuttonpressed = 0;
}
void mousemove(int x, int y)
{
	if(rightbuttonpressed)
		printf("$$$ The right mouse button is now at (%d,  %d).\n", x, y);
}
void reshape(int width, int height)
{
	printf("### The new window size is %dx%d.\n", width, height);
}
void RegisterCallback(void)
{
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutMouseFunc(mousepress);
	glutMotionFunc(mousemove);
	glutReshapeFunc(reshape);
}
void main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA);
	glutInitWindowSize(500, 500);
	glutCreateWindow("My Second OpenGL Code");
	RegisterCallback();
	glutMainLoop();
}
