// graphics.h
// Assignment I4
// Farbod Hesaaraki

#ifndef Graphics_H
#define Graphics_H

#include <QOpenGLWindow>
#include <QOpenGLWidget>

class Graphics : public QOpenGLWidget
{
   Q_OBJECT

public:
   Graphics(QWidget *parent = 0);
   ~Graphics();
    float frequency;
    float amplitude;

protected:
   void initializeGL();
   void paintGL();
   void resizeGL(int w, int h);

   void signal();
};

#endif
