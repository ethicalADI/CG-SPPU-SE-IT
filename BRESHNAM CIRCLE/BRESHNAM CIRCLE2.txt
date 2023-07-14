/*
BY:ADITYA KUMAR  
Topic:BRESHNAM CIRCLES
*/
#include<GL/glut.h>
#include<bits/stdc++.h>
using namespace std;
#define w 700
#define h 700
int xc, yc, xr, yr;

void setpixel(GLint x, GLint y)
{
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_POINTS);
    glVertex2f(x,y);
    glEnd();  
    glFlush();
}
void init()
{
    glClearColor(1.0,1.0,1.0,0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-w/2,w/2,-h/2,h/2);
}
void display()
{
    glPointSize(2);
    for(int i=-w; i<w; i++)
    {
        setpixel(0,i);
        setpixel(i,0);
    }
}
class Circle
{
public:
void drawCircle(int xc, int yc, int x, int y)
{
    setpixel(xc+x, yc+y);  setpixel(xc-x, yc+y);
    setpixel(xc+x, yc-y);  setpixel(xc-x, yc-y);
    setpixel(xc+y, yc+x); setpixel(xc-y, yc+x);
    setpixel(xc+y, yc-x);  setpixel(xc-y, yc-x);
 }
void BresenhamCircle()
{
    int r = sqrt( ((xc-xr)*(xc-xr)) + ((yc-yr)*(yc-yr)) );
    int x = 0, y = r;
    int d = 3 - 2 * r;
    drawCircle(xc, yc, x, y);
    while (y >= x)
    {
        x++;
        if (d > 0) {
            y--;
            d = d + 4 * (x - y) + 10;
            }
        else
            {d = d + 4 * x + 6;
            }
        drawCircle(xc, yc, x, y);
   }
 }
};
Circle obj;

void mouse(int button, int state, int x, int y){
        if( button == GLUT_LEFT_BUTTON && state == GLUT_DOWN  )
      {  xc = x - 350;  yc = 350 - y;
      glPointSize(2.0);
      setpixel(xc,yc);
        }
      else if( button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN )
      {xr = x-350;  yr = 350-y;
      glPointSize(2.0);  
      setpixel(xr,yr);
      }
    
}

void keyboard(unsigned char key, int x, int y)
{
    if( key == 27){
        exit(0); }
}

void menu(int item){
    if( item == 1 )
    {   int r = sqrt( ((xc-xr)*(xc-xr)) + ((yc-yr)*(yc-yr)) );
        obj.BresenhamCircle();
        xc+=2*r;xr+=2*r;
        obj.BresenhamCircle();
        xc+=2*r;xr+=2*r;
        obj.BresenhamCircle();
        xc-=r;xr-=r;yc-=r;yr-=r;
        obj.BresenhamCircle();
        xc-=2*r;xr-=2*r;
        obj.BresenhamCircle();
  }
    if( item == 2 )
     {  exit(0);  }
}

int main(int argc, char **argv)
{
  glutInit(&argc,argv);;
  glutInitWindowSize(w,h);
  glutInitWindowPosition(100,0);
  glutCreateWindow("Assignment 2");
  glutDisplayFunc(display);
  glutMouseFunc(mouse);
  glutKeyboardFunc(keyboard);
  glutCreateMenu(menu);
  glutAddMenuEntry("CIRCLE", 1);
  glutAddMenuEntry("EXIT",2);
  glutAttachMenu(GLUT_MIDDLE_BUTTON);
  init();
  glutMainLoop();
  return 0;
}
