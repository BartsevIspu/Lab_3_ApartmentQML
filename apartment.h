#ifndef APARTMENT_H
#define APARTMENT_H
#include "QString"
//#include <QObject>

class Apartment /*public QObject*/
{
    //Q_OBJECT

public:
    Apartment();
    virtual ~Apartment();
    void setID(const QString ID);
    void setCityDistrict(const QString CityDistrict);
    void setRoomNumber(const QString RoomNumber);
    void setFloor(const QString Floor);
    void setWallMaterial(const QString WallMaterial);
    void setArea(const QString Area);

    QString getID() const;
    QString getCityDistrict() const;
    QString getRoomNumber() const;
    QString getFloor() const;
    QString getWallMaterial() const;
    QString getArea() const;

private:
    QString id;
    QString district;
    QString room;
    QString floor;
    QString material;
    QString area;
};

#endif // APARTMENT_H
