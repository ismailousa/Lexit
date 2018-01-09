//1131603702
//Isma-Ilou SADOU

//kamera yon tuslari ile kontrol edilir
//Oyuncu W-S-A-D tuslari ile hareket ettirilir
//Isik L tusu ile acilip kapanir
//Zoom 1 ve 2 tuslariile yapilir


#include "GL\freeglut.h"
#include "GL\glut.h"
#include <iostream>
#include "main.h"

double rotate_y = 0;
double rotate_x = 0;
double player_x = -0.65;
double player_z = -0.55;
double zoom = 1.0;
bool won = false;

GLuint texName;				
GLubyte *data;					
								
GLubyte header[54];				
GLuint dataPos;					
GLuint width, height;			
GLuint imageSize;

bool light = false;


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
	glDisable(GL_DEPTH_TEST);
	glPushMatrix();
	glRasterPos2f(0.5, 0.7);
	char* string;
	if (won)
		string = "Kazandiniz !!";
	else
		string = "Cikisa gidin";
	int len = (int)strlen(string);
	glPopMatrix();
	//loop to display character by character
	for (int i = 0; i < len; i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, string[i]);
	}
	glEnable(GL_DEPTH_TEST);

	glEnable(GL_LIGHT0);

	// Create light components
	float ambientLight[] = { 0.2f, 0.2f, 0.2f, 1.0f };
	float diffuseLight[] = { 0.8f, 0.8f, 0.8, 1.0f };
	float specularLight[] = { 0.5f, 0.5f, 0.5f, 1.0f };
	float position[] = {0,0,0,1 };

	// Assign created components to GL_LIGHT0
	glLightfv(GL_LIGHT0, GL_AMBIENT, ambientLight);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuseLight);
	glLightfv(GL_LIGHT0, GL_SPECULAR, specularLight);
	glLightfv(GL_LIGHT0, GL_POSITION, position);

	glEnable(GL_TEXTURE_2D);    
								
	glBindTexture(GL_TEXTURE_2D, texName);
	glLoadIdentity();

	// Rotate when user changes rotate_x and rotate_y
	glScalef(zoom, zoom, zoom);
	glRotatef(rotate_x, 1.0, 0.0, 0.0);
	glRotatef(rotate_y, 0.0, 1.0, 0.0);	
#pragma region Wall1

	//FRONT
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 1.0);
	glVertex3f(0.7, -0.5, -0.7);    
	glVertex3f(0.7, -0.4, -0.7);    
	glVertex3f(-0.7, -0.4, -0.7);   
	glVertex3f(-0.7, -0.5, -0.7);   

	glEnd();

	// White side - BACK
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 1.0);
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
	glColor3f(1.0, 0.0, 1.0);
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

	glBindTexture(GL_TEXTURE_2D, texName);
	glBegin(GL_POLYGON);
	glColor3ub(172, 163, 163);
	glTexCoord2f(0, 0);
	glVertex3f(0.7, -0.5, -0.7);
	glTexCoord2f(0, 1);
	glVertex3f(0.7, -0.5, 0.7);
	glTexCoord2f(1, 1);
	glVertex3f(-0.7, -0.5, 0.7);
	glTexCoord2f(1, 0);
	glVertex3f(-0.7, -0.5, -0.7);
	glEnd();
#pragma endregion
#pragma region Wall2
	//FRONT
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 1.0);
	glVertex3f(0.5, -0.5, 0.7);    
	glVertex3f(0.5, -0.4, 0.7);    
	glVertex3f(-0.7, -0.4, 0.7);   
	glVertex3f(-0.7, -0.5, 0.7);   

	glEnd();

	//BACK
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 1.0);
	glVertex3f(0.5, -0.5, 0.6);
	glVertex3f(0.5, -0.4, 0.6);
	glVertex3f(-0.7, -0.4, 0.6);
	glVertex3f(-0.7, -0.5, 0.6);
	glEnd();

	// Purple side - RIGHT
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 1.0);
	glVertex3f(0.5, -0.5, 0.7);
	glVertex3f(0.5, -0.4, 0.7);
	glVertex3f(0.5, -0.4, 0.6);
	glVertex3f(0.5, -0.5, 0.6);
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
	glVertex3f(0.5, -0.4, 0.6);
	glVertex3f(0.5, -0.4, 0.7);
	glVertex3f(-0.7, -0.4, 0.7);
	glVertex3f(-0.7, -0.4, 0.6);
	glEnd();
#pragma endregion
#pragma region Wall3
	//FRONT
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 1.0);
	glVertex3f(-0.6, -0.5, -0.5);
	glVertex3f(-0.6, -0.4, -0.5);
	glVertex3f(-0.7, -0.4, -0.5);
	glVertex3f(-0.7, -0.5, -0.5);

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
	glVertex3f(-0.6, -0.4, -0.5);
	glVertex3f(-0.6, -0.5, -0.5);
	glEnd();
	//LEFT
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 1.0);
	glVertex3f(-0.7, -0.5, -0.5);
	glVertex3f(-0.7, -0.4, -0.5);
	glVertex3f(-0.7, -0.4, 0.7);
	glVertex3f(-0.7, -0.5, 0.7);
	glEnd();

	//TOP
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(-0.6, -0.4, -0.5);
	glVertex3f(-0.6, -0.4, 0.7);
	glVertex3f(-0.7, -0.4, 0.7);
	glVertex3f(-0.7, -0.4, -0.5);
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
	glPushMatrix();
	glTranslatef(player_x, -0.45, player_z);
	glColor3f(1, 0, 0);
	glutSolidSphere(0.04, 20, 20);
	glPopMatrix();
	

	glFlush();
	glutSwapBuffers();
}

GLuint loadBMP_custom(const char * imagepath) {
	FILE * file;
	fopen_s(&file, imagepath, "rb");
	if (!file) {
		printf("Image could not be opened\n");
		return 0;
	}
	if (fread(header, 1, 54, file) != 54) {
		printf("Not a correct BMP file\n");
		return 0;
	}
	if (header[0] != 'B' || header[1] != 'M') {
		printf("Not a correct BMP file\n");
		return 0;
	}
	dataPos = *(int*)&(header[0x0A]);
	imageSize = *(int*)&(header[0x22]);
	width = *(int*)&(header[0x12]);
	height = *(int*)&(header[0x16]);

	if (imageSize == 0)    imageSize = width*height * 3;
	if (dataPos == 0)      dataPos = 54;

										 
	data = new unsigned char[imageSize];
	fread(data, 1, imageSize, file);
	fclose(file);
}


void DokuKaplama(void) {
	glGenTextures(1, &texName); 

	loadBMP_custom("mcqueen.bmp"); 
	glBindTexture(GL_TEXTURE_2D, texName);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, data);
}

void keyboard(unsigned char key, int x, int y)
{
	if (key == 'a' || key == 'A')
		player_x -= 0.1;
	else if (key == 'd' || key == 'D')
		player_x += 0.1;
	else if (key == 'w' || key == 'W') {
		player_z += 0.1;
		if (player_x > 0.5 && player_z > 0.6)
			won = true;
	}
	else if (key == 's' || key == 'S')
		player_z -= 0.1;
	else if (key == '1')
		zoom -= 0.1;
	else if (key == '2')
		zoom += 0.1;
	else if (key == 'l' || key == 'L')
		if (light) {
			light = false;
			glEnable(GL_LIGHTING);
		}
		else {
			light = true;
			glDisable(GL_LIGHTING);
		}

	glutPostRedisplay();
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
	glutKeyboardFunc(keyboard);
	DokuKaplama();
	glutMainLoop();
	return 0;
}