#include <GL/glut.h>
#include <cmath>

void drawOval() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    for (float angle = 0; angle < 2 * M_PI; angle += 0.01) {
        float x = 0.6 * cos(angle); // Width
        float y = 0.4 * sin(angle); // Height
        glVertex2f(x, y);
    }
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
    glutCreateWindow("Oval");
    init();
    glutDisplayFunc(drawOval);
    glutMainLoop();
    return 0;
}

