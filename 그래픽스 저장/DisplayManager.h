#ifndef DISPLAYMANAGER
#define DISPLAYMANAGER
#include "glut.h"
#include "DrawMap.h"

class DisplayManager
{
public:
	static DisplayManager* Instance();
	void myDisplay();

	
	void reshape(int, int);
private:
	DisplayManager()
	{
	}
	virtual ~DisplayManager()
	{
	}
};
#endif
