#ifndef ARROWPADDIALOG_H
#define ARROWPADDIALOG_H

#include <QDialog>

class ArrowPadDialog : public QDialog
{
    Q_OBJECT

public:
    ArrowPadDialog();
    ~ArrowPadDialog();

private:
    int currentX = 0;
    int currentY = 0;

    QPushButton *upBtn;
    QPushButton *downBtn;
    QPushButton *leftBtn;
    QPushButton *rightBtn;

    QPushButton *createButton(const QString &text, const char *member);

private slots:
    void leftClicked();
    void rightClicked();
    void upClicked();
    void downClicked();

};

#endif // ARROWPADDIALOG_H
