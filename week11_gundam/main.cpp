#include <opencv/highgui.h> ///使用 OpenCV 2.1 比較簡單, 只要用 High GUI 即可
#include <opencv/cv.h>
#include <GL/glut.h>
#include "glm.h"
GLMmodel * pmodel = NULL;
int myTexture(char * filename)
{
    IplImage * img = cvLoadImage(filename); ///OpenCV讀圖
    cvCvtColor(img,img, CV_BGR2RGB); ///OpenCV轉色彩 (需要cv.h)
    glEnable(GL_TEXTURE_2D); ///1. 開啟貼圖功能
    GLuint id; ///準備一個 unsigned int 整數, 叫 貼圖ID
    glGenTextures(1, &id); /// 產生Generate 貼圖ID
    glBindTexture(GL_TEXTURE_2D, id); ///綁定bind 貼圖ID
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); /// 貼圖參數, 超過包裝的範圖T, 就重覆貼圖
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT); /// 貼圖參數, 超過包裝的範圖S, 就重覆貼圖
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST); /// 貼圖參數, 放大時的內插, 用最近點
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); /// 貼圖參數, 縮小時的內插, 用最近點
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img->width, img->height, 0, GL_RGB, GL_UNSIGNED_BYTE, img->imageData);
	return id;
}
float angle=0;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    if( pmodel == NULL ){
        pmodel = glmReadOBJ( "data/Gundam.obj");///讀入模型
        glmUnitize( pmodel );///把模型pmodel 調整成單位大小-1...+1
        glmFacetNormals( pmodel );///把facet面的法向量Normals算出來
        glmVertexNormals( pmodel, 90);///把vertex的法向量用面平均算出來，超過90度就分開
    }
    glPushMatrix();
        glRotatef(angle, 0, 1, 0);
        glmDraw(pmodel, GLM_TEXTURE);
    glPopMatrix();
    glutSwapBuffers();
    angle+=1;
}
int main(int argc, char**argv)
{
    glutInit( &argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week11 gundam");

    glutDisplayFunc(display);
    glutIdleFunc(display);
    myTexture("data/Diffuse.jpg");
    glEnable(GL_DEPTH_TEST);

    glutMainLoop();
}
