#include "GL\freeglut.h"
#include "GL\glut.h"
#include <iostream>

double rotate_y = 0;
double rotate_x = 0;

void specialKeys(int key, int x, int y) {

	//  Right arrow - increase rotation by 5 degree
	if (key == GLUT_KEY_RIGHT)
		rotate_y += 5;

	//  Left arrow - decrease rotation by 5 degree
	else if (key == GLUT_KEY_LEFT)
		rotate_y -= 5;

	else if (key == GLUT_KEY_UP)
		rotate_x += 5;

	else if (key == GLUT_KEY_DOWN)
		rotate_x -= 5;

	//  Request display update
	glutPostRedisplay();

}

void renderScene(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();

	// Rotate when user changes rotate_x and rotate_y
	glRotatef(rotate_x, 1.0, 0.0, 0.0);
	glRotatef(rotate_y, 0.0, 1.0, 0.0);

#pragma region Wall1

	//FRONT
	glBegin(GL_POLYGON);

	glColor3f(1.0, 0.0, 0.0);     glVertex3f(0.7, -0.5, -0.7);      // P1 is red
	glColor3f(0.0, 1.0, 0.0);     glVertex3f(0.7, -0.4, -0.7);      // P2 is green
	glColor3f(0.0, 0.0, 1.0);     glVertex3f(-0.7, -0.4, -0.7);      // P3 is blue
	glColor3f(1.0, 0.0, 1.0);     glVertex3f(-0.7, -0.5, -0.7);      // P4 is purple

	glEnd();

	// White side - BACK
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(0.7, -0.5, -0.6);
	glVertex3f(0.7, -0.4, -0.6);
	glVertex3f(-0.7, -0.4, -0.6);
	glVertex3f(-0.7, -0.5, -0.6);
	glEnd();

	// Purple side - RIGHT
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 1.0);
	glVertex3f(0.7, -0.5, -0.7);
	glVertex3f(0.7, -0.4, -0.7);
	glVertex3f(0.7, -0.4, -0.6);
	glVertex3f(0.7, -0.5, -0.6);
	glEnd();

	// Green side - LEFT
	glBegin(GL_POLYGON);
	glColor3f(0.0, 1.0, 0.0);
	glVertex3f(-0.7, -0.5, -0.6);
	glVertex3f(-0.7, -0.4, -0.6);
	glVertex3f(-0.7, -0.4, -0.7);
	glVertex3f(-0.7, -0.5, -0.7);
	glEnd();

	// Blue side - TOP
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(0.7, -0.4, -0.6);
	glVertex3f(0.7, -0.4, -0.7);
	glVertex3f(-0.7, -0.4, -0.7);
	glVertex3f(-0.7, -0.4, -0.6);
	glEnd();

	// Red side - BOTTOM
	/*glBegin(GL_POLYGON);
	glColor3ub(172, 163, 163);
	glVertex3f(0.7, -0.5, -0.7);
	glVertex3f(0.7, -0.5, 0.7);
	glVertex3f(-0.7, -0.5, 0.7);
	glVertex3f(-0.7, -0.5, -075);
	glEnd();*/

	glBegin(GL_POLYGON);
	glColor3ub(172, 163, 163);
	glVertex3f(1.0, -0.5, -1.0);
	glVertex3f(1.0, -0.5, 1.0);
	glVertex3f(-1.0, -0.5, 1.0);
	glVertex3f(-1.0, -0.5, -1.0);
	glEnd();
#pragma endregion
#pragma region Wall2
	//FRONT
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 1.0);
	glVertex3f(0.7, -0.5, 0.7);    
	glVertex3f(0.7, -0.4, 0.7);    
	glVertex3f(-0.7, -0.4, 0.7);   
	glVertex3f(-0.7, -0.5, 0.7);   

	glEnd();

	//BACK
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 1.0);
	glVertex3f(0.7, -0.5, 0.6);
	glVertex3f(0.7, -0.4, 0.6);
	glVertex3f(-0.7, -0.4, 0.6);
	glVertex3f(-0.7, -0.5, 0.6);
	glEnd();

	// Purple side - RIGHT
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 1.0);
	glVertex3f(0.7, -0.5, 0.7);
	glVertex3f(0.7, -0.4, 0.7);
	glVertex3f(0.7, -0.4, 0.6);
	glVertex3f(0.7, -0.5, 0.6);
	glEnd();
	//LEFT
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 1.0);
	glVertex3f(-0.7, -0.5, 0.6);
	glVertex3f(-0.7, -0.4, 0.6);
	glVertex3f(-0.7, -0.4, 0.7);
	glVertex3f(-0.7, -0.5, 0.7);
	glEnd();

	//TOP
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(0.7, -0.4, 0.6);
	glVertex3f(0.7, -0.4, 0.7);
	glVertex3f(-0.7, -0.4, 0.7);
	glVertex3f(-0.7, -0.4, 0.6);
	glEnd();

	// Red side - BOTTOM
	/*glBegin(GL_POLYGON);
	glColor3ub(172, 163, 163);
	glVertex3f(0.7, -0.5, -0.7);
	glVertex3f(0.7, -0.5, 0.7);
	glVertex3f(-0.7, -0.5, 0.7);
	glVertex3f(-0.7, -0.5, -075);
	glEnd();*/

	glBegin(GL_POLYGON);
	glColor3ub(172, 163, 163);
	glVertex3f(1.0, -0.5, -1.0);
	glVertex3f(1.0, -0.5, 1.0);
	glVertex3f(-1.0, -0.5, 1.0);
	glVertex3f(-1.0, -0.5, -1.0);
	glEnd();
