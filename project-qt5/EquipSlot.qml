import QtQuick 2.3
import QtQuick.Controls 1.2
import QtQuick.Controls.Styles 1.2

Rectangle {
    id: equipSlot
    width: parent.width/7
    height: parent.height/7
    color: "black"
    //border.color: "green"
    property int index

    signal displayItem(string type);
    signal itemSelected()

    MouseArea {
        anchors.fill: parent
        onClicked: {
            itemSelected() }
    }

    Image {
        id: slotImage
        anchors.fill: parent
        source: ""
        fillMode: Image.Stretch
        cache: false

        Connections {
            target: equipSlot
            onDisplayItem:{
                if (type === "helm"){
                    slotImage.source = "../img/iron_helm.png"}
                else if (type === "chest piece"){
                    slotImage.source = "../img/iron_chest.png"}
                else if (type === "greaves"){
                    slotImage.source = "../img/iron_greaves.png"}
                else if (type === "boots"){
                    slotImage.source = "../img/iron_boots.png"}
                else if (type === "shield"){
                    slotImage.source = "../img/shield.gif"}
                else if (type === "sword"){
                    slotImage.source = "../img/sword.png"}
                else if (type === "axe"){
                    slotImage.source = "../img/axe.png"}
                else if (type === "mace"){
                    slotImage.source = "../img/mace.png"}
                else if (type === "none"){
                    slotImage.source = ""}
            }
        }
    }
}
