#include <QtWidgets>

#include "mainwindow.h"
#include "arrowpaddialog.h"
#include "detailmainwindow.h"

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
    // Menu Bar
    exitAct = new QAction(tr("E&xit"), this);
    exitAct->setShortcuts(QKeySequence::Quit);
    connect(exitAct, SIGNAL(triggered()), this, SLOT(close()));

    settingMenu = menuBar()->addMenu(tr("&Setting"));
    settingMenu->addAction(exitAct);

    // Central Widget
    QWidget *centralWidget = new QWidget();
    setCentralWidget(centralWidget);

    detailMainBtn = createButton(tr("&Detail MainWindows"), SLOT(detailMainClick()));
    arrowPadBtn = createButton(tr("&Arrow Pad"), SLOT(arrowPadClick()));

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(detailMainBtn);
    mainLayout->addWidget(arrowPadBtn);
    centralWidget->setLayout(mainLayout);
}

QPushButton *MainWindow::createButton(const QString &text, const char *member)
{
    QPushButton *button = new QPushButton(text);
    connect(button, SIGNAL(clicked()), this, member);
    return button;
}

void MainWindow::arrowPadClick()
{
    arrowPadDialog = new ArrowPadDialog();
    arrowPadDialog->show();
}

void MainWindow::detailMainClick() {
    detailMainWindow = new DetailMainWindow();
    detailMainWindow->show();
}
