import QtQuick 2.3
import QtQuick.Controls 1.2
import QtQuick.Controls.Styles 1.2

Rectangle {
    id: gridCell
    width: parent.width/10
    height: parent.height/2
    color: "black"
    border.width: 1
    border.color: "darkgoldenrod"
    property int row
    property int column

    signal displayItem(string type);
    signal itemSelected()

    MouseArea {
        anchors.fill: parent
        onClicked: {
            itemSelected() }
    }

    Image {
        id: cellImage
        anchors.centerIn: parent
        source: ""
        fillMode: Image.PreserveAspectFit
        cache: false        

        Connections {
            target: gridCell
            onDisplayItem:{
                if (type === "helm"){
                    cellImage.source = "../img/iron_helm.png"}
                else if (type === "chest piece"){
                    cellImage.source = "../img/iron_chest.png"}
                else if (type === "greaves"){
                    cellImage.source = "../img/iron_greaves.png"}
                else if (type === "boots"){
                    cellImage.source = "../img/iron_boots.png"}
                else if (type === "shield"){
                    cellImage.source = "../img/shield.gif"}
                else if (type === "sword"){
                    cellImage.source = "../img/sword.png"}
                else if (type === "axe"){
                    cellImage.source = "../img/axe.png"}
                else if (type === "mace"){
                    cellImage.source = "../img/mace.png"}
                else if (type === "health potion"){
                    cellImage.source = "../img/health.png"}
                else if (type === "mana potion"){
                    cellImage.source = "../img/mana.png"}
                else if (type === "none"){
                    cellImage.source = ""}
            }
        }
    }
}