#pragma endregion
#pragma region Wall3
	//FRONT
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 1.0);
	glVertex3f(-0.6, -0.5, -0.7);
	glVertex3f(-0.6, -0.4, -0.7);
	glVertex3f(-0.7, -0.4, -0.7);
	glVertex3f(-0.7, -0.5, -0.7);

	glEnd();

	//BACK
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 1.0);
	glVertex3f(-0.6, -0.5, 0.7);
	glVertex3f(-0.6, -0.4, 0.7);
	glVertex3f(-0.7, -0.4, 0.7);
	glVertex3f(-0.7, -0.5, 0.7);
	glEnd();

	// Purple side - RIGHT
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 1.0);
	glVertex3f(-0.6, -0.5, 0.7);
	glVertex3f(-0.6, -0.4, 0.7);
	glVertex3f(-0.6, -0.4, -0.7);
	glVertex3f(-0.6, -0.5, -0.7);
	glEnd();
	//LEFT
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 1.0);
	glVertex3f(-0.7, -0.5, -0.7);
	glVertex3f(-0.7, -0.4, -0.7);
	glVertex3f(-0.7, -0.4, 0.7);
	glVertex3f(-0.7, -0.5, 0.7);
	glEnd();

	//TOP
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(-0.6, -0.4, -0.7);
	glVertex3f(-0.6, -0.4, 0.7);
	glVertex3f(-0.7, -0.4, 0.7);
	glVertex3f(-0.7, -0.4, -0.7);
	glEnd();

	// Red side - BOTTOM
	/*glBegin(GL_POLYGON);
	glColor3ub(172, 163, 163);
	glVertex3f(0.7, -0.5, -0.7);
	glVertex3f(0.7, -0.5, 0.7);
	glVertex3f(-0.7, -0.5, 0.7);
	glVertex3f(-0.7, -0.5, -075);
	glEnd();*/

	glBegin(GL_POLYGON);
	glColor3ub(172, 163, 163);
	glVertex3f(1.0, -0.5, -1.0);
	glVertex3f(1.0, -0.5, 1.0);
	glVertex3f(-1.0, -0.5, 1.0);
	glVertex3f(-1.0, -0.5, -1.0);
	glEnd();
#pragma endregion
#pragma region Wall4
	//FRONT
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 1.0);
	glVertex3f(0.6, -0.5, -0.7);
	glVertex3f(0.6, -0.4, -0.7);
	glVertex3f(0.7, -0.4, -0.7);
	glVertex3f(0.7, -0.5, -0.7);

	glEnd();

	//BACK
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 1.0);
	glVertex3f(0.6, -0.5, 0.7);
	glVertex3f(0.6, -0.4, 0.7);
	glVertex3f(0.7, -0.4, 0.7);
	glVertex3f(0.7, -0.5, 0.7);
	glEnd();

	// Purple side - RIGHT
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 1.0);
	glVertex3f(0.7, -0.5, -0.7);
	glVertex3f(0.7, -0.4, -0.7);
	glVertex3f(0.7, -0.4, 0.7);
	glVertex3f(0.7, -0.5, 0.7);
	glEnd();
	//LEFT
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 1.0);
	glVertex3f(0.6, -0.5, 0.7);
	glVertex3f(0.6, -0.4, 0.7);
	glVertex3f(0.6, -0.4, -0.7);
	glVertex3f(0.6, -0.5, -0.7);
	glEnd();

	//TOP
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(0.6, -0.4, -0.7);
	glVertex3f(0.6, -0.4, 0.7);
	glVertex3f(0.7, -0.4, 0.7);
	glVertex3f(0.7, -0.4, -0.7);
	glEnd();

	// Red side - BOTTOM
	/*glBegin(GL_POLYGON);
	glColor3ub(172, 163, 163);
	glVertex3f(0.7, -0.5, -0.7);
	glVertex3f(0.7, -0.5, 0.7);
	glVertex3f(-0.7, -0.5, 0.7);
	glVertex3f(-0.7, -0.5, -075);
	glEnd();*/

	glBegin(GL_POLYGON);
	glColor3ub(172, 163, 163);
	glVertex3f(1.0, -0.5, -1.0);
	glVertex3f(1.0, -0.5, 1.0);
	glVertex3f(-1.0, -0.5, 1.0);
	glVertex3f(-1.0, -0.5, -1.0);
	glEnd();
