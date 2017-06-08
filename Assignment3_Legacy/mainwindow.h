// mainwindow.h
// Assignment 3
// Johnny Sloans

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtGui>
#include <QComboBox>
#include <QLCDNumber>
#include <QDial>
#include <QSpinBox>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QGroupBox>
#include <QPushButton>
#include <QTextEdit>
#include <QDockWidget>
#include <QFileDialog>
#include <QMessageBox>
#include <QAction>
#include <QMenuBar>

class Graphics;

class MainWindow : public QMainWindow
{
    Q_OBJECT
    Graphics *graphics;

public:
    MainWindow();

private slots:
    void open();
    void help();

private:
    void createActions();
    void createMenus();
    void createControls();

    QMenu *fileMenu;
    QMenu *helpMenu;

    QAction *openAct;
    QAction *exitAct;
    QAction *helpAct;

    QTextEdit *editor;

    QWidget  *dockCentralWidget;
    QComboBox *comboBox;
    QLCDNumber *LCDStation;
    QSlider *HSlider;
    QDial *dial;
    QSlider *VSlider;
    QSpinBox *spinBox;
    QLCDNumber *LCDVolume;
    QLCDNumber *LCDBass;
    QLCDNumber *LCDTreble;
    QVBoxLayout *layoutDockCentra;
    QHBoxLayout *layout1;
    QGridLayout *voiceLayout;
    QGroupBox *voiceGroup;
    QVBoxLayout *layout2;
    QGroupBox *stationGroup;
    QPushButton *quit;

};

#endif
