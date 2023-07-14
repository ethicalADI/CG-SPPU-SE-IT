
/*
BY:ADITYA KUMAR  
Topic: BIEZER CURVE
*/

#include <iostream>
#include <stdlib.h>
#include <GL/glut.h>
#include<GL/gl.h>
#include <math.h>
using namespace std;
//Point class for taking the points
class Point {
public:
 float x, y;
 void setxy(float x2, float y2)
 {x = x2; y = y2;
 }
 //operator overloading for '=' sign
 const Point & operator=(const Point &rPoint)
 {
 x = rPoint.x;
 y = rPoint.y;
 return *this;
 }
};
int factorial(int n)
{
 if (n<=1)
 return(1);
 else
 n=n*factorial(n-1);
 return n;
}
float binomial_coff(float n,float k)
{
 float ans;
 ans = factorial(n) / (factorial(k)*factorial(n-k));
 return ans;
}
Point abc[20];
int SCREEN_HEIGHT = 500;
int points = 0;
int clicks = 4;
void myInit() {
 glClearColor(1.0,1.0,1.0,0.0);
 glClear(GL_COLOR_BUFFER_BIT);
 glColor3f(0.0,0.0,0.0);
 glPointSize(5);
 glMatrixMode(GL_PROJECTION);
 glLoadIdentity();
 gluOrtho2D(0.0,640.0,0.0,500.0);
}
void drawDot(int x, int y) {
 glBegin(GL_POINTS);
 glVertex2f(x,y);
 glEnd();
 glFlush();
}
void drawLine(Point p1, Point p2) {
 glBegin(GL_LINES);
 glVertex2f(p1.x, p1.y);
 glVertex2f(p2.x, p2.y);
 glEnd();
 glFlush();
}

//Calculate the bezier point [generalized]
Point drawBezierGeneralized(Point PT[], double t) {
 Point P;
 P.x = 0; P.y = 0;
 for (int i = 0; i<clicks; i++)
 {
 P.x = P.x + binomial_coff((float)(clicks - 1), (float)i) * pow(t, (double)i) * pow((1 - t), (clicks - 1 - i)) * PT[i].x;
 P.y = P.y + binomial_coff((float)(clicks - 1), (float)i) * pow(t, (double)i) * pow((1 - t), (clicks - 1 - i)) * PT[i].y;
 }
 return P;
 }

void myMouse(int button, int state, int x, int y) {
 // If left button was clicked
 if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) 
{ abc[points].setxy((float)x,(float)(SCREEN_HEIGHT - y));
 points++;
 drawDot(x, SCREEN_HEIGHT - y);
 
 if(points == clicks)
 { glColor3f(1.0,0.0,0.0);
 for(int k=0;k<clicks-1;k++)
 drawLine(abc[k], abc[k+1]);
 Point p1 = abc[0];
 
 for(double t = 0.0;t <= 1.0; t += 0.02)
 {Point p2 = drawBezierGeneralized(abc,t);
 cout<<p1.x<<" , "<<p1.y<<endl;
 cout<<p2.x<<" , "<<p2.y<<endl;
 cout<<endl;
 drawLine(p1, p2);
 p1 = p2;
 }
 glColor3f(0.0,0.0,0.0);
 points = 0;
 }
 }
}
void myDisplay() {
 glClear(GL_COLOR_BUFFER_BIT);
 glFlush();
}
int main(int argc, char *argv[]) {
 glutInit(&argc, argv);
 glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
 glutInitWindowSize(640,500);
 glutInitWindowPosition(100,150);
 glutCreateWindow("Bezier Curve");
 glutMouseFunc(myMouse);
 glutDisplayFunc(myDisplay);
 myInit();
 glutMainLoop();
 return 0;
}
