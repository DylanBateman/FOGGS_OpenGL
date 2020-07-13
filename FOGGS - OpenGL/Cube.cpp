#include "Cube.h"

Cube::Cube(Mesh* mesh, Texture2D* texture, float x, float y, float z) : SceneObject(mesh, texture)
{
	// Sets Position floats
	_position.x = x;
	_position.y = y;
	_position.z = z;

	// Sets Cubes to Rotate on Y axis
	axisX = 0.0f;
	axisY = 1.0f;
	axisZ = 0.0f;

	_material = new Material();
}

Cube::~Cube()
{
	delete _material;
	_material = NULL;
}

void Cube::Draw()
{
	// Ensures Mesh is Loaded
	if (_mesh->Vertices != nullptr && _mesh->Normals != nullptr && _mesh->Indices != nullptr)
	{		
		glBindTexture(GL_TEXTURE_2D, _texture->GetID());
		
		glEnableClientState(GL_VERTEX_ARRAY);
		glEnable(GL_NORMAL_ARRAY);
		glEnableClientState(GL_TEXTURE_COORD_ARRAY);

		//OpenGL Pointers
		glVertexPointer(3, GL_FLOAT, 0, _mesh->Vertices);
		glNormalPointer(GL_FLOAT, 0, _mesh->Normals);
		glTexCoordPointer(2, GL_FLOAT, 0, _mesh->TexCoords);

		// Loads Material onto Cubes
		SetupLight();
		glMaterialfv(GL_FRONT, GL_AMBIENT,  &(_material->Ambient.x));
		glMaterialfv(GL_FRONT, GL_DIFFUSE,  &(_material->Diffuse.x));
		glMaterialfv(GL_FRONT, GL_SPECULAR, &(_material->Specular.x));
		glMaterialf(GL_FRONT, GL_SHININESS, _material->Shininess);

		// Sets Cubes to move and Rotate
		glPushMatrix();
			glTranslatef(_position.x, _position.y, _position.z);
			glRotatef(_rotation, axisX, axisY, axisZ);
			glDrawElements(GL_TRIANGLES, _mesh->IndexCount, GL_UNSIGNED_SHORT, _mesh->Indices);
		glPopMatrix();

		glDisableClientState(GL_VERTEX_ARRAY);
		glDisableClientState(GL_NORMAL_ARRAY);
		glDisableClientState(GL_TEXTURE_COORD_ARRAY);
	}
}

void Cube::Update()
{
	SceneObject::Update();

	// Cubes rotate on Update
	rotation += rotationSpeed;
	if (rotation >= 360.0f)
	{
		rotation = 0.0f;
	}

	// Cubes Move Towards Camera on Update
	_position.z += 0.2f;
	if (_position.z >= 0.0f)
	{
		_position.z = -100.0f;
	}
}

// Light Setup
void Cube::SetupLight()
{
	_material->Ambient.x = red;
	_material->Ambient.y = green;
	_material->Ambient.z = blue;
	_material->Ambient.w = 1.0;

	_material->Diffuse.x = red;
	_material->Diffuse.y = green;
	_material->Diffuse.z = blue;
	_material->Diffuse.w = 1.0;

	_material->Specular.x = 1.0;
	_material->Specular.y = 1.0;
	_material->Specular.z = 1.0;
	_material->Specular.w = 1.0;
	
	_material->Shininess = 100.0f;
}