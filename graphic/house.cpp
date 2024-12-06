#include <GL/glut.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw the green base (rectangle)
    glColor3f(0.0f, 1.0f, 0.0f); // Green color
    glBegin(GL_POLYGON);
        glVertex2f(-0.6f, -0.6f);
        glVertex2f(0.6f, -0.6f);
        glVertex2f(0.6f, -0.2f);
        glVertex2f(-0.6f, -0.2f);
    glEnd();

    // Draw the gray house body (rectangle)
    glColor3f(0.5f, 0.5f, 0.5f); // Gray color
    glBegin(GL_POLYGON);
        glVertex2f(-0.4f, -0.2f);
        glVertex2f(0.4f, -0.2f);
        glVertex2f(0.4f, 0.4f);
        glVertex2f(-0.4f, 0.4f);
    glEnd();

    // Draw the red roof (triangle)
    glColor3f(1.0f, 0.0f, 0.0f); // Red color
    glBegin(GL_TRIANGLES);
        glVertex2f(-0.5f, 0.4f);
        glVertex2f(0.5f, 0.4f);
        glVertex2f(0.0f, 0.8f);
    glEnd();

    glFlush();
}
void init() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Black
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("House Drawing");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

