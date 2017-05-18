// mainwindow.h
// Assignment I4
// Farbod Hesaaraki

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
class Graphics2;
class Graphics3;
class Graphics4;

class MainWindow : public QMainWindow
{
    Q_OBJECT
    Graphics *graphics1;
    Graphics2 *graphics2;
    Graphics3 *graphics3;
    Graphics4 *graphics4;

public:
    MainWindow();

private slots:
    void open();
    void help();

private slots:
    void changeAMCarrier();
    void convertDial();

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
