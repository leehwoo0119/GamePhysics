#ifndef __MOUSECLICKED_H_
#define __MOUSECLICKED_H_

class MouseClicked
{
private:
	MouseClicked() {}
	virtual ~MouseClicked() {}

public:
	static MouseClicked* Instance()
	{
		static MouseClicked instance;
		return &instance;
	}

private:
	bool isShot = false;

public:
	bool getisShot() { return isShot; }
	void mouse(int, int, int, int);

};
#endif
