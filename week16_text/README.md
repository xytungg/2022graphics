## 1. 修改week15週程式碼 學習內插
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
float NewAngle[20], OldAngle[20];
void myRead(){
    if(fout!=NULL) {
        fclose(fout);///還在讀的檔案要關掉
        fout=NULL;
    }
    if(fin==NULL) fin = fopen("file.txt", "r");
    for(int i=0; i<20; i++){
        OldAngle[i] = NewAngle[i];
    fscanf(fin, "%f", &NewAngle[i]);
        ///fscanf(fin, "%f", &angle[i]);
    }
    glutPostRedisplay();///重畫畫面
}
void myInterpolate(float alpha){
    for(int i=0; i<20; i++){
        angle[i] = alpha * NewAngle[i] + (1-alpha) * OldAngle[i];
        printf("%.2f", angle[i]);
    }
    printf("\n");
    glutPostRedisplay();
    alpha = (alpha+0.1);
    if(alpha>1) alpha = alpha -1;
}
float alpha =0;
void keyboard( unsigned char key, int x, int y){
    if( key=='p' ) myInterpolate(alpha);
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
## 2.將程式碼修改完成
### 加入timer函式-先執行第一次在擺好動作後按s-關閉視窗-再次執行後按下p-得到動畫
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
float NewAngle[20], OldAngle[20];
void myRead(){
    if(fout!=NULL) {
        fclose(fout);///還在讀的檔案要關掉
        fout=NULL;
    }
    if(fin==NULL) fin = fopen("file.txt", "r");
    for(int i=0; i<20; i++){
        OldAngle[i] = NewAngle[i];
    fscanf(fin, "%f", &NewAngle[i]);
        ///fscanf(fin, "%f", &angle[i]);
    }
    glutPostRedisplay();///重畫畫面
}
void myInterpolate(float alpha){
    for(int i=0; i<20; i++){
        angle[i] = alpha * NewAngle[i] + (1-alpha) * OldAngle[i];
        printf("%.2f", angle[i]);
    }
    printf("\n");
    glutPostRedisplay();
}
///float alpha =0;
void timer(int t){
    float alpha = (t%30)/30.0;
    if(t%30==0) myRead();
    myInterpolate(alpha);
    glutTimerFunc(33, timer, t+1);
}
void keyboard( unsigned char key, int x, int y){
    if( key=='p' ) {
        myRead();///先讀一行
        glutTimerFunc(0, timer, 0);
        ///myInterpolate(alpha);
        ///alpha = (alpha+0.01);
        ///if(alpha>1) alpha = alpha-1;
    }
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
## 3.以白色茶壺當範例做投影
```c
#include <GL/glut.h>
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glutSolidTeapot(2);///大茶壼
    glutSwapBuffers();
}
void motion(int x, int y)
{
    glMatrixMode(GL_MODELVIEW);///3D經過轉換到你最後的攝影機
    glLoadIdentity();
    gluLookAt( (x-150)/15.0, (y-150)/15.0, 3, ///eye
                0, 0, 0, ///center
                0, 1, 0);///up
    glutPostRedisplay();
}
void reshape(int w, int h)
{
    const float ar = (float) w / (float) h;
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);///投影,把3D投射到2D畫面
    glLoadIdentity();
    gluPerspective(60, ar, 0.1, 100);
    glMatrixMode(GL_MODELVIEW);///3D經過轉換到你最後的攝影機
    glLoadIdentity() ;
    gluLookAt( 0, 0, 3, 0, 0, 0, 0, 1, 0);
}
int main(int argc, char**argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week16 camera lookat");
    glutReshapeFunc(reshape);
    glutDisplayFunc(display);
    glutMotionFunc(motion);
    glutMainLoop();
}
```
