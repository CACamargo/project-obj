import QtQuick 2.0

Item {
    id: mainWindow
    width: parent.width
    anchors {
        top: parent.top
        bottom: userCommands.top
    }

    Image {
        id: background
        anchors.fill: parent
        source: "../img/corridor.jpg"
        fillMode: Image.Stretch

        Image {
            id: sprite
            anchors.centerIn: parent
            source: "../img/sprite.gif"
            fillMode: Image.PreserveAspectFit
        }
    }
}
