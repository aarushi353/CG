#include <OpenGL/gl.h>
#include <OpenGl/glu.h>
#include <GLUT/glut.h>
#include<stdio.h>
#include<math.h>
#include <iostream>
#define pi 3.142857
void display() {

    glClear(GL_COLOR_BUFFER_BIT); // clear buffers to preset values

    // glClear - OpenGL 4 Reference Pages (khronos.org)

    glColor3f(1.0, 0.0, 0.0);  //

    // glColor3f function (Gl.h) - Win32 apps | Microsoft Learn
    glBegin(GL_TRIANGLES);
    glVertex2f(100.0, 150.0);
    glVertex2f(150.0, 100.0);
    glVertex2f(200.0, 300.0);
    glEnd();
    glFlush(); // The glFlush function empties all these buffers
}

void myinit() {

    glClearColor(0.0, 0.0, 0.0, 0.0); // The glClearColor function specifies clear values for the color buffers.

    glColor3f(1.0, 0.0, 0.0);

    glPointSize(5.0); // The glPointSize function specifies the diameter of rasterized points.

    glMatrixMode(GL_PROJECTION); // The glMatrixMode function specifies which matrix is the current matrix.

    gluOrtho2D(0.0, 499.0, 0.0, 499.0); // The glOrtho function multiplies the current matrix by an orthographic matrix.

}

int main(int argc, char** argv) {

    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutInitWindowSize(1000, 1000);

    glutInitWindowPosition(10.0, 0);

    glutCreateWindow("point Window");

    glutDisplayFunc(display);

    myinit();

    glutMainLoop();

}
