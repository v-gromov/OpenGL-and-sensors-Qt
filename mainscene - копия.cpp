#include "mainscene.h"

MainScene::MainScene(QWidget* parent) : QGLWidget(parent)
{
    coordCubeOX = coordCubeOY = coordCubeOZ = 0;
    sizeCubeOX = sizeCubeOY = sizeCubeOZ = 1;
    rotateCubeOX = rotateCubeOY = rotateCubeOZ = 0;

    scaleCameraOX = scaleCameraOY = scaleCameraOZ = 1;
    rotateCameraOX = rotateCameraOY = 30;
    rotateCameraOZ = 0;
}

void MainScene::paintGL()
{
    qglClearColor(Qt::white);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glRotatef(rotateCameraOX, 1.0, 0.0, 0.0);//поворот камеры по трем осям
    glRotatef(rotateCameraOY, 0.0, 1.0, 0.0);//поворот камеры по трем осям
    glRotatef(rotateCameraOZ, 0.0, 0.0, 1.0);//поворот камеры по трем осям
    glScalef(scaleCameraOX, scaleCameraOX, scaleCameraOX);//масштаб всей сцены по трем осям

    glPushMatrix();//вывод куба
    cubMovement(coordCubeOX, coordCubeOY, coordCubeOZ, rotateCubeOX, rotateCubeOY, rotateCubeOZ, sizeCubeOX, sizeCubeOY, sizeCubeOZ);
    glPopMatrix();


    //сцена, нижняя часть
    lowRectVertexArr[0][0] = 15.0;
    lowRectVertexArr[0][1] = -5.0;//высота нижней части
    lowRectVertexArr[0][2] = 15.0;

    lowRectVertexArr[1][0] = 15.0;
    lowRectVertexArr[1][1] = -5.0;//высота нижней части
    lowRectVertexArr[1][2] = -15.0;

    lowRectVertexArr[2][0] = -15.0;
    lowRectVertexArr[2][1] = -5.0;//высота нижней части
    lowRectVertexArr[2][2] = -15.0;

    lowRectVertexArr[3][0] = -15.0;
    lowRectVertexArr[3][1] = -5.0;//высота нижней части
    lowRectVertexArr[3][2] = 15.0;

    glBindTexture(GL_TEXTURE_2D, textures[7]);

    lowRectIndexArr[0][0] = 0;
    lowRectIndexArr[0][1] = 1;

    lowRectIndexArr[0][2] = 2;
    lowRectIndexArr[0][3] = 3;


    lowRectTextureArr[0][0] = 0.0;
    lowRectTextureArr[0][1] = 0.0;

    lowRectTextureArr[1][0] = 0.0;
    lowRectTextureArr[1][1] = 0.0;

    lowRectTextureArr[2][0] = 0.0;
    lowRectTextureArr[2][1] = 0.0;

    lowRectTextureArr[3][0] = 0.0;
    lowRectTextureArr[3][1] = 0.0;

    glVertexPointer(3, GL_FLOAT, 0, lowRectVertexArr);//координаты в 3д
    glTexCoordPointer(2, GL_FLOAT, 0, lowRectTextureArr);//почему-то в отладке float работает
    glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_BYTE, lowRectIndexArr);
}

