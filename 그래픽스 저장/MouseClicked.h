#ifndef MOUSECLICKED
#define MOUSECLICKED
#include "glut.h"
class MouseClicked
{
private:
	bool isPunch = false;
public:
	static MouseClicked* Instance();
	bool getisPunch() { return isPunch; }
	void mouse(int, int, int, int);
private:
	MouseClicked()
	{
	}
	virtual ~MouseClicked()
	{
	}
};
#endif
