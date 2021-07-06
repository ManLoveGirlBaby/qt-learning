#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
class QAction;
class QMenu;
class QPushButton;
QT_END_NAMESPACE

class ArrowPadDialog;
class DetailMainWindow;
class ImageViewer;
class ItemViewWindow;
class TextEditorWindow;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();

private:
    QAction *exitAct;
    QMenu *settingMenu;

    QPushButton *detailMainBtn;
    QPushButton *arrowPadBtn;
    QPushButton *imageViewerBtn;
    QPushButton *itemViewBtn;
    QPushButton *textEditorBtn;

    DetailMainWindow *detailMainWindow;
    ArrowPadDialog *arrowPadDialog;
    ImageViewer *imageViewer;
    ItemViewWindow *itemViewWindow;
    TextEditorWindow *textEditorWindow;

    void initView();
    QPushButton *createButton(const QString &text, const char *member);

private slots:
    void detailMainClick();
    void arrowPadClick();
    void imageViewClick();
    void itemViewClick();
    void textEditorClick();
};
#endif // MAINWINDOW_H
