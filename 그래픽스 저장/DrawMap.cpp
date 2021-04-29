#include "DrawMap.h"
#include <stdio.h>
float miusn = 0;
DrawMap* DrawMap::Instance()
{
    static DrawMap instance;

    return &instance;
}

void DrawMap::drawMap()
{  
    
    glPushMatrix();  
    miusn -= 1.5;
    glTranslatef(0.0-miusn, 0.0, -20);
    glutWireTeapot(4.0f);
    glPopMatrix();

    glPushMatrix(); 
    glTranslatef(0.0, 0.0, -40);
    glutWireTeapot(4.0f);
    glPopMatrix();

    glPushMatrix();  
    glTranslatef(0.0, 0.0, -60);
    glutWireTeapot(6.0f);
    glPopMatrix();

    glEnable(GL_TEXTURE_2D);
    GLuint texture;
    glGenTextures(1, &texture);

    unsigned char texture_data[2][2][4] =
    {
        188,143,143,0.73,  188,143,143,0.73,
        139,69,19,0.54,   188,143,143,0.73
    };

    glBindTexture(GL_TEXTURE_2D, texture);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, 2, 2, 0, GL_RGBA, GL_UNSIGNED_BYTE, texture_data);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,
        GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
        GL_NEAREST);

    glBegin(GL_QUADS);

    glTexCoord2f(0.0, 0.0);  glVertex3f(-1000.0, -5.0, -1000.0);
    glTexCoord2f(250.0, 0.0);  glVertex3f(1000.0, -5.0, -1000.0);
    glTexCoord2f(250.0, 250.0);  glVertex3f(1000.0, -5.0, 1000.0);
    glTexCoord2f(0.0, 250.0);  glVertex3f(-1000.0, -5.0, 1000.0);
    glEnd();

    glDisable(GL_TEXTURE_2D);
}
