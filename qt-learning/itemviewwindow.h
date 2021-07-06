#ifndef ITEMVIEWWINDOW_H
#define ITEMVIEWWINDOW_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QVector>

class QTreeView;
class QStandardItemModel;
class QStandardItem;
class CarModel;

class ItemViewWindow : public QMainWindow
{
    Q_OBJECT
public:
    ItemViewWindow();

private:
    QTreeView *treeView;
    QVector<CarModel *> carDatas;
    QStandardItemModel *itemModel;

    void initView();
    void initData();

private slots:

};

#endif // ITEMVIEWWINDOW_H
