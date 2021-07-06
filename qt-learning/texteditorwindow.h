#ifndef TEXTEDITOR_H
#define TEXTEDITOR_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QTextEdit>

class TextEditorWindow : public QMainWindow
{
    Q_OBJECT
public:
    TextEditorWindow();
protected:
    void closeEvent(QCloseEvent *event) override;
private:
    QTextEdit *textEdit;

    void initData();
    void initView();

    bool isHasFile();
    void createFile();
    bool saveFile();
    QString readFile();
    QString getFilePath();
};

#endif // TEXTEDITOR_H
