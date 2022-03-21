#include <GL/glut.h>
float angle=0, oldX=0;
void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    glPushMatrix();
        glRotatef(angle, 0, 0, 1);//轉180度
        glColor3f(1,1,0);///黃色
        glutSolidTeapot( 0.3 );/// 0.3 實心茶壼
    glPopMatrix();
    glutSwapBuffers();///交換2倍的buffer
}
void mouse(int button, int state, int x, int y)
{
    oldX = x;
}
void motion(int x, int y)
{
    angle += (x-oldX);
    oldX = x;
    display();
}
int main(int argc, char**argv)
{///進階的 main函式
    glutInit( &argc, argv );///初始化
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH );///兩倍 + 3D
    glutCreateWindow("week03的視窗");///建視窗

    glutDisplayFunc( display );///今天用來畫圖的函式
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutMainLoop();///主要的迴圈
    return 0;
}
