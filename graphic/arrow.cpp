#include <GL/glut.h>

void drawArrow() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Arrowhead
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_TRIANGLES);
    glVertex2f(0.2, 0.2);
    glVertex2f(0.2, -0.2);
    glVertex2f(0.6, 0.0);
    glEnd();

    // Arrow tail (rectangle)
    glBegin(GL_POLYGON);
    glVertex2f(-0.4, 0.1);
    glVertex2f(-0.4, -0.1);
    glVertex2f(0.2, -0.1);
    glVertex2f(0.2, 0.1);
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
    glutCreateWindow("Arrow");
    init();
    glutDisplayFunc(drawArrow);
    glutMainLoop();
    return 0;
}