#pragma endregion
#pragma region Wall5
	//FRONT
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 1.0);
	glVertex3f(-0.1, -0.5, -0.5);
	glVertex3f(-0.1, -0.4, -0.5);
	glVertex3f(-0.5, -0.4, -0.5);
	glVertex3f(-0.5, -0.5, -0.5);

	glEnd();

	//BACK
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 1.0);
	glVertex3f(-0.1, -0.5, -0.4);
	glVertex3f(-0.1, -0.4, -0.4);
	glVertex3f(-0.5, -0.4, -0.4);
	glVertex3f(-0.5, -0.5, -0.4);
	glEnd();

	// Purple side - RIGHT
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 1.0);
	glVertex3f(-0.1, -0.5, -0.4);
	glVertex3f(-0.1, -0.4, -0.4);
	glVertex3f(-0.1, -0.4, -0.5);
	glVertex3f(-0.1, -0.5, -0.5);
	glEnd();
	//LEFT
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 1.0);
	glVertex3f(-0.5, -0.5, -0.5);
	glVertex3f(-0.5, -0.4, -0.5);
	glVertex3f(-0.5, -0.4, -0.4);
	glVertex3f(-0.5, -0.5, -0.4);
	glEnd();

	//TOP
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(-0.1, -0.4, -0.5);
	glVertex3f(-0.1, -0.4, -0.4);
	glVertex3f(-0.5, -0.4, -0.4);
	glVertex3f(-0.5, -0.4, -0.5);
	glEnd();

	// Red side - BOTTOM
	/*glBegin(GL_POLYGON);
	glColor3ub(172, 163, 163);
	glVertex3f(0.7, -0.5, -0.7);
	glVertex3f(0.7, -0.5, 0.7);
	glVertex3f(-0.7, -0.5, 0.7);
	glVertex3f(-0.7, -0.5, -075);
	glEnd();*/

	glBegin(GL_POLYGON);
	glColor3ub(172, 163, 163);
	glVertex3f(1.0, -0.5, -1.0);
	glVertex3f(1.0, -0.5, 1.0);
	glVertex3f(-1.0, -0.5, 1.0);
	glVertex3f(-1.0, -0.5, -1.0);
	glEnd();
#pragma endregion
#pragma region Wall6
	//FRONT
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 1.0);
	glVertex3f(0.3, -0.5, -0.6);
	glVertex3f(0.3, -0.4, -0.6);
	glVertex3f(0.1, -0.4, -0.6);
	glVertex3f(0.1, -0.5, -0.6);

	glEnd();

	//BACK
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 1.0);
	glVertex3f(0.3, -0.5, -0.5);
	glVertex3f(0.3, -0.4, -0.5);
	glVertex3f(0.1, -0.4, -0.5);
	glVertex3f(0.1, -0.5, -0.5);
	glEnd();

	// Purple side - RIGHT
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 1.0);
	glVertex3f(0.3, -0.5, -0.5);
	glVertex3f(0.3, -0.4, -0.5);
	glVertex3f(0.3, -0.4, -0.6);
	glVertex3f(0.3, -0.5, -0.6);
	glEnd();
	//LEFT
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 1.0);
	glVertex3f(0.1, -0.5, -0.6);
	glVertex3f(0.1, -0.4, -0.6);
	glVertex3f(0.1, -0.4, -0.5);
	glVertex3f(0.1, -0.5, -0.5);
	glEnd();

	//TOP
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(0.3, -0.4, -0.6);
	glVertex3f(0.3, -0.4, -0.5);
	glVertex3f(0.1, -0.4, -0.5);
	glVertex3f(0.1, -0.4, -0.6);
	glEnd();
#pragma endregion
#pragma region Wall7
	//FRONT
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 1.0);
	glVertex3f(-0.1, -0.5, -0.2);
	glVertex3f(-0.1, -0.4, -0.2);
	glVertex3f(-0.5, -0.4, -0.2);
	glVertex3f(-0.5, -0.5, -0.2);

	glEnd();

	//BACK
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 1.0);
	glVertex3f(-0.1, -0.5, -0.1);
	glVertex3f(-0.1, -0.4, -0.1);
	glVertex3f(-0.5, -0.4, -0.1);
	glVertex3f(-0.5, -0.5, -0.1);
	glEnd();

	// Purple side - RIGHT
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 1.0);
	glVertex3f(-0.1, -0.5, -0.1);
	glVertex3f(-0.1, -0.4, -0.1);
	glVertex3f(-0.1, -0.4, -0.2);
	glVertex3f(-0.1, -0.5, -0.2);
	glEnd();
	//LEFT
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 1.0);
	glVertex3f(-0.5, -0.5, -0.2);
	glVertex3f(-0.5, -0.4, -0.2);
	glVertex3f(-0.5, -0.4, -0.1);
	glVertex3f(-0.5, -0.5, -0.1);
	glEnd();

	//TOP
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(-0.1, -0.4, -0.2);
	glVertex3f(-0.1, -0.4, -0.1);
	glVertex3f(-0.5, -0.4, -0.1);
	glVertex3f(-0.5, -0.4, -0.2);
	glEnd();

	// Red side - BOTTOM
	/*glBegin(GL_POLYGON);
	glColor3ub(172, 163, 163);
	glVertex3f(0.7, -0.5, -0.7);
	glVertex3f(0.7, -0.5, 0.7);
	glVertex3f(-0.7, -0.5, 0.7);
	glVertex3f(-0.7, -0.5, -075);
	glEnd();*/

	glBegin(GL_POLYGON);
	glColor3ub(172, 163, 163);
	glVertex3f(1.0, -0.5, -1.0);
	glVertex3f(1.0, -0.5, 1.0);
	glVertex3f(-1.0, -0.5, 1.0);
	glVertex3f(-1.0, -0.5, -1.0);
	glEnd();
