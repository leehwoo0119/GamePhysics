#ifndef KEYPRESSED
#define KEYPRESSED
#include "Motion.h"
#include "glut.h"

class KeyPressed
{
private:

public:
	static KeyPressed* Instance();
	Motion* motion;
	void keyboard(unsigned char key, int x, int y);
	void keyboard_up(unsigned char key, int x, int y);

private:
	KeyPressed()
	{
		motion = new Motion;
	}
	virtual ~KeyPressed()
	{
		delete motion;
	}
};

#endif