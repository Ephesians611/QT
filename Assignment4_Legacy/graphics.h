// graphics.h
// Johnny Sloans

#ifndef Graphics_H
#define Graphics_H

#include <QGLWidget>

class Graphics : public QGLWidget
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
