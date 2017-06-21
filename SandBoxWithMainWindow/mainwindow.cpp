#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <math.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    a = 0;
    b = 0;
    c = 0;

    ui->setupUi(this);

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
    setMinimumSize(360, 360);
    resize(700, 640);
}

MainWindow::~MainWindow()
{
    delete ui;
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
            tr("The goal of assignments I1 to I6 is to produce a user interface to a \"cache simulator.\" The interface enables control of parameters of the simulator such as type, number set, and replacement policy"));
}

void MainWindow::getReferenceWordValue(int memorySize)
{
    a = ceil(log2(memorySize));
    lcdReferenceWordSize->display(a);
}
void MainWindow::getOffsetFieldValue(int bytesPerBlock)
{
    b = ceil(log2(bytesPerBlock));
    lcdOffsetFieldSize->display(b);
}
void MainWindow::getIndexFieldValue(int numberSets)
{
    c = ceil(log2(numberSets));
    lcdIndexFieldSize->display(c);
}

void MainWindow::getTagFieldValue(int)
{
    lcdTagFieldSize->display(a-b-c);
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
   dockCentralWidget->setWindowTitle("Assignment I1 - Cache Simulator");

   //  Widget setup
   QVBoxLayout *loutMain = new QVBoxLayout;

       grpSimulationTraceFileInput = new QGroupBox("Simulation Trace File Input");
           loutLoadTrace = new QHBoxLayout;
               btnLoadTrace = new QPushButton("Load Trace File...");
                       btnLoadTrace->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);	// to avoid stretching

       grpSimulationInputControls = new QGroupBox("Simulation Input");
           hloutSimulationInput = new QHBoxLayout;
            vloutSimulationInput = new QVBoxLayout;
               lblReplacementPolicy = new QLabel("Replacement Policy");
               cboReplacementPolicy = new QComboBox();
                   cboReplacementPolicy->addItem("LRU");
                   cboReplacementPolicy->addItem("LFU");
                   cboReplacementPolicy->addItem("Random");
                   cboReplacementPolicy->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);	// to avoid stretching
               lblCacheType = new QLabel("Cache Type");
               rdoInstruction = new QRadioButton("Instruction");
               rdoData = new QRadioButton("Data");
                   rdoInstruction->setChecked(true);
           grdloutSimulationInput = new QGridLayout;
               lblSets = new QLabel("Number Sets");
               hsSets = new QSlider(Qt::Horizontal);
                   hsSets->setRange(1, 16);
               lcdNumSets = new QLCDNumber();\
                   lcdNumSets->setSegmentStyle(QLCDNumber::Flat);
               lblWays = new QLabel("Number Ways");
               spnWays = new QSpinBox;
                   spnWays->setRange(1, 16);
               lcdNumWays = new QLCDNumber();
                   lcdNumWays->setSegmentStyle(QLCDNumber::Flat);
               lblBytesPerBlock = new QLabel("Bytes Per Block");
               dialBytesPerBlock = new QDial();
                   dialBytesPerBlock->setRange(4, 1024);
               lcdNumBytesPerBlock = new QLCDNumber();
                   lcdNumBytesPerBlock->setSegmentStyle(QLCDNumber::Flat);
               lblMemorySize = new QLabel("MemorySize");
               spnMemorySize = new QSpinBox();
                   spnMemorySize->setRange(pow(2,8), pow(2,28));
               lcdMemorySize = new QLCDNumber();
                   lcdMemorySize->setSegmentStyle(QLCDNumber::Flat);

       grpSimulationControls = new QGroupBox("Simulation Control");
           grdloutSimulationControl = new QGridLayout;
               btnRun = new QPushButton("Start");
                       btnRun->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);	// to avoid stretching
               btnContinue = new QPushButton("Continue");
                       btnContinue->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);	// to avoid stretching
               btnRunNumSteps = new QPushButton("Step S");
                       btnRunNumSteps->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);	// to avoid stretching
               spnNumSteps = new QSpinBox;
                   spnNumSteps->setRange(1, 16);
                   spnNumSteps->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);	// to avoid stretching
               btnRunUntil = new QPushButton("Break B");
                       btnRunUntil->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);	// to avoid stretching
               spnBreakAt = new QSpinBox;
                   spnBreakAt->setRange(1, 16);
                   spnBreakAt->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);	// to avoid stretching

       grpSimulationOutputControls = new QGroupBox("Simulation Output");
           grdloutSimulationOutput = new QGridLayout;
               lblMemAccessInstances = new QLabel("Mem Access Instances");
               lcdMemAccessInstances = new QLCDNumber();\
                   lcdMemAccessInstances->setSegmentStyle(QLCDNumber::Flat);
               lblCompMissRatio = new QLabel("Comp Miss Ratio");
               lcdCompMissRatio = new QLCDNumber();
                   lcdCompMissRatio->setSegmentStyle(QLCDNumber::Flat);
               lblHitRatio = new QLabel("Hit Ratio");
               lcdHitRatio = new QLCDNumber();
                   lcdHitRatio->setSegmentStyle(QLCDNumber::Flat);
               lblMissRatio = new QLabel("Miss Ratio");
               lcdMissRatio = new QLCDNumber();
                   lcdMissRatio->setSegmentStyle(QLCDNumber::Flat);
               lblReferenceWordSize = new QLabel("Reference Word Size (bits)");
               lcdReferenceWordSize = new QLCDNumber();\
                   lcdReferenceWordSize->setSegmentStyle(QLCDNumber::Flat);
               lblOffsetFieldSize = new QLabel("Offset Field Size (bits)");
               lcdOffsetFieldSize = new QLCDNumber();
                   lcdOffsetFieldSize->setSegmentStyle(QLCDNumber::Flat);
               lblIndexFieldSize = new QLabel("Index Field Size (bits)");
               lcdIndexFieldSize = new QLCDNumber();
                   lcdIndexFieldSize->setSegmentStyle(QLCDNumber::Flat);
               lblTagFieldSize = new QLabel("Tag Field Size (bits)");
               lcdTagFieldSize = new QLCDNumber();
                   lcdTagFieldSize->setSegmentStyle(QLCDNumber::Flat);

       quit = new QPushButton("Quit");
               quit->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);	// to avoid stretching

   // Widget Connections
   QObject::connect(hsSets,            SIGNAL(valueChanged(int)),  lcdNumSets,          SLOT(display(int)));
   QObject::connect(spnWays,           SIGNAL(valueChanged(int)),  lcdNumWays,          SLOT(display(int)));
   QObject::connect(dialBytesPerBlock, SIGNAL(valueChanged(int)),  lcdNumBytesPerBlock, SLOT(display(int)));
   QObject::connect(spnMemorySize,    SIGNAL(valueChanged(int)),  lcdMemorySize,       SLOT(display(int)));

   QObject::connect(spnMemorySize,    SIGNAL(valueChanged(int)),   this,   SLOT(getReferenceWordValue(int)));
   QObject::connect(dialBytesPerBlock, SIGNAL(valueChanged(int)),   this,   SLOT(getOffsetFieldValue(int)));
   QObject::connect(hsSets,            SIGNAL(valueChanged(int)),   this,   SLOT(getIndexFieldValue(int)));
   QObject::connect(spnMemorySize,    SIGNAL(valueChanged(int)),   this,   SLOT(getTagFieldValue(int)));

   QObject::connect(quit,              SIGNAL(clicked()),          qApp,                SLOT(quit()));  // apply quit function to quit button

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

   grdloutSimulationInput->addWidget(lblSets,               0, 0, Qt::AlignCenter);
   grdloutSimulationInput->addWidget(hsSets,                1, 0, Qt::AlignCenter);
   grdloutSimulationInput->addWidget(lcdNumSets,            2, 0, Qt::AlignCenter);
   grdloutSimulationInput->addWidget(lblWays,               0, 1, Qt::AlignCenter);
   grdloutSimulationInput->addWidget(spnWays,               1, 1, Qt::AlignCenter);
   grdloutSimulationInput->addWidget(lcdNumWays,            2, 1, Qt::AlignCenter);
   grdloutSimulationInput->addWidget(lblBytesPerBlock,      0, 2, Qt::AlignCenter);
   grdloutSimulationInput->addWidget(dialBytesPerBlock,     1, 2, Qt::AlignCenter);
   grdloutSimulationInput->addWidget(lcdNumBytesPerBlock,   2, 2, Qt::AlignCenter);
   grdloutSimulationInput->addWidget(lblMemorySize,         0, 3, Qt::AlignCenter);
   grdloutSimulationInput->addWidget(spnMemorySize,        1, 3, Qt::AlignCenter);
   grdloutSimulationInput->addWidget(lcdMemorySize,         2, 3, Qt::AlignCenter);

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
   grdloutSimulationOutput->addWidget(lblMemAccessInstances,    0, 0, Qt::AlignCenter);
   grdloutSimulationOutput->addWidget(lcdMemAccessInstances,    1, 0, Qt::AlignCenter);
   grdloutSimulationOutput->addWidget(lblCompMissRatio,         0, 1, Qt::AlignCenter);
   grdloutSimulationOutput->addWidget(lcdCompMissRatio,         1, 1, Qt::AlignCenter);
   grdloutSimulationOutput->addWidget(lblHitRatio,              0, 2, Qt::AlignCenter);
   grdloutSimulationOutput->addWidget(lcdHitRatio,              1, 2, Qt::AlignCenter);
   grdloutSimulationOutput->addWidget(lblMissRatio,             0, 3, Qt::AlignCenter);
   grdloutSimulationOutput->addWidget(lcdMissRatio,             1, 3, Qt::AlignCenter);
   grdloutSimulationOutput->addWidget(lblReferenceWordSize,     2, 0, Qt::AlignCenter);
   grdloutSimulationOutput->addWidget(lcdReferenceWordSize,     3, 0, Qt::AlignCenter);
   grdloutSimulationOutput->addWidget(lblOffsetFieldSize,       2, 1, Qt::AlignCenter);
   grdloutSimulationOutput->addWidget(lcdOffsetFieldSize,       3, 1, Qt::AlignCenter);
   grdloutSimulationOutput->addWidget(lblIndexFieldSize,        2, 2, Qt::AlignCenter);
   grdloutSimulationOutput->addWidget(lcdIndexFieldSize,        3, 2, Qt::AlignCenter);
   grdloutSimulationOutput->addWidget(lblTagFieldSize,          2, 3, Qt::AlignCenter);
   grdloutSimulationOutput->addWidget(lcdTagFieldSize,          3, 3, Qt::AlignCenter);

   grpSimulationOutputControls->setLayout(grdloutSimulationOutput);

   // Organize Child Layouts
   loutMain->addWidget(grpSimulationTraceFileInput);
   loutMain->addWidget(grpSimulationInputControls);
   loutMain->addWidget(grpSimulationControls);
   loutMain->addWidget(grpSimulationOutputControls);
   loutMain->addWidget(quit, Qt::AlignCenter);
   loutMain->setAlignment(quit, Qt::AlignHCenter); 	// to align center the quit button horizontally

   // Parent Window Layout
   //window->setLayout(loutMain);

   dockCentralWidget->setLayout(loutMain);
   dockCentralWidget->setFixedWidth(560);
}
