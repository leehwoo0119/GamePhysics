#ifndef DRAWMAP
#define DRAWMAP
#include "glut.h"

class DrawMap
{
public:
	static DrawMap* Instance();
	void drawMap();
private:
	DrawMap()
	{
	}
	virtual ~DrawMap()
	{
	}
};
#endif
