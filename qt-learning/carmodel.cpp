#include "carmodel.h"

CarModel::CarModel()
{

}

CarModel::CarModel(QString name, QString info)
{
    carName = name;
    carInfo = info;
}

void CarModel::setCarName(QString name)
{
   carName = name;
}

QString CarModel::getCarName()
{
    return carName;
}

void CarModel::setCarInfo(QString info)
{
    carInfo = info;
}

QString CarModel::getCarInfo()
{
    return carInfo;
}
