#ifndef _GLUTCALLBACKS_H

class GameScreenManager;

class GameScreenMenu;
class GameScreenCubefield;
class GameScreenOBJLoader;

namespace GLUTCallbacks
{
	void Init(GameScreenManager* gl);

	void Init(GameScreenMenu* gl);
	void Init(GameScreenCubefield* gl);
	void Init(GameScreenOBJLoader* gl);

	void Display();

	void Timer(int preferredRefresh);

	void Keyboard(unsigned char key, int x, int y);

};

#endif // !_GLUTCALLBACKS_H