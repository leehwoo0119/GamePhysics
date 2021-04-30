#include "glut.h"
#include "MouseClicked.h"

void MouseClicked::mouse(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        isShot = true;
    }
    if (button == GLUT_LEFT_BUTTON && state == GLUT_UP)
    {
        isShot = false;
    }
}
