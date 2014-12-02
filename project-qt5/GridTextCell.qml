import QtQuick 2.3
import QtQuick.Controls 1.2
import QtQuick.Controls.Styles 1.2

Rectangle {
    id: gridTextCell
    width: parent.width/3
    height: parent.height/3
    color: "black"
    border.width: 1
    border.color: "darkgoldenrod"
    property int position

    signal displayText(string text);
    signal cellSelected()

    MouseArea {
        anchors.fill: parent
        onClicked: {
            cellSelected() }
    }


    Text {
        id: cellTextBox
        width: parent.width
        height: parent.height
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        font.pointSize: 15
        color: "green"
        text: ""

        Connections {
            target: gridTextCell
            onDisplayText: {
                cellTextBox.text = text
            }
        }
    }
}
