#include "apartmentlist.h"
#include <QDebug>
#include <QMessageBox>
#include <QWidget>
#include <QApplication>

ApartmentList::ApartmentList(QObject* parent):QAbstractListModel(parent)
{
    add("Фрунзенский", "4", "4", "Красный кирпич", "48");
    add("Ленинский", "3", "9", "Гипсокартон", "34");
    add("Третий", "3", "1", "Древесина", "40");
}

ApartmentList::~ApartmentList()
{

}

int ApartmentList::rowCount(const QModelIndex&) const
{
    return listOfApartments.size();
}


QVariant ApartmentList::data(const QModelIndex &index, int role) const
{
    if (index.row() < 0 || index.row() >= listOfApartments.size())
            return QVariant();
      {
        switch (role) {
                case district:
                    return QVariant(listOfApartments.at(index.row()).getCityDistrict());
                case room:
                    return QVariant(listOfApartments.at(index.row()).getRoomNumber());
                case floor:
                    return QVariant(listOfApartments.at(index.row()).getFloor());
                case material:
                    return QVariant(listOfApartments.at(index.row()).getWallMaterial());
                case area:
                    return QVariant(listOfApartments.at(index.row()).getArea());

                default:
                    return QVariant();
            }

    }
}

QHash<int, QByteArray> ApartmentList::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[district] = "districtOfAp";
    roles[room] = "roomOfAp";
    roles[floor] = "floorOfAp";
    roles[material] = "materialOfAp";
    roles[area] = "areaOfAp";
       return roles;
}

void ApartmentList::add(const QString& districtAp, const QString& floorAp, const QString& roomAp, const QString& materialAp, const QString& areaAp){
     Apartment ap;
     ap.setCityDistrict(districtAp);
     ap.setFloor(floorAp);
     ap.setRoomNumber(roomAp);
     ap.setWallMaterial(materialAp);
     ap.setArea(areaAp);

    beginInsertRows(QModelIndex(),listOfApartments.size(),listOfApartments.size());
    listOfApartments.append(ap);  //добавление в конец списка
    endInsertRows();

}

QAbstractListModel* ApartmentList::getModel(){
    return this;
}

void ApartmentList::del(const int index){

     if (index >= 0 && index < listOfApartments.size())
     {

    // сообщение модели о процессе удаления данных
         beginRemoveRows(QModelIndex(), index, index);
        listOfApartments.removeAt(index);
              endRemoveRows();
     }
     else qDebug() << "Error index";

}

QString ApartmentList::count(const QString& textSelArea){
    int count = 0;
    for(int i = 0; i < listOfApartments.size(); i++)
        if(listOfApartments[i].getArea().toInt() > textSelArea.toInt())
            count++;
    QString c = QString::number(count);
    return c;
}

void ApartmentList::edit(const QString& districtAp, const QString& floorAp, const QString& roomAp, const QString& materialAp, const QString& areaAp, const int index) {
     if (index >= 0 && index < listOfApartments.size() )
     {
        auto& currentRiver = listOfApartments[index];
        if (currentRiver.getCityDistrict().compare(districtAp)!= 0 || currentRiver.getFloor() != floorAp || currentRiver.getRoomNumber() != roomAp
                || currentRiver.getWallMaterial() != materialAp || currentRiver.getArea() != areaAp)
        {
            currentRiver.setCityDistrict(districtAp);
            currentRiver.setFloor(floorAp);
            currentRiver.setRoomNumber(roomAp);
            currentRiver.setWallMaterial(materialAp);
            currentRiver.setArea(areaAp);

            auto modelIndex = createIndex(index, 0);
            emit dataChanged(modelIndex, modelIndex);
            qDebug() << listOfApartments[index].getArea();
        }

     }
      else qDebug() << "Error index";
}
