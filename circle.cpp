#include <OpenGL/gl.h>
#include <OpenGl/glu.h>
#include <GLUT/glut.h>
#include<stdio.h>
#include<math.h>
#include <iostream>
void init(void)
{
 glClearColor(0.0, 0.0, 0.0, 0.0);
 glMatrixMode(GL_PROJECTION);
 gluOrtho2D(0, 640, 0, 480);
}
// Draw a point
void drawPixel(int x, int y)
{
 glBegin(GL_POINTS);
 glVertex2i(x, y);
 glEnd();
}
// Midpoint Circle Algorithm
void midpointCircle(int xc, int yc, int r)
{
 int x = 0;
 int y = r;
 int p = 1 - r;
 drawPixel(xc + x, yc + y);
 drawPixel(xc - x, yc + y);
 drawPixel(xc + x, yc - y);
 drawPixel(xc - x, yc - y);
 drawPixel(xc + y, yc + x);
 drawPixel(xc - y, yc + x);
 drawPixel(xc + y, yc - x);
 drawPixel(xc - y, yc - x);
 while (x < y)
 {
 x++;
 if (p < 0)
 {
 p += 2 * x + 1;
 }
 else
 {
 y--;
 p += 2 * (x - y) + 1;
 }
 drawPixel(xc + x, yc + y);
 drawPixel(xc - x, yc + y);
 drawPixel(xc + x, yc - y);
 drawPixel(xc - x, yc - y);
 drawPixel(xc + y, yc + x);
 drawPixel(xc - y, yc + x);
 drawPixel(xc + y, yc - x);
 drawPixel(xc - y, yc - x);
 }
}
// Display Function
void display()
{
 glClear(GL_COLOR_BUFFER_BIT);
 glColor3f(1.0, 1.0, 1.0);
 midpointCircle(320, 240, 100);
 glFlush();
}
// Main Function
int main(int argc, char** argv)
{
 glutInit(&argc, argv);
 glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
 glutInitWindowSize(640, 480);
 glutInitWindowPosition(100, 100);
 glutCreateWindow("Midpoint Circle Algorithm using OpenGL");
 init();
 glutDisplayFunc(display);
 glutMainLoop();
 return 0;
