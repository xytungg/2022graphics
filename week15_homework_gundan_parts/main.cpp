#include <GL/glut.h>
#include <stdio.h>
#include "glm.h"
GLMmodel * pmodel = NULL;
float angle[20],oldX=0;
int angleID=0;///0:��0�����`,1:��1�����`,2:��2�����`
FILE * fout = NULL,* fin = NULL;
void myWrite()
{
    if(fin!=NULL)
    {
        fclose(fin); fin=NULL;
    }
    if(fout==NULL)fout = fopen("file.txt","w+");
    for(int i=0;i<20;i++)
    {
         printf(     "%.2f ",angle[i]);
        fprintf(fout,"%.2f ",angle[i]);
    }
    printf("\n");
    fprintf(fout,"\n");///�֤Ffclose�A�]�����Q�n�~�L�@��N�����A�Q�g�h��@�I
}
void myRead()
{
    if(fout!=NULL){fclose(fout);fout=NULL;}///�٦bŪ���ɮ׭n����
    if(fin==NULL)fin = fopen("file.txt","r");
    for(int i=0;i<20;i++)
    {
        fscanf(fin,"%f",&angle[i]);
    }
    glutPostRedisplay();///���e�e��
}
void keyboarad(unsigned char key,int x,int y)
{
    if(key=='r') myRead();
    if(key=='s') myWrite();///save
    if(key=='1') angleID=1;///�w�]�o�O�Ĥ@��
    if(key=='2') angleID=2;
    if(key=='3') angleID=3;
    if(key=='4') angleID=4;
}///��keyboarad������A�ӨM�w���@�Umotion()�̭n�諸
void mouse(int button,int state,int x,int y)
{///mouse���U�h
    oldX=x;
}
void motion(int x,int y)
{
    angle[angleID]+=(x-oldX);
    ///myWrite();///�S�����n�@���g��
    oldX=x;
    glutPostRedisplay();///���e�e��Re display
}
void display()///�ǳƷs��display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    if( pmodel == NULL ){///�{����o��
        pmodel = glmReadOBJ("data/Gundam.obj");
        glmUnitize(pmodel);
        glmFacetNormals(pmodel);
        glmVertexNormals(pmodel,90);
    }
    glmDraw(pmodel, GLM_SMOOTH);
    glutSwapBuffers();
}
void displayOld()///���ª�display��W�l
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1,1,1);///�զ⪺
    glRectf(0.3,0.5,-0.3,-0.2);///����
    glPushMatrix();///�k�b��
        glTranslatef(0.3,0.5,0);///(3)���U�n��0.5,0.5
        glRotatef(angle[1],0,0,1);///(2)����
        glTranslatef(-0.3,-0.4,0);///(1)������त�ߩ񥿤���
        glColor3f(1,0,0);///���⪺
        glRectf(0.3,0.5,0.8,0.3);///�W���u
        glPushMatrix();
            glTranslatef(0.8,0.4,0);///(3)��U��y���b���`�W
            glRotatef(angle[2],0,0,1);///(2)����
            glTranslatef(-0.8,-0.4,0);///(1)��U��y�����त��,�񥿤���
            glColor3f(0,1,0);///��⪺
            glRectf(0.8,0.5,1.1,0.3);///�A�e�k�U��y
        glPopMatrix();
    glPopMatrix();

    glPushMatrix();///���b��
        glTranslatef(-0.3,0.5,0);///(3)���U�n��0.5,0.5
        glRotatef(angle[3],0,0,1);///(2)����
        glTranslatef(0.3,-0.4,0);///(1)������त�ߩ񥿤���
        glColor3f(1,0,0);///���⪺
        glRectf(-0.3,0.5,-0.8,0.3);///�W���u
        glPushMatrix();
            glTranslatef(-0.8,0.4,0);///(3)��U��y���b���`�W
            glRotatef(angle[4],0,0,1);///(2)����
            glTranslatef(0.8,-0.4,0);///(1)��U��y�����त��,�񥿤���
            glColor3f(0,1,0);///��⪺
            glRectf(-0.8,0.5,-1.1,0.3);///�A�e���U��y
        glPopMatrix();
    glPopMatrix();

    glutSwapBuffers();
}
int main(int argc,char**argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH);
    ///glutInitWindowSize(600,600);
    glutCreateWindow("week15");
    glutKeyboardFunc(keyboarad);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutDisplayFunc(display);///����Idle
    glutMainLoop();
}
