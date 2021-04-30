#ifndef __GAMEMANAGER_H_
#define __GAMEMANAGER_H_

class GameManager
{
private:
	GameManager() {};
	virtual ~GameManager() {};

public:
	static GameManager* Instance()
	{
		static GameManager instance;
		return &instance;
	}

private:
	static void AppRender();
	static void AppReshape(int, int);
	static void AppKeyboard(unsigned char, int, int);
	static void AppKeyboardUp(unsigned char, int, int);
	static void AppMouse(int, int, int, int);
	static void timer(int);

public:
	void setBasic();
	void init();
	void Update();
};
#endif
