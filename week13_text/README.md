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
