#pragma once

#include <Windows.h>
#include <gl/GL.h>
#include "GL/freeglut.h"

#include "Structures.h"

class Screen
{
public:
	Screen();
	~Screen(void);

	virtual void InitGL();
	virtual void InitLighting();
	virtual void InitCamera();

	virtual void Display();
	virtual void Update();

	Camera* camera;

	Vector4* _lightPosition;
	Lighting* _lightData;
};