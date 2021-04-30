#include <math.h>
#include "glut.h"
#include "Player.h"
#include "KeyPressed.h"
#include "Motion.h"
#include "GameInfo.h"

KeyPressed* Player::getKey()
{
    return KeyPressed::Instance();
}

void Player::moveCtrl()
{
    //getMotionForward()일 때 pitch++
    if (getKey()->getMotion()->getMotionForward())
    {
        pitch += 3;
        if (PlayerPitch < 60)PlayerPitch += 1;
    }
    //getMotionLeft()일 때 yaw++
    if (getKey()->getMotion()->getMotionLeft())
    {
        yaw += 1;
        if (PlayerYaw < 60)PlayerYaw += 1;
    }
    //getMotionRight()일 때 yaw--
    if (getKey()->getMotion()->getMotionRight())
    {
        yaw -= 1;
        if (PlayerYaw > -60)PlayerYaw -= 1;
    }
    //getMotionBackward()일 때 pitch--
    if (getKey()->getMotion()->getMotionBackward())
    {
        pitch -= 3;
        if (PlayerPitch > -60)PlayerPitch -= 1;
    }
    //getMotionAccelerator()일 때 Accelerator++
    if (getKey()->getMotion()->getMotionAccelerator())
    {
        if (Accelerator < 3) Accelerator += 0.025;
    }
    //!getMotionAccelerator()일 때 Accelerator--
    else
    {
        if (Accelerator > 1)Accelerator -= 0.025;
    }
    //PlayerYaw==플레이어 좌우 기울기 키 입력 없을시 자동으로 0이되도록
    if (PlayerYaw != 0)
    {
        if (!getKey()->getMotion()->getMotionLeft() && !getKey()->getMotion()->getMotionRight())
        {
            if (PlayerYaw > 0)PlayerYaw -= 1;
            if (PlayerYaw < 0)PlayerYaw += 1;
        }
    }
}

void Player::CameraCtrl()
{
    
    camX += cos((yaw + 90) * TO_RADIANS) * Accelerator;                   //x축 이동
    camZ -= sin((yaw + 90) * TO_RADIANS) * Accelerator;                   //z축 이동
    
    if (getKey()->getMotion()->getMotionForward())
    {
        if (camY < 120) camY -= cos((pitch + 90) * TO_RADIANS) / 2.0;     //최대 120까지 상승
    }
    if (getKey()->getMotion()->getMotionBackward())
    {
        if (camY > 5)  camY -= sin((pitch + 180) * TO_RADIANS) / 2.0;     //최소 5까지 하강
    }
    if (camY < 5)                                                         //높이 5이하 못가게 고정
        camY = 5;
    
    if (pitch >= 80)                                                      //회전 제한
        pitch = 80;
    if (pitch <= -80)
        pitch = -80;
    
    drawPlayer();                                                         //플레이어 그리기
    glRotatef(-pitch / 50, 1.0, 0.0, 0.0);                                // -pitch만큼 회전
    glRotatef(-yaw, 0.0, 1.0, 0.0);                                       // -yaw만큼 회전
     
    glTranslatef(-camX, -camY,-camZ);                                     //카메라 이동
   
}
void Player::drawPlayer()
{ 
    glPushMatrix();
    glRotatef(PlayerPitch / 5, 1.0, 0.0, 0.0);                            //상하이동
    glRotatef(PlayerYaw, 0.0, 0.0, 1.0);                                  //좌우이동
    glTranslatef(-0.35f, 0.5f, -1.5 - (Accelerator / 2));                 //이동
    glutSolidCube(0.1f); 
    glPopMatrix();

    glPushMatrix();
    glRotatef(PlayerPitch / 5, 1.0, 0.0, 0.0);
    glRotatef(PlayerYaw, 0.0, 0.0, 1.0);
    glTranslatef(0.35f, 0.5f, -1.5 - (Accelerator / 2));
    glutSolidCube(0.1f);
    glPopMatrix();
    
    glPushMatrix();
    glRotatef(PlayerPitch / 5, 1.0, 0.0, 0.0);
    glRotatef(PlayerYaw, 0.0, 0.0, 1.0);     
    glTranslatef(0.0f, 0.5f, -1.5 - (Accelerator / 2));
    glutWireCube(0.5f);
    glPopMatrix();   
}





