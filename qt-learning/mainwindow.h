#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
class QAction;
class QMenu;
class QPushButton;
QT_END_NAMESPACE
class ArrowPadDialog;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();
    ~MainWindow();

private:
    QAction *exitAct;
    QMenu *settingMenu;
    QPushButton *arrowPadBtn;
    ArrowPadDialog *arrowPadDialog;

    void initView();
    QPushButton *createButton(const QString &text, const char *member);

private slots:
    void arrowPadClick();

};
#endif // MAINWINDOW_H
