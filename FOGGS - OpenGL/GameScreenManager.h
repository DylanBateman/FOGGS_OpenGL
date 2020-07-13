#ifndef _GAMESCREENMANAGER_H

#include "Structures.h"

#include <iostream>

class Screen;

class GameScreenManager
{
public:
	GameScreenManager();
	~GameScreenManager(void);

	void Display();
	void Update();

	void ChangeScreen(SCREENS newScreen);
	void Keyboard(unsigned char key, int x, int y);

private:
	Screen* mCurrentScreen;
};

#endif // !_GAMESCREENMANAGER_H