#include <GL/glut.h>
float angle=0, oldX=0;
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
    glColor3f(1, 1, 1);///�զ�
    glRectf(0.3, 0.5, -0.3, -0.2);///����A�G��
    glPushMatrix();///������m���ܤF
        glTranslatef(0.3, 0.5, 0);
        glRotatef(angle, 0, 0, 1);
        glTranslatef(-0.3, -0.4, 0);
        glColor3f(1, 0, 0);
        glRectf(0.3, 0.5, 0.8, 0.3);///�W���u
        glPushMatrix();
            glTranslatef(0.8, 0.4, 0);///(3) ��U��y���b���`�W
            glRotatef(angle, 0, 0 ,1);///(2) ����
            glTranslatef(-0.8, -0.4, 0);///(1) ��U��y�����त�ߩ񥿤���
            glColor3f(0, 1, 0);///��⪺
            glRectf(0.8, 0.5, 1.1, 0.3);/// �A�e�U��y
        glPopMatrix();
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
