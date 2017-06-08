// mainwindow.cpp
// Johnny Sloans

#include "mainwindow.h"

MainWindow::MainWindow()
{
    QWidget *window = new QWidget;
    setCentralWidget(window);

    editor = new QTextEdit();

    QHBoxLayout *layout = new QHBoxLayout;
    layout->setMargin(10);

    createControls();	// creates the widget from assignment I1.
                       // The name of the widget will be: dockCentralWidget

    QDockWidget  *dock = new QDockWidget();
    dock->setWidget(dockCentralWidget);

    layout->addWidget(dock);
    layout->addWidget(editor);

    window->setLayout(layout);

    createActions();	// sets the actions for menu (open, help and exit)
    createMenus();

    setWindowTitle(tr("AssignmentI2"));
    setMinimumSize(160, 160);
    resize(700, 340);
}

// opens the file and put its content into the text editor
void MainWindow::open()
{
    QFont font;
    font.setFamily("Arial");
    font.setPointSize(12);

    editor->setFont(font);
    editor->setAlignment(Qt::AlignJustify);

    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File..."), QString(), tr("Text Files (*.txt);;All Files (*)"));

    if (!fileName.isEmpty()) {
        QFile file(fileName);
        if (file.open(QFile::ReadOnly | QFile::Text))
            editor->setPlainText(file.readAll());
    }
}

// opens a message box as our help item
void MainWindow::help()
{
    QMessageBox::about(this, tr("Help"),
            tr("The goal of assignments I1 to I6 is to produce a user interface to a \"software radio.\" The interface enables control of parameters of the radio such as modulation, station, and volume, as well as bass settings, treble settings, stereo, etc."));
}

void MainWindow::createActions()
{
    openAct = new QAction(tr("&Open..."), this);
    openAct->setShortcuts(QKeySequence::Open);			// sets the keyboard shortcut for this action to default Ctrl+O
    openAct->setStatusTip(tr("Open an existing file"));
    connect(openAct, SIGNAL(triggered()), this, SLOT(open()));


    exitAct = new QAction(tr("E&xit"), this);
    exitAct->setShortcuts(QKeySequence::Quit);			// sets the keyboard shortcut for this action to default Alt+F4 (for linux)
    exitAct->setStatusTip(tr("Exit the application"));
    connect(exitAct, SIGNAL(triggered()), this, SLOT(close()));


    helpAct = new QAction(tr("&Help"), this);
    helpAct->setStatusTip(tr("Show the application's Help box"));
    connect(helpAct, SIGNAL(triggered()), this, SLOT(help()));

}

void MainWindow::createMenus()
{
    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(openAct);
    fileMenu->addSeparator();
    fileMenu->addAction(exitAct);

    helpMenu = menuBar()->addMenu(tr("&Help"));
    helpMenu->addAction(helpAct);
}

void MainWindow::createControls()
{
   dockCentralWidget = new QWidget();
   dockCentralWidget->setWindowTitle("Assignment I1 - Software Radio");

   comboBox = new QComboBox();
   LCDStation = new QLCDNumber();
   HSlider = new QSlider(Qt::Horizontal);
   dial = new QDial();
   VSlider = new QSlider(Qt::Vertical);
   spinBox = new QSpinBox;
   LCDVolume = new QLCDNumber();
   LCDBass = new QLCDNumber();
   LCDTreble = new QLCDNumber();

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

   layoutDockCentra = new QVBoxLayout;
   layout1 = new QHBoxLayout;
   voiceLayout = new QGridLayout;
   voiceGroup = new QGroupBox("Voice Controls");
   layout2 = new QVBoxLayout;
   stationGroup = new QGroupBox("Station Controls");

   quit = new QPushButton("Quit");
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

   layoutDockCentra->addWidget(stationGroup);
   layoutDockCentra->addWidget(voiceGroup);
   layoutDockCentra->addWidget(quit, Qt::AlignCenter);

   layoutDockCentra->setAlignment(quit, Qt::AlignHCenter); 	// to align center the quit button horizontally

   dockCentralWidget->setLayout(layoutDockCentra);
   dockCentralWidget->setFixedWidth(260);
}
