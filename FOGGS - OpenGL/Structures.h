#pragma once

#include <Windows.h>
#include <gl\GL.h>

#define REFRESHRATE		16
#define OBJECTCOUNT		800

enum SCREENS
{
	SCREEN_MENU = 0,
	SCREEN_CUBEFIELD,
	SCREEN_OBJLOADER
};

// Camera Structures
struct Vector3
{
	float x;
	float y;
	float z;
};

struct Camera
{
	Vector3 eye;
	Vector3 center;
	Vector3 up;
};

// Lighting Structures
struct Vector4
{
	float x, y, z, w;
};

struct Lighting
{
	Vector4 Ambient, Diffuse, Specular;
};

struct Material
{
	Vector4 Ambient, Diffuse, Specular;
	GLfloat Shininess;
};

// Mesh Structures
struct Vertex
{
	GLfloat x, y, z;
};

struct Color
{
	GLfloat r, g, b;
};

struct TexCoord
{
	GLfloat u, v;
};

// Mesh Structure
struct Mesh
{
	Vertex* Vertices;
	Vector3* Normals;
	TexCoord* TexCoords;
	GLushort* Indices;
	int VertexCount, NormalCount, IndexCount, TexCoordCount;
};