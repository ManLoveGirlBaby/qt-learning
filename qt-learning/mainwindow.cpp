#include <QtWidgets>

#include "mainwindow.h"
#include "arrowpaddialog.h"

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

    QWidget *centralWidget = new QWidget();
    setCentralWidget(centralWidget);

    arrowPadBtn = createButton(tr("&Arrow Pad"), SLOT(arrowPadClick()));

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(arrowPadBtn);
    centralWidget->setLayout(mainLayout);

}

QPushButton *MainWindow::createButton(const QString &text, const char *member)
{
    QPushButton *button = new QPushButton(text);
    connect(button, SIGNAL(clicked()), this, member);
    return button;
}

void MainWindow::arrowPadClick() {
    arrowPadDialog = new ArrowPadDialog();
    arrowPadDialog->show();
}
