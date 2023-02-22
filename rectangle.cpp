#include <GL/glut.h>
#include<stdio.h>
#include<math.h>
#include <iostream>
#define pi 3.142857

void display() {
   glClear(GL_COLOR_BUFFER_BIT);

   // set drawing color to red
   glColor3f(1.0, 0.0, 0.0);

   // draw rectangle with lower left corner at (-0.5, -0.5)
   // and upper right corner at (0.5, 0.5)
   glBegin(GL_QUADS);
      glVertex2f(-0.5, -0.5);
      glVertex2f(0.5, -0.5);
      glVertex2f(0.5, 0.5);
      glVertex2f(-0.5, 0.5);
   glEnd();

   glFlush();
}

int main(int argc, char **argv) {
   glutInit(&argc, argv);
   glutCreateWindow("Rectangle");
   glutDisplayFunc(display);
   glutMainLoop();
   return 0;
}