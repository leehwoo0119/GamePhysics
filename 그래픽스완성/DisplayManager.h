#ifndef __DISPLAYMANAGER_H_
#define __DISPLAYMANAGER_H_

class Bullet;

class DisplayManager
{
private:
	DisplayManager();
	virtual ~DisplayManager();

public:
	static DisplayManager* Instance()
	{
		static DisplayManager instance;
		return &instance;
	}

private:
	Bullet* bullet;

public:
	void myDisplay();
	void reshape(int, int);
};
#endif
