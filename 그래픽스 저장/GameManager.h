#ifndef GAMEMANAGER
#define GAMEMANAGER
#include "glut.h"
#include "GameInfo.h"
#include "KeyPressed.h"
#include "DisplayManager.h"
#include "MouseClicked.h"
class GameManager
{
public:
	static GameManager* Instance();
	void setBasic();
	void init();
	void SetGame();
	static void AppRender();
	static void AppReshape(int, int);
	static void AppKeyboard(unsigned char, int, int);
	static void AppKeyboardUp(unsigned char, int, int);
	static void AppMouse(int, int, int, int);
	static void timer(int);
private:
	GameManager() {};
	virtual ~GameManager() {};
};
#endif
