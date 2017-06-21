#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QApplication>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QtGui>
#include <QSlider>
#include <QSpinBox>
#include <QComboBox>
#include <QLCDNumber>
#include <QLabel>
#include <QDial>
#include <QGroupBox>
#include <QPushButton>
#include <QRadioButton>
#include <QTextEdit>
#include <QDockWidget>
#include <QFileDialog>
#include <QMessageBox>
#include <QMenu>
#include <QMenuBar>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void open();
    void help();
    void getReferenceWordValue(int);
    void getOffsetFieldValue(int);
    void getIndexFieldValue(int);
    void getTagFieldValue(int);


private:
    Ui::MainWindow *ui;
    int a, b, c;
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

    QVBoxLayout *loutMain;

        QGroupBox *grpSimulationTraceFileInput;
            QHBoxLayout *loutLoadTrace;
                QPushButton *btnLoadTrace;

        QGroupBox *grpSimulationInputControls;
            QHBoxLayout *hloutSimulationInput;
            QVBoxLayout *vloutSimulationInput;
                QLabel *lblReplacementPolicy;
                QComboBox *cboReplacementPolicy;
                QLabel *lblCacheType;
                QRadioButton *rdoInstruction;
                QRadioButton *rdoData;
            QGridLayout *grdloutSimulationInput;
                QLabel *lblSets;
                QSlider *hsSets;
                QLCDNumber *lcdNumSets;\
                QLabel *lblWays;
                QSpinBox *spnWays;
                QLCDNumber *lcdNumWays;
                QLabel *lblBytesPerBlock;
                QDial *dialBytesPerBlock;
                QLCDNumber *lcdNumBytesPerBlock;
                QLabel *lblMemorySize;
                QSpinBox *spnMemorySize;
                QLCDNumber *lcdMemorySize;

        QGroupBox *grpSimulationControls;
            QGridLayout *grdloutSimulationControl;
                QPushButton *btnRun;
                QPushButton *btnContinue;
                QPushButton *btnRunNumSteps;
                QSpinBox *spnNumSteps;
                QPushButton *btnRunUntil;
                QSpinBox *spnBreakAt;

        QGroupBox *grpSimulationOutputControls;
            QGridLayout *grdloutSimulationOutput;
                QLabel *lblMemAccessInstances;
                QLCDNumber *lcdMemAccessInstances;\
                QLabel *lblCompMissRatio;
                QLCDNumber *lcdCompMissRatio;
                QLabel *lblHitRatio;
                QLCDNumber *lcdHitRatio;
                QLabel *lblMissRatio;
                QLCDNumber *lcdMissRatio;

                QLabel *lblReferenceWordSize;
                QLCDNumber *lcdReferenceWordSize;\
                QLabel *lblOffsetFieldSize;
                QLCDNumber *lcdOffsetFieldSize;
                QLabel *lblIndexFieldSize;
                QLCDNumber *lcdIndexFieldSize;
                QLabel *lblTagFieldSize;
                QLCDNumber *lcdTagFieldSize;

        QPushButton *quit;
};

#endif // MAINWINDOW_H
