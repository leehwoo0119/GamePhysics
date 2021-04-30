#include "glut.h"
#include "KeyPressed.h"
#include "Motion.h"

KeyPressed::KeyPressed()
{
    motion = new Motion;
}
KeyPressed::~KeyPressed()
{
    delete motion;
}

//��������
void KeyPressed::keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'W':
    case 'w':          
        motion->setMotionForward(true);
        break;
    case 'A':
    case 'a':
        motion->setMotionLeft(true);
        break;
    case 'S':
    case 's':
        motion->setMotionBackward(true);
        break;
    case 'D':
    case 'd':
        motion->setMotionRight(true);
        break;
    case 32:
        motion->setMotionAccelerator(true);
        break;
    case 27:
        //glutDestroyWindow(0);           //ESC ���α׷� ����
        exit(0);
        break;
    default:
        break;
    }
}
//������
void KeyPressed::keyboard_up(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'W':
    case 'w':
        motion->setMotionForward(false);
        break;
    case 'A':
    case 'a':
        motion->setMotionLeft(false);
        break;
    case 'S':
    case 's':
        motion->setMotionBackward(false);
        break;
    case 'D':
    case 'd':
        motion->setMotionRight(false);
        break;
    case 32:
        motion->setMotionAccelerator(false);
        break;
    default:
        break;
    }

}

Motion* KeyPressed::getMotion()
{
    return motion;
}


