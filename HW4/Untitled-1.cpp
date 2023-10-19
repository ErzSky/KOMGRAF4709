#include <GL/glut.h>
#include <iostream>

int x1, y1, x2, y2;

void drawPixel(int x, int y) {
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}

void drawLineBresenham(int x1, int y1, int x2, int y2) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int x, y;

    if (dx >= dy) {
        int d = 2 * dy - dx;
        int ds = 2 * dy;
        int dt = 2 * (dy - dx);

        if (x1 < x2) {
            x = x1;
            y = y1;
        } else {
            x = x2;
            y = y2;
            x2 = x1;
            y2 = y1;
        }

        drawPixel(x, y);

        while (x < x2) {
            x++;

            if (d < 0)
                d += ds;
            else {
                if ((x2 > x1 && y2 > y1) || (x2 < x1 && y2 < y1))
                    y++;
                else
                    y--;

                d += dt;
            }

            drawPixel(x, y);
        }
    } else {
        int d = 2 * dx - dy;
        int ds = 2 * dx;
        int dt = 2 * (dx - dy);

        if (y1 < y2) {
            x = x1;
            y = y1;
        } else {
            x = x2;
            y = y2;
            y2 = y1;
        }

        drawPixel(x, y);

        while (y < y2) {
            y++;

            if (d < 0)
                d += ds;
            else {
                if ((x2 > x1 && y2 > y1) || (x2 < x1 && y2 < y1))
                    x++;
                else
                    x--;

                d += dt;
            }

            drawPixel(x, y);
        }
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);

    drawLineBresenham(x1, y1, x2, y2);

    glFlush();
}

int main(int argc, char** argv) {
    std::cout << "Enter two points (x1 y1 x2 y2): ";
    std::cin >> x1 >> y1 >> x2 >> y2;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(400, 400);
    glutCreateWindow("Bresenham Line Drawing Algorithm");
    glOrtho(0, 400, 0, 400, -1, 1);
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
