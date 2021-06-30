#include <QtWidgets>

#include "arrowpaddialog.h"

ArrowPadDialog::ArrowPadDialog()
{
//    隐藏窗口标题栏
//    setWindowFlags(Qt::CustomizeWindowHint|Qt::WindowStaysOnTopHint);

    upBtn = createButton(tr("&Up"), SLOT(upClicked()));
    downBtn = createButton(tr("&Down"), SLOT(downClicked()));
    leftBtn = createButton(tr("&Left"), SLOT(leftClicked()));
    rightBtn = createButton(tr("&Right"), SLOT(rightClicked()));

    QGridLayout *mainLayout = new QGridLayout;
    mainLayout->addWidget(upBtn, 0, 1);
    mainLayout->addWidget(leftBtn, 1, 0);
    mainLayout->addWidget(rightBtn, 1, 2);
    mainLayout->addWidget(downBtn, 2, 1);
    setLayout(mainLayout);

    currentX = this->x();
    currentY = this->y();
}

ArrowPadDialog::~ArrowPadDialog()
{
    delete upBtn;
    delete downBtn;
    delete leftBtn;
    delete rightBtn;
}

QPushButton *ArrowPadDialog::createButton(const QString &text, const char *member)
{
    QPushButton *button = new QPushButton(text);
    connect(button, SIGNAL(clicked()), this, member);
    return button;
}

void ArrowPadDialog::upClicked() {
    currentY -= 10;
    move(currentX, currentY);
}

void ArrowPadDialog::downClicked() {
    currentY += 10;
    move(currentX, currentY);
}

void ArrowPadDialog::leftClicked() {
    currentX -= 10;
    move(currentX, currentY);
}

void ArrowPadDialog::rightClicked() {
    currentX += 10;
    move(currentX, currentY);
}