void  MainScene::cubMovement(float coordX, float coordY, float coordZ, float rotateX, float rotateY, float rotateZ, float sizeX, float sizeY, float sizeZ)
{

    glRotated(rotateX, 1.0, 0.0, 0.0);//поворот матрицы с кубом по трем осям.
    glRotated(rotateY, 0.0, 1.0, 0.0);//поворот матрицы с кубом по трем осям.
    glRotated(rotateZ, 0.0, 0.0, 1.0);//поворот матрицы с кубом по трем осям.
    glTranslated(coordX, coordY, coordZ);//перемещение матрицы с кубом по трем осям.
    glScaled(sizeX, sizeY, sizeZ);//масштаб матрицы по трем осям.

    cubeVertexArray[0][0] = -1;
    cubeVertexArray[0][1] = -1;
    cubeVertexArray[0][2] = 1;

    cubeVertexArray[1][0] = -1;
    cubeVertexArray[1][1] = 1;
    cubeVertexArray[1][2] = 1;

    cubeVertexArray[2][0] = 1;
    cubeVertexArray[2][1] = 1;
    cubeVertexArray[2][2] = 1;

    cubeVertexArray[3][0] = 1;
    cubeVertexArray[3][1] = -1;
    cubeVertexArray[3][2] = 1;

    cubeVertexArray[4][0] = -1;
    cubeVertexArray[4][1] = -1;
    cubeVertexArray[4][2] = -1;

    cubeVertexArray[5][0] = -1;
    cubeVertexArray[5][1] = 1;
    cubeVertexArray[5][2] = -1;

    cubeVertexArray[6][0] = 1;
    cubeVertexArray[6][1] = 1;
    cubeVertexArray[6][2] = -1;

    cubeVertexArray[7][0] = 1;
    cubeVertexArray[7][1] = -1;
    cubeVertexArray[7][2] = -1;


    //текстуры
    glBindTexture(GL_TEXTURE_2D, textures[0]);

    cubeTextureArray[0][0] = 0.0;
    cubeTextureArray[0][1] = 0.0;

    cubeTextureArray[1][0] = 1.0;
    cubeTextureArray[1][1] = 0.0;

    cubeTextureArray[2][0] = 1.0;
    cubeTextureArray[2][1] = 1.0;

    cubeTextureArray[3][0] = 0.0;
    cubeTextureArray[3][1] = 1.0;

    cubeIndexArray[0][0] = 0;//задаем индексы
    cubeIndexArray[0][1] = 3;
    cubeIndexArray[0][2] = 2;
    cubeIndexArray[0][3] = 1;

    glVertexPointer(3, GL_FLOAT, 0, cubeVertexArray);//отрисовка
    glTexCoordPointer(2, GL_FLOAT, 0, cubeTextureArray);
    glDrawElements(GL_QUADS, 4, GL_UNSIGNED_BYTE, cubeIndexArray);

    glBindTexture(GL_TEXTURE_2D, textures[1]);

    cubeTextureArray[0][0] = 0.0;
    cubeTextureArray[0][1] = 0.0;

    cubeTextureArray[1][0] = 1.0;
    cubeTextureArray[1][1] = 0.0;

    cubeTextureArray[5][0] = 1.0;
    cubeTextureArray[5][1] = 1.0;

    cubeTextureArray[4][0] = 0.0;
    cubeTextureArray[4][1] = 1.0;

    cubeIndexArray[0][0] = 0;
    cubeIndexArray[0][1] = 1;
    cubeIndexArray[0][2] = 5;
    cubeIndexArray[0][3] = 4;

    glVertexPointer(3, GL_FLOAT, 0, cubeVertexArray);
    glTexCoordPointer(2, GL_FLOAT, 0, cubeTextureArray);
    glDrawElements(GL_QUADS, 4, GL_UNSIGNED_BYTE, cubeIndexArray);

    glBindTexture(GL_TEXTURE_2D, textures[2]);

    cubeTextureArray[7][0] = 0.0;
    cubeTextureArray[7][1] = 0.0;

    cubeTextureArray[4][0] = 1.0;
    cubeTextureArray[4][1] = 0.0;

    cubeTextureArray[5][0] = 1.0;
    cubeTextureArray[5][1] = 1.0;

    cubeTextureArray[6][0] = 0.0;
    cubeTextureArray[6][1] = 1.0;

    cubeIndexArray[0][0] = 7;
    cubeIndexArray[0][1] = 4;
    cubeIndexArray[0][2] = 5;
    cubeIndexArray[0][3] = 6;

    glVertexPointer(3, GL_FLOAT, 0, cubeVertexArray);
    glTexCoordPointer(2, GL_FLOAT, 0, cubeTextureArray);
    glDrawElements(GL_QUADS, 4, GL_UNSIGNED_BYTE, cubeIndexArray);

    glBindTexture(GL_TEXTURE_2D, textures[3]);

    cubeTextureArray[3][0] = 0.0;
    cubeTextureArray[3][1] = 0.0;

    cubeTextureArray[7][0] = 1.0;
    cubeTextureArray[7][1] = 0.0;

    cubeTextureArray[6][0] = 1.0;
    cubeTextureArray[6][1] = 1.0;

    cubeTextureArray[2][0] = 0.0;
    cubeTextureArray[2][1] = 1.0;

    cubeIndexArray[0][0] = 3;
    cubeIndexArray[0][1] = 7;
    cubeIndexArray[0][2] = 6;
    cubeIndexArray[0][3] = 2;

    glVertexPointer(3, GL_FLOAT, 0, cubeVertexArray);
    glTexCoordPointer(2, GL_FLOAT, 0, cubeTextureArray);
    glDrawElements(GL_QUADS, 4, GL_UNSIGNED_BYTE, cubeIndexArray);

    glBindTexture(GL_TEXTURE_2D, textures[4]);

    cubeTextureArray[1][0] = 0.0;
    cubeTextureArray[1][1] = 0.0;

    cubeTextureArray[2][0] = 1.0;
    cubeTextureArray[2][1] = 0.0;

    cubeTextureArray[6][0] = 1.0;
    cubeTextureArray[6][1] = 1.0;

    cubeTextureArray[5][0] = 0.0;
    cubeTextureArray[5][1] = 1.0;

    cubeIndexArray[0][0] = 1;
    cubeIndexArray[0][1] = 2;
    cubeIndexArray[0][2] = 6;
    cubeIndexArray[0][3] = 5;

    glVertexPointer(3, GL_FLOAT, 0, cubeVertexArray);
    glTexCoordPointer(2, GL_FLOAT, 0, cubeTextureArray);
    glDrawElements(GL_QUADS, 4, GL_UNSIGNED_BYTE, cubeIndexArray);

    glBindTexture(GL_TEXTURE_2D, textures[5]);

    cubeTextureArray[0][0] = 0.0;
    cubeTextureArray[0][1] = 0.0;

    cubeTextureArray[4][0] = 1.0;
    cubeTextureArray[4][1] = 0.0;

    cubeTextureArray[7][0] = 1.0;
    cubeTextureArray[7][1] = 1.0;

    cubeTextureArray[3][0] = 0.0;
    cubeTextureArray[3][1] = 1.0;

    cubeIndexArray[0][0] = 0;
    cubeIndexArray[0][1] = 4;
    cubeIndexArray[0][2] = 7;
    cubeIndexArray[0][3] = 3;

    glVertexPointer(3, GL_FLOAT, 0, cubeVertexArray);
    glTexCoordPointer(2, GL_FLOAT, 0, cubeTextureArray);
    glDrawElements(GL_QUADS, 4, GL_UNSIGNED_BYTE, cubeIndexArray);
}

