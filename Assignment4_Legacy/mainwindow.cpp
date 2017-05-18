// mainwindow.cpp
// Assignment I4
// Farbod Hesaaraki

#include "mainwindow.h"
#include "graphics.h"
#include "graphics2.h"
#include "graphics3.h"
#include "graphics4.h"

MainWindow::MainWindow()
{
    QWidget *window = new QWidget;
    setCentralWidget(window);

    graphics1 = new Graphics;		// implements the drawing of an AM carrier
    graphics2 = new Graphics2;		// implements the simple graphics (from I3)
    graphics3 = new Graphics3;		// implements the drawing of a fractal
    graphics4 = new Graphics4;		// implements the drawing of a signal stored in a file

    QHBoxLayout *layout = new QHBoxLayout;
    layout->setMargin(10);

    createControls();	// creates the widget from assignment I1.
                       // The name of the widget will be: dockCentralWidget

    QDockWidget  *dock = new QDockWidget();
    dock->setWidget(dockCentralWidget);

    QGridLayout *graphicsGrid = new QGridLayout();
    graphicsGrid->addWidget(graphics1, 0, 0);
    graphicsGrid->addWidget(graphics2, 0, 1);
    graphicsGrid->addWidget(graphics3, 1, 0);
    graphicsGrid->addWidget(graphics4, 1, 1);
    QDockWidget *graphicsDock = new QDockWidget();
    QWidget *graphics = new QWidget;
    graphics->setLayout(graphicsGrid);
    graphicsDock->setWidget(graphics);



    layout->addWidget(dock);
    layout->addWidget(graphicsDock);

    window->setLayout(layout);

    createActions();	// sets the actions for menu (open, help and exit)
    createMenus();

    setWindowTitle(tr("AssignmentI4"));
    setMinimumSize(160, 160);
    resize(700, 340);

}

// opens the file and put its content into the text editor
void MainWindow::open()
{
   QString fileName = QFileDialog::getOpenFileName(this, tr("Open File..."), QString(), tr("Text Files (*.txt);;All Files (*)"));
   QString line;

   QFile inputFile(fileName);
   if (inputFile.open(QIODevice::ReadOnly))
   {
       QTextStream in(&inputFile);
       line = in.readLine();
       if (line == "S2")
       {
           line = in.readLine();
           while (line[0] == '#')
           {
               line = in.readLine();
           }

           graphics4->info = line.split(" ");

           line = in.readLine();
           graphics4->numbers = line.split(" ");
       }
       else
       {
           QMessageBox::critical(this, tr("Error"), tr("The file format is wrong!"));
       }
   }
   inputFile.close();
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
   dial->setNotchesVisible(true);
   VSlider = new QSlider(Qt::Vertical);
   spinBox = new QSpinBox;
   LCDVolume = new QLCDNumber();
   LCDBass = new QLCDNumber();
   LCDTreble = new QLCDNumber();

   dial->setFixedSize(65, 65);

   HSlider->setRange(1, 250);  // The AM range is 535 - 1605 KHz
   dial->setRange(0, 100);
   VSlider->setRange(0, 100);
   spinBox->setRange(0, 100);


   dial->setValue(3 * 20);
   LCDVolume->display(3);
   LCDStation->display(105);
   HSlider->setValue(105);
   changeAMCarrier();



   // apply the hslider and dial values to the AM carrier
   // setting comboBox items
   comboBox->addItem("AM");
   comboBox->addItem("FM");

   // setting LCD for AM display (four digits and decimal).
   LCDStation->setNumDigits(4);
   LCDStation->setMode(QLCDNumber::Dec);

   // set LCDs' segment style to Flat (solid black)
   LCDStation->setSegmentStyle(QLCDNumber::Flat);
   LCDVolume->setSegmentStyle(QLCDNumber::Flat);
   LCDBass->setSegmentStyle(QLCDNumber::Flat);
   LCDTreble->setSegmentStyle(QLCDNumber::Flat);

   // connect each widget to its LCD output
   connect(HSlider, SIGNAL(valueChanged(int)), LCDStation, SLOT(display(int)));
   connect(HSlider, SIGNAL(valueChanged(int)), this, SLOT(changeAMCarrier()));
   connect(dial, SIGNAL(valueChanged(int)), this, SLOT(convertDial()));
   connect(dial, SIGNAL(valueChanged(int)), this, SLOT(changeAMCarrier()));
   connect(VSlider, SIGNAL(valueChanged(int)), LCDBass, SLOT(display(int)));
   connect(spinBox, SIGNAL(valueChanged(int)), LCDTreble, SLOT(display(int)));

   layoutDockCentra = new QVBoxLayout;
   layout1 = new QHBoxLayout;
   voiceLayout = new QGridLayout;
   voiceGroup = new QGroupBox("Voice Controls");
   layout2 = new QVBoxLayout;
   stationGroup = new QGroupBox("Station Controls");

   quit = new QPushButton("Quit");
   quit->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);	// to avoid stretching the qiut button
   connect(quit, SIGNAL(clicked()), qApp, SLOT(quit()));  // apply quit function to quit button

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

//Event slot when a button to change the sceene is clicked
//Updates the gl object with the new sceene
void MainWindow::changeAMCarrier()
{
    graphics1->amplitude = (double(dial->value())/20)/5;
    graphics1->frequency = double(HSlider->value())/20;

    graphics1->updateGL();
}

//Event slot when a button to change the sceene is clicked
//Updates the gl object with the new sceene
void MainWindow::convertDial()
{
    LCDVolume->display(double(dial->value())/20);
}
