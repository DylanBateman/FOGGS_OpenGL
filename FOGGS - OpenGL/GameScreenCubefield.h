#ifndef _GAMESCREENCUBEFIELD_H

#include "GLUTCallbacks.h"
#include "Structures.h"
#include "Screen.h"
#include "Cube.h"
#include "SceneObject.h"

class GameScreenCubefield : Screen
{
public:
	GameScreenCubefield();
	~GameScreenCubefield(void);

	void Display();
	void Update();

	void InitGL();
	void InitLighting();
	void InitObjects();

	void Keyboard(unsigned char key, int x, int y);

	void DrawString(const char* text, Vector3* position, Color* color);

private:
	float rotation;

	float movementSpeed = 0.5f;

	Mesh* cubeMesh;

	Texture2D* texturePenguins;
	Texture2D* textureStars;

	SceneObject* objects[OBJECTCOUNT];

};

#endif // !_GAMESCREENCUBEFIELD_H