void MainScene::sizeCube(float ox, float oy, float oz)
{
    if(ox < 1)
        sizeCubeOX = 1;
    else sizeCubeOX = ox;

    if(oy < 1)
        sizeCubeOY = 1;
    else sizeCubeOY = oy;

    if(oz < 1)
        sizeCubeOZ = 1;
    else sizeCubeOZ = oz;
    updateGL();
}

void MainScene::mouseMoveEvent(QMouseEvent *event)
{
    rotateCameraOX += (180 * ((GLfloat)event->y() - (GLfloat)pressPosition.y())) / (currentHeight);
    rotateCameraOY += (180 * ((GLfloat)event->x() - (GLfloat)pressPosition.x())) / (currentWidth);
    pressPosition = event->pos();
    updateGL();
}


void MainScene::generateTextures()
{
    glGenTextures(6, textures);
    QImage texture1;
    texture1.load(":/cubeOne.jpg");
    texture1 = QGLWidget::convertToGLFormat(texture1);
    glBindTexture(GL_TEXTURE_2D, textures[0]);
    glTexImage2D(GL_TEXTURE_2D, 0, 3, (GLsizei)texture1.width(), (GLsizei)texture1.height(), 0, GL_RGBA, GL_UNSIGNED_BYTE, texture1.bits());
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);

    QImage texture2;
    texture2.load(":/cubeTwo.jpg");
    texture2 = QGLWidget::convertToGLFormat(texture2);
    glBindTexture(GL_TEXTURE_2D, textures[1]);
    glTexImage2D(GL_TEXTURE_2D, 0, 3, (GLsizei)texture2.width(), (GLsizei)texture2.height(), 0, GL_RGBA, GL_UNSIGNED_BYTE, texture2.bits());
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);

    QImage texture3;
    texture3.load(":/cubeThree.jpg");
    texture3 = QGLWidget::convertToGLFormat(texture3);
    glBindTexture(GL_TEXTURE_2D, textures[2]);
    glTexImage2D(GL_TEXTURE_2D, 0, 3, (GLsizei)texture3.width(), (GLsizei)texture3.height(), 0, GL_RGBA, GL_UNSIGNED_BYTE, texture3.bits());
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);

    QImage texture4;
    texture4.load(":/cubeFour.jpg");
    texture4 = QGLWidget::convertToGLFormat(texture4);
    glBindTexture(GL_TEXTURE_2D, textures[3]);
    glTexImage2D(GL_TEXTURE_2D, 0, 3, (GLsizei)texture4.width(), (GLsizei)texture4.height(), 0, GL_RGBA, GL_UNSIGNED_BYTE, texture4.bits());
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);

    QImage texture5;
    texture5.load(":/cubeFive.jpg");
    texture5 = QGLWidget::convertToGLFormat(texture5);
    glBindTexture(GL_TEXTURE_2D, textures[4]);
    glTexImage2D(GL_TEXTURE_2D, 0, 3, (GLsizei)texture5.width(), (GLsizei)texture5.height(), 0, GL_RGBA, GL_UNSIGNED_BYTE, texture5.bits());
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);

    QImage texture6;
    texture6.load(":/cubeSix.jpg");
    texture6 = QGLWidget::convertToGLFormat(texture6);
    glBindTexture(GL_TEXTURE_2D, textures[5]);
    glTexImage2D(GL_TEXTURE_2D, 0, 3, (GLsizei)texture6.width(), (GLsizei)texture6.height(), 0, GL_RGBA, GL_UNSIGNED_BYTE, texture6.bits());
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);

    QImage texture7;
    texture2.load(":/lower_t.jpg");
    texture2 = QGLWidget::convertToGLFormat(texture2);
    glBindTexture(GL_TEXTURE_2D, textures[6]);
    glTexImage2D(GL_TEXTURE_2D, 0, 3, (GLsizei)texture2.width(), (GLsizei)texture2.height(), 0, GL_RGBA, GL_UNSIGNED_BYTE, texture2.bits());
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
}

