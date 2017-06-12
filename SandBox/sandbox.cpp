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
                        btnLoadTrace->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);	// to avoid stretching

        QGroupBox *grpSimulationInputControls = new QGroupBox("Simulation Input");
            QHBoxLayout *hloutSimulationInput = new QHBoxLayout;
            QVBoxLayout *vloutSimulationInput = new QVBoxLayout;
                QLabel *lblReplacementPolicy = new QLabel("Replacement Policy");
                QComboBox *cboReplacementPolicy = new QComboBox();
                    cboReplacementPolicy->addItem("LRU");
                    cboReplacementPolicy->addItem("LFU");
                    cboReplacementPolicy->addItem("Random");
                    cboReplacementPolicy->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);	// to avoid stretching
                QLabel *lblCacheType = new QLabel("Cache Type");
                QRadioButton *rdoInstruction = new QRadioButton("Instruction");
                QRadioButton *rdoData = new QRadioButton("Data");
                    rdoInstruction->setChecked(true);
            QGridLayout *grdloutSimulationInput = new QGridLayout;
                QLabel *lblSets = new QLabel("Number Sets");
                QSlider *hsSets = new QSlider(Qt::Horizontal);
                    hsSets->setRange(1, 16);
                QLCDNumber *lcdNumSets = new QLCDNumber();\
                    lcdNumSets->setSegmentStyle(QLCDNumber::Flat);
                QLabel *lblWays = new QLabel("Number Ways");
                QSpinBox *spnWays = new QSpinBox;
                    spnWays->setRange(1, 16);
                QLCDNumber *lcdNumWays = new QLCDNumber();
                    lcdNumWays->setSegmentStyle(QLCDNumber::Flat);
                QLabel *lblBytesPerBlock = new QLabel("Bytes Per Block");
                QDial *dialBytesPerBlock = new QDial();
                    dialBytesPerBlock->setRange(4, 1024);
                QLCDNumber *lcdNumBytesPerBlock = new QLCDNumber();
                    lcdNumBytesPerBlock->setSegmentStyle(QLCDNumber::Flat);

        QGroupBox *grpSimulationControls = new QGroupBox("Simulation Control");
            QGridLayout *grdloutSimulationControl = new QGridLayout;
                QPushButton *btnRun = new QPushButton("Start");
                        btnRun->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);	// to avoid stretching
                QPushButton *btnContinue = new QPushButton("Continue");
                        btnContinue->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);	// to avoid stretching
                QPushButton *btnRunNumSteps = new QPushButton("Step S");
                        btnRunNumSteps->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);	// to avoid stretching
                QSpinBox *spnNumSteps = new QSpinBox;
                    spnNumSteps->setRange(1, 16);
                    spnNumSteps->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);	// to avoid stretching
                QPushButton *btnRunUntil = new QPushButton("Break B");
                        btnRunUntil->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);	// to avoid stretching
                QSpinBox *spnBreakAt = new QSpinBox;
                    spnBreakAt->setRange(1, 16);
                    spnBreakAt->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);	// to avoid stretching

        QGroupBox *grpSimulationOutputControls = new QGroupBox("Simulation Output");
            QGridLayout *grdloutSimulationOutput = new QGridLayout;
                QLabel *lblMemAccessInstances = new QLabel("Mem Access Instances");
                QLCDNumber *lcdMemAccessInstances = new QLCDNumber();\
                    lcdMemAccessInstances->setSegmentStyle(QLCDNumber::Flat);
                QLabel *lblCompMissRatio = new QLabel("Comp Miss Ratio");
                QLCDNumber *lcdCompMissRatio = new QLCDNumber();
                    lcdCompMissRatio->setSegmentStyle(QLCDNumber::Flat);
                QLabel *lblHitRatio = new QLabel("Hit Ratio");
                QLCDNumber *lcdHitRatio = new QLCDNumber();
                    lcdHitRatio->setSegmentStyle(QLCDNumber::Flat);
                QLabel *lblMissRatio = new QLabel("Miss Ratio");
                QLCDNumber *lcdMissRatio = new QLCDNumber();
                    lcdMissRatio->setSegmentStyle(QLCDNumber::Flat);

        QPushButton *quit = new QPushButton("Quit");
                quit->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);	// to avoid stretching

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
    vloutSimulationInput->addWidget(lblReplacementPolicy);
    vloutSimulationInput->addWidget(cboReplacementPolicy);
    vloutSimulationInput->addWidget(lblCacheType);
    vloutSimulationInput->addWidget(rdoInstruction);
    vloutSimulationInput->addWidget(rdoData);

    grdloutSimulationInput->addWidget(lblSets,              0, 0, Qt::AlignCenter);
    grdloutSimulationInput->addWidget(hsSets,               1, 0, Qt::AlignCenter);
    grdloutSimulationInput->addWidget(lcdNumSets,           2, 0, Qt::AlignCenter);

    grdloutSimulationInput->addWidget(lblWays,              0, 1, Qt::AlignCenter);
    grdloutSimulationInput->addWidget(spnWays,              1, 1, Qt::AlignCenter);
    grdloutSimulationInput->addWidget(lcdNumWays,           2, 1, Qt::AlignCenter);

    grdloutSimulationInput->addWidget(lblBytesPerBlock,     0, 2, Qt::AlignCenter);
    grdloutSimulationInput->addWidget(dialBytesPerBlock,    1, 2, Qt::AlignCenter);
    grdloutSimulationInput->addWidget(lcdNumBytesPerBlock,  2, 2, Qt::AlignCenter);

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
    grdloutSimulationOutput->addWidget(lblMemAccessInstances,   0, 0, Qt::AlignCenter);
    grdloutSimulationOutput->addWidget(lcdMemAccessInstances,   1, 0, Qt::AlignCenter);
    grdloutSimulationOutput->addWidget(lblCompMissRatio,        0, 1, Qt::AlignCenter);
    grdloutSimulationOutput->addWidget(lcdCompMissRatio,        1, 1, Qt::AlignCenter);
    grdloutSimulationOutput->addWidget(lblHitRatio,             0, 2, Qt::AlignCenter);
    grdloutSimulationOutput->addWidget(lcdHitRatio,             1, 2, Qt::AlignCenter);
    grdloutSimulationOutput->addWidget(lblMissRatio,            0, 3, Qt::AlignCenter);
    grdloutSimulationOutput->addWidget(lcdMissRatio,            1, 3, Qt::AlignCenter);
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

