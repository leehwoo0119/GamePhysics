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
    //getMotionForward()�� �� pitch++
    if (getKey()->getMotion()->getMotionForward())
    {
        pitch += 3;
        if (PlayerPitch < 60)PlayerPitch += 1;
    }
    //getMotionLeft()�� �� yaw++
    if (getKey()->getMotion()->getMotionLeft())
    {
        yaw += 1;
        if (PlayerYaw < 60)PlayerYaw += 1;
    }
    //getMotionRight()�� �� yaw--
    if (getKey()->getMotion()->getMotionRight())
    {
        yaw -= 1;
        if (PlayerYaw > -60)PlayerYaw -= 1;
    }
    //getMotionBackward()�� �� pitch--
    if (getKey()->getMotion()->getMotionBackward())
    {
        pitch -= 3;
        if (PlayerPitch > -60)PlayerPitch -= 1;
    }
    //getMotionAccelerator()�� �� Accelerator++
    if (getKey()->getMotion()->getMotionAccelerator())
    {
        if (Accelerator < 3) Accelerator += 0.025;
    }
    //!getMotionAccelerator()�� �� Accelerator--
    else
    {
        if (Accelerator > 1)Accelerator -= 0.025;
    }
    //PlayerYaw==�÷��̾� �¿� ���� Ű �Է� ������ �ڵ����� 0�̵ǵ���
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
    
    camX += cos((yaw + 90) * TO_RADIANS) * Accelerator;                   //x�� �̵�
    camZ -= sin((yaw + 90) * TO_RADIANS) * Accelerator;                   //z�� �̵�
    
    if (getKey()->getMotion()->getMotionForward())
    {
        if (camY < 120) camY -= cos((pitch + 90) * TO_RADIANS) / 2.0;     //�ִ� 120���� ���
    }
    if (getKey()->getMotion()->getMotionBackward())
    {
        if (camY > 5)  camY -= sin((pitch + 180) * TO_RADIANS) / 2.0;     //�ּ� 5���� �ϰ�
    }
    if (camY < 5)                                                         //���� 5���� ������ ����
        camY = 5;
    
    if (pitch >= 80)                                                      //ȸ�� ����
        pitch = 80;
    if (pitch <= -80)
        pitch = -80;
    
    drawPlayer();                                                         //�÷��̾� �׸���
    glRotatef(-pitch / 50, 1.0, 0.0, 0.0);                                // -pitch��ŭ ȸ��
    glRotatef(-yaw, 0.0, 1.0, 0.0);                                       // -yaw��ŭ ȸ��
     
    glTranslatef(-camX, -camY,-camZ);                                     //ī�޶� �̵�
   
}
void Player::drawPlayer()
{ 
    glPushMatrix();
    glRotatef(PlayerPitch / 5, 1.0, 0.0, 0.0);                            //�����̵�
    glRotatef(PlayerYaw, 0.0, 0.0, 1.0);                                  //�¿��̵�
    glTranslatef(-0.35f, 0.5f, -1.5 - (Accelerator / 2));                 //�̵�
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





