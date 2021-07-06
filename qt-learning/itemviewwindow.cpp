#include <QtWidgets>

#include "itemviewwindow.h"
#include "carmodel.h"

ItemViewWindow::ItemViewWindow()
{
    setGeometry(100, 100, 300, 300);
    initView();
    initData();
}

void ItemViewWindow::initView()
{
    itemModel = new QStandardItemModel(this);
    itemModel->setHorizontalHeaderLabels(QStringList()<<QStringList("车名")<<QStringList("信息"));

    treeView = new QTreeView(this);
//    treeView->header()->hide();
    treeView->setModel(itemModel);
    setCentralWidget(treeView);
}

void ItemViewWindow::initData()
{
    CarModel *model = new CarModel();
    model->setCarName("奔驰");
    model->setCarInfo("德国");
    CarModel *model1 = new CarModel();
    model1->setCarName("宝马");
    model1->setCarInfo("德国");
    carDatas.append(model);
    carDatas.append(model1);

    foreach(CarModel *carModel, carDatas) {
        QStandardItem *itemName = new QStandardItem();
        itemName->setText(carModel->getCarName());
        QStandardItem *itemInfo = new QStandardItem();
        itemInfo->setText(carModel->getCarInfo());
        QList<QStandardItem *> items = {itemName, itemInfo};
//        item->setData(carModel);
        itemModel->appendRow(items);
    }
}
