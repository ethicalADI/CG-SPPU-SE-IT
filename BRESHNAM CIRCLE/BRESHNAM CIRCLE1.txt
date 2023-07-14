
/*
BY:ADITYA KUMAR  
Topic:BRESHNAM CIRCLES
*/

#include <iostream>
#include <cmath>
#include <GL/glut.h>

// Circle center coordinates and radius
int centerX[5] = { -100, 0, 100, -50, 50 };
int centerY[5] = { 100, 100, 100, 50, 50 };
int radius = 50;

// Function to plot a point (x, y)
void plotPoint(int x, int y)
{   glColor3f(1.0,0.0,0.0);
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
    glFlush();
}

// Function to draw a circle using Bresenham's algorithm
void drawCircle(int centerX, int centerY, int radius)
{
    int x = 0;
    int y = radius;
    int d = 3 - 2 * radius;

    while (x <= y)
    {
        plotPoint(centerX + x, centerY + y);
        plotPoint(centerX - x, centerY + y);
        plotPoint(centerX + x, centerY - y);
        plotPoint(centerX - x, centerY - y);
        plotPoint(centerX + y, centerY + x);
        plotPoint(centerX - y, centerY + x);
        plotPoint(centerX + y, centerY - x);
        plotPoint(centerX - y, centerY - x);

        if (d < 0)
        {
            d = d + 4 * x + 6;
        }
        else
        {
            d = d + 4 * (x - y) + 10;
            y--;
        }

        x++;
    }
}


void resize(int width, int height)
{
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-width / 2, width / 2, -height / 2, height / 2);
    glMatrixMode(GL_MODELVIEW);
}


void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    glColor3f(0.0f, 0.0f, 1.0f); // Blue color
    for (int i = 0; i < 5; i++)
    {
        drawCircle(centerX[i], centerY[i], radius);
    }

    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
     glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
 glutInitWindowSize(640,500);
 glutInitWindowPosition(100,150);
    glutCreateWindow("Olympic Rings Symbol");
    glutDisplayFunc(display);
    glutReshapeFunc(resize);

    glClearColor(1.0, 1.0, 1.0, 1.0); // Set clear color to white

    glutMainLoop();
    return 0;
}
