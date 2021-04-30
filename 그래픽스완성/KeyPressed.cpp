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

//눌렀을때
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
        //glutDestroyWindow(0);           //ESC 프로그램 종료
        exit(0);
        break;
    default:
        break;
    }
}
//뗏을때
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


