#include <GL/glut.h>
#include <stdio.h>
#include "glm.h"
GLMmodel * pmodel = NULL;
float angle[20],oldX=0;
int angleID=0;///0:第0個關節,1:第1個關節,2:第2個關節
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
    fprintf(fout,"\n");///少了fclose，因為不想要才印一行就結束，想寫多行一點
}
void myRead()
{
    if(fout!=NULL){fclose(fout);fout=NULL;}///還在讀的檔案要關掉
    if(fin==NULL)fin = fopen("file.txt","r");
    for(int i=0;i<20;i++)
    {
        fscanf(fin,"%f",&angle[i]);
    }
    glutPostRedisplay();///重畫畫面
}
void keyboarad(unsigned char key,int x,int y)
{
    if(key=='r') myRead();
    if(key=='s') myWrite();///save
    if(key=='1') angleID=1;///預設這是第一個
    if(key=='2') angleID=2;
    if(key=='3') angleID=3;
    if(key=='4') angleID=4;
}///用keyboarad的按鍵，來決定等一下motion()裡要改的
void mouse(int button,int state,int x,int y)
{///mouse按下去
    oldX=x;
}
void motion(int x,int y)
{
    angle[angleID]+=(x-oldX);
    ///myWrite();///沒有必要一直寫檔
    oldX=x;
    glutPostRedisplay();///重畫畫面Re display
}
void display()///準備新的display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    if( pmodel == NULL ){///程式放這裡
        pmodel = glmReadOBJ("data/Gundam.obj");
        glmUnitize(pmodel);
        glmFacetNormals(pmodel);
        glmVertexNormals(pmodel,90);
    }
    glmDraw(pmodel, GLM_SMOOTH);
    glutSwapBuffers();
}
void displayOld()///把舊的display改名子
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1,1,1);///白色的
    glRectf(0.3,0.5,-0.3,-0.2);///身體
    glPushMatrix();///右半邊
        glTranslatef(0.3,0.5,0);///(3)等下要掛0.5,0.5
        glRotatef(angle[1],0,0,1);///(2)旋轉
        glTranslatef(-0.3,-0.4,0);///(1)先把旋轉中心放正中心
        glColor3f(1,0,0);///紅色的
        glRectf(0.3,0.5,0.8,0.3);///上手臂
        glPushMatrix();
            glTranslatef(0.8,0.4,0);///(3)把下手肘掛在關節上
            glRotatef(angle[2],0,0,1);///(2)旋轉
            glTranslatef(-0.8,-0.4,0);///(1)把下手肘的旋轉中心,放正中心
            glColor3f(0,1,0);///綠色的
            glRectf(0.8,0.5,1.1,0.3);///再畫右下手肘
        glPopMatrix();
    glPopMatrix();

    glPushMatrix();///左半邊
        glTranslatef(-0.3,0.5,0);///(3)等下要掛0.5,0.5
        glRotatef(angle[3],0,0,1);///(2)旋轉
        glTranslatef(0.3,-0.4,0);///(1)先把旋轉中心放正中心
        glColor3f(1,0,0);///紅色的
        glRectf(-0.3,0.5,-0.8,0.3);///上手臂
        glPushMatrix();
            glTranslatef(-0.8,0.4,0);///(3)把下手肘掛在關節上
            glRotatef(angle[4],0,0,1);///(2)旋轉
            glTranslatef(0.8,-0.4,0);///(1)把下手肘的旋轉中心,放正中心
            glColor3f(0,1,0);///綠色的
            glRectf(-0.8,0.5,-1.1,0.3);///再畫左下手肘
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
    glutDisplayFunc(display);///不放Idle
    glutMainLoop();
}
