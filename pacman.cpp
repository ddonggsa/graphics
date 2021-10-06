#include<iostream>
#include<cstdlib>
#include<ctime>
#include<cmath>
#include"include/GL/freeglut.h"
using namespace std;



int Width = 800, Height = 600;
int Key = 0;
char c;
int pacman = 0;
int dy, dx = 1.0;
GLint num = 0;
GLint arr1[8][2];
GLint arr2[3][2];
GLfloat gx = 400, gy = 300;
GLfloat xv, yv;
GLfloat duration;
clock_t start;
clock_t finish;


void Reshape(int w, int h);
void Display();
void Pacman_right();
void Pacman_left();
void Pacman_up();
void Pacman_down();
void Fruit();
void Keyboard(int Key, int x, int y);

void Keyboard(int Key, int x, int y) {
    switch (Key) {
    case GLUT_KEY_LEFT:
        pacman = 1;
        if (gx - 40 <= 0) {
            break;
        }
        gx = gx - 10.0f;
        break;
    case GLUT_KEY_RIGHT:
        pacman = 2;
        if (gx + 40 >= Width) {
            break;
        }
        gx = gx + 10.0f;
        break;
    case GLUT_KEY_UP:
        pacman = 3;
        if (gy + 40 >= Height) {
            break;
        }
        gy = gy + 10.0f;
        break;
    case GLUT_KEY_DOWN:
        pacman = 4;
        if (gy - 40 <= 0) {
            break;
        }
        gy = gy - 10.0f;
        break;
    }
    glutPostRedisplay();
}
void Pacman_right() {
    glBegin(GL_TRIANGLE_FAN);
    glColor3d(1.0, 1.0, 0.0);
    glVertex2d(gx, gy);
    for (int i = 0;i < 30;++i) {

        double theta = i / (29.0) * 3.141592 * 2.0;
        double x = 40.0 * cos(theta);
        double y = 40.0 * sin(theta);
        glVertex2d(gx + x, gy + y);

    }
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3d(1.0, 0.0, 0.0);
    glVertex2d(gx, gy);
    for (int i = 170;i < 200;++i) {
        double theta = i / (29.0) * 3.141592 * 0.3;
        double x = 40.0 * cos(theta);
        double y = 40.0 * sin(theta);
        glVertex2d(gx + x, gy + y);
    }
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3d(0.0, 0.0, 0.0);
    glVertex2d(gx + 20, gy + 20);
    for (int i = 235;i < 265;++i) {
        double theta = i / (29.0) * 3.141592 * 2.0;
        double x = 4.0 * cos(theta);
        double y = 4.0 * sin(theta);
        glVertex2d(gx + x + 20, gy + y + 20);
    }
    glEnd();


}
void Pacman_left() {
    glBegin(GL_TRIANGLE_FAN);
    glColor3d(1.0, 1.0, 0.0);
    glVertex2d(gx, gy);
    for (int i = 0;i < 30;++i) {
        double theta = i / (29.0) * 3.141592 * 2.0;
        double x = 40.0 * cos(theta);
        double y = 40.0 * sin(theta);
        glVertex2d(gx + x, gy + y);
    }
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3d(1.0, 0.0, 0.0);
    glVertex2d(gx, gy);
    for (int i = 85;i < 115;++i) {
        double theta = i / (29.0) * 3.141592 * 0.3;
        double x = 40.0 * cos(theta);
        double y = 40.0 * sin(theta);
        glVertex2d(gx + x, gy + y);
    }
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3d(0.0, 0.0, 0.0);
    glVertex2d(gx - 20, gy + 20);
    for (int i = 235;i < 265;++i) {
        double theta = i / (29.0) * 3.141592 * 2.0;
        double x = 4.0 * cos(theta);
        double y = 4.0 * sin(theta);
        glVertex2d(gx + x - 20, gy + y + 20);
    }
    glEnd();


}
void Pacman_up() {
    glBegin(GL_TRIANGLE_FAN);
    glColor3d(1.0, 1.0, 0.0);
    glVertex2d(gx, gy);
    for (int i = 0;i < 30;++i) {
        double theta = i / (29.0) * 3.141592 * 2.0;
        double x = 40.0 * cos(theta);
        double y = 40.0 * sin(theta);
        glVertex2d(gx + x, gy + y);
    }
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3d(1.0, 0.0, 0.0);
    glVertex2d(gx, gy);
    for (int i = 25;i < 55;++i) {
        double theta = i / (29.0) * 3.141592 * 0.3;
        double x = 40.0 * cos(theta);
        double y = 40.0 * sin(theta);
        glVertex2d(gx + x, gy + y);
    }
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3d(0.0, 0.0, 0.0);
    glVertex2d(gx - 20, gy + 20);
    for (int i = 235;i < 265;++i) {
        double theta = i / (29.0) * 3.141592 * 2.0;
        double x = 4.0 * cos(theta);
        double y = 4.0 * sin(theta);
        glVertex2d(gx + x - 20, gy + y + 20);
    }
    glEnd();


}
void Pacman_down() {
    glBegin(GL_TRIANGLE_FAN);
    glColor3d(1.0, 1.0, 0.0);
    glVertex2d(gx, gy);
    for (int i = 0;i < 30;++i) {
        double theta = i / (29.0) * 3.141592 * 2.0;
        double x = 40.0 * cos(theta);
        double y = 40.0 * sin(theta);
        glVertex2d(gx + x, gy + y);
    }
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3d(1.0, 0.0, 0.0);
    glVertex2d(gx, gy);
    for (int i = 135;i < 165;++i) {
        double theta = i / (29.0) * 3.141592 * 0.3;
        double x = 40.0 * cos(theta);
        double y = 40.0 * sin(theta);
        glVertex2d(gx + x, gy + y);
    }
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3d(0.0, 0.0, 0.0);
    glVertex2d(gx - 20, gy - 20);
    for (int i = 235;i < 265;++i) {
        double theta = i / (29.0) * 3.141592 * 2.0;
        double x = 4.0 * cos(theta);
        double y = 4.0 * sin(theta);
        glVertex2d(gx + x - 20, gy + y - 20);
    }
    glEnd();


}

