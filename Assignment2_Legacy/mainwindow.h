// mainwindow.h

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtGui>
#include <QTextEdit>
#include <QAction>
#include <QBoxLayout>
#include <QDockWidget>
#include <QFileDialog>
#include <QMessageBox>
#include <QMenu>
#include <QMenuBar>
#include <QComboBox>
#include <QLCDNumber>
#include <QDial>
#include <QSpinBox>
#include <QGroupBox>
#include <QPushButton>


class MainWindow : public QMainWindow
{
    Q_OBJECT

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
