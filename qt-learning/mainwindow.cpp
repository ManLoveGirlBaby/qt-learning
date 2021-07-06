#include <QtWidgets>

#include "mainwindow.h"
#include "arrowpaddialog.h"
#include "detailmainwindow.h"
#include "imageviewer.h"
#include "itemviewwindow.h"
#include "texteditorwindow.h"

MainWindow::MainWindow()
{
    setGeometry(100, 100, 250, 400);
    initView();
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
    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    detailMainBtn = createButton(tr("&MainWindow 探索"), SLOT(detailMainClick()));
    arrowPadBtn = createButton(tr(u8"方向面板"), SLOT(arrowPadClick()));
    imageViewerBtn = createButton(tr("&图片预览器"), SLOT(imageViewClick()));
    itemViewBtn = createButton("&ItemView 探索", SLOT(itemViewClick()));
    textEditorBtn = createButton("&记事本", SLOT(textEditorClick()));

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(detailMainBtn);
    mainLayout->addWidget(arrowPadBtn);
    mainLayout->addWidget(imageViewerBtn);
    mainLayout->addWidget(itemViewBtn);
    mainLayout->addWidget(textEditorBtn);
    mainLayout->addStrut(1);
    centralWidget->setLayout(mainLayout);
}

QPushButton *MainWindow::createButton(const QString &text, const char *member)
{
    QPushButton *button = new QPushButton(text, this);
    connect(button, SIGNAL(clicked()), this, member);
    return button;
}

void MainWindow::detailMainClick()
{
    detailMainWindow = new DetailMainWindow();
    detailMainWindow->setWindowTitle("MainWindow 探索");
    detailMainWindow->show();
}

void MainWindow::arrowPadClick()
{
    arrowPadDialog = new ArrowPadDialog();
    arrowPadDialog->setWindowTitle("方向面板");
    arrowPadDialog->show();
}

void MainWindow::imageViewClick()
{
    imageViewer = new ImageViewer();
    imageViewer->setWindowTitle("图片预览器");
    imageViewer->show();
}

void MainWindow::itemViewClick()
{
    itemViewWindow = new ItemViewWindow();
    itemViewWindow->setWindowTitle("ItemView 探索");
    itemViewWindow->show();
}

void MainWindow::textEditorClick()
{
    textEditorWindow = new TextEditorWindow();
    textEditorWindow->setWindowTitle("记事本");
    textEditorWindow->show();
}