void MainScene::rotateCamera(float x, float y, float z)
{
    rotateCameraOX += x;
    rotateCameraOY += y;
    rotateCameraOZ += z;
    updateGL();
}

void MainScene::sclareCamera(float x, float y, float z)
{
    if(x < 1)
        x = 1;
    /*else
        sclareCameraX = x;
    if(y < 1)
        y = 1;
    else
        sclareCameraY = y;
    if( z < 1)
        z = 1;
    else
        sclareCameraZ = z;*/
    updateGL();
}

void MainScene::rotateCube(float x, float y, float z)
{
    rotateCubeOX = x;
    rotateCubeOY = y;
    rotateCubeOZ = z;
    updateGL();
}

void MainScene::moving(float x, float y, float z)
{
    coordCubeOX = x;
    coordCubeOY = y;
    coordCubeOZ = z;
    updateGL();
}

void MainScene::reset()
{
    coordCubeOX = coordCubeOY = coordCubeOZ = 0;
    sizeCubeOX = sizeCubeOY = sizeCubeOZ = 1;
    rotateCubeOX = rotateCubeOY = rotateCubeOZ = 0;

    scaleCameraOX = scaleCameraOY = scaleCameraOZ = 1;
    rotateCameraOX = rotateCameraOY = 30;
    rotateCameraOZ = 0;
    updateGL();
}

void MainScene::initializeGL()
{
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glEnable(GL_DEPTH_TEST);
    glShadeModel(GL_FLAT);
    glEnable(GL_CULL_FACE);
    glEnable(GL_TEXTURE_2D);
    generateTextures();
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_TEXTURE_COORD_ARRAY);
}
void MainScene::resizeGL(int nWidth, int nHeight)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-15.0, 15.0, -15.0, 15.0, -15.0, 15.0);
    /*glViewport(0, 0, (GLint)nWidth, (GLint)nHeight);
    currentWidth = nWidth;
    currentHeight = nHeight;*/
}

/*void MainScene::mousePressEvent(QMouseEvent *event)
{
    pressPosition = event->pos();
}*/
