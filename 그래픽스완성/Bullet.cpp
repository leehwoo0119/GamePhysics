#include <math.h>
#include "GameInfo.h"
#include "glut.h"
#include "Bullet.h"
#include "Player.h"
#include "MouseClicked.h"

MouseClicked* Bullet::getmouse()
{
    return MouseClicked::Instance();
}

void Bullet::drawBullet()
{
    //���콺 ���� ��ư Ŭ����
    if (getmouse()->getisShot())
    {
        isShotStart = true;
        shotPowerZ = 0;
        shotPowerX = 0;
        isShotEnd = false;
    }
    else
    {
        isShotStart = false;
    }

    if (isShotStart)
    {
        int val = (int)Player::Instance()->getYaw() % 360;          //yaw 360 ������
        saveYaw = Player::Instance()->getYaw();                     //isShotStart�� �� yaw ����
        val < 0 ? val *= -1 : val;                                  //���� ���� ������ֱ�
        //  printf("%d\n", val);
        if ((val >= 0 && val <= 90) || (val >= 270 && val <= 360))  //shotPowerZ�� ����� �Ǵ� �κ�
            isbiggerZ = true;
        else
            isbiggerZ = false;                                      //shotPowerZ�� ������ �Ǵ� �κ�

        if ((val >= 0 && val <= 180))                               //shotPowerX�� ����� �Ǵ� �κ�     
            isbiggerX = true;
        else
            isbiggerX = false;                                      //shotPowerX�� ������ �Ǵ� �κ�  
        isShotEnd = true;
    }
    if (isShotEnd)
    {
        if (isbiggerZ)
        {
            shotPowerZ += sin((saveYaw + 90) * TO_RADIANS);;
        }
        else
        {
            shotPowerZ += sin((saveYaw + 90) * TO_RADIANS);;
        }
        if (isbiggerX)
        {
            shotPowerX -= cos((saveYaw + 90) * TO_RADIANS);
        }
        else
        {
            shotPowerX -= cos((saveYaw + 90) * TO_RADIANS);
        }
    }
   
    glPushMatrix();
    glMatrixMode(GL_MODELVIEW);                                                 //�𵨺� ��� ����
    glTranslatef(Player::Instance()->getcamX() - shotPowerX,                    //�Ѿ� �׸���
        Player::Instance()->getcamY() + (Player::Instance()->getPlayerPitch() / 200),
        Player::Instance()->getcamZ() - shotPowerZ);
        glutWireSphere(0.05f, 50.0f, 50.0f);
    glPopMatrix();
}
