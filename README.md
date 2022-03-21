# week1
1. CodeBlocks, File-New-Project, 選 OpenGL專案
2. 要記得...對應的目錄
3. 取個專案名
4. Build & Run, 可以看到彩色三角形在轉動
# week3
1. 先把第01週的程式從 GitHub 下載
2. 跑今天的範例 Shape.exe
3. 今天的主題: 點、線、面、色彩
4. 複習上週的課堂作業 GLUT 要裝 freeglut 4.1. 把 freeglut.....zip 的freeglut拉到桌面 4.2. 再把 桌面\freeglut\lib\libglut32.a 複製好 4.3. 就可以跑上週的 week01_GLUT 範例了!!!
5. 今天的主角要出現了(把上週的2個程式會合併) 5.1. File-New-Project, GLUT專案, week03_color 小心, ...的目錄要在桌面 (freeglut目錄不要錯) (目前看起來和上週 week01_GLUT一樣) 5.2. 把程式全刪掉!!!!!!
6. 回家作業: 小畫家,可幫忙 (1) 小滴管+編輯色彩, 得到色彩的值(0-255) => 0.0~1.0 (2) 座標,可得到座標 0...300 => -1...+1

```c++
#include <GL/glut.h>
void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

    glColor3f(1,1,0);///黃色
    glutSolidTeapot( 0.3 );/// 0.3 實心茶壼

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

```c++
#include <GL/glut.h>
void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

    glColor3f(1,1,0);///黃色
//    glutSolidTeapot( 0.3 );/// 0.3 實心茶壼
    glBegin(GL_TRIANGLES);
        glColor3f(1.0f, 0.0f, 0.0f);   glVertex2f(0.0f,   1.0f);
        glColor3f(0.0f, 1.0f, 0.0f);   glVertex2f(0.87f,  -0.5f);
        glColor3f(0.0f, 0.0f, 1.0f);   glVertex2f(-0.87f, -0.5f);
    glEnd();
    glutSwapBuffers();///交換2倍的buffer
}

int main(int argc, char**argv)
{///進階的 main函式
    glutInit( &argc, argv );///初始化
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH );///兩倍 + 3D
    glutCreateWindow("week03的彩色三角形視窗");///建視窗

    glutDisplayFunc( display );///今天用來畫圖的函式

    glutMainLoop();///主要的迴圈
    return 0;
}
```

# week4

1. 下載範例 jsyeh.org/3dcg10
windows.zip > 下載\windows\Transformation.exe
data.zip         > 下載\windows\data\很多模型
執行 Transformation.exe
2. 將紅色的茶壼移到右上方，避免亂動要加上glPushMatrix()及glPopMatrix()
```c
#include <GL/glut.h>
void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    glPushMatrix();
        glTranslatef(0.3, 0.2, 0);
        glColor3f(1,0,0);///黃色
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
3. 標上座標可做成四個茶壺
```c
#include <GL/glut.h>
void myTeapot( float x, float y )
{
    glPushMatrix();
        glTranslatef( x, y, 0);
        glutSolidTeapot(0.3);
    glPopMatrix();
}
void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    glColor3f(1,0,0);///紅色
    myTeapot(+0.5, +0.5);
    myTeapot(+0.5, -0.5);
    myTeapot(-0.5, -0.5);
    myTeapot(-0.5, +0.5);

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
4. mouse滑鼠事件，我們使用glutMouseFunc(mouse)來註冊 void mouse(int button, int state, int x, int y) 的這個函式，使用printf()把值印出來，加深大家的印象，了解左鍵0、中鍵1、右鍵2、了解，按下去0，放開1， 了解座標0...300 的值
```c
#include <GL/glut.h>
#include <stdio.h>
void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

    glutSwapBuffers();///交換2倍的buffer
}
void mouse( int button, int state, int x, int y )
{
    printf("%d %d %d %d\n", button, state, x, y);
}
int main(int argc, char**argv)
{///進階的 main函式
    glutInit( &argc, argv );///初始化
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH );///兩倍 + 3D
    glutCreateWindow("week04 mouse");///建視窗

    glutDisplayFunc( display );///今天用來畫圖的函式
    glutMouseFunc(mouse);
    glutMainLoop();///主要的迴圈
    return 0;
}
```
5.將剛剛的印出座標改成控制茶壺在視窗中的方向
```c
#include <GL/glut.h>
#include <stdio.h>
int mouseX=0, mouseY=0;
void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    glColor3f(1,1,0);
    glPushMatrix();
        glTranslatef( (mouseX-150)/150.0, -(mouseY-150)/150.0, 0);
        glutSolidTeapot(0.3);
    glPopMatrix();
    glutSwapBuffers();///交換2倍的buffer
}
void mouse( int button, int state, int x, int y )
{
    mouseX=x; mouseY=y;
}
int main(int argc, char**argv)
{///進階的 main函式
    glutInit( &argc, argv );///初始化
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH );///兩倍 + 3D
    glutCreateWindow("week04 mouse");///建視窗

    glutDisplayFunc( display );///今天用來畫圖的函式
    glutMouseFunc(mouse);
    glutMainLoop();///主要的迴圈
    return 0;
}
```
6.利用滑鼠來寫程式，把座標備份在mx[i]及my[i]裡面。
```c
#include <GL/glut.h>
#include <stdio.h>
int mouseX=0, mouseY=0, N=0;
int mx[100], my[100];
void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    glColor3f(1,1,0);
    glBegin(GL_LINE_LOOP);
        for(int i=0; i<N; i++){
            glVertex2f( (mx[i]-150)/150.0, -(my[i]-150)/150.0);
        }
    glEnd();
    glutSwapBuffers();
}
void mouse( int button, int state, int x, int y )
{
    mouseX=x; mouseY=y;
    if(state==GLUT_DOWN){
        printf("    glVertex2f( (%d-150)/150.0, -(%d-150)/150.0); \n", x, y);
        N++;
        mx[N-1]=x;
        my[N-1]=y;
    }
}
int main(int argc, char**argv)
{///進階的 main函式
    glutInit( &argc, argv );///初始化
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH );///兩倍 + 3D
    glutCreateWindow("week04 mouse");///建視窗

    glutDisplayFunc( display );///今天用來畫圖的函式
    glutMouseFunc(mouse);
    glutMainLoop();///主要的迴圈
    return 0;
}
```
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
