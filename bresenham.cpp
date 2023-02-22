#include <GLUT/glut.h>
#include <glut/GLUT.h>
#include <iostream>
#include <math.h>
using namespace std;
int X1, Y1, X2, Y2;
void display()
{
 int dx = X2 - X1;
 int dy = Y2 - Y1;
 if (dx < 0)
 dx = -dx;
 if (dy < 0)
 dy = -dy;
 int inc_x = X1 < X2 ? 1 : -1;
 int inc_y = Y1 < Y2 ? 1 : -1;
 int x = X1;
 int y = Y1;
 cout << x << " " << y << endl;
 if (dx > dy)
 {
 int d = 2 * dy - dx;
 int d1 = 2 * dy;
 int d2 = 2 * (dy - dx);
 glBegin(GL_POINTS);
 while (x != X2)
 {
 cout << x << ", " << y << endl;
 glVertex2i(x, y);
 x += inc_x;
 if (d > 0)
 {
 d += d2;
 }
 else
 {
 d += d1;
 y += inc_y;
 }
 }
 glEnd();
 }
 else
 {
 int d = 2 * dx - dy;
 int d1 = 2 * dx;
 int d2 = 2 * (dx - dy);
 glBegin(GL_POINTS);
 while (y != Y2)
 {
 cout << x << ", " << y << endl;
 glVertex2i(x, y);
 y += inc_y;
 if (d > 0)
 {
 d += d2;
 }
 else
 {
 d += d1;
 x += inc_x;
 }
 }
 glEnd();
 }
 glFlush();
}
void init()
{
 glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
 glutInitWindowSize(400, 400);
 glutInitWindowPosition(100, 200);
 glutCreateWindow("bresenhems Line Algorithm");
 gluOrtho2D(0, 400, 400, 0);
}
int main(int argc, char** argv)
{
 printf("Enter coordinates of first point: ");
 scanf("%d%d", &X1, &Y1);
 printf("\nEnter coordinates of second point: ");
 scanf("%d%d", &X2, &Y2);
 glutInit(&argc, argv);
 init();
 glutDisplayFunc(display);
 glutMainLoop();
 return 0;
}
