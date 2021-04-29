#ifndef PLAYER
#define CAMERA
#include "GameInfo.h"
#include <math.h>
#include "KeyPressed.h"
#include "MouseClicked.h"
class Player
{
private:
	const int width = 16 * 50;
	const int height = 9 * 50;
	float pitch = 0.0, yaw = 0.0;
	
	float camX = 0.0, camZ = 0.0, camY = 30.0;
	bool isShot = false;
	float shotPower = 0.0;
public:
	float PlayerPitch = 0.0, PlayerYaw = 0.0;
	static Player* Instance();
	void PlayerCtrl();
	void moveCtrl();
	void drawPlayer();
	KeyPressed* getKey() { return KeyPressed::Instance(); };
	MouseClicked* getmouse() { return MouseClicked::Instance(); };
private:
	Player()
	{
	}
	virtual ~Player()
	{
	}
};
#endif
