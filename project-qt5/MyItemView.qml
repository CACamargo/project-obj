import QtQuick 2.0

Rectangle {
    id: itemView
    width: parent.width/2
    height: parent.height/2
    anchors {right: parent.right}
    color:"black"
    border.color: "darkgoldenrod"
    property int itemRow
    property int itemColumn

    signal equipItemRequest(int row, int column)
    signal requestEquippedItemInfo(int index)
    signal useItemRequest(int row, int column)
    signal discardItemRequest(int row, int column)

    Connections {
        target: mainWindow
        onRelayItemInfo:{
            itemDescriptionBox.text = info;
            itemView.itemRow = row
            itemView.itemColumn = column
            if (type != "none" && type != "health potion" && type != "mana potion"){
                equipButton.visible = true
                discardButton.visible = true
                useItemButton.visible = false
            }
            else if (type === "health potion" || type === "mana potion"){
                equipButton.visible = false
                discardButton.visible = true
                useItemButton.visible = true
            }
            else{
                equipButton.visible = false
                discardButton.visible = false
                useItemButton.visible = false
            }
        }
        onRelayEquippedItemInfo:{
            itemDescriptionBox.text = info;
            equipButton.visible = false
            discardButton.visible = false
        }
    }

    Connections {
        target: equipButton
        onClicked:{
            itemView.equipItemRequest(itemView.itemRow, itemView.itemColumn)
        }
    }

    Connections {
        target: discardButton
        onClicked:{
            itemView.discardItemRequest(itemView.itemRow, itemView.itemColumn)
        }
    }

    Connections {
        target: useItemButton
        onClicked:{
            itemView.useItemRequest(itemView.itemRow, itemView.itemColumn)
        }
    }

    Text {
        id: itemDescriptionBox
        width: parent.width
        height: parent.height/2
        text: ""
        font.pointSize: 20
        color: "green"
    }

    Rectangle {
        id: itemViewButtonBox
        width: parent.width
        height: parent.height/5
        anchors {bottom: parent.bottom}
        color: "black"
        border.color: "darkgoldenrod"

        CustomButton {
            id: equipButton
            anchors {
                left: parent.left
                bottom: parent.bottom
                verticalCenter: parent.verticalCenter
                leftMargin: parent.width/6
            }
            text: "EQUIP"
            visible: false
        }

        CustomButton {
            id: discardButton
            anchors {
                right: parent.right
                bottom: parent.bottom
                verticalCenter: parent.verticalCenter
                rightMargin: parent.width/6
            }
            text: "DISCARD"
            visible: false
        }

        CustomButton {
            id: useItemButton
            anchors {
                left: parent.left
                bottom: parent.bottom
                verticalCenter: parent.verticalCenter
                leftMargin: parent.width/6
            }
            text: "USE"
            visible: false
        }
    }
}
