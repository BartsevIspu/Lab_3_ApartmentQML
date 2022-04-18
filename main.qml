import QtQuick 6.0
import QtQuick.Window 6.0
import QtQuick.Controls 6.0// это версия библиотеки, содержащей Contol (аналоги виджетов) для версии Qt 5.6
import QtQuick.Layouts 6.0

Window {
    visible: true
    width: 800
    height: 550
    title: qsTr("Каталог квартир риелтора")

    // объявляется системная палитра
    SystemPalette {
          id: palette;
          colorGroup: SystemPalette.Active
       }

    Rectangle{
        anchors.left: parent.left
        anchors.top: parent.top
        anchors.right: parent.right
        anchors.bottom: butAdd.top
        anchors.bottomMargin: 8
        //border.color: "SteelBlue"


    ScrollView {
        anchors.fill: parent
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 15
        //flickableItem.interactive: true   // сохранять свойство "быть выделенным" при потере фокуса мыши

        ListView {
            id: apList
            anchors.fill: parent
            model: apartmentModel           // назначение модели, данные которой отображаются списком
            delegate: DelegateForAp{}
            clip: true
            activeFocusOnTab: true          // реагирование на перемещение между элементами ввода с помощью Tab
            focus: true                     // элемент может получить фокус
        }
    }
    }

    Button {
        id: butAdd
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 8
        anchors.rightMargin: 8
        anchors.right:butEdit.left
        text: "Добавить"
        width: 100
        onClicked: windowAdd.show()
    }

    Button {
        id: butEdit
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 8
        anchors.right: butDel.left
        anchors.rightMargin: 8
        text: "Редактировать"
        width: 100
        onClicked: {
            var districtAp = apList.currentItem.apartmentData.districtOfAp
            var roomAp = apList.currentItem.apartmentData.roomOfAp
            var floorAp = apList.currentItem.apartmentData.floorOfAp
            var materialAp = apList.currentItem.apartmentData.materialOfAp
            var areaAp = apList.currentItem.apartmentData.areaOfAp

            windowEdit.execute(districtAp, roomAp, floorAp, materialAp, areaAp, apList.currentIndex)
        }
    }

    Button {
        id: butDel
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 8
        anchors.right:parent.right
        anchors.rightMargin: 8
        text: "Удалить"
        width: 100
        enabled: apList.currentIndex >= 0
        onClicked: del(apList.currentIndex)
    }

        Label {
            id: labelArea1
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 12
            anchors.left: parent.left
            //anchors.right: butAdd.left
            anchors.rightMargin: 8
            anchors.leftMargin: 8
            Layout.alignment: Qt.AlignRight  // выравнивание по правой стороне
            text: qsTr("Введите искомую площадь квартиры:")
        }
        TextField {
            id: textSelArea
            Layout.fillWidth: true
            placeholderText: qsTr("")
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 10
            anchors.leftMargin: 8
            anchors.left: labelArea1.right
            anchors.rightMargin: 8
        }
        Button {
            id: butCount
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 8
            //anchors.right:parent.right
            anchors.left: textSelArea.right
            anchors.leftMargin: 8
            text: "Подсчитать"
            width: 100
            enabled: textSelArea.text != ""
            onClicked: windowAnswer.countApartments(textSelArea.text)
        }

    DialogForAdd {
        id: windowAdd
    }
    DialogForEdit {
        id: windowEdit
    }
    DialogForAnswer {
        id: windowAnswer
    }
}

