#ifndef _GAMESCREENOBJLOADER_H

#include <Windows.h>
#include <gl/GLU.h>
#include "GL/freeglut.h"

#include "GLUTCallbacks.h"
#include "Screen.h"

#include "OBJLoader.h"

class GameScreenOBJLoader : Screen
{
public:
	GameScreenOBJLoader();
	~GameScreenOBJLoader(void);

	void Display();
	void Update();

	void InitGL();
	void InitLighting();
	void InitObjects();

	void Keyboard(unsigned char key, int x, int y);

	void DrawString(const char* text, Vector3* position, Color* color);

	void LoadOBJ();

private:
	bool loadedTeapot, loadedGourd, loadedIcosahedron;

	float rotation = 0.2f;

	OBJLoader OBJTeapot, OBJGourd, OBJIcosahedron;
};

#endif // !_GAMESCREENOBJLOADER_H