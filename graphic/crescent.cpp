#include <GL/glut.h>
#include <cmath>

void drawCrescent() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Large circle
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    for (float angle = 0; angle < 2 * M_PI; angle += 0.01) {
        float x = 0.5 * cos(angle);
        float y = 0.5 * sin(angle);
        glVertex2f(x, y);
    }
    glEnd();

    // Small circle to create the crescent effect
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    for (float angle = 0; angle < 2 * M_PI; angle += 0.01) {
        float x = 0.4 * cos(angle) + 0.2; // Shifted to the right
        float y = 0.4 * sin(angle);
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
    glutCreateWindow("Crescent");
    init();
    glutDisplayFunc(drawCrescent);
    glutMainLoop();
    return 0;
}
