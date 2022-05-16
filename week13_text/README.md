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
