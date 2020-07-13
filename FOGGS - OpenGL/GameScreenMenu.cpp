#include "GameScreenMenu.h"

#include <iostream>

// Initalises Compoennts for Menu Screen
GameScreenMenu::GameScreenMenu() : Screen()
{
	InitGL();
	InitObjects();
	glutMainLoop();
}

GameScreenMenu::~GameScreenMenu(void)
{

}

void GameScreenMenu::InitGL()
{
	// Initalises GL Components
	Screen::InitGL();

	// Initalises Callbacks
	GLUTCallbacks::Init(this);
	glutDisplayFunc(GLUTCallbacks::Display);
}


void GameScreenMenu::InitObjects()
{
	// Initalises Camera
	Screen::InitCamera();

}

void GameScreenMenu::Display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Draws Text onto Screen
	DrawText();

	glFlush();
	glutSwapBuffers();
}

void GameScreenMenu::Update()
{
	glLoadIdentity();

	// Updates the Screen
	Screen::Update();

	glutPostRedisplay();
}

// Draws String
void GameScreenMenu::DrawString(const char* text, Vector3* position, Color* color)
{
	glPushMatrix();
		glColor3f(color->r, color->g, color->b);
		glTranslatef(position->x, position->y, position->z);
		glRasterPos2f(0.0, 0.0);
		glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_24, (unsigned char*)text);
	glPopMatrix();
}

// Text to draw onto Screen
void GameScreenMenu::DrawText()
{
	glDisable(GL_TEXTURE_2D);
	
	Vector3 vCubefieldTitle =	{ -1.3f, 0.3f, -1.0f };
	Vector3 vCubefieldKey	=	{ -1.2f, 0.0f, -1.0f };

	Vector3 vOBJLoaderTitle = { 0.3f, 0.3f, -1.0f };
	Vector3 vOBJLoaderKey = { 0.4f, 0.0f, -1.0f };

	Color cWhite			=	{ 1.0f, 1.0f, 1.0f };
												 				  
	DrawString("CUBEFIELD", &vCubefieldTitle, &cWhite);
	DrawString("PRESS '2'", &vCubefieldKey, &cWhite);

	DrawString("OBJ LOADER", &vOBJLoaderTitle, &cWhite);
	DrawString("PRESS '3'", &vOBJLoaderKey, &cWhite);

	glEnable(GL_TEXTURE_2D);
}