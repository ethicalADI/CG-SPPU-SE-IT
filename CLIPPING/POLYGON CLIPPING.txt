/*
BY:ADITYA KUMAR  
Topic:POLYGON CLIPPING
*/

#include<gl/glut.h>
#include<bits/stdc++.h>
#include<math.h>
using namespace std;
float xmx=150,ymx=150,xmn=-150,ymn=-150;
vector<float> a;
vector<float> b;
vector<float> p;
vector<float> q;
void init(){
   glClearColor(1.0,1.0,1.0,0.0);
   glClear(GL_COLOR_BUFFER_BIT);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   gluOrtho2D(-300,300,-300,300);


}
void display(){
    glColor3f(1.0,0.0,0.0);
    glPointSize(5);
    glBegin(GL_POLYGON);
    glVertex2f(xmx,ymx);
    glVertex2f(xmx,ymn);
    glVertex2f(xmn,ymn);
    glVertex2f(xmn,ymx);
    glEnd();
    glFlush();
}
void clipleft(){
    for(int i=0; i<a.size()-1; i++)
   {  float m;
     if((a[i+1]-a[i])!=0)
      {  m=(b[i+1]-b[i])/(a[i+1]-a[i]);
      }
    else
       {
        m=100000;
       }
    if(a[i]<xmn && a[i+1]>=xmn){
        p.push_back(xmn);
        q.push_back(b[i]+m*(xmn-a[i]));
        p.push_back(a[i+1]);
        q.push_back(b[i+1]);
        cout<<"pehla"<<endl;
    }
    if(a[i]>=xmn && a[i+1]>=xmn){
        p.push_back(a[i+1]);
        q.push_back(b[i+1]);
        cout<<"duja"<<endl;

    }
    if(a[i+0]>=xmn && a[i+1]<xmn){
        p.push_back(xmn);
        q.push_back(b[i]+m*(xmn-a[i]));
        cout<<"teja"<<endl;
    }
    }
}
void clipright(){
    for(int i=0; i<a.size()-1; i++){
    float m;
    if((a[i+1]-a[i])!=0){
        m=(b[i+1]-b[i])/(a[i+1]-a[i]);
    }
    else{
        m=100000;

    }
    if(a[i]>xmx && a[i+1]<=xmx){
        p.push_back(xmx);
        q.push_back(b[i]+m*(xmx-a[i]));
        p.push_back(a[i+1]);
        q.push_back(b[i+1]);
        cout<<"pehla"<<endl;
    }
    if(a[i]<=xmx && a[i+1]<=xmx){
        p.push_back(a[i+1]);
        q.push_back(b[i+1]);
        cout<<"duja"<<endl;

    }
    if(a[i+0]<=xmx && a[i+1]>xmx){
        p.push_back(xmx);
        q.push_back(b[i]+m*(xmx-a[i]));
        cout<<"teja"<<endl;
    }
    }
}
void cliptop(){
      for(int i=0; i<a.size()-1; i++){
    float m;
    if((a[i+1]-a[i])!=0){
        m=(b[i+1]-b[i])/(a[i+1]-a[i]);
    }
    else{
        m=100000;

    }
    if(b[i]>ymx && b[i+1]<=ymx){
        p.push_back((ymx-b[i])/m+a[i]);
        q.push_back(ymx);
        p.push_back(a[i+1]);
        q.push_back(b[i+1]);
        cout<<"pehla"<<endl;
    }
    if(b[i]<=ymx && b[i+1]<=ymx){
        p.push_back(a[i+1]);
        q.push_back(b[i+1]);
        cout<<"duja"<<endl;

    }
    if(b[i+0]<=ymx && b[i+1]>ymx){
        p.push_back((ymx-b[i])/m+a[i]);
        q.push_back(ymx);
        cout<<"teja"<<endl;
    }
    }
}
void clipbottom(){
   for(int i=0; i<a.size()-1; i++){
    float m;
    if((a[i+1]-a[i])!=0){
        m=(b[i+1]-b[i])/(a[i+1]-a[i]);
    }
    else{
        m=100000;

    }
    if(b[i]<ymn && b[i+1]>=ymn){
        p.push_back((ymn-b[i])/m+a[i]);
        q.push_back(ymn);
        p.push_back(a[i+1]);
        q.push_back(b[i+1]);
        cout<<"pehla"<<endl;
    }
    if(b[i]>=ymn && b[i+1]>=ymn){
        p.push_back(a[i+1]);
        q.push_back(b[i+1]);
        cout<<"duja"<<endl;

    }
    if(b[i+0]>=ymn && b[i+1]<ymn){
        p.push_back((ymn-b[i])/m+a[i]);
        q.push_back(ymn);
        cout<<"teja"<<endl;
    }
    }
}

void menu(int x){

    if(x==1){
        a.push_back(a[0]);
        b.push_back(b[0]);
        glColor3f(1.0,0.0,0.0);
        glBegin(GL_POLYGON);
         for(int i=0;i<a.size();i++){
            glVertex2f(a[i],b[i]);
         }
         glEnd();
         glFlush();
    }
    else if(x==2){
        init();
        display();

        clipleft();
        p.push_back(p[0]);
        q.push_back(q[0]);
        a.clear();
        b.clear();
        for(int i=0;i<p.size();i++){
            a.push_back(p[i]);
            b.push_back(q[i]);
        }
        p.clear();
        q.clear();

        clipright();
        p.push_back(p[0]);
        q.push_back(q[0]);

        a.clear();
        b.clear();
        for(int i=0;i<p.size();i++){
            a.push_back(p[i]);
            b.push_back(q[i]);
        }
        p.clear();
        q.clear();
        cliptop();
         p.push_back(p[0]);
        q.push_back(q[0]);


        a.clear();
        b.clear();
        for(int i=0;i<p.size();i++){
            a.push_back(p[i]);
            b.push_back(q[i]);
        }
        p.clear();
        q.clear();

        clipbottom();
         p.push_back(p[0]);
        q.push_back(q[0]);


        glColor3f(1.0,0.0,1.0);
        glBegin(GL_POLYGON);
         for(int i=0;i<p.size();i++){
            glVertex2f(p[i],q[i]);
         }
         glEnd();
         glFlush();
    }
}

void mouse(int button,int state,int x, int y){
    if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN){
            glColor3f(1.0,0.0,0.0);
            glBegin(GL_POINTS);
            glVertex2f(x-300,300-y);
            glEnd();
            glFlush();
        a.push_back(x-300);
        b.push_back(300-y);
    }
   
}

int main(int argc, char**argv){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowSize(600,600);
    glutInitWindowPosition(0,0);
    glutCreateWindow("GAURAV");
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutCreateMenu(menu);
    glutAddMenuEntry("polygon",1);
    glutAddMenuEntry("clip",2);
    init();
    glutAttachMenu(GLUT_MIDDLE_BUTTON);
    glutMainLoop();
}
