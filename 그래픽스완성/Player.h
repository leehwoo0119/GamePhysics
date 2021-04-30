#ifndef __PLAYER_H_
#define __PLAYER_H_

class KeyPressed;

class Player
{
private:
	Player() {}
	virtual ~Player() {}

public:
	static Player* Instance()
	{
		static Player instance;
		return &instance;
	}

private:
	float camX = 0.0; float camZ = 0.0; float camY = 30.0;		//카메라 움직임
	float pitch = 0.0; float yaw = 0.0;							//카메라 회전
							
	
	float PlayerPitch = 0.0, PlayerYaw = 0.0;					//플레이어 회전

	float Accelerator = 1;					

private:
	KeyPressed* getKey();
	
public:
	void CameraCtrl();
	void moveCtrl();
	void drawPlayer();

	float getPitch() { return pitch; }
	float getYaw() { return yaw; }
	float getPlayerPitch() {return PlayerPitch;}
	float getcamX() { return camX; }
	float getcamY() { return camY; }
	float getcamZ() { return camZ; }
};
#endif
