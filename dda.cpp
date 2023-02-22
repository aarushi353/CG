#include<GLUT/glut.h>
#include<OpenGL/OpenGL.h>
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#define ROUND(x) ((int)(x+0.5))
int xa, xb, ya, yb;
void display(void) {
int dx = xb
- xa, dy = yb
- ya, steps, k;
float xIncrement, yIncrement, x = xa, y = ya;
glClear(GL_COLOR_BUFFER_BIT);
glColor3f(1.0, 1.0, 0.0);
if (abs(dx) > abs(dy))
steps = abs(dx);
else
steps = abs(dy);
xIncrement = dx / (float)steps;
yIncrement = dy / (float)steps;
glBegin(GL_POINTS);
glVertex2s(ROUND(x), ROUND(y));
for (k = 0; k < steps; k++) {
x += xIncrement;
y += yIncrement;
glVertex2s(ROUND(x), ROUND(y));
printf("%lf %lf\n", x, y);
}
glColor3f(1.0, 1.0, 1.0);
for (int i =-100; i <= 100; i++) {
glVertex2s(i, 0);
glVertex2s(0, i);
}
glEnd();
glFlush();
}
void init(void) {
glClearColor(0.0, 0.0, 0.0, 0.0);
glOrtho(-100.0, 100.0,-100.0, 100.0,-1.0, 1.0);
}
int main(int argc, char** argv) {
printf("Enter coordinates of two points :\n");
scanf("%d %d %d %d", &xa, &ya, &xb, &yb);
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize(500, 500);
glutInitWindowPosition(100, 100);
glutCreateWindow("Simple DDA ");
init();
glutDisplayFunc(display);
glutMainLoop();
return 0;
}

// Input
// 20
// 10
// 30
// 18