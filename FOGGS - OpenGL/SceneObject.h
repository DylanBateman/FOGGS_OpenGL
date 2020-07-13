#pragma once

#include "Structures.h"
#include "Texture2D.h"

class SceneObject
{
public:
	SceneObject(Mesh* mesh, Texture2D* texture);
	virtual ~SceneObject();

	virtual void Update();
	virtual void Draw();

	GLfloat _rotation;
	Vector3 _position;

	float red, green, blue,		axisX, axisY, axisZ;

protected:
	Mesh* _mesh;
	Texture2D* _texture;
};