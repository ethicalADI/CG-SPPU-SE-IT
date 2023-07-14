/*
BY:ADITYA KUMAR  
Topic:POLYGON FILLING
*/

#include<gl/glut.h>
#include<bits/stdc++.h>
using namespace std;

void Init(void)
{
  glClearColor(0.0,0.0,0.0,0.0);
  glClear(GL_COLOR_BUFFER_BIT);
  glPointSize(1);
  glLineWidth(2);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
 gluOrtho2D(0.0,640.0,0.0,500.0);
}
void display(void)
{  }
struct COLOR
{
  float r; float g; float b;
};
class polygon_fill
{
  int compare_color(COLOR a,COLOR b)
  {     if(a.r==b.r&&a.g==b.g && a.b==b.b)
      return 1;
    else
      return 0;
  }
  void draw(int x,int y,COLOR c)
  {
    glColor3f(c.r,c.g,c.b);
    glBegin(GL_POINTS);
    glVertex2f(x,y);
    glEnd();
   glFlush();
  }

  COLOR getpixelcolor(int x,int y)
  {
    COLOR c;
    glReadPixels(x,y,1,1,GL_RGB,GL_FLOAT,&c);
    return c;
  }

  public:
  void bound_fill(int x,int y,COLOR fill,COLOR border_col)
  {
    COLOR color;
    color=getpixelcolor(x,y);
    if(compare_color(color,border_col)==0&&compare_color(color,fill)==0)
    {
      draw(x,y,fill);
      bound_fill(x+1,y,fill,border_col);  bound_fill(x,y+1,fill,border_col);
      bound_fill(x-1,y,fill,border_col);  bound_fill(x,y-1,fill,border_col);
      bound_fill(x-1,y-1,fill,border_col);  bound_fill(x-1,y+1,fill,border_col);
      bound_fill(x+1,y-1,fill,border_col);  bound_fill(x+1,y+1,fill,border_col);
    }
  }

  void flood_fill(int x,int y,COLOR fill,COLOR bg_color)
  {
    COLOR color;
    color=getpixelcolor(x,y);
    if(compare_color(color,bg_color)==1)
    {
      draw(x,y,fill);
      flood_fill(x+1,y,fill,bg_color);  flood_fill(x,y+1,fill,bg_color);
      flood_fill(x-1,y,fill,bg_color);  flood_fill(x,y-1,fill,bg_color);
      flood_fill(x+1,y+1,fill,bg_color);  flood_fill(x-1,y+1,fill,bg_color);
      flood_fill(x-1,y+1,fill,bg_color);  flood_fill(x+1,y-1,fill,bg_color);
    }
  }
};

bool flag=true;
polygon_fill p;
bool cur=false;
int xc,yc,i=0,j=0;
int xarr[100];
int yarr[100];
float col[6][3]={ {0.0,0.0,1.0} , {0.0,1.0,1.0} , {1.0,1.0,1.0}  , {0.0,1.0,0.0} ,{1.0,1.0,0.0} ,{1.0,0.0,1.0}};

void menu(int value)
{

  COLOR fill,bouncol,backcol,c;
  fill.r=1.0;
  fill.g=1.0;
  fill.b=1.0;
  bouncol.r=0.0;
  bouncol.g=0.0;
  bouncol.b=1.0;
  backcol.r=0.0;
 backcol.g=0.0;
 backcol.b=0.0;
  switch(value)
  {
    case 1:
        flag=true;
      break;
    case 2:
        flag=false;
      break;
        case 3:
                if(cur and flag)p.flood_fill(xc,500-yc,fill,backcol);
                if(cur and !flag)p.bound_fill(xc,500-yc,fill,bouncol);
                cur=false;
                i=0;j=0;
                break;


  }

}


void mouse(int button,int state,int x,int y)
{

    if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
    {
      xarr[i]=x;   yarr[i]=y;
      if(flag)j++;
      j%=6;

      if(i>=1)
      {
        cur=true;
        glColor3f(col[j][0],col[j][1],col[j][2]);
        glBegin(GL_LINE_STRIP);
        glVertex2i(xarr[i-1],500-yarr[i-1]);
        glVertex2i(xarr[i],500-yarr[i]);
        glEnd();
        glFlush();
      }
      i++;
    }

    if(button==GLUT_RIGHT_BUTTON && state==GLUT_DOWN)
    {
      xc=x;  yc=y;

    }

  return;
}
void keyboard(unsigned char key,int x,int y)
{
  if(key==27)
    exit(0);

}

int main(int argc,char **argv)
{
  glutInit(&argc,argv);
 glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
 glutInitWindowSize(640,500);
 glutInitWindowPosition(100,150);
  glutCreateWindow("POLYGON FILL");
  glutDisplayFunc(display);
  glutMouseFunc(mouse);
  glutKeyboardFunc(keyboard);
  glutCreateMenu(menu);
  glutAddMenuEntry("FLOOD FILL",1);
  glutAddMenuEntry("BOUNDARY FILL",2);
  glutAddMenuEntry("RUN",3);
  glutAttachMenu(GLUT_MIDDLE_BUTTON);

  Init();
  glutMainLoop();
  return  0;
}
