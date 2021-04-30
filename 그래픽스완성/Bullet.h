#ifndef __BUIIET_H_
#define __BUIIET_H_

class MouseClicked;

class Bullet
{
public:
	Bullet(){}
	virtual ~Bullet(){}

private:
	bool isbiggerZ = false; bool isbiggerX = false;				//총알 이동관련
	bool isShotStart = false; bool isShotEnd = false;
	float shotPowerZ = 0.0; float shotPowerX = 0.0;

	float saveYaw = 0;

private:
	MouseClicked* getmouse();

public:
	void drawBullet();	
};

#endif