#include <OpenGL/gl.h>
#include <OpenGl/glu.h>
#include <GLUT/glut.h>
#include<iostream>
#include<math.h>
using namespace std;
int xc, yc, rx, ry;
void plot(int x, int y) {
 glBegin(GL_POINTS);
 glVertex2i(xc + x, yc + y);
 glVertex2i(xc + x, yc - y);
 glVertex2i(xc - x, yc + y);
 glVertex2i(xc - x, yc - y);
 glEnd();
}
void midpointEllipse() {
 int x = 0, y = ry;
 double d1 = ry * ry - rx * rx * ry + rx * rx / 4.0;
 plot(x, y);
 while (rx * rx * (y - 0.5) > ry * ry * (x + 1)) {
 if (d1 < 0) {
 d1 += ry * ry * (2 * x + 3);
 } else {
 d1 += ry * ry * (2 * x + 3) + rx * rx * (-2 * y + 2);
 y--;
 }
 x++;
 plot(x, y);
 }
 double d2 = ry * ry * (x + 0.5) * (x + 0.5) + rx * rx * (y - 1) * (y - 1) - rx * rx * ry 
* ry;
 while (y > 0) {
 if (d2 < 0) {
 d2 += ry * ry * (2 * x + 2) + rx * rx * (-2 * y + 3);
 x++;
 } else {
 d2 += rx * rx * (-2 * y + 3);
 }
 y--;
 plot(x, y);
 }
}
void display() {
 glClear(GL_COLOR_BUFFER_BIT);
 midpointEllipse();
 glFlush();
}
void init() {
 glClearColor(0.0, 0.0, 0.0, 1.0);
 glColor3f(1.0, 1.0, 1.0);
 glPointSize(2.0);
 gluOrtho2D(0, 640, 0, 480);
}
int main(int argc, char **argv) {
 cout << "Enter the coordinates of the center of the ellipse: ";
 cin >> xc >> yc;
 cout << "Enter the major and minor axes of the ellipse: ";
 cin >> rx >> ry;
 glutInit(&argc, argv);
 glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
 glutInitWindowSize(640, 480);
 glutInitWindowPosition(100, 100);
 glutCreateWindow("Midpoint Ellipse Algorithm");
 init();
 glutDisplayFunc(display);
 glutMainLoop();
 return 0;
}

// Input
// 100
// 100
// 50
// 25