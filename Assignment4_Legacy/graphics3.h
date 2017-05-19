// graphics3.h
// Assignment I4


#ifndef Graphics3_H
#define Graphics3_H

#include <QGLWidget>

/* initial triangle */


class Graphics3 : public QGLWidget
{
   Q_OBJECT

public:
   Graphics3(QWidget *parent = 0);
   ~Graphics3();
   int n; /* number of recursive steps */
   GLfloat v[3][2];

private slots:
    void animate();

protected:
   void initializeGL();
   void paintGL();
   void resizeGL(int w, int h);

   void triangle( GLfloat *, GLfloat *, GLfloat *);
   void divide_triangle(GLfloat *, GLfloat *, GLfloat *, int);
};

#endif
