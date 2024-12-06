#include <GL/glut.h>
#include <cmath>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    // Number of spikes in the star
    const int spikes = 12;
    const float centerX = 0.0f, centerY = 0.0f;
    const float innerRadius = 0.2f;
    const float outerRadius = 0.8f;

    glBegin(GL_TRIANGLE_FAN);

    // Center of the star (white color)
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(centerX, centerY);

    // Loop to create the spikes
    for (int i = 0; i <= spikes * 2; ++i) {
        float angle = i * M_PI / spikes;
        float radius = (i % 2 == 0) ? outerRadius : innerRadius;

        float x = radius * cos(angle);
        float y = radius * sin(angle);

        // Alternate colors for gradient effect
        if (i % 2 == 0) {
            glColor3f(1.0f, 0.0f, 0.0f); // Red
        } else {
            glColor3f(1.0f, 0.5f, 0.5f); // Light red
        }

        glVertex2f(x, y);
    }

    glEnd();

    glFlush();
}

void init() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Black background
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Starburst Shape");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
/*
#include <GL/glut.h>
#include <cmath>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    // Number of spikes in the star
    const int spikes = 12;
    const float centerX = 0.0f, centerY = 0.0f;
    const float innerRadius = 0.2f;
    const float outerRadius = 0.8f;

    glBegin(GL_TRIANGLE_FAN);

    // Center of the star (white color)
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(centerX, centerY);

    // Loop to create the spikes
    for (int i = 0; i <= spikes * 2; ++i) {
        float angle = i * M_PI / spikes;
        float radius = (i % 2 == 0) ? outerRadius : innerRadius;

        float x = radius * cos(angle);
        float y = radius * sin(angle);

        // Alternate colors for gradient effect
        if (i % 2 == 0) {
            glColor3f(1.0f, 0.0f, 0.0f); // Red
        } else {
            glColor3f(1.0f, 0.5f, 0.5f); // Light red
        }

        glVertex2f(x, y);
    }

    glEnd();

    glFlush();
}

void init() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Black background
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Starburst Shape");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
0}*/
