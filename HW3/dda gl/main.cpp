#include <GL/glut.h>
#include <iostream>

using namespace std;

int x1, y1, x2, y2;

void drawLineDDA() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POINTS);

    int dx = x2 - x1;
    int dy = y2 - y1;

    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

    float xIncrement = static_cast<float>(dx) / static_cast<float>(steps);
    float yIncrement = static_cast<float>(dy) / static_cast<float>(steps);

    float x = x1;
    float y = y1;

    for (int i = 0; i <= steps; i++) {
        glVertex2i(x, y);
        x += xIncrement;
        y += yIncrement;
    }

    glEnd();
    glFlush();
}

void display() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    drawLineDDA();
    glFlush();
}

int main(int argc, char** argv)
{
    cout << "Masukkan koordinat x1: ";
    cin >> x1;
    cout << "Masukkan koordinat y1: ";
    cin >> y1;
    cout << "Masukkan koordinat x2: ";
    cin >> x2;
    cout << "Masukkan koordinat y2: ";
    cin >> y2;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Algoritma DDA");

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 500.0, 0.0, 500.0);

    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
