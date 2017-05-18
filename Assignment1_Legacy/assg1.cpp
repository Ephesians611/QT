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

    window->setWindowTitle("Assignment I1 - Software Radio");

    QComboBox *comboBox = new QComboBox();
    QLCDNumber *LCDStation = new QLCDNumber();
    QSlider *HSlider = new QSlider(Qt::Horizontal);
    QDial *dial = new QDial();
    QSlider *VSlider = new QSlider(Qt::Vertical);
    QSpinBox *spinBox = new QSpinBox;
    QLCDNumber *LCDVolume = new QLCDNumber();
    QLCDNumber *LCDBass = new QLCDNumber();
    QLCDNumber *LCDTreble = new QLCDNumber();

    dial->setFixedSize(65, 65);

    HSlider->setRange(535, 1605);  // The AM range is 535 - 1605 KHz
    dial->setRange(0, 100);
    VSlider->setRange(0, 100);
    spinBox->setRange(0, 100);

    // setting comboBox items
    comboBox->addItem("AM");
    comboBox->addItem("FM");

    // setting LCD for AM display (four digits and decimal).
    LCDStation->setDigitCount(4);
    LCDStation->setMode(QLCDNumber::Dec);
    LCDStation->display(535);

    // set LCDs' segment style to Flat (solid black)
    LCDStation->setSegmentStyle(QLCDNumber::Flat);
    LCDVolume->setSegmentStyle(QLCDNumber::Flat);
    LCDBass->setSegmentStyle(QLCDNumber::Flat);
    LCDTreble->setSegmentStyle(QLCDNumber::Flat);

    // connect each widget to its LCD output
    QObject::connect(HSlider, SIGNAL(valueChanged(int)), LCDStation, SLOT(display(int)));
    QObject::connect(dial, SIGNAL(valueChanged(int)), LCDVolume, SLOT(display(int)));
    QObject::connect(VSlider, SIGNAL(valueChanged(int)), LCDBass, SLOT(display(int)));
    QObject::connect(spinBox, SIGNAL(valueChanged(int)), LCDTreble, SLOT(display(int)));

    QVBoxLayout *layout = new QVBoxLayout;
    QHBoxLayout *layout1 = new QHBoxLayout;
    QGridLayout *voiceLayout = new QGridLayout;
    QGroupBox *voiceGroup = new QGroupBox("Voice Controls");
    QVBoxLayout *layout2 = new QVBoxLayout;
    QGroupBox *stationGroup = new QGroupBox("Station Controls");

    QPushButton *quit = new QPushButton("Quit");
    quit->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);	// to avoid stretching the qiut button
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

