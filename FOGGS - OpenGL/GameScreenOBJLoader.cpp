#include "GameScreenOBJLoader.h"

// Initalise Scene Components
GameScreenOBJLoader::GameScreenOBJLoader()
{
	InitGL();
	InitLighting();
	InitObjects();

	loadedTeapot = true;

	glutMainLoop();
}

GameScreenOBJLoader::~GameScreenOBJLoader(void)
{

}

void GameScreenOBJLoader::InitGL()
{
	// Initalises GL components for Scene
	Screen::InitGL();

	// Initalise Callbacks
	GLUTCallbacks::Init(this);
	glutDisplayFunc(GLUTCallbacks::Display);
	glutKeyboardFunc(GLUTCallbacks::Keyboard);

}

void GameScreenOBJLoader::InitLighting()
{
	// Initalise Lighting
	Screen::InitLighting();

}

void GameScreenOBJLoader::InitObjects()
{
	//Initlaise Camera
	Screen::InitCamera();
	// Provides Filepath and Loads .obj Files
	OBJTeapot.Load((char*)"Objects/TeapotOBJ.obj");
	OBJGourd.Load((char*)"Objects/GourdOBJ.obj");
	OBJIcosahedron.Load((char*)"Objects/IcosahedronOBJ.obj");

	
}

// Draws Objects Sets Correct Scale and Translation
void GameScreenOBJLoader::LoadOBJ()
{
	glPushMatrix();
	if (loadedTeapot)
	{
		glEnable(GL_NORMALIZE);
		glScalef(2.0f, 2.0f, 1.0f);
		glTranslatef(-0.2f, -1.5f, -10.0f);
		glRotatef(rotation, 0, 1, 0);
		rotation++;
		OBJTeapot.Draw();
		
	}
	else if (loadedGourd)
	{
		glEnable(GL_NORMALIZE);
		glScalef(3.0f, 3.0f, 1.0f);
		glTranslatef(-0.4f, -0.2f, -10.0f);
		glRotatef(rotation, 0, 1, 0);
		rotation++;
		OBJGourd.Draw();
	}
	else if (loadedIcosahedron)
	{
		glEnable(GL_NORMALIZE);
		glScalef(3.0f, 3.0f, 1.0f);
		glTranslatef(0.0f, -0.2f, -10.0f);
		glRotatef(rotation, 0, 1, 0);
		rotation++;
		OBJIcosahedron.Draw();
	}
	glPopMatrix();
}

// Draws String
void GameScreenOBJLoader::DrawString(const char* text, Vector3* position, Color* color)
{
	glPushMatrix();
	glTranslatef(position->x, position->y, position->z);
	glRasterPos2f(0.0f, 0.0f);
	glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_24, (unsigned char*)text);
	glPopMatrix();
}

// Displays Objects and Text
void GameScreenOBJLoader::Display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glDisable(GL_TEXTURE_2D);

	LoadOBJ();
	glEnable(GL_TEXTURE_2D);

	Vector3 v = { -1.8f, 1.7f, -1.0f };
	Color c = { 0.0f, 1.0f, 0.0f };
	DrawString("GameScreen .OBJ Loader", &v, &c);

	glFlush();
	glutSwapBuffers();
}

// Updates Screen
void GameScreenOBJLoader::Update()
{
	glLoadIdentity();

	Screen::Update();

	glutPostRedisplay();
}

// Keyboard Controls for Scene
void GameScreenOBJLoader::Keyboard(unsigned char key, int x, int y)
{
	// Change Object
	if (key == '5')
	{
		loadedTeapot = true;
		loadedGourd = false;
		loadedIcosahedron = false;
	}

	if (key == '6')
	{
		loadedGourd = true;
		loadedTeapot = false;
		loadedIcosahedron = false;
	}

	if (key == '7')
	{
		loadedIcosahedron = true;
		loadedTeapot = false;
		loadedGourd = false;
	}

}