#include "DisplayManager.h"
#include "Player.h"


DisplayManager* DisplayManager::Instance()
{
    static DisplayManager instance;

    return &instance;
}
void DisplayManager::myDisplay()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);// depth buffer를 비워주기

    glLoadIdentity();
    
    
    Player::Instance()->PlayerCtrl();
    Player::Instance()->moveCtrl();
   // Camera::Instance()->CameraView();
    DrawMap::Instance()->drawMap();
   
   /* glPushMatrix();
    glTranslatef(0.0, 0.0, -40);
    glutWireTeapot(4.0f);
    glPopMatrix();*/
   

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






