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
            QHBoxLayout *layout1 = new QHBoxLayout;
                QComboBox *cboReplacementPolicy = new QComboBox();
                    cboReplacementPolicy->addItem("LRU");
                    cboReplacementPolicy->addItem("LFU");
                    cboReplacementPolicy->addItem("Random");
                QComboBox *cboCacheType = new QComboBox();
                    cboCacheType->addItem("Instruction");
                    cboCacheType->addItem("Data");
                QLCDNumber *LCDStation = new QLCDNumber();
                    LCDStation->setDigitCount(4);
                    LCDStation->setMode(QLCDNumber::Dec);
                    LCDStation->display(535);
                    LCDStation->setSegmentStyle(QLCDNumber::Flat);
            QVBoxLayout *layout2 = new QVBoxLayout;
                QSlider *HSlider = new QSlider(Qt::Horizontal);
                    HSlider->setRange(535, 1605);

        QGroupBox *grpSimulationControls = new QGroupBox("Simulation Control");
            QGridLayout *voiceLayout = new QGridLayout;
                QDial *dial = new QDial();
                    dial->setFixedSize(165, 165);
                    dial->setRange(0, 100);
                QSlider *VSlider = new QSlider(Qt::Vertical);
                    VSlider->setRange(0, 100);
                QSpinBox *spinBox = new QSpinBox;
                    spinBox->setRange(0, 100);
                QLCDNumber *LCDVolume = new QLCDNumber();
                    LCDVolume->setSegmentStyle(QLCDNumber::Flat);
                QLCDNumber *LCDBass = new QLCDNumber();
                    LCDBass->setSegmentStyle(QLCDNumber::Flat);
                QLCDNumber *LCDTreble = new QLCDNumber();
                    LCDTreble->setSegmentStyle(QLCDNumber::Flat);

        QGroupBox *grpSimulationOutputControls = new QGroupBox("Simulation Output");

        QPushButton *quit = new QPushButton("Quit");
                quit->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);	// to avoid stretching the button

    // Widget Connections
    QObject::connect(HSlider,   SIGNAL(valueChanged(int)),  LCDStation,     SLOT(display(int)));
    QObject::connect(dial,      SIGNAL(valueChanged(int)),  LCDVolume,      SLOT(display(int)));
    QObject::connect(VSlider,   SIGNAL(valueChanged(int)),  LCDBass,        SLOT(display(int)));
    QObject::connect(spinBox,   SIGNAL(valueChanged(int)),  LCDTreble,      SLOT(display(int)));
    QObject::connect(quit,      SIGNAL(clicked()),          qApp,           SLOT(quit()));  // apply quit function to quit button

    // Widget Layouts
    //
    // Child Trace File Input Layout
    loutLoadTrace->addWidget(btnLoadTrace,0, Qt::AlignLeft);
    grpSimulationTraceFileInput->setLayout(loutLoadTrace);

    // Child Simulation Input Controls Layout
    layout1->addWidget(comboBox);
    layout1->addWidget(LCDStation);
    layout2->addLayout(layout1);
    layout2->addWidget(HSlider);
    grpSimulationInputControls->setLayout(layout2);

    // Child Simulation Controls Layout
    voiceLayout->addWidget(dial, 0, 0, Qt::AlignCenter);
    voiceLayout->addWidget(LCDVolume, 1, 0);
    voiceLayout->addWidget(VSlider, 0, 1, Qt::AlignCenter);
    voiceLayout->addWidget(LCDBass, 1, 1);
    voiceLayout->addWidget(spinBox, 0, 2, Qt::AlignCenter);
    voiceLayout->addWidget(LCDTreble, 1, 2);
    grpSimulationControls->setLayout(voiceLayout);

    // Child Simulation Output Controls Layout

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

