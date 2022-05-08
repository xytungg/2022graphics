# week6
1. keyboard 互動
```c
#include <GL/glut.h>
#include <stdio.h>
void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
        glColor3f( 1, 1, 0 );
        glutSolidTeapot(0.3);
    glutSwapBuffers();
}
void keyboard( unsigned char key, int x, int y )
{
    printf("現在按下：%c 座標在：%d %d\n", key, x, y);
}
int main(int argc, char**argv)
{
    glutInit( &argc, argv );
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH );
    glutCreateWindow("week06 keyboard");

    glutDisplayFunc( display );
    glutKeyboardFunc(keyboard);

    glutMainLoop();
    return 0;
}
```
2. 加上 mouse() 及 motion()函式，希望能完整互動 

```c
#include <GL/glut.h>
#include <stdio.h>
void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
        glColor3f( 1, 1, 0 );
        glutSolidTeapot(0.3);
    glutSwapBuffers();
}
void keyboard( unsigned char key, int x, int y )
{
    printf("現在按下：%c 座標在：%d %d\n", key, x, y);
}
void mouse ( int button, int state, int x, int y )
{

}
void motion(int x, int y)
{

}
int main(int argc, char**argv)
{///進階的 main函式
    glutInit( &argc, argv );///初始化
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH );///兩倍 + 3D
    glutCreateWindow("week06 keyboard");///建視窗

    glutDisplayFunc( display );///今天用來畫圖的函式
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMOtionFunc(motion);
    glutMainLoop();///主要的迴圈
    return 0;
}
```
3.做出 glTranslatef() 移動
```c
#include <GL/glut.h>
#include <stdio.h>
float x=0, y=0, z=0, oldX, oldY;
void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    glPushMatrix();
        glTranslatef( (x-150)/150.0 , -(y-150)/150.0, z);
        ///glRotatef( angle, 0, 0, 1);
        ///glScalef( scale, scale, scale );
        glColor3f( 1, 1, 0 );
        glutSolidTeapot(0.3);
    glPopMatrix();
    glutSwapBuffers();
}
void keyboard( unsigned char key, int mouseX, int mouseY )
{
    printf("現在按下：%c 座標在：%d %d\n", key, x, y);
}
void mouse ( int button, int state, int mouseX, int mouseY )
{
    oldX=mouseX; oldY=mouseY;
}
void motion(int mouseX, int mouseY)
{
    x += (mouseX-oldX);
    y += (mouseY-oldY);
    oldX = mouseX; oldY = mouseY;
    display();
}
int main(int argc, char**argv)
{///進階的 main函式
    glutInit( &argc, argv );///初始化
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH );///兩倍 + 3D
    glutCreateWindow("week06 keyboard");///建視窗

    glutDisplayFunc( display );///今天用來畫圖的函式
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutMainLoop();///主要的迴圈
    return 0;
}
```
4. 實作「縮放」程式，利用 float scale=1.0 這個變數，如果 if(mousX大於oldX)就讓 scale 放大 1%，反過來就讓 scale 變小 1%
```c
#include <GL/glut.h>
#include <stdio.h>
float x=0, y=0, z=0, scale=1.0, oldX, oldY;
void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    glPushMatrix();
        ///glRotatef( angle, 0, 0, 1);
        glScalef( scale, scale, scale );
        glColor3f( 1, 1, 0 );
        glutSolidTeapot(0.3);
    glPopMatrix();
    glutSwapBuffers();
}
void keyboard( unsigned char key, int mouseX, int mouseY )
{
    printf("現在按下：%c 座標在：%d %d\n", key, x, y);
}
void mouse ( int button, int state, int mouseX, int mouseY )
{
    oldX=mouseX; oldY=mouseY;
}
void motion(int mouseX, int mouseY)
{
    if( mouseX>oldX ) scale = scale * 1.01;
    if( mouseX<oldX ) scale = scale * 0.99;
    oldX = mouseX; oldY = mouseY;
    display();
}
int main(int argc, char**argv)
{///進階的 main函式
    glutInit( &argc, argv );///初始化
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH );///兩倍 + 3D
    glutCreateWindow("week06 keyboard");///建視窗

    glutDisplayFunc( display );///今天用來畫圖的函式
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutMainLoop();///主要的迴圈
    return 0;
}
```
5. 利用 if(key=='w' 或 key=='W') now=1做移動, if(key=='r' 或 key=='R')now=3 做縮放。接下來在 motion()裡，if(now==1)做移動的計算，if(now==3)做縮放的計算
```c
#include <GL/glut.h>
#include <stdio.h>
float x=0, y=0, z=0, scale=1.0, angle=0.0, oldX, oldY;
int now=1;
void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    glPushMatrix();
        glTranslatef( (x-150)/150.0 , -(y-150)/150.0, z);
        glRotatef( angle, 0, 0, 1);
        glScalef( scale, scale, scale );///Maya: r
        glColor3f( 1, 1, 0 );
        glutSolidTeapot(0.3);
    glPopMatrix();
    glutSwapBuffers();
}
void keyboard( unsigned char key, int mouseX, int mouseY )
{//printf("現在按下：%c 座標在：%d %d\n", key, x, y);
    if(key=='w' || key=='W') now=1;///移動
    if(key=='e' || key=='E') now=2;///旋轉
    if(key=='r' || key=='R') now=3;///縮放
}
void mouse ( int button, int state, int mouseX, int mouseY )
{
    oldX=mouseX; oldY=mouseY;
}
void motion(int mouseX, int mouseY)
{
    if(now==1){///移動
        x += (mouseX-oldX);
        y += (mouseY-oldY);
    }else if(now=3){///縮放
       if( mouseX>oldX ) scale = scale * 1.01;
        if( mouseX<oldX ) scale = scale * 0.99;
    }
    oldX = mouseX; oldY = mouseY;
    display();
}
int main(int argc, char**argv)
{///進階的 main函式
    glutInit( &argc, argv );
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH );
    glutCreateWindow("week06 keyboard");
    glutDisplayFunc( display );
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutMainLoop();
    return 0;
}
```
6.加上旋轉，用keyboard的 w,e,r 來切換移動、旋轉、縮放。還多學了 glutInitWindowSize(500,500)放大
```c
#include <GL/glut.h>
#include <stdio.h>
float x=250, y=250, z=0, scale=1.0, angle=0.0, oldX, oldY;
int now=1;
void display()
{
    glClearColor(0.5, 0.5, 0.5, 1);
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    glPushMatrix();
        glTranslatef( (x-250)/250.0 , -(y-250)/250.0, z);
        glRotatef( angle, 0, 0, 1);
        glScalef( scale, scale, scale );///Maya: r
        glColor3f( 1, 1, 0 );
        glutSolidTeapot(0.3);
    glPopMatrix();
    glutSwapBuffers();
}
void keyboard( unsigned char key, int mouseX, int mouseY )
{//printf("現在按下：%c 座標在：%d %d\n", key, x, y);
    if(key=='w' || key=='W') now=1;///移動
    if(key=='e' || key=='E') now=2;///旋轉
    if(key=='r' || key=='R') now=3;///縮放
}
void mouse ( int button, int state, int mouseX, int mouseY )
{
    oldX=mouseX; oldY=mouseY;
}
void motion(int mouseX, int mouseY)
{
    if(now==1){///移動
        x += (mouseX-oldX);
        y += (mouseY-oldY);
    }else if(now==2){
        angle += (mouseX-oldX);
    }else if(now=3){///縮放
       if( mouseX>oldX ) scale = scale * 1.01;
        if( mouseX<oldX ) scale = scale * 0.99;
    }
    oldX = mouseX; oldY = mouseY;
    display();
}
int main(int argc, char**argv)
{///進階的 main函式
    glutInit( &argc, argv );
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH );
    glutCreateWindow("week06 keyboard");
    glutDisplayFunc( display );
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutMainLoop();
    return 0;
}
```
