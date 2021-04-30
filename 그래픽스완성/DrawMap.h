#ifndef __DRAWMAP_H_
#define __DRAWMAP_H_

class DrawMap
{
private:
	DrawMap() {}
	virtual ~DrawMap() {}

public:
	static DrawMap* Instance()
	{
		static DrawMap instance;
		return &instance;
	}

public:
	void drawMap();

};
#endif
