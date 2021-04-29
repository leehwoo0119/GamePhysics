#include "glut.h"
#include "GameManager.h"

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    
    GameManager::Instance()->setBasic();
    GameManager::Instance()->init();
    GameManager::Instance()->SetGame();

    glutMainLoop();

    return 0;
}



