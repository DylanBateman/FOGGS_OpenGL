#include "Screen.h"

Screen::Screen()
{

}

// Delet old Screen Components
Screen::~Screen(void)
{
	delete camera;
	camera = NULL;

	delete _lightPosition;
	_lightPosition = NULL;

	delete _lightData;
	_lightData = NULL;
}

// Initalise OpenGL Components for Current Screen
void Screen::InitGL()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(90, 1, 1, 1000);
	glMatrixMode(GL_MODELVIEW);
}

// Initalise Lighting for Current Screen
void Screen::InitLighting()
{
	_lightPosition = new Vector4();

	_lightPosition->x = 0.0;
	_lightPosition->y = 0.0;
	_lightPosition->z = 1.0;
	_lightPosition->w = 0.0;

	_lightData = new Lighting();

	_lightData->Ambient.x = 0.2;
	_lightData->Ambient.y = 0.2;
	_lightData->Ambient.z = 0.2;
	_lightData->Ambient.w = 1.0;

	_lightData->Diffuse.x = 0.8;
	_lightData->Diffuse.y = 0.8;
	_lightData->Diffuse.z = 0.8;
	_lightData->Diffuse.w = 1.0;

	_lightData->Specular.x = 0.2;
	_lightData->Specular.y = 0.2;
	_lightData->Specular.z = 0.2;
	_lightData->Specular.w = 1.0;
}

// Initalise Camera for Current Screen
void Screen::InitCamera()
{
	// Set up camera
	camera = new Camera();

	camera->eye.x = 0.0f;
	camera->eye.y = 0.0f;
	camera->eye.z = 1.0f;

	camera->center.x = 0.0f;
	camera->center.y = 0.0f;
	camera->center.z = 0.0f;

	camera->up.x = 0.0f;
	camera->up.y = 1.0f;
	camera->up.z = 0.0f;	
}

void Screen::Display()
{

}

// Update Camera for Current Screen
void Screen::Update()
{
	gluLookAt(
		camera->eye.x,
		camera->eye.y,
		camera->eye.z,

		camera->center.x,
		camera->center.y,
		camera->center.z,

		camera->up.x,
		camera->up.y,
		camera->up.z
	);
}