#include "glut.h"
#include <GL/gl.h>
#include <GL/glu.h>

float angle_1 = 0, angle_2 = 0, angle_3 = 0;
float trans = 0.3;
void MyDisplay()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glViewport(0, 0, 1000, 1000);
    glColor3f(0.0, 0.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
    //수성
    glPushMatrix();
    glRotatef(angle_2*1.7, 0.0, 0.0, 1.0);
    glColor3f(1.0, 1.0, 0.0);
    glTranslatef(trans-0.18, 0.0, 0.0);
    glutWireSphere(0.02, 20, 16);

    //금성
    glLoadIdentity();
    glPopMatrix();
    glPushMatrix();
    glColor3f(0.0, 1.0, 0.0);
    glRotatef(angle_2*1.3, 0.0, 0.0, 1.0);
    glTranslatef(trans -0.1, 0.0, 0.0);
    glutWireSphere(0.025, 20, 16);

    //지구
    glLoadIdentity();
    glColor3f(0.0, 0.0, 1.0);
    glRotatef(angle_2, 0.0, 0.0, 1.0);
    glTranslatef(trans, 0.0, 0.0);
    glutWireSphere(0.03, 20, 16);

    
    //달
   
    glRotatef(angle_3, 0.0, 0.0, 1.0);
    glTranslatef(trans - 0.35, 0.0, 0.0);
    glutSolidCube(0.015);
    glutWireSphere(0.005, 20, 16);

    //화성
    glLoadIdentity();
    glPopMatrix();
    glPushMatrix();
    glColor3f(0.5, 0.5, 0.5);
    glRotatef(angle_2/1.3, 0.0, 0.0, 1.0);
    glTranslatef(trans + 0.15, 0.0, 0.0);
    glutWireSphere(0.035, 20, 16);

    //목성
    glLoadIdentity();
    glPopMatrix();
    glPushMatrix();
    glColor3f(1.0, 0.0, 1.0);
    glRotatef(angle_2 / 1.6, 0.0, 0.0, 1.0);
    glTranslatef(trans + 0.3, 0.0, 0.0);
    glutWireSphere(0.045, 20, 16);

    //토성
    glLoadIdentity();
    glPopMatrix();
    glPushMatrix();
    glColor3f(0.0, 1.0, 1.0);
    glRotatef(angle_2 / 1.8, 0.0, 0.0, 1.0);
    glTranslatef(trans + 0.45, 0.0, 0.0);
    glutWireSphere(0.04, 20, 16);

    //천왕성
    glLoadIdentity();
    glPopMatrix();
    glPushMatrix();
    glColor3f(0.5, 1.0, 0.0);
    glRotatef(angle_2 / 2, 0.0, 0.0, 1.0);
    glTranslatef(trans + 0.55, 0.0, 0.0);
    glutWireSphere(0.02, 20, 16);

    //해왕성
    glLoadIdentity();
    glPopMatrix();
    glPushMatrix();
    glColor3f(0.0, 0.5, 0.0);
    glRotatef(angle_2 / 2.2, 0.0, 0.0, 1.0);
    glTranslatef(trans + 0.6, 0.0, 0.0);
    glutWireSphere(0.02, 20, 16);
    //해
   
    glLoadIdentity();
    glColor3f(1.0, 0.0, 0.0);
    glRotatef(angle_1, 0.0, 0.0, 1.0);
    glutWireSphere(0.08, 20, 16);
   
    glutSwapBuffers();
}

void MyIdle()
{
    angle_1 += 0.005f;
    angle_2 += 0.02f;
    angle_3 += 0.03f;
    glutPostRedisplay();
}

int main(int argc, char** argv)
{
    
    glutInit(&argc,argv);
    //glutInitDisplayMode(GLUT_RGBA);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowSize(1000, 1000);
    glutInitWindowPosition(500, 500);
    glutCreateWindow("OpenGL Sample Drawing");
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
    glutDisplayFunc(MyDisplay);
    glutIdleFunc(MyIdle);
    glutMainLoop();
    return 0;
}
