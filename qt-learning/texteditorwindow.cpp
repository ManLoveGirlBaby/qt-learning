#include <QWidget>
#include <QDir>
#include <QFile>
#include <QTextStream>
#include "texteditorwindow.h"

TextEditorWindow::TextEditorWindow()
{
    setGeometry(100, 100, 250, 400);
    initView();
    initData();
}

void TextEditorWindow::initView()
{
    textEdit = new QTextEdit(this);
    QPalette pe;
    pe.setColor(QPalette::Window, Qt::white);
    textEdit->setAutoFillBackground(true);
    textEdit->setPalette(pe);
    setCentralWidget(textEdit);
}

void TextEditorWindow::initData()
{
    if (!isHasFile()) {
        // 没有->创建
        createFile();
    }
    textEdit->setText(readFile());
}

bool TextEditorWindow::isHasFile()
{
    QFile *file = new QFile(getFilePath());
    if (!file->exists()) {
        return false;
    } else {
        return true;
    }
}

void TextEditorWindow::createFile()
{
    QFile *file = new QFile(getFilePath());
    file->open(QIODevice::WriteOnly | QIODevice::Text);
    file->close();
}

bool TextEditorWindow::saveFile()
{
    QFile *file = new QFile(getFilePath());
    file->open(QIODevice::WriteOnly | QIODevice::Text);
    //写入文件需要字符串为QByteArray格式
    QString context = textEdit->toPlainText();
    file->write(context.toUtf8());
    file->close();
}

QString TextEditorWindow::readFile()
{
    QFile *file = new QFile(getFilePath());
    file->open(QIODevice::ReadOnly | QIODevice::Text);

    //使用QTextStream一行一行读取文件
    QString context = "";
    QTextStream *in = new QTextStream(file);
    while (!in->atEnd())
    {
        context += in->readLine();      //整行读取
    }
    file->close();
    return context;
}

QString TextEditorWindow::getFilePath()
{
    QString curPath = QDir::currentPath(); // 获取系统当前目录
    QString fileName = "qt_learning.txt";
    return curPath + "/" + fileName;
}

void TextEditorWindow::closeEvent(QCloseEvent *event)
{
    saveFile();
}
