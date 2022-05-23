1. 練習開檔、寫檔、關檔
```c
#include <stdio.h>
int main()
{
    FILE * fout = fopen("file.txt", "w+");
    printf("Hello World\n"); ///小黑視窗
    fprintf(fout, "Hello World\n"); ///txt
    fclose(fout);
}
```
2. 練習開檔、讀檔、關檔
```c
#include <stdio.h>
int main()
{
    FILE * fout = fopen("file2.txt", "w+");
    fprintf(fout, "angle1 %d\n", 999);
    fclose(fout);

    char line[200];
    int a;
    FILE * fin = fopen("file2.txt", "r");
    fscanf(fin, "%s %d", line, &a);
    printf("讀到了字串:%s 及整數%d\n", line, a);
    fclose(fin);
}
```
3. 把上週week13_rect_many_TRT 拿來繼續寫，練習開檔、寫檔、關檔
```c
#include <GL/glut.h>
#include <stdio.h> ///為了 printf, fprintf, fopen, fclose
float angle[20], oldX=0;
int angleID=0;
FILE * fout = NULL;
void myWrite(){
    if(fout==NULL) fout = fopen("file.txt", "w+");
    for(int i=0; i<20; i++){
        fprintf(fout, "%.2f", angle[i]);
    }
}
void keyboard( unsigned char key, int x, int y){
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
    myWrite();
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
    glutCreateWindow("week14 TRT angle write");
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutKeyboardFunc(keyboard);
    glutDisplayFunc( display );
    glutMainLoop();
    return 0;
}
```
4. 印出座標、跳行
```c
#include <GL/glut.h>
#include <stdio.h> ///為了 printf, fprintf, fopen, fclose
float angle[20], oldX=0;
int angleID=0;
FILE * fout = NULL;
void myWrite(){
    if(fout==NULL) fout = fopen("file.txt", "w+");
    for(int i=0; i<20; i++){
        printf(       "%.2f", angle[i]);
        fprintf(fout, "%.2f", angle[i]);
    }
    printf("\n");
    fprintf(fout, "\n");
}
void keyboard( unsigned char key, int x, int y){
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
    myWrite();
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
    glutCreateWindow("week14 TRT angle write");
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutKeyboardFunc(keyboard);
    glutDisplayFunc( display );
    glutMainLoop();
    return 0;
}
```
5. 讀入檔案
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
    if( key=='0' ) angleID=0;
    if( key=='1' ) angleID=1;
    if( key=='2' ) angleID=2;
    if( key=='3' ) angleID=3;
    if( key=='r' ) {
        myRead();
    }
}///用keyboard的按鍵來決定
void mouse(int button, int state, int x, int y){
    oldX = x;
}
void motion(int x, int y){
    angle[angleID] += (x-oldX);
    myWrite();
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
    glutCreateWindow("week14 TRT angle write");
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutKeyboardFunc(keyboard);
    glutDisplayFunc( display );
    glutMainLoop();
    return 0;
}
```
6. 學習glutTimerFunc( timer, 時間)
```c
#include <GL/glut.h>
#include <stdio.h>

void timer(int t){///t的單位是ms，1000代表1秒
    printf("鬧鐘%d, 我起床了\n", t);
    printf("設定下一個鬧鐘\n");
    glutTimerFunc( 1000, timer, t+1 );
    printf("設好鬧鐘，再回去睡\n");
}
void display()
{


}
int main(int argc, char**argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week14 timer");

    glutTimerFunc(3000, timer, 0);
    glutDisplayFunc(display);
    glutMainLoop();
}
```
