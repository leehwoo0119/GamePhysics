#include "GameManager.h"

GameManager* GameManager::Instance()
{
    static GameManager instance;

    return &instance;
}
void GameManager::setBasic()
{
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(width, height);
    glutCreateWindow("Projectile Motion - 3D Simulation");
}
void GameManager::init()
{
  // glutSetCursor(GLUT_CURSOR_NONE);         //���� â�� ����� Ŀ�� �̹��� ����
    glEnable(GL_DEPTH_TEST);                 //���� �׽�Ʈ(���ٰ�)
    glDepthFunc(GL_LEQUAL);                  //�۰ų� ������ ���� �׽�Ʈ ���
   // glutWarpPointer(width / 2, height / 2);  //���콺 ������ �ʱⰪ ������
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

void GameManager::SetGame()
{
    glutDisplayFunc(AppRender);
    glutReshapeFunc(AppReshape);

    glutTimerFunc(0, timer, 0);

    glutMouseFunc(AppMouse);
    glutKeyboardFunc(AppKeyboard);            //���� â������ Ű���� �ݹ�(�Ű����� �ƽ�Ű����)
    glutKeyboardUpFunc(AppKeyboardUp);
}
