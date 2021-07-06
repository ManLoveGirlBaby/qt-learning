#ifndef CARMODEL_H
#define CARMODEL_H

#include <QObject>

class CarModel
{
public:
    CarModel();
    CarModel(QString name, QString info);

    void setCarName(QString name);
    QString getCarName();
    void setCarInfo(QString info);
    QString getCarInfo();

private:
    QString carName;
    QString carInfo;

};

#endif // CARMODEL_H
