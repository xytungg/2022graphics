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
