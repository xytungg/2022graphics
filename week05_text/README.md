# week5
1. 用glRotatef旋轉茶壺
```c
#include <GL/glut.h>
void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    glPushMatrix();
        glRotatef(180, 0, 0, 1);//轉180度
        glColor3f(1,1,0);///黃色
        glutSolidTeapot( 0.3 );/// 0.3 實心茶壼
    glPopMatrix();
    glutSwapBuffers();///交換2倍的buffer
}

int main(int argc, char**argv)
{///進階的 main函式
    glutInit( &argc, argv );///初始化
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH );///兩倍 + 3D
    glutCreateWindow("week03的視窗");///建視窗

    glutDisplayFunc( display );///今天用來畫圖的函式

    glutMainLoop();///主要的迴圈
    return 0;
}
```
2. 加入滑鼠互動
```c
#include <GL/glut.h>
float angle=0;
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
void motion(int x, int y)
{
    angle = x;
    display();

}
int main(int argc, char**argv)
{///進階的 main函式
    glutInit( &argc, argv );///初始化
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH );///兩倍 + 3D
    glutCreateWindow("week03的視窗");///建視窗

    glutDisplayFunc( display );///今天用來畫圖的函式
    glutMotionFunc(motion);
    glutMainLoop();///主要的迴圈
    return 0;
}
```
3. 讓滑鼠事件連續動作
```c
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
```
4.複習滑鼠繪圖
```c
#include <GL/glut.h>
#include <stdio.h>
int N=0;
int x[1000], y[1000];
void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    glBegin(GL_LINE_LOOP);
        for(int i=0; i<N; i++){
            glVertex2f( (x[i]-150)/150.0, -(y[i]-150)/150.0);
        }
    glEnd();
    glutSwapBuffers();
}
void mouse( int button, int state, int mouseX, int mouseY )
{
    if(state==GLUT_DOWN){
        N++;
        x[N-1]=mouseX;
        y[N-1]=mouseY;
        printf("現在按下滑鼠，得到新座標 %d %d\n", x[N-1], y[N-1]);
    }
    display();
}
int main(int argc, char**argv)
{///進階的 main函式
    glutInit( &argc, argv );
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH );
    glutCreateWindow("week05 複習 mouse");

    glutDisplayFunc( display );
    glutMouseFunc(mouse);
    glutMainLoop();
    return 0;
}
```
5.利用滑鼠連續描圖

```c
#include <GL/glut.h>
#include <stdio.h>
int N=0;
int x[1000], y[1000];
void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    glBegin(GL_LINE_LOOP);
        for(int i=0; i<N; i++){
            glVertex2f( (x[i]-150)/150.0, -(y[i]-150)/150.0);
        }
    glEnd();
    glutSwapBuffers();
}
//void mouse( int button, int state, int mouseX, int mouseY )
void motion (int mouseX, int mouseY)
{
    //if(state==GLUT_DOWN){
        N++;
        x[N-1]=mouseX;
        y[N-1]=mouseY;
        printf("現在按下滑鼠，得到新座標 %d %d\n", x[N-1], y[N-1]);
    //}
    display();
}
int main(int argc, char**argv)
{///進階的 main函式
    glutInit( &argc, argv );
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH );
    glutCreateWindow("week0 複習 mouse");

    glutDisplayFunc( display );
    glutMotionFunc(motion);
    glutMainLoop();
    return 0;
}
```
