#include "GLUTCallbacks.h"

#include "GameScreenManager.h"

#include "GameScreenMenu.h"
#include "GameScreenCubefield.h"
#include "GameScreenOBJLoader.h"

namespace GLUTCallbacks
{
	namespace
	{
		// Pointers for Callbacks
		GameScreenManager* gameScreenManager = nullptr;
		GameScreenMenu* gameScreenMenu = nullptr;

		GameScreenCubefield* gameScreenCubefield = nullptr;
		GameScreenOBJLoader* gameScreenOBJLoader = nullptr;

	}
	// Initalise Screen Manager
	void Init(GameScreenManager* gl)
	{
		gameScreenManager = gl;
	}

	// Initalise Game Screens
	void Init(GameScreenMenu* gl)
	{
		gameScreenCubefield = nullptr;
		gameScreenOBJLoader = nullptr;

		gameScreenMenu = gl;
	}

	void Init(GameScreenCubefield* gl)
	{
		gameScreenMenu = nullptr;
		gameScreenOBJLoader = nullptr;

		gameScreenCubefield = gl;
	}

	void Init(GameScreenOBJLoader* gl)
	{
		gameScreenMenu = nullptr;
		gameScreenCubefield = nullptr;

		gameScreenOBJLoader = gl;
	}


	// Displays Correct Screen
	void Display()
	{
		if (gameScreenMenu != nullptr)
			gameScreenMenu->Display();

		else if (gameScreenCubefield != nullptr)
			gameScreenCubefield->Display();

		else if (gameScreenOBJLoader != nullptr)
			gameScreenOBJLoader->Display();
	}

	// Controls FPS for Each Screen
	void Timer(int preferredRefresh)
	{
		int updateTime = glutGet(GLUT_ELAPSED_TIME);

		if (gameScreenMenu != nullptr)
			gameScreenMenu->Update();

		else if (gameScreenCubefield != nullptr)
			gameScreenCubefield->Update();

		else if (gameScreenOBJLoader != nullptr)
			gameScreenOBJLoader->Update();

	

		updateTime = glutGet(GLUT_ELAPSED_TIME) - updateTime;
		glutTimerFunc(preferredRefresh - updateTime, GLUTCallbacks::Timer, preferredRefresh);
	}

	// Keyboard Controls For Each Screen
	void Keyboard(unsigned char key, int x, int y)
	{
		gameScreenManager->Keyboard(key, x, y);

		if (gameScreenCubefield != nullptr)
			gameScreenCubefield->Keyboard(key, x, y);

		else if (gameScreenOBJLoader != nullptr)
			gameScreenOBJLoader->Keyboard(key, x, y);
	}
}