#pragma endregion
#pragma region Wall8
	//FRONT
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 1.0);
	glVertex3f(-0.1, -0.5, 0.4);
	glVertex3f(-0.1, -0.4, 0.4);
	glVertex3f(-0.5, -0.4, 0.4);
	glVertex3f(-0.5, -0.5, 0.4);

	glEnd();

	//BACK
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 1.0);
	glVertex3f(-0.1, -0.5, 0.5);
	glVertex3f(-0.1, -0.4, 0.5);
	glVertex3f(-0.5, -0.4, 0.5);
	glVertex3f(-0.5, -0.5, 0.5);
	glEnd();

	// Purple side - RIGHT
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 1.0);
	glVertex3f(-0.1, -0.5, 0.5);
	glVertex3f(-0.1, -0.4, 0.5);
	glVertex3f(-0.1, -0.4, 0.4);
	glVertex3f(-0.1, -0.5, 0.4);
	glEnd();
	//LEFT
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 1.0);
	glVertex3f(-0.5, -0.5, 0.4);
	glVertex3f(-0.5, -0.4, 0.4);
	glVertex3f(-0.5, -0.4, 0.5);
	glVertex3f(-0.5, -0.5, 0.5);
	glEnd();

	//TOP
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(-0.1, -0.4, 0.4);
	glVertex3f(-0.1, -0.4, 0.5);
	glVertex3f(-0.5, -0.4, 0.5);
	glVertex3f(-0.5, -0.4, 0.4);
	glEnd();

	// Red side - BOTTOM
	/*glBegin(GL_POLYGON);
	glColor3ub(172, 163, 163);
	glVertex3f(0.7, -0.5, -0.7);
	glVertex3f(0.7, -0.5, 0.7);
	glVertex3f(-0.7, -0.5, 0.7);
	glVertex3f(-0.7, -0.5, -075);
	glEnd();*/

	glBegin(GL_POLYGON);
	glColor3ub(172, 163, 163);
	glVertex3f(1.0, -0.5, -1.0);
	glVertex3f(1.0, -0.5, 1.0);
	glVertex3f(-1.0, -0.5, 1.0);
	glVertex3f(-1.0, -0.5, -1.0);
	glEnd();
#pragma endregion
#pragma region Wall9
	//FRONT
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 1.0);
	glVertex3f(0.1, -0.5, 0.4);
	glVertex3f(0.1, -0.4, 0.4);
	glVertex3f(0.5, -0.4, 0.4);
	glVertex3f(0.5, -0.5, 0.4);

	glEnd();

	//BACK
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 1.0);
	glVertex3f(0.1, -0.5, 0.5);
	glVertex3f(0.1, -0.4, 0.5);
	glVertex3f(0.5, -0.4, 0.5);
	glVertex3f(0.5, -0.5, 0.5);
	glEnd();

	// Purple side - RIGHT
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 1.0);
	glVertex3f(0.5, -0.5, 0.5);
	glVertex3f(0.5, -0.4, 0.5);
	glVertex3f(0.5, -0.4, 0.4);
	glVertex3f(0.5, -0.5, 0.4);
	glEnd();
	//LEFT
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 1.0);
	glVertex3f(0.1, -0.5, 0.4);
	glVertex3f(0.1, -0.4, 0.4);
	glVertex3f(0.1, -0.4, 0.5);
	glVertex3f(0.1, -0.5, 0.5);
	glEnd();

	//TOP
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(0.1, -0.4, 0.4);
	glVertex3f(0.1, -0.4, 0.5);
	glVertex3f(0.5, -0.4, 0.5);
	glVertex3f(0.5, -0.4, 0.4);
	glEnd();

	// Red side - BOTTOM
	/*glBegin(GL_POLYGON);
	glColor3ub(172, 163, 163);
	glVertex3f(0.7, -0.5, -0.7);
	glVertex3f(0.7, -0.5, 0.7);
	glVertex3f(-0.7, -0.5, 0.7);
	glVertex3f(-0.7, -0.5, -075);
	glEnd();*/

	glBegin(GL_POLYGON);
	glColor3ub(172, 163, 163);
	glVertex3f(1.0, -0.5, -1.0);
	glVertex3f(1.0, -0.5, 1.0);
	glVertex3f(-1.0, -0.5, 1.0);
	glVertex3f(-1.0, -0.5, -1.0);
	glEnd();
#pragma endregion
#pragma region Wall10
	//FRONT
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 1.0);
	glVertex3f(-0.3, -0.5, -0.3);
	glVertex3f(-0.3, -0.4, -0.3);
	glVertex3f(-0.5, -0.4, -0.3);
	glVertex3f(-0.5, -0.5, -0.3);

	glEnd();

	//BACK
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 1.0);
	glVertex3f(-0.3, -0.5, -0.2);
	glVertex3f(-0.3, -0.4, -0.2);
	glVertex3f(-0.5, -0.4, -0.2);
	glVertex3f(-0.5, -0.5, -0.2);
	glEnd();

	// Purple side - RIGHT
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 1.0);
	glVertex3f(-0.3, -0.5, -0.2);
	glVertex3f(-0.3, -0.4, -0.2);
	glVertex3f(-0.3, -0.4, -0.3);
	glVertex3f(-0.3, -0.5, -0.3);
	glEnd();
	//LEFT
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 1.0);
	glVertex3f(-0.5, -0.5, -0.3);
	glVertex3f(-0.5, -0.4, -0.3);
	glVertex3f(-0.5, -0.4, -0.2);
	glVertex3f(-0.5, -0.5, -0.2);
	glEnd();

	//TOP
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(-0.3, -0.4, -0.3);
	glVertex3f(-0.3, -0.4, -0.2);
	glVertex3f(-0.5, -0.4, -0.2);
	glVertex3f(-0.5, -0.4, -0.3);
	glEnd();

	// Red side - BOTTOM
	/*glBegin(GL_POLYGON);
	glColor3ub(172, 163, 163);
	glVertex3f(0.7, -0.5, -0.7);
	glVertex3f(0.7, -0.5, 0.7);
	glVertex3f(-0.7, -0.5, 0.7);
	glVertex3f(-0.7, -0.5, -075);
	glEnd();*/

	glBegin(GL_POLYGON);
	glColor3ub(172, 163, 163);
	glVertex3f(1.0, -0.5, -1.0);
	glVertex3f(1.0, -0.5, 1.0);
	glVertex3f(-1.0, -0.5, 1.0);
	glVertex3f(-1.0, -0.5, -1.0);
	glEnd();
