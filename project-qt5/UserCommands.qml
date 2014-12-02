import QtQuick 2.0

Rectangle {
    id : userCommands
    width: parent.width
    height: parent.height/5
    anchors {
        bottom: parent.bottom
    }
    signal requestPlayerInfo()
    signal sendUseRequest()
    signal sendTalkRequest()
    signal sendInventoryRequest()
    signal sendStatusRequest()
    signal sendAttackOrder()
    signal requestAbilities()
    signal sendAbilityUseOrder(int position)
    signal sendGuardOrder()
    signal sendFleeOrder()
    signal sendCombatUseRequest(int row, int column)
    signal sendCombatInventoryRequest()

    Connections {
        target: mainWindow
        onReportMode: {
            if (mode === "exploration"){
                combatDisplay.visible = false
                explorationDisplay.visible = true
            }
            else if (mode === "encounter" || mode === "combat"){
                explorationDisplay.visible = false
                combatDisplay.visible = true
                userCommands.requestPlayerInfo()
            }
        }

        onRelayPlayerInfo: {
            statusTextBox.text = info
        }

        onRelayAbilityUseReport: {
            if (abilityView.visible === true){
                attackButton.visible = true
                abilitiesButton.visible = true
                guardButton.visible = true
                combatUseButton.visible = true
                fleeButton.visible = true
                abilityView.visible = false
                abilityView.focus = false
                mainWindow.focus = true
            }
        }

        onRelayCombatUseReport: {
            if (combatItemView.visible === true){
                attackButton.visible = true
                abilitiesButton.visible = true
                guardButton.visible = true
                combatUseButton.visible = true
                fleeButton.visible = true
                combatItemView.visible = false
                combatItemView.focus = false
                mainWindow.focus = true
            }
        }
    }

    Connections {
        target: explorationUseButton
        onClicked:
            userCommands.sendUseRequest()
    }

    Connections {
        target: talkButton
        onClicked:
            userCommands.sendTalkRequest()
    }

    Connections {
        target: invButton
        onClicked:
            userCommands.sendInventoryRequest()
    }

    Connections {
        target: statusButton
        onClicked:
            userCommands.sendStatusRequest()
    }

    Connections {
        target: attackButton
        onClicked:
            userCommands.sendAttackOrder()
    }

    Connections {
        target: abilitiesButton
        onClicked: {
            if (abilityView.visible === false && textDisplayBox.visible === false){
                attackButton.visible = false
                abilitiesButton.visible = false
                guardButton.visible = false
                combatUseButton.visible = false
                fleeButton.visible = false
                abilityView.visible = true
                abilityView.focus = true
                mainWindow.focus = false
                userCommands.requestAbilities()
            }
        }
    }

    Connections {
        target: guardButton
        onClicked:
            userCommands.sendGuardOrder()
    }

    Connections {
        target: combatUseButton
        onClicked: {
            if (combatItemView.visible === false && textDisplayBox.visible === false){
                userCommands.sendCombatInventoryRequest()
                attackButton.visible = false
                abilitiesButton.visible = false
                guardButton.visible = false
                combatUseButton.visible = false
                fleeButton.visible = false
                combatItemView.visible = true
                combatItemView.focus = true
                mainWindow.focus = false
            }
        }
    }

    Connections {
        target: fleeButton
        onClicked:
            userCommands.sendFleeOrder()
    }

    Connections {
        target: abilityView
        onSendAbilityPosition:{
            userCommands.sendAbilityUseOrder(position)
        }
    }

    Connections {
        target: combatItemView
        onSendItemPosition:{
            userCommands.sendCombatUseRequest(row, column)
        }
    }

    Image {
        id: commandTex
        anchors.fill: parent
        source: "../img/wall.jpg"
        fillMode: Image.Stretch
    }

    //Exploration mode
    Rectangle {
        id: explorationDisplay
        width: parent.width
        height: parent.height
        color: "transparent"
        border.color: "darkgoldenrod"
        anchors {
            left: parent.left
        }
        visible: true

        CustomButton {
            id: explorationUseButton
            anchors {
                left: parent.left
                verticalCenter: parent.verticalCenter
                leftMargin: parent.width/9
            }
            text: "USE"
        }

        CustomButton {
            id: talkButton
            anchors {
                left: explorationUseButton.right
                verticalCenter: parent.verticalCenter
                leftMargin: parent.width/9
            }
            text: "TALK"
        }

        CustomButton {
            id: invButton
            anchors {
                left: talkButton.right
                verticalCenter: parent.verticalCenter
                leftMargin: parent.width/9
            }
            text: "INVENTORY"
        }

        CustomButton {
            id: statusButton
            anchors {
                left: invButton.right
                verticalCenter: parent.verticalCenter
                leftMargin: parent.width/9
            }
            text: "STATUS"
        }
    }

    //Combat mode
    Rectangle {
        id: combatDisplay
        width: parent.width
        height: parent.height
        color: "transparent"
        border.color: "darkgoldenrod"
        anchors {
            left: parent.left
        }
        visible: false

        Text {
            id: statusTextBox
            width: parent.width/5
            height: parent.height
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            text: ""
            font.pointSize: 20
            color: "gold"
        }
        Rectangle {
            id: combatCommands
            width: parent.width - parent.width/5
            height: parent.height
            color: "transparent"
            border.color: "darkgoldenrod"
            anchors {
                left: statusTextBox.right
            }

            CustomButton {
                id: attackButton
                anchors {
                    left: parent.left
                    leftMargin: parent.width/3.6
                    top: parent.top
                    topMargin: parent.height/6
                }
                text: "ATTACK"
            }

            CustomButton {
                id: abilitiesButton
                anchors {
                    left: attackButton.right
                    leftMargin: parent.width/7.6
                    top: parent.top
                    topMargin: parent.height/6
                }
                text: "ABILITIES"
            }

            CustomButton {
                id: guardButton
                anchors {
                    left: parent.left
                    leftMargin: parent.width/7
                    bottom: parent.bottom
                    bottomMargin: parent.height/6
                }
                text: "GUARD"
            }

            CustomButton {
                id: combatUseButton
                anchors {
                    left: guardButton.right
                    leftMargin: parent.width/7
                    bottom: parent.bottom
                    bottomMargin: parent.height/6
                }
                text: "USE"
            }

            CustomButton {
                id: fleeButton
                anchors {
                    left: combatUseButton.right
                    leftMargin: parent.width/7
                    bottom: parent.bottom
                    bottomMargin: parent.height/6
                }
                text: "FLEE"
            }

            AbilityGrid{
                id: abilityView
                width: parent.width
                height: parent.height
                visible: false
                color: "transparent"

                Keys.onReturnPressed: {
                    if (abilityView.visible === true){
                        attackButton.visible = true
                        abilitiesButton.visible = true
                        guardButton.visible = true
                        combatUseButton.visible = true
                        fleeButton.visible = true
                        abilityView.visible = false
                        abilityView.focus = false
                        mainWindow.focus = true
                    }
                }
            }

            CombatItemGrid {
                id: combatItemView
                width: parent.width
                height: parent.height
                visible: false
                color: "transparent"

                Keys.onReturnPressed: {
                    if (combatItemView.visible === true){
                        attackButton.visible = true
                        abilitiesButton.visible = true
                        guardButton.visible = true
                        combatUseButton.visible = true
                        fleeButton.visible = true
                        combatItemView.visible = false
                        combatItemView.focus = false
                        mainWindow.focus = true
                    }
                }
            }
        }
    }
}
