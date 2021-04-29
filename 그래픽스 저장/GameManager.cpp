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
  // glutSetCursor(GLUT_CURSOR_NONE);         //현재 창에 사용할 커서 이미지 설정
    glEnable(GL_DEPTH_TEST);                 //깊이 테스트(원근감)
    glDepthFunc(GL_LEQUAL);                  //작거나 깊으면 깊이 테스트 통과
   // glutWarpPointer(width / 2, height / 2);  //마우스 포인터 초기값 가운대로
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

void GameManager::SetGame()
{
    glutDisplayFunc(AppRender);
    glutReshapeFunc(AppReshape);

    glutTimerFunc(0, timer, 0);

    glutMouseFunc(AppMouse);
    glutKeyboardFunc(AppKeyboard);            //현재 창에대한 키보드 콜백(매개변수 아스키문자)
    glutKeyboardUpFunc(AppKeyboardUp);
}
