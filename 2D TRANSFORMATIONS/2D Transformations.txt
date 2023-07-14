/*
BY:ADITYA KUMAR  
Topic: 2D TRANSFORMATIONS
*/


#include <stdio.h>
#include <math.h>
#include <iostream>
#include <vector>
#include <GL/glut.h>
using namespace std;

int choice = 0, edges=6;
int pntX[4]={};
int pntY[4]={};
int transx, transy;
double scalex, scaley;
double angle, angleRad;
char reflectionAxis, shearingAxis;
int shearx, sheary;
int rotationx,rotationy;
int op=0;
int po=0;
int dx[4]={};
int dy[4]={};

void init()
{    glClearColor(1.0, 1.0, 1.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
      glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-320.0, 320.0, -250.0, 250);
}
void Display()
{
  glColor3f(1.0,0.0,0.0);
}

void drawPolygon(){
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 0.0);
	for (int i = 0; i < op; i++){
		glVertex2i(pntX[i], pntY[i]);
	}
	glEnd();
	glFlush();
}


void translation(int transx, int transy){
	glBegin(GL_POLYGON);
	glColor3f(0.0, 1.0, 0.0);
	for (int i = 0; i < op; i++){
		glVertex2i(dx[i] + transx, dy[i] + transy);
	}
	glEnd();
	glFlush();
}

void scaling(double scalex, double scaley)
{
	glBegin(GL_POLYGON);
	glColor3f(0.0, 1.0, 0.0);
	for (int i = 0; i < op; i++){
		glVertex2i(dx[i] * scalex,dy[i] * scaley);
	}
	glEnd();
	glFlush();
}

void rotation(double angleRad,int rotationx,int rotationy)
{
    glBegin(GL_POLYGON);
	glColor3f(0.0, 1.0, 0.0);
	for (int i = 0; i < op; i++){
glVertex2i((dx[i]*cos(angleRad)-dy[i]*sin(angleRad)-rotationx*cos(angleRad)+rotationy*sin(angleRad)+rotationx),(dx[i]*sin(angleRad)+dy[i]*cos(angleRad)-rotationx*sin(angleRad)-rotationy*cos(angleRad)+rotationy));
	}
	glEnd();
	glFlush();
}

void reflection(char reflectionAxis)
{
	glBegin(GL_POLYGON);
	glColor3f(0.0, 1.0, 0.0);
	if (reflectionAxis == 'x'){
		for (int i = 0; i < op; i++){
			glVertex2i(dx[i], dy[i] * -1);
		}
	}
	else if (reflectionAxis == 'y'){
		for (int i = 0; i < op; i++){
			glVertex2i((dx[i]*-1),(dy[i]));
		}
	}
	glEnd();
	glFlush();
}

void shearing(int shearx,int sheary )
{
	glBegin(GL_POLYGON);
	glColor3f(0.0, 1.0, 0.0);
    for (int i = 0; i < op; i++){
        glVertex2i(dx[i]+shearx*dy[i], dy[i]+sheary*dx[i]);
    }
	glEnd();
	glFlush();
}


void menu(int x){
    if(x==1){
        drawPolygon();
    }
    if(x==2){
        Init();
        drawPolygon();
        for(int i=0;i<op;i++){
            dx[i]=pntX[i];
        }
        for(int i=0;i<op;i++){
            dy[i]=pntY[i];
        }
        cout << "Enter the translation factor for X and Y: ";
		cin >> transx >> transy;
        translation(transx, transy);
    }
    if(x==3){
        Init();
        drawPolygon();
        for(int i=0;i<op;i++){
            dx[i]=pntX[i];
        }
        for(int i=0;i<op;i++){
            dy[i]=pntY[i];
        }
        cout << "Enter the scaling factor for X and Y: ";
		cin >> scalex >> scaley;
        scaling(scalex, scaley);

    }
	if (x == 4){
	    Init();
        drawPolygon();
	    for(int i=0;i<op;i++){
            dx[i]=pntX[i];
        }
        for(int i=0;i<op;i++){
            dy[i]=pntY[i];
        }
        cout<<"ENTER ARBITARY POINT X &Y"<<endl;
        cin>>rotationx>>rotationy;

		cout <<"Enter the angle for rotation"<<endl;
		cin >> angle;
		angleRad = angle * 3.1416 / 180;
		rotation(angleRad,rotationx,rotationy);
	}
	if (x == 5){
	    Init();
        drawPolygon();
	    for(int i=0;i<op;i++){
            dx[i]=pntX[i];
        }
        for(int i=0;i<op;i++){
            dy[i]=pntY[i];
        }
	    cout << "Enter reflection axis ( X or Y ): ";
		cin >> reflectionAxis;
		reflection(reflectionAxis);
	}
	if (x == 6){
	    Init();
        drawPolygon();
	    for(int i=0;i<op;i++){
            dx[i]=pntX[i];
        }
        for(int i=0;i<op;i++){
            dy[i]=pntY[i];
        }
        cout << "Enter the shearing factor for X and Y ";
        cin >> shearx>>sheary;

		shearing(shearx,sheary);
	}

}
void mouse(int button,int state,int mx,int my){
   if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN){
     glPointSize(5);
     glBegin(GL_POINTS);
      glVertex2f(mx-320,250-my);
     glEnd();
     glFlush();
     pntX[op++]=mx-320;
     pntY[po++]=250-my;
   }
}
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	 glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(640,500);
    glutInitWindowPosition(100,150);
	glutCreateWindow("Extended Basic Transformations");
	glutDisplayFunc(Display);
	glutMouseFunc(mouse);
	glutCreateMenu(menu);
	glutAddMenuEntry("draw",1);
	glutAddMenuEntry("TRANSLATION",2);
	glutAddMenuEntry("SCALLING",3);
	glutAddMenuEntry("ROTTATION",4);
	glutAddMenuEntry("REFLECTION",5);
	glutAddMenuEntry("SHEARING",6);
	glutAttachMenu(GLUT_MIDDLE_BUTTON);
      Init();
	glutMainLoop();

}
