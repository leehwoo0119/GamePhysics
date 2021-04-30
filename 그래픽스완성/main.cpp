#include "glut.h"
#include "GameManager.h"

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    
    GameManager::Instance()->setBasic();
    GameManager::Instance()->init();
    GameManager::Instance()->Update();

    glutMainLoop();

    return 0;
}



