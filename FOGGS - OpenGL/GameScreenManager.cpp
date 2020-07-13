#include "GLUTCallbacks.h"

#include "Screen.h"
#include "GameScreenManager.h"

#include "GameScreenMenu.h"
#include "GameScreenCubefield.h"
#include "GameScreenOBJLoader.h"


GameScreenManager::GameScreenManager()
{
	mCurrentScreen = NULL;

	// Initalises Callbacks
	GLUTCallbacks::Init(this);
	glutKeyboardFunc(GLUTCallbacks::Keyboard);
	glutTimerFunc(REFRESHRATE, GLUTCallbacks::Timer, REFRESHRATE);

	// Sets Screen to Menu Screen
	ChangeScreen(SCREEN_MENU);
}

GameScreenManager::~GameScreenManager(void)
{
	delete mCurrentScreen;
	mCurrentScreen = NULL;
}

void GameScreenManager::Display()
{
	// Displays Screen
	mCurrentScreen->Display();
}

void GameScreenManager::Update()
{
	// Updates Screen
	mCurrentScreen->Update();
}

// Changes Screens
void GameScreenManager::ChangeScreen(SCREENS newScreen)
{	
	GameScreenMenu* tempMenu;
	GameScreenCubefield* tempCubefield;
	GameScreenOBJLoader* tempOBJLoader;

	switch (newScreen)
	{
	case SCREEN_MENU:
		tempMenu = new GameScreenMenu();
		mCurrentScreen = (Screen*)tempMenu;
		tempMenu = NULL;
		break;
	case SCREEN_CUBEFIELD:
		tempCubefield = new GameScreenCubefield();
		mCurrentScreen = (Screen*)tempCubefield;
		tempCubefield = NULL;
		break;
	case SCREEN_OBJLOADER:
		tempOBJLoader = new GameScreenOBJLoader();
		mCurrentScreen = (Screen*)tempOBJLoader;
		tempOBJLoader = NULL;
		break;
	default:
		std::cout << "ERROR::Was not able to load any of the scenes!" << std::endl;
		break;
	}

	mCurrentScreen->~Screen();
}

// Keyboard Controls for Menu
void GameScreenManager::Keyboard(unsigned char key, int x, int y)
{
	if (key == '1' || key == '2' || key == '3' || key == 27)
	{
		delete mCurrentScreen;
		mCurrentScreen = NULL;
	}

	if (key == '1')
		ChangeScreen(SCREEN_MENU);

	else if (key == '2')
		ChangeScreen(SCREEN_CUBEFIELD);

	else if (key == '3')
		ChangeScreen(SCREEN_OBJLOADER);

	if (key == 27)
		exit(0);
}