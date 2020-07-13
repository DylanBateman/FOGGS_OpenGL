#include "GameScreenManager.h"

#include <Windows.h>
#include <gl/GLU.h>
#include "GL/freeglut.h"

// Initlaises Window and other OpenGL CCOmponents
int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("FOGGS - OpenGL");

	glMatrixMode(GL_PROJECTION);
	glViewport(0, 0, 800, 800);
	gluPerspective(90, 1, 1, 1000);

	glEnable(GL_TEXTURE_2D);
	glMatrixMode(GL_MODELVIEW);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);

	GameScreenManager *game = new GameScreenManager();

	return 0;
}