#pragma endregion
#pragma region Wall11
	//FRONT
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 1.0);
	glVertex3f(-0.4, -0.5, 0.0);
	glVertex3f(-0.4, -0.4, 0.0);
	glVertex3f(-0.6, -0.4, 0.0);
	glVertex3f(-0.6, -0.5, 0.0);

	glEnd();

	//BACK
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 1.0);
	glVertex3f(-0.4, -0.5, 0.1);
	glVertex3f(-0.4, -0.4, 0.1);
	glVertex3f(-0.6, -0.4, 0.1);
	glVertex3f(-0.6, -0.5, 0.1);
	glEnd();

	// Purple side - RIGHT
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 1.0);
	glVertex3f(-0.4, -0.5, 0.1);
	glVertex3f(-0.4, -0.4, 0.1);
	glVertex3f(-0.4, -0.4, 0.0);
	glVertex3f(-0.4, -0.5, 0.0);
	glEnd();
	//LEFT
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 1.0);
	glVertex3f(-0.6, -0.5, 0.0);
	glVertex3f(-0.6, -0.4, 0.0);
	glVertex3f(-0.6, -0.4, 0.1);
	glVertex3f(-0.6, -0.5, 0.1);
	glEnd();

	//TOP
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(-0.4, -0.4, 0.0);
	glVertex3f(-0.4, -0.4, 0.1);
	glVertex3f(-0.6, -0.4, 0.1);
	glVertex3f(-0.6, -0.4, 0.0);
	glEnd();

	// Red side - BOTTOM
	/*glBegin(GL_POLYGON);
	glColor3ub(172, 163, 163);
	glVertex3f(0.7, -0.5, -0.7);
	glVertex3f(0.7, -0.5, 0.7);
	glVertex3f(-0.7, -0.5, 0.7);
	glVertex3f(-0.7, -0.5, -075);
	glEnd();*/

	glBegin(GL_POLYGON);
	glColor3ub(172, 163, 163);
	glVertex3f(1.0, -0.5, -1.0);
	glVertex3f(1.0, -0.5, 1.0);
	glVertex3f(-1.0, -0.5, 1.0);
	glVertex3f(-1.0, -0.5, -1.0);
	glEnd();
#pragma endregion
#pragma region Wall12
	//FRONT
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 1.0);
	glVertex3f(0.4, -0.5, 0.0);
	glVertex3f(0.4, -0.4, 0.0);
	glVertex3f(0.2, -0.4, 0.0);
	glVertex3f(0.2, -0.5, 0.0);

	glEnd();

	//BACK
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 1.0);
	glVertex3f(0.4, -0.5, 0.1);
	glVertex3f(0.4, -0.4, 0.1);
	glVertex3f(0.2, -0.4, 0.1);
	glVertex3f(0.2, -0.5, 0.1);
	glEnd();

	// Purple side - RIGHT
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 1.0);
	glVertex3f(0.4, -0.5, 0.1);
	glVertex3f(0.4, -0.4, 0.1);
	glVertex3f(0.4, -0.4, 0.0);
	glVertex3f(0.4, -0.5, 0.0);
	glEnd();
	//LEFT
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 1.0);
	glVertex3f(0.2, -0.5, 0.0);
	glVertex3f(0.2, -0.4, 0.0);
	glVertex3f(0.2, -0.4, 0.1);
	glVertex3f(0.2, -0.5, 0.1);
	glEnd();

	//TOP
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(0.4, -0.4, 0.0);
	glVertex3f(0.4, -0.4, 0.1);
	glVertex3f(0.2, -0.4, 0.1);
	glVertex3f(0.2, -0.4, 0.0);
	glEnd();

	// Red side - BOTTOM
	/*glBegin(GL_POLYGON);
	glColor3ub(172, 163, 163);
	glVertex3f(0.7, -0.5, -0.7);
	glVertex3f(0.7, -0.5, 0.7);
	glVertex3f(-0.7, -0.5, 0.7);
	glVertex3f(-0.7, -0.5, -075);
	glEnd();*/

	glBegin(GL_POLYGON);
	glColor3ub(172, 163, 163);
	glVertex3f(1.0, -0.5, -1.0);
	glVertex3f(1.0, -0.5, 1.0);
	glVertex3f(-1.0, -0.5, 1.0);
	glVertex3f(-1.0, -0.5, -1.0);
	glEnd();
