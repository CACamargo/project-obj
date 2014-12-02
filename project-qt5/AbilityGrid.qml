import QtQuick 2.0

Rectangle {
    id: abilityView
    width: parent.width
    height: parent.height
    color:"black"
    border.color: "darkgoldenrod"

    signal sendAbilityPosition(int position)

    Connections {
        target: mainWindow
        onRelayAbilityInfo:{
            abilityView.receiveAbilityInfo(position,info)
        }
    }

    function receiveAbilityInfo(position, info){
        if (position === 1)
            cell_1.displayText(info);
        else if (position ===2)
            cell_2.displayText(info);
        else if (position ===3)
            cell_3.displayText(info);
        else if (position ===4)
            cell_4.displayText(info);
        else if (position ===5)
            cell_5.displayText(info);
        else if (position ===6)
            cell_6.displayText(info);
        else if (position ===7)
            cell_7.displayText(info);
        else if (position ===8)
            cell_8.displayText(info);
        else if (position ===9)
            cell_9.displayText(info);
    }

    GridTextCell {
        id: cell_1
        position: 1
        anchors {top:parent.top; left: parent.left}
    }
    GridTextCell {
        id: cell_2
        position: 2
        anchors {left:cell_1.right}
    }
    GridTextCell {
        id: cell_3
        position: 3
        anchors {left:cell_2.right}
    }
    GridTextCell {
        id: cell_4
        position: 4
        anchors {verticalCenter: parent.verticalCenter; left:parent.left}
    }
    GridTextCell {
        id: cell_5
        position: 5
        anchors {verticalCenter: parent.verticalCenter; left:cell_4.right}
    }
    GridTextCell {
        id: cell_6
        position: 6
        anchors {verticalCenter: parent.verticalCenter; left:cell_5.right}
    }
    GridTextCell {
        id: cell_7
        position: 7
        anchors {bottom: parent.bottom; left:parent.left}
    }
    GridTextCell {
        id: cell_8
        position: 8
        anchors {bottom: parent.bottom; left:cell_7.right}
    }
    GridTextCell {
        id: cell_9
        position: 9
        anchors {bottom: parent.bottom; left:cell_8.right}
    }

    //Upper cell connections
    Connections {
        target: cell_1
        onCellSelected: {abilityView.sendAbilityPosition(cell_1.position)}
    }
    Connections {
        target: cell_2
        onCellSelected: {abilityView.sendAbilityPosition(cell_2.position)}
    }
    Connections {
        target: cell_3
        onCellSelected: {abilityView.sendAbilityPosition(cell_3.position)}
    }
    Connections {
        target: cell_4
        onCellSelected: {abilityView.sendAbilityPosition(cell_4.position)}
    }
    Connections {
        target: cell_5
        onCellSelected: {abilityView.sendAbilityPosition(cell_5.position)}
    }
    Connections {
        target: cell_6
        onCellSelected: {abilityView.sendAbilityPosition(cell_6.position)}
    }
    Connections {
        target: cell_7
        onCellSelected: {abilityView.sendAbilityPosition(cell_7.position)}
    }
    Connections {
        target: cell_8
        onCellSelected: {abilityView.sendAbilityPosition(cell_8.position)}
    }
    Connections {
        target: cell_9
        onCellSelected: {abilityView.sendAbilityPosition(cell_9.position)}
    }
}
