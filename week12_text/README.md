# week12
```c
#include <GL/glut.h>
void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    glPushMatrix();
        glTranslatef( 0.4, -0.07, 0 );
        glutSolidTeapot( 0.3 );
    glPopMatrix();
    glutSwapBuffers();
}

int main(int argc, char**argv)
{
    glutInit( &argc, argv );
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH );
    glutCreateWindow("week12 TRT");

    glutDisplayFunc( display );
    glutMainLoop();
    return 0;
}
```
