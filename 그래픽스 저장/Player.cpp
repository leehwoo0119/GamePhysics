#include "Player.h"

#include <stdio.h>

Player* Player::Instance()
{
    static Player instance;

    return &instance;
}
void Player::moveCtrl()
{
    if (getKey()->motion->getMotionForward())
    {
        pitch += 3;
        if (PlayerPitch < 100)PlayerPitch += 1;
    }
    if (getKey()->motion->getMotionLeft())
    {
        yaw += 1;
        if (PlayerYaw < 60)PlayerYaw += 1;
    }
    if (getKey()->motion->getMotionRight())
    {
        yaw -= 1;
        if (PlayerYaw > -60)PlayerYaw -= 1;
    }
    if (getKey()->motion->getMotionBackward())
    {
        pitch -= 3;
        if (PlayerPitch > -100)PlayerPitch -= 1;
    }
    if (PlayerYaw != 0)
    {
        if (!getKey()->motion->getMotionLeft() && !getKey()->motion->getMotionRight())
        {
            if (PlayerYaw > 0)PlayerYaw -= 1;
            if (PlayerYaw < 0)PlayerYaw += 1;
        }
    }
}

void Player::PlayerCtrl()
{
    drawPlayer();
    camX += cos((yaw + 90) * TO_RADIANS);
    camZ -= sin((yaw + 90) * TO_RADIANS);
    //printf("%d", getKey()->motion->getMotionForward());
    if (getKey()->motion->getMotionForward())
    {
        if (camY < 120) camY -= cos((pitch + 90) * TO_RADIANS) / 2.0;
    }
    if (getKey()->motion->getMotionBackward())
    {
        if (camY > 5)  camY += cos((pitch + 180) * TO_RADIANS) / 2.0;
    }
    if (camY < 5)camY = 5;
    
    if (pitch >= 100)
        pitch = 100;
    if (pitch <= -100)
        pitch = -100;
    // printf("%f\n", pitch);  
    // printf("%f\n", camX);
    // printf("%f\n", camY);
    // printf("%f\n", yaw);
    //ector::Instance()->SetVectorX(camX / 50);
    //ector::Instance()->SetVectorY(camY / 50);
    //ector::Instance()->SetVectorZ(camZ / 50);
    glRotatef(-pitch / 50, 1.0, 0.0, 0.0);  //x축 중심으로 -pitch만큼 회전
    glRotatef(-yaw, 0.0, 1.0, 0.0);    //y축 중심으로 -yaw만큼 회전(오버플로우 위험있음)
    glTranslatef(-camX
        , -camY,
        -camZ);
   
}
void Player::drawPlayer()
{
    if (getmouse()->getisPunch())isShot = true;
    else isShot = false;

    glPushMatrix();
    glRotatef(PlayerPitch / 5, 1.0, 0.0, 0.0);
    glRotatef(PlayerYaw, 0.0, 0.0, 1.0);
    glTranslatef(-0.35f, 0.5f, -3);
    glutSolidCube(0.1f);
    //glLoadIdentity();
    glPopMatrix();

    glPushMatrix();
    glRotatef(PlayerPitch / 5, 1.0, 0.0, 0.0);
    glRotatef(PlayerYaw, 0.0, 0.0, 1.0);
    glTranslatef(0.35f, 0.5f, -3);
    glutSolidCube(0.1f);
    //glLoadIdentity();
    glPopMatrix();

    if (isShot) {
        shotPower = 2.1;
    }
    else shotPower = 0;

    glPushMatrix();
    glRotatef(PlayerPitch / 5, 1.0, 0.0, 0.0);
    glRotatef(PlayerYaw, 0.0, 0.0, 1.0);
    glTranslatef(0.43f, 0.30f, -3 - shotPower);
    glutWireSphere(0.05f, 50.0f, 50.0f);
    glPopMatrix();

    glPushMatrix();
    glRotatef(PlayerPitch / 5, 1.0, 0.0, 0.0);
    glRotatef(PlayerYaw, 0.0, 0.0, 1.0);    //y축 중심으로 -yaw만큼 회전(오버플로우 위험있음)   
    glTranslatef(0.0f, 0.5f, -3);    //플래ㅔ이어
    glutWireCube(0.5f);
    glPopMatrix();
}

