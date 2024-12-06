#include <GL/glut.h>

void drawKite() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(0.0, 0.5);   // Top
    glVertex2f(-0.3, 0.0);  // Left
    glVertex2f(0.0, -0.5);  // Bottom
    glVertex2f(0.3, 0.0);   // Right
    glEnd();
    glFlush();
}

void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Kite");
    init();
    glutDisplayFunc(drawKite);
    glutMainLoop();
    return 0;
}