#pragma endregion
#pragma region Wall13
	//FRONT
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 1.0);
	glVertex3f(0.5, -0.5, -0.4);
	glVertex3f(0.5, -0.4, -0.4);
	glVertex3f(0.2, -0.4, -0.4);
	glVertex3f(0.2, -0.5, -0.4);

	glEnd();

	//BACK
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 1.0);
	glVertex3f(0.5, -0.5, -0.3);
	glVertex3f(0.5, -0.4, -0.3);
	glVertex3f(0.2, -0.4, -0.3);
	glVertex3f(0.2, -0.5, -0.3);
	glEnd();

	// Purple side - RIGHT
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 1.0);
	glVertex3f(0.5, -0.5, -0.3);
	glVertex3f(0.5, -0.4, -0.3);
	glVertex3f(0.5, -0.4, -0.4);
	glVertex3f(0.5, -0.5, -0.4);
	glEnd();
	//LEFT
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 1.0);
	glVertex3f(0.2, -0.5, -0.4);
	glVertex3f(0.2, -0.4, -0.4);
	glVertex3f(0.2, -0.4, -0.3);
	glVertex3f(0.2, -0.5, -0.3);
	glEnd();

	//TOP
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(0.5, -0.4, -0.4);
	glVertex3f(0.5, -0.4, -0.3);
	glVertex3f(0.2, -0.4, -0.3);
	glVertex3f(0.2, -0.4, -0.4);
	glEnd();
#pragma endregion
#pragma region Wall14
	//FRONT
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 1.0);
	glVertex3f(-0.1, -0.5, -0.4);
	glVertex3f(-0.1, -0.4, -0.4);
	glVertex3f(-0.2, -0.4, -0.4);
	glVertex3f(-0.2, -0.5, -0.4);

	glEnd();

	//BACK
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 1.0);
	glVertex3f(-0.1, -0.5, -0.3);
	glVertex3f(-0.1, -0.4, -0.3);
	glVertex3f(-0.2, -0.4, -0.3);
	glVertex3f(-0.2, -0.5, -0.3);
	glEnd();

	// Purple side - RIGHT
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 1.0);
	glVertex3f(-0.1, -0.5, -0.3);
	glVertex3f(-0.1, -0.4, -0.3);
	glVertex3f(-0.1, -0.4, -0.4);
	glVertex3f(-0.1, -0.5, -0.4);
	glEnd();
	//LEFT
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 1.0);
	glVertex3f(-0.2, -0.5, -0.4);
	glVertex3f(-0.2, -0.4, -0.4);
	glVertex3f(-0.2, -0.4, -0.3);
	glVertex3f(-0.2, -0.5, -0.3);
	glEnd();

	//TOP
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(-0.1, -0.4, -0.4);
	glVertex3f(-0.1, -0.4, -0.3);
	glVertex3f(-0.2, -0.4, -0.3);
	glVertex3f(-0.2, -0.4, -0.4);
	glEnd();
#pragma endregion
#pragma region Wall15
	//FRONT
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 1.0);
	glVertex3f(0.5, -0.5, -0.5);
	glVertex3f(0.5, -0.4, -0.5);
	glVertex3f(0.4, -0.4, -0.5);
	glVertex3f(0.4, -0.5, -0.5);

	glEnd();

	//BACK
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 1.0);
	glVertex3f(0.5, -0.5, -0.4);
	glVertex3f(0.5, -0.4, -0.4);
	glVertex3f(0.4, -0.4, -0.4);
	glVertex3f(0.4, -0.5, -0.4);
	glEnd();

	// Purple side - RIGHT
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 1.0);
	glVertex3f(0.5, -0.5, -0.4);
	glVertex3f(0.5, -0.4, -0.4);
	glVertex3f(0.5, -0.4, -0.5);
	glVertex3f(0.5, -0.5, -0.5);
	glEnd();
	//LEFT
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 1.0);
	glVertex3f(0.4, -0.5, -0.5);
	glVertex3f(0.4, -0.4, -0.5);
	glVertex3f(0.4, -0.4, -0.4);
	glVertex3f(0.4, -0.5, -0.4);
	glEnd();

	//TOP
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(0.5, -0.4, -0.5);
	glVertex3f(0.5, -0.4, -0.4);
	glVertex3f(0.4, -0.4, -0.4);
	glVertex3f(0.4, -0.4, -0.5);
	glEnd();
#pragma endregion
#pragma region Wall16
	//FRONT
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 1.0);
	glVertex3f(0.1, -0.5, -0.4);
	glVertex3f(0.1, -0.4, -0.4);
	glVertex3f(0.0, -0.4, -0.4);
	glVertex3f(0.0, -0.5, -0.4);

	glEnd();

	//BACK
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 1.0);
	glVertex3f(0.1, -0.5, 0.1);
	glVertex3f(0.1, -0.4, 0.1);
	glVertex3f(0.0, -0.4, 0.1);
	glVertex3f(0.0, -0.5, 0.1);
	glEnd();

	// Purple side - RIGHT
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 1.0);
	glVertex3f(0.1, -0.5, 0.1);
	glVertex3f(0.1, -0.4, 0.1);
	glVertex3f(0.1, -0.4, -0.4);
	glVertex3f(0.1, -0.5, -0.4);
	glEnd();
	//LEFT
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 1.0);
	glVertex3f(0.0, -0.5, -0.4);
	glVertex3f(0.0, -0.4, -0.4);
	glVertex3f(0.0, -0.4, 0.1);
	glVertex3f(0.0, -0.5, 0.1);
	glEnd();

	//TOP
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(0.1, -0.4, -0.4);
	glVertex3f(0.1, -0.4, 0.1);
	glVertex3f(0.0, -0.4, 0.1);
	glVertex3f(0.0, -0.4, -0.4);
	glEnd();
