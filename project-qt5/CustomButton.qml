import QtQuick 2.3
import QtQuick.Controls 1.2
import QtQuick.Controls.Styles 1.2

Button {
    style: ButtonStyle{
        background: Rectangle {
            implicitWidth: 100
            implicitHeight: 25
            border.width: control.activeFocus ? 2 : 1
            border.color: "darkgoldenrod"
            radius: 4
            gradient: Gradient {
                GradientStop { position: 0 ; color: control.pressed ? "dimgrey" : "black" }
                GradientStop { position: 1 ; color: control.pressed ? "black" : "dimgrey" }
            }
        }
        label: Text {
            renderType: Text.NativeRendering
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            font.family: "Helvetica"
            font.pointSize: 20
            color: "gold"
            text: control.text
        }
    }
}
