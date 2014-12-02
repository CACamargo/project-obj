import QtQuick 2.0

Rectangle {
    id: equipView
    width: parent.width/2
    height: parent.height/2
    anchors {left: parent.left}
    color:"black"
    border.color: "darkgoldenrod"

    signal sendEquipPosition(int index)

    Connections {
        target: mainWindow
        onRelayEquipType:{
            equipView.receiveEquipType(position,type)
        }
    }

    function receiveEquipType(position, type){
        if (position === 1)
            slot_1.displayItem(type);
        else if (position ===2)
            slot_2.displayItem(type);
        else if (position ===3)
            slot_3.displayItem(type);
        else if (position ===4)
            slot_4.displayItem(type);
        else if (position ===5)
            slot_5.displayItem(type);
        else if (position ===6)
            slot_6.displayItem(type);
    }

    EquipSlot {
        id: slot_1
        index: 0
        anchors {
            top: equipView.top
            horizontalCenter: parent.horizontalCenter
            topMargin: parent.height/11
        }
    }
    EquipSlot {
        id: slot_2
        index: 1
        anchors {
            top: slot_1.bottom
            horizontalCenter: parent.horizontalCenter
            topMargin: parent.height/11
        }
    }
    EquipSlot {
        id: slot_3
        index: 2
        anchors {
            top: slot_2.bottom
            horizontalCenter: parent.horizontalCenter
            topMargin: parent.height/11
        }
    }
    EquipSlot {
        id: slot_4
        index: 3
        anchors {
            top: slot_3.bottom
            horizontalCenter: parent.horizontalCenter
            topMargin: parent.height/11
        }
    }
    EquipSlot {
        id: slot_5
        index: 4
        height: parent.height/4
        anchors {
            left: parent.left
            leftMargin: parent.width/7
            verticalCenter: parent.verticalCenter
        }
    }
    EquipSlot {
        id: slot_6
        index: 5
        height: parent.height/4
        anchors {
            right: parent.right
            rightMargin: parent.width/7
            verticalCenter: parent.verticalCenter
        }
    }

    Connections {
        target: slot_1
        onItemSelected: {equipView.sendEquipPosition(slot_1.index)}
    }
    Connections {
        target: slot_2
        onItemSelected: {equipView.sendEquipPosition(slot_2.index)}
    }
    Connections {
        target: slot_3
        onItemSelected: {equipView.sendEquipPosition(slot_3.index)}
    }
    Connections {
        target: slot_4
        onItemSelected: {equipView.sendEquipPosition(slot_4.index)}
    }
    Connections {
        target: slot_5
        onItemSelected: {equipView.sendEquipPosition(slot_5.index)}
    }
    Connections {
        target: slot_6
        onItemSelected: {equipView.sendEquipPosition(slot_6.index)}
    }
}
