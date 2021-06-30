#include <QtWidgets>

#include "detailmainwindow.h"

DetailMainWindow::DetailMainWindow()
{
    setGeometry(100, 100, 500, 800);

    // Menu Bar
    QAction *exitAct = new QAction(tr("E&xit"), this);
    exitAct->setShortcuts(QKeySequence::Quit);
    connect(exitAct, SIGNAL(triggered()), this, SLOT(close()));

    QMenu *menuBar1 = menuBar()->addMenu(tr("&Menu Bar"));
    menuBar1->addAction(exitAct);

    // Central Widget
    QWidget *centralWidget = new QWidget();
    setCentralWidget(centralWidget);

    QLabel *label = new QLabel();
    label->setText("Hello World!");
    label->setFont(QFont("Timers", 28, QFont::Bold));

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(label);
    centralWidget->setLayout(mainLayout);

    // Toolbars
    QAction *openAction = new QAction(tr("&Open"),this);
    QToolBar *fileToolBar = new QToolBar;  //创建一个工具栏
    fileToolBar = addToolBar(tr("&File"));  //添加工具栏到顶层窗口中
    fileToolBar->addAction(openAction);
    this->addToolBar(fileToolBar);

    // Dock Widgets
    QDockWidget *dock = new QDockWidget();
    dock->setWidget(centralWidget);
    this->addDockWidget(Qt::LeftDockWidgetArea, dock);

    // StatusBar
    QLabel *msgLabel = new QLabel();
    msgLabel->setText("Status Bar");
    msgLabel->setMinimumSize(msgLabel->sizeHint());
    msgLabel->setAlignment(Qt::AlignHCenter);
    statusBar()->addWidget(msgLabel);
}
