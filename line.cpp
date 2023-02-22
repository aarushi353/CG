#include <GL/glut.h>

void display() {
   glClear(GL_COLOR_BUFFER_BIT);

   // set drawing color to green
   glColor3f(0.0, 1.0, 0.0);

   // draw a line from (-0.5, 0.0) to (0.5, 0.0)
   glBegin(GL_LINES);
      glVertex2f(-0.5, 0.0);
      glVertex2f(0.5, 0.0);
   glEnd();

   glFlush();
}

int main(int argc, char **argv) {
   glutInit(&argc, argv);
   glutCreateWindow("Green Line");
   glutDisplayFunc(display);
   glutMainLoop();
   return 0;
}
