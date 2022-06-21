# week17
期末作品講解
## 1.環境建置
### a. 開啟CodeBlocks-新增Glut專案
### b. 開啟Setting-Compiler 
  =>確認Search directories 是否有Add 「C:\OpenCV2.1\include」
  =>確認Linker settings 是否有Add 「cv210」、「cxcore210」、「highgui210」
### c. 開啟當日新增的專案資料夾-用滑鼠右鍵點選Nopad++開啟當日cbp檔案
  =>將working_dir後引號內改成「.」(11行和21行)
### d. 將freeglut.dll複製丟進當日資料夾
### e. 在當日資料夾新增data資料夾，將分割好的obj檔和mtl檔丟入
## 2. Glut初始建置
```c
#include <GL/glut.h>
#include <stdio.h>
void display(){
    glClearColor(1, 1, 0, 0);///調整背景顏色
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    glColor3f(1, 0, 0); ///紅色的
    glutSolidTeapot( 0.3 );
    glutSwapBuffers();
}
int main(int argc, char**argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week17 demo");

    glutDisplayFunc(display);
    
    glutMainLoop();
}
```
=>輸出會得到黃色背景紅色茶壺
## 3. 加入打光
```c
#include <GL/glut.h>
#include <stdio.h>
void display(){
    glClearColor(1, 1, 0, 0);///調整背景顏色
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glColor3f(1, 0, 0); ///紅色的
    glutSolidTeapot( 0.3 );
    glutSwapBuffers();
}
const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, 5.0f, 0.0f };

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };
void mylight(){
    glEnable(GL_DEPTH_TEST);///3D的depth深度測試
    glDepthFunc(GL_LESS);

    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);

    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
}
int main(int argc, char**argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week17 demo");

    glutDisplayFunc(display);
    mylight();

    glutMainLoop();
}
```
## 4. 讀入3D模型
### a. 將glm.h跟glm.cpp複製到當日資料夾
### b. 在Codeblocks中左欄右鍵Add「glm.cpp」
