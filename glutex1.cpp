#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
/*
	GLUT - The OpenGL Utility Toolkit
		is a window system independent toolki for writing OpenGL programs by M.Kilgard.
		provides a portable API so you can write a single OpenGL program that works on across all PC and workstation OS platform.
		Has both C, C++ (same as C), Fortran, and Ada programming bindings.
		The current version of the GLUT API is 3.
		The current source code distribution is GLUT 3.7.
		Supports:
			Multiple winodws for OpenGL rendering
			Callback driven event processing
			Sophisticated input devices
			An 'idle' routine and timers
			A sample, cascading pop-up menu facility
			Utility routines to generate various solid and wire frame objects
			Support for bitmap and stroke fonts
			Miscellaneous window management functions
*/
void display(void) // 다시 그릴 필요가 있을 때 호출
{
	glClearColor(0.259, 0.259, 0.435, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_LINES);
	glVertex2f(-1.0, 0.0);
	glVertex2f(0.0, 0.0);
	glEnd();
	glFlush();
}
void keyboard(unsigned char key, int x, int y)
{
	switch(key)
	{
	case 'q':
		exit(0);
	case 'A':
		printf("'A' is pressed!\n");
	}
}
/*
	이벤트 메시지의 처리 - 컬백 함수 (Callback fucntion)의 정의
	- callback function
		윈도우 프로그램 수행 시 발생하는 여러 종류의 윈도우 및 입력 이벤트 중 관심이 있는 이벤트 각각에 대하여
		어떠한 처리를 하고자 한다는 것을 기술해주는 함수
	1) 프로그래머가 관심이 있는 이벤트 종류 각각에 대하여 콜백 함수를 정의한 후 등록 (registration)
*/
void RegisterCallback(void)
{
	glutDisplayFunc(display);		// Set the display callback for the current window
	// special key들이 아니다
	glutKeyboardFunc(keyboard);		// Set the keyboard callback for the current window
}
void main(int argc, char **argv)
{
	glutInit(&argc, argv); // Initialize the GLUT library
	/*
		Color Buffer: GLUT_RGBA, GLUT_RGB, GLUT_INDEX, GLUT_ALPHA, GLUT_SINGLE, GLUT_DOUBLE, GLUT_STEREO,
		GLUT_LUMINANCE, GLUT_MULTISAMPLING
	*/
	glutInitDisplayMode(GLUT_RGB); // Set the initial display mode
	glutInitWindowSize(500, 500);  // Set the initial window size
	glutCreateWindow("My First OpenGL Code"); // Create top-level window
	RegisterCallback();
	glutMainLoop(); // Enter the GLUT event processing loop
}
