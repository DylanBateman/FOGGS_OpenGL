#ifndef _GAMESCREENMENU_H

#include <Windows.h>
#include <gl/GLU.h>
#include "GL/freeglut.h"

#include "GLUTCallbacks.h"
#include "Screen.h"
#include "Texture2D.h"

class GameScreenMenu : Screen
{
public:
	GameScreenMenu();
	~GameScreenMenu(void);

	void Display();
	void Update();

	void InitGL();

	void InitObjects();

	void DrawString(const char* text, Vector3* position, Color* color);
	void DrawText();
};

#endif // !_GAMESCREENMENU_H