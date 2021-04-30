#ifndef __KEYPRESSED_H_
#define __KEYPRESSED_H_

class Motion;

class KeyPressed
{
private:
	KeyPressed();
	virtual ~KeyPressed();

public:
	static KeyPressed* Instance()
	{
		static KeyPressed instance;
		return &instance;
	}

private:
	Motion* motion;

public:
	void keyboard(unsigned char key, int x, int y);
	void keyboard_up(unsigned char key, int x, int y);
	Motion* getMotion();

};

#endif