#pragma endregion
#pragma region Wall17
	//FRONT
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 1.0);
	glVertex3f(-0.1, -0.5, -0.1);
	glVertex3f(-0.1, -0.4, -0.1);
	glVertex3f(-0.2, -0.4, -0.1);
	glVertex3f(-0.2, -0.5, -0.1);

	glEnd();

	//BACK
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 1.0);
	glVertex3f(-0.1, -0.5, 0.0);
	glVertex3f(-0.1, -0.4, 0.0);
	glVertex3f(-0.2, -0.4, 0.0);
	glVertex3f(-0.2, -0.5, 0.0);
	glEnd();

	// Purple side - RIGHT
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 1.0);
	glVertex3f(-0.1, -0.5, 0.0);
	glVertex3f(-0.1, -0.4, 0.0);
	glVertex3f(-0.1, -0.4, -0.1);
	glVertex3f(-0.1, -0.5, -0.1);
	glEnd();
	//LEFT
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 1.0);
	glVertex3f(-0.2, -0.5, -0.1);
	glVertex3f(-0.2, -0.4, -0.1);
	glVertex3f(-0.2, -0.4, 0.0);
	glVertex3f(-0.2, -0.5, 0.0);
	glEnd();

	//TOP
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(-0.1, -0.4, -0.1);
	glVertex3f(-0.1, -0.4, 0.0);
	glVertex3f(-0.2, -0.4, 0.0);
	glVertex3f(-0.2, -0.4, -0.1);
	glEnd();
#pragma endregion
#pragma region Wall18
	//FRONT
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 1.0);
	glVertex3f(-0.2, -0.5, 0.2);
	glVertex3f(-0.2, -0.4, 0.2);
	glVertex3f(-0.3, -0.4, 0.2);
	glVertex3f(-0.3, -0.5, 0.2);

	glEnd();

	//BACK
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 1.0);
	glVertex3f(-0.2, -0.5, 0.4);
	glVertex3f(-0.2, -0.4, 0.4);
	glVertex3f(-0.3, -0.4, 0.4);
	glVertex3f(-0.3, -0.5, 0.4);
	glEnd();

	// Purple side - RIGHT
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 1.0);
	glVertex3f(-0.2, -0.5, 0.4);
	glVertex3f(-0.2, -0.4, 0.4);
	glVertex3f(-0.2, -0.4, 0.2);
	glVertex3f(-0.2, -0.5, 0.2);
	glEnd();
	//LEFT
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 1.0);
	glVertex3f(-0.3, -0.5, 0.2);
	glVertex3f(-0.3, -0.4, 0.2);
	glVertex3f(-0.3, -0.4, 0.4);
	glVertex3f(-0.3, -0.5, 0.4);
	glEnd();

	//TOP
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(-0.2, -0.4, 0.2);
	glVertex3f(-0.2, -0.4, 0.4);
	glVertex3f(-0.3, -0.4, 0.4);
	glVertex3f(-0.3, -0.4, 0.2);
	glEnd();
#pragma endregion
#pragma region Wall19
	//FRONT
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 1.0);
	glVertex3f(0.5, -0.5, 0.2);
	glVertex3f(0.5, -0.4, 0.2);
	glVertex3f(0.4, -0.4, 0.2);
	glVertex3f(0.4, -0.5, 0.2);

	glEnd();

	//BACK
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 1.0);
	glVertex3f(0.5, -0.5, 0.4);
	glVertex3f(0.5, -0.4, 0.4);
	glVertex3f(0.4, -0.4, 0.4);
	glVertex3f(0.4, -0.5, 0.4);
	glEnd();

	// Purple side - RIGHT
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 1.0);
	glVertex3f(0.5, -0.5, 0.4);
	glVertex3f(0.5, -0.4, 0.4);
	glVertex3f(0.5, -0.4, 0.2);
	glVertex3f(0.5, -0.5, 0.2);
	glEnd();
	//LEFT
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 1.0);
	glVertex3f(0.4, -0.5, 0.2);
	glVertex3f(0.4, -0.4, 0.2);
	glVertex3f(0.4, -0.4, 0.4);
	glVertex3f(0.4, -0.5, 0.4);
	glEnd();

	//TOP
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(0.5, -0.4, 0.2);
	glVertex3f(0.5, -0.4, 0.4);
	glVertex3f(0.4, -0.4, 0.4);
	glVertex3f(0.4, -0.4, 0.2);
	glEnd();
