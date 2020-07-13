#ifndef _OBJLOADER_H


#include <windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include "GL/glut.h"

// Input Output Stream
#include <iostream>

//File Stream
#include <fstream>

//Mathematical Functions
#include <cmath>

// String Stream
#include <sstream>

//String Type
#include <string>

class OBJLoader
{
public:
	OBJLoader();

	float* calculateNormal(float* coord1, float* coord2, float* coord3);

	int Load(char* filename);

	void Draw();

	void Release();

	float* normals;
	float* triangleFaces;
	float* vertexBuffer;

	long totalPoints;
	long totalTriangles;
};

#endif // !_OBJLOADER_H