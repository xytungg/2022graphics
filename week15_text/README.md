# week15
1. 播放聲音
```c
///#include <mmsystem.h>//上週教
#include <windows.h>///另一種寫法，結果一樣
int main()
{           ///先放不存在的檔     上週教SND_ASYNC
    PlaySound("badbadbad.wav", NULL, SND_SYNC);
}///Compile成功，但是link失敗
/// .c .cpp =compile=> .o =link=> .exe
```
2. 播放想要的音效
```c
///#include <mmsystem.h>//上週教
#include <windows.h>///另一種寫法，結果一樣
int main()
{           ///先放不存在的檔     上週教SND_ASYNC
    PlaySound("badbadbad.wav", NULL, SND_SYNC); ///更改這行
}///Compile成功，但是link失敗
/// .c .cpp =compile=> .o =link=> .exe
```
3. 比較 SND_SYNC 和 SND_ASYNC
```c
#include <windows.h>
#include <stdio.h>///printf()
int main()
{
    printf("現在在PlaySound()前\n");
    PlaySound("07042111.wav", NULL, SND_ASYNC);
    printf("現在在PlaySound()後\n");
    int N;
    scanf("%d", &N);///等你輸入數字
}
```
4. 播放mp3
```c
#include  "CMP3_MCI.h"
#include <stdio.h>
CMP3_MCI mp3;
int main()
{
    mp3.Load("07042111.mp3");
    mp3.Play();
    printf("現在正在播放羊的聲音\n");
    int N;
    scanf("%d", &N);


}
```
5. 接續上週 week14_angles_TRT_write_and_read，改成固定後記錄動作
```c
#include <GL/glut.h>
#include <stdio.h> ///為了 printf, fprintf, fopen, fclose
float angle[20], oldX=0;
int angleID=0;
FILE * fout = NULL, * fin = NULL;
void myWrite(){
    if(fout==NULL) fout = fopen("file.txt", "w+");
    for(int i=0; i<20; i++){
        printf(       "%.2f", angle[i]);
        fprintf(fout, "%.2f", angle[i]);
    }
    printf("\n");
    fprintf(fout, "\n");
}
void myRead(){
    if(fout!=NULL) {
        fclose(fout);///還在讀的檔案要關掉
        fout=NULL;
    }
    if(fin==NULL) fin = fopen("file.txt", "r");
    for(int i=0; i<20; i++){
        fscanf(fin, "%f", &angle[i]);
    }
}
void keyboard( unsigned char key, int x, int y){
    if( key=='r' ) myRead();
    if( key=='s' ) myWrite();///save
    if( key=='0' ) angleID=0;
    if( key=='1' ) angleID=1;
    if( key=='2' ) angleID=2;
    if( key=='3' ) angleID=3;
}///用keyboard的按鍵來決定
void mouse(int button, int state, int x, int y){
    oldX = x;
}
void motion(int x, int y){
    angle[angleID] += (x-oldX);
    ///myWrite();///沒有必要一直寫檔
    oldX = x;
    glutPostRedisplay();
}
void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    glColor3f(1, 1, 1);///白色
    glRectf(0.3, 0.5, -0.3, -0.2);///身體，瘦身
    glPushMatrix();///掛的位置改變了
        glTranslatef(0.3, 0.5, 0);
        glRotatef(angle[0], 0, 0, 1);
        glTranslatef(-0.3, -0.4, 0);
        glColor3f(1, 0, 0);
        glRectf(0.3, 0.5, 0.8, 0.3);///上手臂
        glPushMatrix();
            glTranslatef(0.8, 0.4, 0);///(3) 把下手肘掛在關節上
            glRotatef(angle[1], 0, 0 ,1);///(2) 旋轉
            glTranslatef(-0.8, -0.4, 0);///(1) 把下手肘的旋轉中心放正中心
            glColor3f(0, 1, 0);///綠色的
            glRectf(0.8, 0.5, 1.1, 0.3);/// 再畫下手肘
        glPopMatrix();
    glPopMatrix();

    glPushMatrix();///左半邊
        glTranslatef(-0.3, 0.5, 0);
        glRotatef(angle[2], 0, 0, 1);
        glTranslatef(+0.3, -0.4, 0);
        glColor3f(1, 0, 0);
        glRectf(-0.3, 0.5, -0.8, 0.3);///上手臂
        glPushMatrix();
            glTranslatef(-0.8, 0.4, 0);///(3) 把下手肘掛在關節上
            glRotatef(angle[3], 0, 0 ,1);///(2) 旋轉
            glTranslatef(+0.8, -0.4, 0);///(1) 把下手肘的旋轉中心放正中心
            glColor3f(0, 1, 0);///綠色的
            glRectf(-0.8, 0.5, -1.1, 0.3);/// 再畫下手肘
        glPopMatrix();
    glPopMatrix();

    glutSwapBuffers();
}
int main(int argc, char**argv)
{
    glutInit( &argc, argv );
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH );
    glutInitWindowSize(600, 600);
    glutCreateWindow("week15 TRT angles again");
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutKeyboardFunc(keyboard);
    glutDisplayFunc( display );
    glutMainLoop();
    return 0;
}
```
6. 機器人跳舞 期末作業講解
```c
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
```