void Villian() {
    for (int i = 0;i < 3;i++) {
        if (pow(arr2[i][0] - gx, 2) + pow(arr2[i][1] - gy, 2) >= 4900) {
            glBegin(GL_TRIANGLE_FAN);
            glColor3d(0.0, 0.4, 0.0);
            glVertex2d(arr2[i][0], arr2[i][1]);
            for (int j = 0;j < 30;++j) {
                double theta = j / (29.0) * 3.141592 * 2.0;
                double x2 = 30.0 * cos(theta);
                double y2 = 30.0 * sin(theta);
                glVertex2d(arr2[i][0] + x2, arr2[i][1] + y2);

            }
            glEnd();

            glLineWidth(2.0);
            glBegin(GL_LINES);
            glColor3d(1.0, 1.0, 1.0);
            glVertex2d(arr2[i][0] - 17, arr2[i][1] + 10);
            glVertex2d(arr2[i][0] - 2, arr2[i][1] + 4);
            glEnd();

            glLineWidth(2.0);
            glBegin(GL_LINES);
            glColor3d(1.0, 1.0, 1.0);
            glVertex2d(arr2[i][0] - 17, arr2[i][1] + 4);
            glVertex2d(arr2[i][0] - 2, arr2[i][1] + 10);
            glEnd();

            glLineWidth(2.0);
            glBegin(GL_LINES);
            glColor3d(1.0, 1.0, 1.0);
            glVertex2d(arr2[i][0] + 17, arr2[i][1] + 4);
            glVertex2d(arr2[i][0] + 2, arr2[i][1] + 10);
            glEnd();

            glLineWidth(2.0);
            glBegin(GL_LINES);
            glColor3d(1.0, 1.0, 1.0);
            glVertex2d(arr2[i][0] + 2, arr2[i][1] + 4);
            glVertex2d(arr2[i][0] + 17, arr2[i][1] + 10);
            glEnd();

            glBegin(GL_TRIANGLE_FAN);
            glColor3d(1.0, 0.0, 0.0);
            glVertex2d(arr2[i][0], arr2[i][1] - 13);
            for (int j = 0;j < 30;++j) {
                double theta = j / (29.0) * 3.141592 * 2.0;
                double x2 = 10.0 * cos(theta);
                double y2 = 10.0 * sin(theta);
                glVertex2d(arr2[i][0] + x2, arr2[i][1] - 13 + y2);

            }

            glEnd();
        }
        else {
            glBegin(GL_TRIANGLE_FAN);
            glColor3d(0.0, 0.4, 0.0);
            glVertex2d(arr2[i][0], arr2[i][1]);
            for (int j = 0;j < 30;++j) {
                double theta = j / (29.0) * 3.141592 * 2.0;
                double x2 = 30.0 * cos(theta);
                double y2 = 30.0 * sin(theta);
                glVertex2d(arr2[i][0] + x2, arr2[i][1] + y2);

            }
            finish = clock();
            duration = (float)(finish - start);
            cout << "Time Later: " << duration / CLOCKS_PER_SEC << endl;


            arr2[i][0] = -10000;
            arr2[i][1] = -10000;
            glEnd();

            glLineWidth(2.0);
            glBegin(GL_LINES);
            glColor3d(1.0, 1.0, 1.0);
            glVertex2d(arr2[i][0] - 17, arr2[i][1] + 10);
            glVertex2d(arr2[i][0] - 2, arr2[i][1] + 4);
            glEnd();

            glLineWidth(2.0);
            glBegin(GL_LINES);
            glColor3d(1.0, 1.0, 1.0);
            glVertex2d(arr2[i][0] - 17, arr2[i][1] + 4);
            glVertex2d(arr2[i][0] - 2, arr2[i][1] + 10);
            glEnd();

            glLineWidth(2.0);
            glBegin(GL_LINES);
            glColor3d(1.0, 1.0, 1.0);
            glVertex2d(arr2[i][0] + 17, arr2[i][1] + 4);
            glVertex2d(arr2[i][0] + 2, arr2[i][1] + 10);
            glEnd();

            glLineWidth(2.0);
            glBegin(GL_LINES);
            glColor3d(1.0, 1.0, 1.0);
            glVertex2d(arr2[i][0] + 2, arr2[i][1] + 4);
            glVertex2d(arr2[i][0] + 17, arr2[i][1] + 10);
            glEnd();

            glBegin(GL_TRIANGLE_FAN);
            glColor3d(1.0, 0.0, 0.0);
            glVertex2d(arr2[i][0], arr2[i][1] - 13);
            for (int j = 0;j < 30;++j) {
                double theta = j / (29.0) * 3.141592 * 2.0;
                double x2 = 10.0 * cos(theta);
                double y2 = 10.0 * sin(theta);
                glVertex2d(arr2[i][0] + x2, arr2[i][1] - 13 + y2);

            }

            cout << "You Lose..." << endl;
            cout << "Collected Fruit : " << num << endl;


            glutLeaveMainLoop();
        }

    }

}
void Fruit() {
    for (int i = 0;i <= 7;i++) {
        if (pow(arr1[i][0] - gx, 2) + pow(arr1[i][1] - gy, 2) >= 2500) {
            glBegin(GL_TRIANGLE_FAN);
            glColor3d(0.6, 1.0, 0.6);
            glVertex2d(arr1[i][0], arr1[i][1]);
            for (int j = 0;j < 30;++j) {
                double theta = j / (29.0) * 3.141592 * 2.0;
                double x1 = 10.0 * cos(theta);
                double y1 = 10.0 * sin(theta);
                glVertex2d(arr1[i][0] + x1, arr1[i][1] + y1);

            }
            glEnd();

            glLineWidth(2.0);
            glBegin(GL_LINES);
            glColor3d(0.6, 0.0, 0.0);
            glVertex2d(arr1[i][0], arr1[i][1] + 5);
            glVertex2d(arr1[i][0], arr1[i][1] + 15);

            glEnd();
        }
        else {

            glBegin(GL_TRIANGLE_FAN);
            glColor3d(0.6, 1.0, 0.6);
            glVertex2d(-100, -100);
            for (int j = 0;j < 30;++j) {
                double theta = j / (29.0) * 3.141592 * 2.0;
                double x1 = 10.0 * cos(theta);
                double y1 = 10.0 * sin(theta);
                glVertex2d(x1 - 100, y1 - 100);

            }
            arr1[i][0] = -10000;
            arr1[i][1] = -10000;

            glEnd();

            glLineWidth(2.0);
            glBegin(GL_LINES);
            glColor3d(0.6, 0.0, 0.0);
            glVertex2d(arr1[i][0], arr1[i][1] + 5);
            glVertex2d(arr1[i][0], arr1[i][1] + 15);

            glEnd();
            num++;
        }
    }

}
void Timer(int value) {
    for (int i = 0;i < 3;i++) {
        float speed = 0.006;
        xv = gx - arr2[i][0];
        yv = gy - arr2[i][1];

        arr2[i][0] += speed * xv;
        arr2[i][1] += speed * yv;

        if (pow(arr2[i][0] - arr1[i][0], 2) + pow(arr2[i][1] - arr1[i][1], 2) <= 1600) {
            arr1[1][0] = -10000;
            arr1[i][1] = -10000;
            speed += 0.001;

        }
        glutPostRedisplay();
    }

    glutTimerFunc(40, Timer, 1);

}



