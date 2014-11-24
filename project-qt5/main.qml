import QtQuick 2.3
import QtQuick.Window 2.2
import QtQuick.Controls 1.2
import QtQuick.Controls.Styles 1.2

Window {
    id: topView
    visible: true
    width: 1024
    height: 768

    SystemPalette { id: activePalette }

    Rectangle {
        id : userCommands
        width: parent.width
        height: parent.height/5

        anchors { bottom: parent.bottom }

        Image {
            id: commandTex
            anchors.fill: parent
            source: "../img/wall.jpg"
            fillMode: Image.Stretch
        }

        CtButton {
            id: useButton
            anchors {
                left: parent.left
                verticalCenter: parent.verticalCenter
                leftMargin: parent.width/7
            }
            text: "USE"
        }

        CtButton {
            id: talkButton
            anchors {
                left: useButton.right
                verticalCenter: parent.verticalCenter
                leftMargin: parent.width/13
            }
            text: "TALK"
        }

        CtButton {
            id: invButton
            anchors {
                left: talkButton.right
                verticalCenter: parent.verticalCenter
                leftMargin: parent.width/13
            }
            text: "INVENTORY"            
        }

        CtButton {
            objectName: "statusButton"
            id: statusButton
            anchors {
                left: invButton.right
                verticalCenter: parent.verticalCenter
                leftMargin: parent.width/13
            }
            text: "STATUS"            
        }
    }

    Item {
        objectName: "mainWindow"
        id: mainWindow
        width: parent.width
        focus: true
        anchors {
            top: parent.top
            bottom: userCommands.top
        }
        signal move(string direction)
        signal changeImage(string newID)
        Keys.onUpPressed: {mainWindow.move("forward")}
        Keys.onLeftPressed: {mainWindow.move("left")}

        /*MouseArea {
           hoverEnabled: false
           anchors.fill: parent
           onClicked: {
               mainWindow.move("forward")
           }
       }*/

        function updateImage(newID){
            if (newID === "corridor")
                mainWindow.changeImage("../img/corridor.jpg")
            if (newID === "cave")
                mainWindow.changeImage("../img/cave.jpg")
        }

        Image {
            id: background
            anchors.fill: parent
            source: "../img/corridor.jpg"
            fillMode: Image.Stretch
            cache: false

            Connections {
             target: mainWindow
             onChangeImage: {background.source = newID}
            }

            Image {
                id: sprite
                anchors.centerIn: parent
                source: ""
                //source: "../img/sprite.gif"
                fillMode: Image.PreserveAspectFit
            }
        }
    }
}
