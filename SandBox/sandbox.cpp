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
//   the screenshot that I submitted has both following styles
//    QApplication::setStyle("windows");
    QApplication::setStyle("platinum");

    QApplication app(argc, argv);
    QWidget *window = new QWidget;

    window->setWindowTitle("Assignment I1 - Cache Simulation");

    QVBoxLayout *layout = new QVBoxLayout;
        QGroupBox *stationGroup = new QGroupBox("Station Controls");
            QHBoxLayout *layout1 = new QHBoxLayout;
                QComboBox *comboBox = new QComboBox();
                    comboBox->addItem("AM");
                    comboBox->addItem("FM");
                QLCDNumber *LCDStation = new QLCDNumber();
                    LCDStation->setDigitCount(4);
                    LCDStation->setMode(QLCDNumber::Dec);
                    LCDStation->display(535);
                    LCDStation->setSegmentStyle(QLCDNumber::Flat);
            QVBoxLayout *layout2 = new QVBoxLayout;
                QSlider *HSlider = new QSlider(Qt::Horizontal);
                    HSlider->setRange(535, 1605);  // The AM range is 535 - 1605 KHz

        QGroupBox *voiceGroup = new QGroupBox("Voice Controls");
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

        QPushButton *quit = new QPushButton("Quit");
                quit->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);	// to avoid stretching the qiut button

    // connect each widget to its LCD output
    QObject::connect(HSlider, SIGNAL(valueChanged(int)), LCDStation, SLOT(display(int)));
    QObject::connect(dial, SIGNAL(valueChanged(int)), LCDVolume, SLOT(display(int)));
    QObject::connect(VSlider, SIGNAL(valueChanged(int)), LCDBass, SLOT(display(int)));
    QObject::connect(spinBox, SIGNAL(valueChanged(int)), LCDTreble, SLOT(display(int)));
    QObject::connect(quit, SIGNAL(clicked()), qApp, SLOT(quit()));  // apply quit function to quit button

    // organizing station related widgets
    layout1->addWidget(comboBox);
    layout1->addWidget(LCDStation);
    layout2->addLayout(layout1);
    layout2->addWidget(HSlider);
    stationGroup->setLayout(layout2);

    // organizing voice related widgets
    voiceLayout->addWidget(dial, 0, 0, Qt::AlignCenter);
    voiceLayout->addWidget(LCDVolume, 1, 0);
    voiceLayout->addWidget(VSlider, 0, 1, Qt::AlignCenter);
    voiceLayout->addWidget(LCDBass, 1, 1);
    voiceLayout->addWidget(spinBox, 0, 2, Qt::AlignCenter);
    voiceLayout->addWidget(LCDTreble, 1, 2);
    voiceGroup->setLayout(voiceLayout);

    layout->addWidget(stationGroup);
    layout->addWidget(voiceGroup);
    layout->addWidget(quit, Qt::AlignCenter);

    layout->setAlignment(quit, Qt::AlignHCenter); 	// to align center the quit button horizontally

    window->setLayout(layout);

    window->show();
    return app.exec();
}

