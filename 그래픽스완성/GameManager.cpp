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
    glEnable(GL_DEPTH_TEST);                 //깊이 테스트(원근감)
    glDepthFunc(GL_LEQUAL);                  //작거나 깊으면 깊이 테스트 통과
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
    //윈도우를 다시 그리도록 요청
    glutPostRedisplay();
    //FPS(60)만큼 화면을 계속 업데이트
    glutTimerFunc(1000 / FPS, timer, 0);
}

void GameManager::Update()
{
    glutDisplayFunc(AppRender);               //mydisplay 콜백  
    glutReshapeFunc(AppReshape);              //reshape 콜백
    glutTimerFunc(0, timer, 0);               //60 프레임 고정
    glutMouseFunc(AppMouse);                  //마우스 입력 콜백
    glutKeyboardFunc(AppKeyboard);            //현재 창에대한 키보드(눌렀을 때) 콜백(매개변수 아스키문자)
    glutKeyboardUpFunc(AppKeyboardUp);        //현재 창에대한 키보드(뗏을 때) 콜백(매개변수 아스키문자)
}

