import QtQuick 2.0

Rectangle {
    id: gridView
    width: parent.width
    height: parent.height/2
    anchors {bottom: parent.bottom}
    color:"black"
    border.color: "darkgoldenrod"

    signal sendItemPosition(int row, int column)    

    Connections {
        target: mainWindow
        onRelayItemType:{
            gridView.receiveItemType(position,type)
        }        
    }    

    function receiveItemType(position, type){
        if (position === 1)
            upperCell_1.displayItem(type);
        else if (position ===2)
            upperCell_2.displayItem(type);
        else if (position ===3)
            upperCell_3.displayItem(type);
        else if (position ===4)
            upperCell_4.displayItem(type);
        else if (position ===5)
            upperCell_5.displayItem(type);
        else if (position ===6)
            upperCell_6.displayItem(type);
        else if (position ===7)
            upperCell_7.displayItem(type);
        else if (position ===8)
            upperCell_8.displayItem(type);
        else if (position ===9)
            upperCell_9.displayItem(type);
        else if (position ===10)
            upperCell_10.displayItem(type);
        if (position === 11)
            lowerCell_1.displayItem(type);
        else if (position ===12)
            lowerCell_2.displayItem(type);
        else if (position ===13)
            lowerCell_3.displayItem(type);
        else if (position ===14)
            lowerCell_4.displayItem(type);
        else if (position ===15)
            lowerCell_5.displayItem(type);
        else if (position ===16)
            lowerCell_6.displayItem(type);
        else if (position ===17)
            lowerCell_7.displayItem(type);
        else if (position ===18)
            lowerCell_8.displayItem(type);
        else if (position ===19)
            lowerCell_9.displayItem(type);
        else if (position ===20)
            lowerCell_10.displayItem(type);
    }

    //Upper Cells
    GridCell {
        id: upperCell_1
        row: 0
        column: 0
    }
    GridCell {
        id: upperCell_2
        row: 0
        column: 1
        anchors {left:upperCell_1.right}
    }
    GridCell {
        id: upperCell_3
        row: 0
        column: 2
        anchors {left:upperCell_2.right}
    }
    GridCell {
        id: upperCell_4
        row: 0
        column: 3
        anchors {left:upperCell_3.right}
    }
    GridCell {
        id: upperCell_5
        row: 0
        column: 4
        anchors {left:upperCell_4.right}
    }
    GridCell {
        id: upperCell_6
        row: 0
        column: 5
        anchors {left:upperCell_5.right}
    }
    GridCell {
        id: upperCell_7
        row: 0
        column: 6
        anchors {left:upperCell_6.right}
    }
    GridCell {
        id: upperCell_8
        row: 0
        column: 7
        anchors {left:upperCell_7.right}
    }
    GridCell {
        id: upperCell_9
        row: 0
        column: 8
        anchors {left:upperCell_8.right}
    }
    GridCell {
        id: upperCell_10
        row: 0
        column: 9
        anchors {left:upperCell_9.right}
    }

    //Upper cell connections
    Connections {
        target: upperCell_1
        onItemSelected: {gridView.sendItemPosition(upperCell_1.row, upperCell_1.column)}
    }
    Connections {
        target: upperCell_2
        onItemSelected: {gridView.sendItemPosition(upperCell_2.row, upperCell_2.column)}
    }
    Connections {
        target: upperCell_3
        onItemSelected: {gridView.sendItemPosition(upperCell_3.row, upperCell_3.column)}
    }
    Connections {
        target: upperCell_4
        onItemSelected: {gridView.sendItemPosition(upperCell_4.row, upperCell_4.column)}
    }
    Connections {
        target: upperCell_5
        onItemSelected: {gridView.sendItemPosition(upperCell_5.row, upperCell_5.column)}
    }
    Connections {
        target: upperCell_6
        onItemSelected: {gridView.sendItemPosition(upperCell_6.row, upperCell_6.column)}
    }
    Connections {
        target: upperCell_7
        onItemSelected: {gridView.sendItemPosition(upperCell_7.row, upperCell_7.column)}
    }
    Connections {
        target: upperCell_8
        onItemSelected: {gridView.sendItemPosition(upperCell_8.row, upperCell_8.column)}
    }
    Connections {
        target: upperCell_9
        onItemSelected: {gridView.sendItemPosition(upperCell_9.row, upperCell_9.column)}
    }
    Connections {
        target: upperCell_10
        onItemSelected: {gridView.sendItemPosition(upperCell_10.row, upperCell_10.column)}
    }


    //Lower Cells
    GridCell {
        id: lowerCell_1
        row: 1
        column: 0
        anchors {bottom: parent.bottom}
    }
    GridCell {
        id: lowerCell_2
        row: 1
        column: 1
        anchors {bottom: parent.bottom; left: lowerCell_1.right}
    }
    GridCell {
        id: lowerCell_3
        row: 1
        column: 2
        anchors {bottom: parent.bottom; left: lowerCell_2.right}
    }
    GridCell {
        id: lowerCell_4
        row: 1
        column: 3
        anchors {bottom: parent.bottom; left: lowerCell_3.right}
    }
    GridCell {
        id: lowerCell_5
        row: 1
        column: 4
        anchors {bottom: parent.bottom; left: lowerCell_4.right}
    }
    GridCell {
        id: lowerCell_6
        row: 1
        column: 5
        anchors {bottom: parent.bottom; left: lowerCell_5.right}
    }
    GridCell {
        id: lowerCell_7
        row: 1
        column: 6
        anchors {bottom: parent.bottom; left: lowerCell_6.right}
    }
    GridCell {
        id: lowerCell_8
        row: 1
        column: 7
        anchors {bottom: parent.bottom; left: lowerCell_7.right}
    }
    GridCell {
        id: lowerCell_9
        row: 1
        column: 8
        anchors {bottom: parent.bottom; left: lowerCell_8.right}
    }
    GridCell {
        id: lowerCell_10
        row: 1
        column: 9
        anchors {bottom: parent.bottom; left: lowerCell_9.right}
    }

    //Lower cell connections
    Connections {
        target: lowerCell_1
        onItemSelected: {gridView.sendItemPosition(lowerCell_1.row, lowerCell_1.column)}
    }
    Connections {
        target: lowerCell_2
        onItemSelected: {gridView.sendItemPosition(lowerCell_2.row, lowerCell_2.column)}
    }
    Connections {
        target: lowerCell_3
        onItemSelected: {gridView.sendItemPosition(lowerCell_3.row, lowerCell_3.column)}
    }
    Connections {
        target: lowerCell_4
        onItemSelected: {gridView.sendItemPosition(lowerCell_4.row, lowerCell_4.column)}
    }
    Connections {
        target: lowerCell_5
        onItemSelected: {gridView.sendItemPosition(lowerCell_5.row, lowerCell_5.column)}
    }
    Connections {
        target: lowerCell_6
        onItemSelected: {gridView.sendItemPosition(lowerCell_6.row, lowerCell_6.column)}
    }
    Connections {
        target: lowerCell_7
        onItemSelected: {gridView.sendItemPosition(lowerCell_7.row, lowerCell_7.column)}
    }
    Connections {
        target: lowerCell_8
        onItemSelected: {gridView.sendItemPosition(lowerCell_8.row, lowerCell_8.column)}
    }
    Connections {
        target: lowerCell_9
        onItemSelected: {gridView.sendItemPosition(lowerCell_9.row, lowerCell_9.column)}
    }
    Connections {
        target: lowerCell_10
        onItemSelected: {gridView.sendItemPosition(lowerCell_10.row, lowerCell_10.column)}
    }
}
