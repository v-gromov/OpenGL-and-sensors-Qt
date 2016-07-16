#ifndef MAINSCENE_H
#define MAINSCENE_H

#include <QGLWidget>
#include <QWidget>
//#include "qopengl.h"
#include <QtOpenGL>
#include <QPoint>


#include <QtGui>
#include <math.h>

//#include <QtOpenGL
//#include <gl/glext.h>
//#include <gl/gl.h>


class MainScene: public QGLWidget
{

public:
    MainScene(QWidget* parent = 0);
    ~MainScene();
    void rotateCamera(float x, float y, float z);
    void sclareCamera(float x, float y, float z);
    void rotateCube(float x, float y, float z);
    void moving(float x, float y, float z);
    void sizeCube(float ox, float oy, float oz);
    void paintUpdate();
    void reset();
protected:
    void initializeGL();
    void resizeGL(int , int );
    void paintGL();

    //они используются также для отображения сцены
    GLfloat cubeVertexArray[8][3];//восемь вершин с тремя координатамя
    GLfloat cubeTextureArray[8][2];//восемь вершин с тремя составляющими
    GLubyte cubeIndexArray[6][4];//шесть граней с четырьмя выходящими линиями

    /*GLfloat lowRectVertexArr[4][3];
    GLbyte lowRectTextureArr[4][2];//Почему вылетает с QLfoat?
    GLubyte lowRectIndexArr[1][4];*/
    QPoint pressPosition;

    GLfloat currentWidth;//для работы поворотом мыши
    GLfloat currentHeight;//для работы поворотом мыши

    GLfloat coordCubeOX;//координата куба ось х
    GLfloat coordCubeOY;//координата куба ось у
    GLfloat coordCubeOZ;//координата куба ось z

    GLfloat sizeCubeOX;//размер грани куба по оси x
    GLfloat sizeCubeOY;//размер грани куба по оси y
    GLfloat sizeCubeOZ;//размер грани куба по оси z

    GLfloat rotateCubeOX;//поворот куба на градусы ось x
    GLfloat rotateCubeOY;//поворот куба на градусы ось y
    GLfloat rotateCubeOZ;//поворот куба на градусы ось z


    GLfloat scaleCameraOX;//масштаб всей сцены ось x
    GLfloat scaleCameraOY;//масштаб всей сцены ось y
    GLfloat scaleCameraOZ;//масштаб всей сцены ось z

    GLfloat rotateCameraOX;//поворот всей сцены на градусы ось x
    GLfloat rotateCameraOY;//поворот всей сцены на градусы ось y
    GLfloat rotateCameraOZ;//поворот всей сцены на градусы ось z
    GLuint textures[8];
    //float ambient[4];
    void generateTextures();
private:

    void cubMovement(float coordX, float coordY, float coordZ, float rotateX, float rotateY, float rotateZ, float sizeX, float sizeY, float sizeZ);
    void printScene();
    /*
protected:
    //void mousePressEvent(QMouseEvent *event);
    //void mouseMoveEvent(QMouseEvent *event);
    */
};

#endif // MAINSCENE_H
