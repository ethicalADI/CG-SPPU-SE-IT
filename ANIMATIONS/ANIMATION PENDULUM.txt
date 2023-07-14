
/*
BY:ADITYA KUMAR  
Topic: ANIMATION:PENDULUM
*/

#include<bits/stdc++.h>
#include <GL/glut.h>
using namespace std;

float px = 100, py = 100;
float triangleRotation = 0.0;
float rectangleRotation = 0.0;
float tx=0.0;
float speedy=0.0;
int k=0;

void drawCircle(float cx, float cy, float r, int num_segments)
{
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_TRIANGLE_FAN);
    for(int ii = 0; ii < num_segments; ii++)
    {
        float theta = 2.0f * 3.1415926f * float(ii) / float(num_segments);
        float x = r * cosf(theta);
        float y = r * sinf(theta);
        glVertex2f(x + cx, y + cy);
    }
    glEnd();
}
void drawCircle1(float cx, float cy, float r, int num_segments)
{
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_LINE_LOOP);
    for(int ii = 0; ii < num_segments; ii++)
    {
        float theta = 2.0f * 3.1415926f * float(ii) / float(num_segments);

        float x = r * cosf(theta);
        float y = r * sinf(theta);
        glVertex2f(x + cx, y + cy);
    }
    glEnd();
}
void pendulum(){
    glBegin(GL_LINES);
     glVertex2f(0,110);
     glVertex2f(0,110-100);
    glEnd();
    glFlush();
    drawCircle(-3,-25,30,360);

}

void Init() {
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    gluOrtho2D(-320.0, 320.0, -240.0, 240.0);
}
void draw(){

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,150,0);
    glRotatef(triangleRotation, 0, 0, 1);
    glTranslatef(0,-150,0);
    glLineWidth(5);
    glBegin(GL_LINES);
     glVertex2f(0, 150);
     glVertex2f(0,200);
    glEnd();
    glPopMatrix();
    glFlush();

    glPushMatrix();
    glTranslatef(0,110,0);
    glRotatef(speedy,0,0,1);
    glTranslatef(0,-110,0);
       glLineWidth(5);
    glBegin(GL_LINES);
     glVertex2f(0,110);
     glVertex2f(0,110-100);
    glEnd();
    glPopMatrix();
    glFlush();

    float offsetX = 0.0;
    float bobX = offsetX + sinf(speedy * 3.14159 / 180.0) * 100.0f;
    float bobY = 10.0f - cosf(speedy * 3.14159 / 180.0) * 100.0f;
    drawCircle(bobX,bobY+100,30,360);
    glutSwapBuffers();

}

void idle(){
   triangleRotation += 0.3;
   tx+=0.5;
   if(k==1){
    speedy-=0.1;
    if(speedy < -45.0){
        k=0;
    }
   }
   if(k==0){
    speedy+=0.1;
    if (speedy > 45.0){
    k=1;
   }
   }
   glutPostRedisplay();
}

void Display() {
    glPointSize(5);
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    glColor3f(1.0, 0.0, 0.0);
    gluOrtho2D(-320.0, 320.0, -240.0, 240.0);
    drawCircle1(1,150,50,360);
    draw();
}
void mouse(int button, int state, int mx, int my) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {

        glPointSize(5);
        glBegin(GL_POINTS);
        glVertex2f(mx - 320, 240 - my);
        glEnd();
        glFlush();
    }
}
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(200, 100);
    glutCreateWindow("2D ANIMATION");
    glutDisplayFunc(Display);
    glutMouseFunc(mouse);
    glutIdleFunc(idle);
    Init();
    glutMainLoop();
}
