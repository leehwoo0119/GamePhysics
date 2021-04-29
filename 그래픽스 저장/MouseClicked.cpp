#include "MouseClicked.h"
#include <stdio.h>
MouseClicked* MouseClicked::Instance()
{
    static MouseClicked instance;

    return &instance;
}

void MouseClicked::mouse(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        isPunch = true;
    }
    if (button == GLUT_LEFT_BUTTON && state == GLUT_UP)
    {
        isPunch = false;
    }
}
