// graphics4.h
// Assignment I4
// Farbod Hesaaraki

#ifndef Graphics4_H
#define Graphics4_H

#include <QtGui>

/* initial triangle */


class Graphics4 : public QWidget
{
   Q_OBJECT

public:
   Graphics4(QWidget *parent = 0);
   ~Graphics4();
   QStringList info;
   QStringList numbers;

protected:
   void initializeGL();
   void paintGL();
   void resizeGL(int w, int h);

   void point(GLfloat, GLfloat);
};

#endif
