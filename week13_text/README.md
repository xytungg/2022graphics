# week13
1. 畫出白色長方形
```c
#include <GL/glut.h>
void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    glRectf(0.5, 0.5, -0.5, -0.5);
    glutSwapBuffers();
}

int main(int argc, char**argv)
{
    glutInit( &argc, argv );
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH );
    glutInitWindowSize(600, 600);
    glutCreateWindow("week12 TRT");

    glutDisplayFunc( display );
    glutMainLoop();
    return 0;
}
```
2. 畫出白色長方形當作身體，紅色長方形當作手臂
```c
#include <GL/glut.h>
void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    glColor3f(1, 1, 1);
    glRectf(0.5, 0.5, -0.5, -0.5);///身體
    glPushMatrix();
        ///glTranslatef(x, y, z);
        ///glRotatef(angle, 0, 0, 1);
        ///glTranslatef(x2, y2, z3);
        glColor3f(1, 0, 0);
        glRectf(0.5, 0.5, 1.0, 0.3);///手臂
    glPopMatrix();
    glutSwapBuffers();
}

int main(int argc, char**argv)
{
    glutInit( &argc, argv );
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH );
    glutInitWindowSize(600, 600);
    glutCreateWindow("week13 rect TRT");

    glutDisplayFunc( display );
    glutMainLoop();
    return 0;
}
```
3.移動紅色方塊位置到正中心
```c
#include <GL/glut.h>
void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    glColor3f(1, 1, 1);
    glRectf(0.5, 0.5, -0.5, -0.5);///身體
    glPushMatrix();
        ///glTranslatef(x, y, z);
        glRotatef(45, 0, 0, 1);
        glTranslatef(-0.5, -0.4, 0);
        glColor3f(1, 0, 0);
        glRectf(0.5, 0.5, 1.0, 0.3);///手臂
    glPopMatrix();
    glutSwapBuffers();
}

int main(int argc, char**argv)
{
    glutInit( &argc, argv );
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH );
    glutInitWindowSize(600, 600);
    glutCreateWindow("week13 rect TRT");

    glutDisplayFunc( display );
    glutMainLoop();
    return 0;
}
```
4. 加入滑鼠事件讓紅色方塊跟著滑鼠移動旋轉
```c
#include <GL/glut.h>
float angle=45, oldX=0;
void mouse(int button, int state, int x, int y){
    oldX = x;
}
void motion(int x, int y){
    angle += (x-oldX);
    oldX = x;
    glutPostRedisplay();
}
void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    glColor3f(1, 1, 1);
    glRectf(0.5, 0.5, -0.5, -0.5);///身體
    glPushMatrix();
        glTranslatef(0.5, 0.5, 0);
        glRotatef(angle, 0, 0, 1);
        glTranslatef(-0.5, -0.4, 0);
        glColor3f(1, 0, 0);
        glRectf(0.5, 0.5, 1.0, 0.3);///手臂
    glPopMatrix();
    glutSwapBuffers();
}
int main(int argc, char**argv)
{
    glutInit( &argc, argv );
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH );
    glutInitWindowSize(600, 600);
    glutCreateWindow("week13 rect TRT");
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutDisplayFunc( display );
    glutMainLoop();
    return 0;
}
```
5. 新增一個新的專案 week13_rect_TRT_TRT
將數值改小讓白熱長方形瘦身，並將紅色方塊移動到正確位置
```c
#include <GL/glut.h>
float angle=45, oldX=0;
void mouse(int button, int state, int x, int y){
    oldX = x;
}
void motion(int x, int y){
    angle += (x-oldX);
    oldX = x;
    glutPostRedisplay();
}
void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    glColor3f(1, 1, 1);
    glRectf(0.3, 0.5, -0.3, -0.5);///身體
    glPushMatrix();
        glTranslatef(0.3, 0.5, 0);
        glRotatef(angle, 0, 0, 1);
        glTranslatef(-0.5, -0.4, 0);
        glColor3f(1, 0, 0);
        glRectf(0.5, 0.5, 1.0, 0.3);///手臂
    glPopMatrix();
    glutSwapBuffers();
}
int main(int argc, char**argv)
{
    glutInit( &argc, argv );
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH );
    glutInitWindowSize(600, 600);
    glutCreateWindow("week13 rect TRT");
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutDisplayFunc( display );
    glutMainLoop();
    return 0;
}
```
