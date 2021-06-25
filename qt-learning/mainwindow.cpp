#include <QtWidgets>

#include "mainwindow.h"

MainWindow::MainWindow()
{
    setGeometry(100, 100, 500, 800);
    initView();
}

MainWindow::~MainWindow()
{
    delete exitAct;
    delete settingMenu;
}

void MainWindow::initView()
{
    exitAct = new QAction(tr("E&xit"), this);
    exitAct->setShortcuts(QKeySequence::Quit);
    connect(exitAct, SIGNAL(triggered()), this, SLOT(close()));

    settingMenu = menuBar()->addMenu(tr("&Setting"));
    settingMenu->addAction(exitAct);
}
