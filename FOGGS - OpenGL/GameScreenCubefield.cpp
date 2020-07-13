#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "GameScreenCubefield.h"
#include "MeshLoader.h"

GameScreenCubefield::GameScreenCubefield() : Screen()
{
	// Initalises All Parts of Scene
	InitGL();
	InitLighting();
	InitObjects();

	glutMainLoop();
}

GameScreenCubefield::~GameScreenCubefield(void)
{
	for (int i = 0; i < OBJECTCOUNT; i++)
	{
		delete objects[i];
		objects[i] = NULL;
	}
}

void GameScreenCubefield::InitGL()
{
	// Initalises GL components for Scene
	Screen::InitGL();

	// Sets up Callbacks
	GLUTCallbacks::Init(this);
	glutKeyboardFunc(GLUTCallbacks::Keyboard);
	glutDisplayFunc(GLUTCallbacks::Display);
	glutTimerFunc(REFRESHRATE, GLUTCallbacks::Timer, REFRESHRATE);
}

void GameScreenCubefield::InitLighting()
{
	// Initalises Lighting components for Scene
	Screen::InitLighting();
}

void GameScreenCubefield::InitObjects()
{
	// Initalises Camera for Scene
	Screen::InitCamera();

	// Set Up Objects
	cubeMesh = MeshLoader::Load((char*)"Objects/cube.txt");

	texturePenguins = new Texture2D();
	texturePenguins->Load((char*)"Textures/penguins.raw", 512, 512);

	textureStars = new Texture2D();
	textureStars->Load((char*)"Textures/stars.raw", 512, 512);

	// Sets Random Positions for Cubes
	srand(time(NULL));

	for (int i = 0; i < OBJECTCOUNT; i++)
	{
		objects[i] = new Cube(cubeMesh, texturePenguins, ((rand() % 400) / 10.0f) - 20.0f, ((rand() % 200) / 10.0f) - 10.0f, -(rand() % 1000) / 10.0f);
	}
}

// Draws string into Scene
void GameScreenCubefield::DrawString(const char* text, Vector3* position, Color* color)
{
	glPushMatrix();
	glTranslatef(position->x, position->y, position->z);
	glRasterPos2f(0.0f, 0.0f);
	glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_24, (unsigned char*)text);
	glPopMatrix();
}

// Displays Cubes and Text
void GameScreenCubefield::Display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	for (int i = 0; i < OBJECTCOUNT; i++)
	{
		objects[i]->Draw();
	}

	Vector3 v = { -1.8f, 1.7f, -1.0f };
	Color c = { 0.0f, 1.0f, 0.0f };
	DrawString("GameScreen Cubefield", &v, &c);

	glFlush();
	glutSwapBuffers();
}

// Updates Cubes, Lights and Camera
void GameScreenCubefield::Update()
{
	glLoadIdentity();

	Screen::Update();

	for (int i = 0; i < OBJECTCOUNT; i++)
	{
		objects[i]->Update();
		if (objects[i]->_position.z > 10.0f)
		{
			objects[i]->_position.z = -100.0f;
		}
	}

	glLightfv(GL_LIGHT0, GL_AMBIENT, &(_lightData->Ambient.x));
	glLightfv(GL_LIGHT0, GL_DIFFUSE, &(_lightData->Diffuse.x));
	glLightfv(GL_LIGHT0, GL_SPECULAR, &(_lightData->Specular.x));
	glLightfv(GL_LIGHT0, GL_POSITION, &(_lightPosition->x));

	glutPostRedisplay();
}

// Keyboard Controls for Scene
void GameScreenCubefield::Keyboard(unsigned char key, int x, int y)
{ 
	// Object Movement
	for (int i = 0; i < OBJECTCOUNT; i++)
	{
		if (key == 'q')
			objects[i]->_rotation -= 2.0f;
		else if (key == 'e')
			objects[i]->_rotation += 2.0f;
	}

	// Camera Movement
	if (key == 'w')
		camera->eye.y -= movementSpeed;

	else if (key == 'a')
		camera->eye.x += movementSpeed;

	else if (key == 's')
		camera->eye.y += movementSpeed;

	else if (key == 'd')
		camera->eye.x -= movementSpeed;

	// Change Texture
	for (int i = 0; i < OBJECTCOUNT; i++)
	{
		if (key == 'o')
			objects[i] = new Cube(cubeMesh, textureStars, objects[i]->_position.x, objects[i]->_position.y, objects[i]->_position.z);
		else if (key == 'p')
			objects[i] = new Cube(cubeMesh, texturePenguins, objects[i]->_position.x, objects[i]->_position.y, objects[i]->_position.z);
	}

	// Change Colour
	for (int i = 0; i < OBJECTCOUNT; i++)
	{
		if (key == 'r')
		{
			objects[i]->red = 1.0f;
			objects[i]->green = 0.0f;
			objects[i]->blue = 0.0f;
		}

		if (key == 'g')
		{
			objects[i]->red = 0.0f;
			objects[i]->green = 1.0f;
			objects[i]->blue = 0.0f;
		}

		if (key == 'b')
		{
			objects[i]->red = 0.0f;
			objects[i]->green = 0.0f;
			objects[i]->blue = 1.0f;
		}
	}
}