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
    //마우스 좌측 버튼 클릭시
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
        int val = (int)Player::Instance()->getYaw() % 360;          //yaw 360 나머지
        saveYaw = Player::Instance()->getYaw();                     //isShotStart일 때 yaw 저장
        val < 0 ? val *= -1 : val;                                  //양의 정수 만들어주기
        //  printf("%d\n", val);
        if ((val >= 0 && val <= 90) || (val >= 270 && val <= 360))  //shotPowerZ가 양수가 되는 부분
            isbiggerZ = true;
        else
            isbiggerZ = false;                                      //shotPowerZ가 음수가 되는 부분

        if ((val >= 0 && val <= 180))                               //shotPowerX가 양수가 되는 부분     
            isbiggerX = true;
        else
            isbiggerX = false;                                      //shotPowerX가 음수가 되는 부분  
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
    glMatrixMode(GL_MODELVIEW);                                                 //모델뷰 행렬 스택
    glTranslatef(Player::Instance()->getcamX() - shotPowerX,                    //총알 그리기
        Player::Instance()->getcamY() + (Player::Instance()->getPlayerPitch() / 200),
        Player::Instance()->getcamZ() - shotPowerZ);
        glutWireSphere(0.05f, 50.0f, 50.0f);
    glPopMatrix();
}
