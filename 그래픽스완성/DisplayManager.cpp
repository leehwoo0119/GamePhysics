#include "glut.h"
#include "DisplayManager.h"
#include "Player.h"
#include "Bullet.h"
#include "DrawMap.h"

DisplayManager::DisplayManager()
{
    bullet = new Bullet;
}

DisplayManager::~DisplayManager()
{
    delete bullet; bullet = nullptr;
}

void DisplayManager::myDisplay()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);// depth buffer를 비워주기
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    Player::Instance()->CameraCtrl();           //카메라
 
    Player::Instance()->moveCtrl();             //이동 전반

    DrawMap::Instance()->drawMap();             //맵그리기
    
    bullet->drawBullet();                       //총알 그리기
  
    glutSwapBuffers();
}

void DisplayManager::reshape(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60, 16.0 / 9.0, 1, 1000);
    glMatrixMode(GL_MODELVIEW);
}