void Display() {

    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, Width, 0.0, Height);

    glMatrixMode(GL_MODELVIEW);
    Fruit();

    switch (pacman) {
    case 1:
        Pacman_left();
        break;
    case 2:
        Pacman_right();
        break;
    case 3:
        Pacman_up();
        break;
    case 4:
        Pacman_down();
        break;
    default:
        Pacman_right();
        break;
    }
    Villian();
    glutSwapBuffers();


}

void Reshape(int w, int h) {

    glViewport(0, 0, w, h);
    Width = w;
    Height = h;
}
int main(int argc, char** argv) {
    start = clock();
    srand(time(0));
    for (int i = 0;i <= 7;i++) {
        arr1[i][0] = rand() % (781) + 10;
        arr1[i][1] = rand() % (581) + 10;
    }
    for (int i = 0;i < 3;i++) {
        arr2[i][0] = rand() % (781) + 30;
        arr2[i][1] = rand() % (581) + 30;
    }
    glutInit(&argc, argv);

    glutInitWindowSize(Width, Height);
    glutCreateWindow("PacMan");
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);


    glutDisplayFunc(Display);
    glutSpecialFunc(Keyboard);
    glutReshapeFunc(Reshape);
    glutTimerFunc(40, Timer, 1);
    glutMainLoop();
    return 0;

}

