// Johnny Sloans

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

int main(int argc, char *argv[])
{
//    QApplication::setStyle("windows");
    QApplication::setStyle("platinum");

    QApplication app(argc, argv);
    QWidget *window = new QWidget;

    window->setWindowTitle("Assignment I1 - Cache Simulation");

    //  Widget setup
    QVBoxLayout *loutMain = new QVBoxLayout;

        QGroupBox *grpSimulationTraceFileInput = new QGroupBox("Simulation Trace File Input");
            QHBoxLayout *loutLoadTrace = new QHBoxLayout;
                QPushButton *btnLoadTrace = new QPushButton("Load Trace File...");
                        btnLoadTrace->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);	// to avoid stretching the button

        QGroupBox *grpSimulationInputControls = new QGroupBox("Simulation Input");
            QHBoxLayout *hloutSimulationInput = new QHBoxLayout;
            QVBoxLayout *vloutSimulationInput = new QVBoxLayout;
                QComboBox *cboReplacementPolicy = new QComboBox();
                    cboReplacementPolicy->addItem("LRU");
                    cboReplacementPolicy->addItem("LFU");
                    cboReplacementPolicy->addItem("Random");
                QGroupBox *grpCacheType = new QGroupBox();
                    QRadioButton *rdoInstruction = new QRadioButton("Instruction");
                    QRadioButton *rdoData = new QRadioButton("Data");
                    rdoInstruction->setChecked(true);
            QGridLayout *grdloutSimulationInput = new QGridLayout;
                QSlider *hsSets = new QSlider(Qt::Horizontal);
                    hsSets->setRange(1, 16);
                QLCDNumber *lcdNumSets = new QLCDNumber();\
                    lcdNumSets->setSegmentStyle(QLCDNumber::Flat);
                QSpinBox *spnWays = new QSpinBox;
                    spnWays->setRange(1, 16);
                QLCDNumber *lcdNumWays = new QLCDNumber();
                    lcdNumWays->setSegmentStyle(QLCDNumber::Flat);
                QDial *dialBytesPerBlock = new QDial();
                    dialBytesPerBlock->setRange(4, 1024);
                QLCDNumber *lcdNumBytesPerBlock = new QLCDNumber();
                    lcdNumBytesPerBlock->setSegmentStyle(QLCDNumber::Flat);

        QGroupBox *grpSimulationControls = new QGroupBox("Simulation Control");
            QGridLayout *grdloutSimulationControl = new QGridLayout;
                QPushButton *btnRun = new QPushButton("Start");
                        btnRun->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);	// to avoid stretching the button
                QPushButton *btnContinue = new QPushButton("Continue");
                        btnContinue->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);	// to avoid stretching the button
                QPushButton *btnRunNumSteps = new QPushButton("Step S");
                        btnRunNumSteps->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);	// to avoid stretching the button
                QSpinBox *spnNumSteps = new QSpinBox;
                    spnNumSteps->setRange(1, 16);
                QPushButton *btnRunUntil = new QPushButton("Break B");
                        btnRunUntil->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);	// to avoid stretching the button
                QSpinBox *spnBreakAt = new QSpinBox;
                    spnBreakAt->setRange(1, 16);

        QGroupBox *grpSimulationOutputControls = new QGroupBox("Simulation Output");
            QGridLayout *grdloutSimulationOutput = new QGridLayout;
                QLCDNumber *lcdMemAccessInstances = new QLCDNumber();\
                    lcdMemAccessInstances->setSegmentStyle(QLCDNumber::Flat);
                QLCDNumber *lcdCompMissRatio = new QLCDNumber();
                    lcdCompMissRatio->setSegmentStyle(QLCDNumber::Flat);
                QLCDNumber *lcdHitRatio = new QLCDNumber();
                    lcdHitRatio->setSegmentStyle(QLCDNumber::Flat);
                QLCDNumber *lcdMissRatio = new QLCDNumber();
                    lcdMissRatio->setSegmentStyle(QLCDNumber::Flat);

        QPushButton *quit = new QPushButton("Quit");
                quit->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);	// to avoid stretching the button

    // Widget Connections
    QObject::connect(hsSets,            SIGNAL(valueChanged(int)),  lcdNumSets,         SLOT(display(int)));
    QObject::connect(spnWays,           SIGNAL(valueChanged(int)),  lcdNumWays,         SLOT(display(int)));
    QObject::connect(dialBytesPerBlock, SIGNAL(valueChanged(int)),  lcdNumBytesPerBlock,SLOT(display(int)));
    QObject::connect(quit,              SIGNAL(clicked()),          qApp,               SLOT(quit()));  // apply quit function to quit button

    // Widget Layouts
    //
    // Child Trace File Input Layout
    loutLoadTrace->addWidget(btnLoadTrace,0, Qt::AlignLeft);
    grpSimulationTraceFileInput->setLayout(loutLoadTrace);

    // Child Simulation Input Controls Layout
    vloutSimulationInput->addWidget(cboReplacementPolicy);
    vloutSimulationInput->addWidget(grpCacheType);

    grdloutSimulationInput->addWidget(hsSets,               0, 0, Qt::AlignBottom);
    grdloutSimulationInput->addWidget(lcdNumSets,           1, 0, Qt::AlignBottom);
    grdloutSimulationInput->addWidget(spnWays,              0, 1, Qt::AlignBottom);
    grdloutSimulationInput->addWidget(lcdNumWays,           1, 1, Qt::AlignBottom);
    grdloutSimulationInput->addWidget(dialBytesPerBlock,    0, 2, Qt::AlignCenter);
    grdloutSimulationInput->addWidget(lcdNumBytesPerBlock,  2, 2, Qt::AlignTop);

    hloutSimulationInput->addLayout(vloutSimulationInput);
    hloutSimulationInput->addLayout(grdloutSimulationInput);
    grpSimulationInputControls->setLayout(hloutSimulationInput);

    // Child Simulation Controls Layout
    grdloutSimulationControl->addWidget(btnRun,         0, 0, Qt::AlignCenter);
    grdloutSimulationControl->addWidget(btnContinue,    1, 0);
    grdloutSimulationControl->addWidget(btnRunNumSteps, 0, 1, Qt::AlignCenter);
    grdloutSimulationControl->addWidget(spnNumSteps,    1, 1);
    grdloutSimulationControl->addWidget(btnRunUntil,    0, 2);
    grdloutSimulationControl->addWidget(spnBreakAt,     1, 2);
    grpSimulationControls->setLayout(grdloutSimulationControl);

    // Child Simulation Output Controls Layout
    grdloutSimulationOutput->addWidget(lcdMemAccessInstances,   0, 0, Qt::AlignCenter);
    grdloutSimulationOutput->addWidget(lcdCompMissRatio,        1, 0, Qt::AlignCenter);
    grdloutSimulationOutput->addWidget(lcdHitRatio,             0, 1, Qt::AlignCenter);
    grdloutSimulationOutput->addWidget(lcdMissRatio,            1, 1, Qt::AlignCenter);
    grpSimulationOutputControls->setLayout(grdloutSimulationOutput);

    // Organize Child Layouts
    loutMain->addWidget(grpSimulationTraceFileInput);
    loutMain->addWidget(grpSimulationInputControls);
    loutMain->addWidget(grpSimulationControls);
    loutMain->addWidget(grpSimulationOutputControls);
    loutMain->addWidget(quit, Qt::AlignCenter);
    loutMain->setAlignment(quit, Qt::AlignHCenter); 	// to align center the quit button horizontally

    // Parent Window Layout
    window->setLayout(loutMain);

    window->show();

    return app.exec();
}

