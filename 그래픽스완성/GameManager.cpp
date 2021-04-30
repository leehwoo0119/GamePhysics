#include "glut.h"
#include "GameManager.h"
#include "KeyPressed.h"
#include "MouseClicked.h"
#include "DisplayManager.h"
#include "GameInfo.h"

void GameManager::setBasic()
{
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(width, height);
    glutCreateWindow("Projectile Motion - 3D Simulation");
}
void GameManager::init()
{
    glEnable(GL_DEPTH_TEST);                 //���� �׽�Ʈ(���ٰ�)
    glDepthFunc(GL_LEQUAL);                  //�۰ų� ������ ���� �׽�Ʈ ���
}
void GameManager::AppRender()
{
    DisplayManager::Instance()->myDisplay();
}
void GameManager::AppReshape(int w, int h)
{
    DisplayManager::Instance()->reshape(w, h);
}
void GameManager::AppKeyboard(unsigned char key, int x, int y)
{
    KeyPressed::Instance()->keyboard(key, x, y);
}
void GameManager::AppKeyboardUp(unsigned char key, int x, int y)
{
    KeyPressed::Instance()->keyboard_up(key, x, y);
}

void GameManager::AppMouse(int button, int state, int x, int y)
{
    MouseClicked::Instance()->mouse(button, state, x, y);
}
void GameManager::timer(int)
{
    //�����츦 �ٽ� �׸����� ��û
    glutPostRedisplay();
    //FPS(60)��ŭ ȭ���� ��� ������Ʈ
    glutTimerFunc(1000 / FPS, timer, 0);
}

void GameManager::Update()
{
    glutDisplayFunc(AppRender);               //mydisplay �ݹ�  
    glutReshapeFunc(AppReshape);              //reshape �ݹ�
    glutTimerFunc(0, timer, 0);               //60 ������ ����
    glutMouseFunc(AppMouse);                  //���콺 �Է� �ݹ�
    glutKeyboardFunc(AppKeyboard);            //���� â������ Ű����(������ ��) �ݹ�(�Ű����� �ƽ�Ű����)
    glutKeyboardUpFunc(AppKeyboardUp);        //���� â������ Ű����(���� ��) �ݹ�(�Ű����� �ƽ�Ű����)
}

