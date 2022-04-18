#include "apartment.h"

Apartment::Apartment()
{

}

void Apartment::setID(const QString ID)
{
    id = ID;
}
void Apartment::setCityDistrict(const QString CityDistrict)
{
    district = CityDistrict;
}
void Apartment::setRoomNumber(const QString Floor)
{
    floor = Floor;
}
void Apartment::setFloor(const QString RoomNumber)
{
    room = RoomNumber;
}
void Apartment::setWallMaterial(const QString WallMaterial)
{
    material = WallMaterial;
}
void Apartment::setArea(const QString Area)
{
    area = Area;
}

QString Apartment::getID() const
{
    return id;
}
QString Apartment::getCityDistrict() const
{
    return district;
}
QString Apartment::getRoomNumber() const
{
    return floor;
}
QString Apartment::getFloor() const
{
    return room;
}
QString Apartment::getWallMaterial() const
{
    return material;
}
QString Apartment::getArea() const
{
    return area;
}

 Apartment::~Apartment()
{
}
