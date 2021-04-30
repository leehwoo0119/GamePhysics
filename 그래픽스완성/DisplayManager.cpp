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
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);// depth buffer�� ����ֱ�
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    Player::Instance()->CameraCtrl();           //ī�޶�
 
    Player::Instance()->moveCtrl();             //�̵� ����

    DrawMap::Instance()->drawMap();             //�ʱ׸���
    
    bullet->drawBullet();                       //�Ѿ� �׸���
  
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