#pragma endregion
#pragma region Wall20
	//FRONT
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 1.0);
	glVertex3f(0.1, -0.5, 0.3);
	glVertex3f(0.1, -0.4, 0.3);
	glVertex3f(0.0, -0.4, 0.3);
	glVertex3f(0.0, -0.5, 0.3);

	glEnd();

	//BACK
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 1.0);
	glVertex3f(0.1, -0.5, 0.5);
	glVertex3f(0.1, -0.4, 0.5);
	glVertex3f(0.0, -0.4, 0.5);
	glVertex3f(0.0, -0.5, 0.5);
	glEnd();

	// Purple side - RIGHT
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 1.0);
	glVertex3f(0.1, -0.5, 0.5);
	glVertex3f(0.1, -0.4, 0.5);
	glVertex3f(0.1, -0.4, 0.3);
	glVertex3f(0.1, -0.5, 0.3);
	glEnd();
	//LEFT
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 1.0);
	glVertex3f(0.0, -0.5, 0.3);
	glVertex3f(0.0, -0.4, 0.3);
	glVertex3f(0.0, -0.4, 0.5);
	glVertex3f(0.0, -0.5, 0.5);
	glEnd();

	//TOP
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(0.1, -0.4, 0.3);
	glVertex3f(0.1, -0.4, 0.5);
	glVertex3f(0.0, -0.4, 0.5);
	glVertex3f(0.0, -0.4, 0.3);
	glEnd();
#pragma endregion
#pragma region Wall21
	//FRONT
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 1.0);
	glVertex3f(0.3, -0.5, 0.1);
	glVertex3f(0.3, -0.4, 0.1);
	glVertex3f(0.2, -0.4, 0.1);
	glVertex3f(0.2, -0.5, 0.1);

	glEnd();

	//BACK
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 1.0);
	glVertex3f(0.3, -0.5, 0.3);
	glVertex3f(0.3, -0.4, 0.3);
	glVertex3f(0.2, -0.4, 0.3);
	glVertex3f(0.2, -0.5, 0.3);
	glEnd();

	// Purple side - RIGHT
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 1.0);
	glVertex3f(0.3, -0.5, 0.3);
	glVertex3f(0.3, -0.4, 0.3);
	glVertex3f(0.3, -0.4, 0.1);
	glVertex3f(0.3, -0.5, 0.1);
	glEnd();
	//LEFT
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 1.0);
	glVertex3f(0.2, -0.5, 0.1);
	glVertex3f(0.2, -0.4, 0.1);
	glVertex3f(0.2, -0.4, 0.3);
	glVertex3f(0.2, -0.5, 0.3);
	glEnd();

	//TOP
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(0.3, -0.4, 0.1);
	glVertex3f(0.3, -0.4, 0.3);
	glVertex3f(0.2, -0.4, 0.3);
	glVertex3f(0.2, -0.4, 0.1);
	glEnd();
#pragma endregion
#pragma region Wall22
	//FRONT
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 1.0);
	glVertex3f(0.6, -0.5, -0.1);
	glVertex3f(0.6, -0.4, -0.1);
	glVertex3f(0.5, -0.4, -0.1);
	glVertex3f(0.5, -0.5, -0.1);

	glEnd();

	//BACK
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 1.0);
	glVertex3f(0.6, -0.5, 0.1);
	glVertex3f(0.6, -0.4, 0.1);
	glVertex3f(0.5, -0.4, 0.1);
	glVertex3f(0.5, -0.5, 0.1);
	glEnd();

	// Purple side - RIGHT
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, -1.0);
	glVertex3f(0.6, -0.5, 0.1);
	glVertex3f(0.6, -0.4, 0.1);
	glVertex3f(0.6, -0.4,-0.1);
	glVertex3f(0.6, -0.5, 0.1);
	glEnd();
	//LEFT
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 1.0);
	glVertex3f(0.5, -0.5, -0.1);
	glVertex3f(0.5, -0.4, -0.1);
	glVertex3f(0.5, -0.4, 0.1);
	glVertex3f(0.5, -0.5, 0.1);
	glEnd();

	//TOP
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(0.6, -0.4, -0.1);
	glVertex3f(0.6, -0.4, 0.1);
	glVertex3f(0.5, -0.4, 0.1);
	glVertex3f(0.5, -0.4, -0.1);
	glEnd();
#pragma endregion
#pragma region Wall23
	//FRONT
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 1.0);
	glVertex3f(0.6, -0.5, -0.2);
	glVertex3f(0.6, -0.4, -0.2);
	glVertex3f(0.4, -0.4, -0.2);
	glVertex3f(0.4, -0.5, -0.2);

	glEnd();

	//BACK
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 1.0);
	glVertex3f(0.6, -0.5, -0.1);
	glVertex3f(0.6, -0.4, -0.1);
	glVertex3f(0.4, -0.4, -0.1);
	glVertex3f(0.4, -0.5, -0.1);
	glEnd();

	// Purple side - RIGHT
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 1.0);
	glVertex3f(0.6, -0.5, -0.1);
	glVertex3f(0.6, -0.4, -0.1);
	glVertex3f(0.6, -0.4, -0.2);
	glVertex3f(0.6, -0.5, -0.2);
	glEnd();
	//LEFT
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 1.0);
	glVertex3f(0.4, -0.5, -0.2);
	glVertex3f(0.4, -0.4, -0.2);
	glVertex3f(0.4, -0.4, -0.1);
	glVertex3f(0.4, -0.5, -0.1);
	glEnd();

	//TOP
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(0.6, -0.4, -0.2);
	glVertex3f(0.6, -0.4, -0.1);
	glVertex3f(0.4, -0.4, -0.1);
	glVertex3f(0.4, -0.4, -0.2);
	glEnd();
#pragma endregion


	glFlush();
	glutSwapBuffers();
}

int main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(800, 600);
	glutCreateWindow("Cube");
	glEnable(GL_DEPTH_TEST);
	glutDisplayFunc(renderScene);
	glutSpecialFunc(specialKeys);

	glutMainLoop();
	return 0;
}