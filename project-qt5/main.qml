import QtQuick 2.3
import QtQuick.Window 2.2
import QtQuick.Controls 1.2
import QtQuick.Controls.Styles 1.2
import QtMultimedia 5.0

Window {
    id: topView
    visible: true
    width: 1024
    height: 768

    SystemPalette { id: activePalette }

    Audio {
        id: musicEngine
        source: "../music/title.wav"
        loops: Audio.Infinite
        autoPlay: true
        autoLoad: true
    }

    Audio {
        id: effectEngine
        source: ""
    }

    UserCommands {
        id: userCommands
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
        visible: false
        property string mode: "exploration"
        property string scene: ""
        property string turn: "player"

        signal move(string direction)
        signal changeImage(string newID)
        signal displayEntity(string type)
        signal reportMode(string mode)
        signal relayUseRequest()
        signal relayTalkRequest()
        signal relayInventoryRequest()
        signal relayStatusRequest()
        signal relayPlayerInfoRequest()
        signal relayPlayerInfo(string info)
        signal relayPlayerAttackOrder()
        signal relayEnemyAttackOrder()
        signal relayAbilityUseOrder(int position)
        signal relayAbilityUseReport()
        signal relayGuardOrder()
        signal relayCombatUseRequest(int row, int column)
        signal relayCombatUseReport()
        signal relayFleeOrder()

        signal relayPlayerStatus(string info)
        signal displayText(string text)
        signal relayInventoryInfo()
        signal relayItemType(int position, string type)
        signal requestItemInfo(int row, int column)
        signal relayItemInfo(string info, string type, int row, int column)
        signal requestEquipType(int index)
        signal relayEquipType(int position, string type)
        signal relayEquipItemRequest(int row, int column)
        signal relayRequestEquippedItemInfo(int index)
        signal relayEquippedItemInfo(string info)
        signal relayUseItemRequest(int row, int column)
        signal relayDiscardItemRequest(int row, int column)
        signal relayAbilitiesRequest()
        signal relayAbilityInfo(int position, string info)

        signal relayCombatInventoryRequest()
        signal relayCombatItemType(int position, string type)

        signal displayGameOver()

        Keys.onUpPressed: {
            if (mode === "exploration" && statusScreen.visible === false && textDisplayBox.visible === false)
                mainWindow.move("forward")
        }
        Keys.onLeftPressed: {
            if (mode === "exploration" && statusScreen.visible === false && textDisplayBox.visible === false){
                mainWindow.move("left")
                if (arrow.rotation === 0)
                    arrow.rotation = 270
                else if (arrow.rotation === 90)
                    arrow.rotation = 0
                else if (arrow.rotation === 180)
                    arrow.rotation = 90
                else if (arrow.rotation === 270)
                    arrow.rotation = 180
            }

        }
        Keys.onRightPressed: {
            if (mode === "exploration" && statusScreen.visible === false && textDisplayBox.visible === false){
                mainWindow.move("right")
                if (arrow.rotation === 0)
                    arrow.rotation = 90
                else if (arrow.rotation === 90)
                    arrow.rotation = 180
                else if (arrow.rotation === 180)
                    arrow.rotation = 270
                else if (arrow.rotation === 270)
                    arrow.rotation = 0
            }
        }

        function updateImage(newID){
            if (newID !== mainWindow.scene){
                if (mainWindow.scene != ""){
                    effectEngine.source = "../effects/move.wav"
                    effectEngine.play()
                }
                if (newID === "corridor"){
                    mainWindow.scene = "corridor"
                    mainWindow.changeImage("../img/corridor.jpg")
                    //musicEngine.source = "../music/corridor.wav"
                }
                else if (newID === "entrance"){
                    mainWindow.scene = "entrance"
                    mainWindow.changeImage("../img/entrance.jpg")
                    //musicEngine.source = "../music/entrance.wav"
                }
                else if (newID === "cave"){
                    mainWindow.scene = "cave"
                    mainWindow.changeImage("../img/cave.jpg")
                    //musicEngine.source = "../music/cave.wav"
                }
                else if (newID === "center"){
                    mainWindow.scene = "center"
                    mainWindow.changeImage("../img/center.jpg")
                    //musicEngine.source = "../music/cave.wav"
                }
                else if (newID === "hall"){
                    mainWindow.scene = "hall"
                    mainWindow.changeImage("../img/hall.jpg")
                    //musicEngine.source = "../music/hall.wav"
                }
                else if (newID === "cellar"){
                    mainWindow.scene = "cellar"
                    mainWindow.changeImage("../img/cellar.jpg")
                    //musicEngine.source = "../music/cellar.wav"
                }
            }
        }        

        function receiveUseVerdict(verdict){
            if (statusScreen.visible === false && inventoryScreen.visible === false)
                mainWindow.displayText(verdict)
        }

        function receiveTalkVerdict(verdict){
            if (statusScreen.visible === false && inventoryScreen.visible === false)
                mainWindow.displayText(verdict)
        }

        function receiveInventoryInfo(){
            if (statusScreen.visible === false && textDisplayBox.visible === false)
                mainWindow.relayInventoryInfo()
        }

        function receivePlayerStatus(info){
            if (textDisplayBox.visible === false && inventoryScreen.visible === false)
                mainWindow.relayPlayerStatus(info)
        }

        function receiveItemType(position, type){
            mainWindow.relayItemType(position, type)
        }

        function receiveItemInfo(info, type, row, column){
            mainWindow.relayItemInfo(info, type, row, column)
        }        

        function receiveEquipType(position, type){
            mainWindow.relayEquipType(position, type)
        }

        function receiveEquippedItemInfo(info){
            mainWindow.relayEquippedItemInfo(info)
        }

        function receivePlayerInfo(info){
            mainWindow.relayPlayerInfo(info)
        }

        function receiveSceneInfo(special){
            if (special !== "none"){
                if (special === "chest" || special === "old man")
                    mainWindow.displayEntity(special)
                else{
                    mainWindow.mode = "encounter"
                    arrow.visible = false
                    musicEngine.source = "../music/encounter.wav"
                    mainWindow.displayText("Enemy encountered, prepare for combat!")
                }
            }
            else {
                mainWindow.turn = "player"
                mainWindow.mode = "exploration"
                arrow.visible = true
                musicEngine.source = "../music/corridor.wav"
            }
            mainWindow.reportMode(mainWindow.mode)
            mainWindow.displayEntity(special)
        }

        function receiveEnemyDamageReport(report){
            effectEngine.source = "../effects/enemyhit.wav"
            effectEngine.play()
            mainWindow.displayText(report)            
        }

        function receivePlayerDamageReport(report){
            effectEngine.source = "../effects/wound.wav"
            effectEngine.play()
            mainWindow.displayText(report)
        }

        function receivePlayerDeathReport(){
            mainWindow.displayGameOver()
        }

        function receiveAbilityInfo(position, info){
            mainWindow.relayAbilityInfo(position,info)
        }

        function receiveAbilityUseReport(){
            if (mainWindow.mode !== "combat")
                mainWindow.mode = "combat"
            if (musicEngine.source !== "../music/battle.wav")
                musicEngine.source = "../music/battle.wav"
            mainWindow.relayAbilityUseReport()            
            mainWindow.relayPlayerInfoRequest()
        }

        function receiveCombatUseReport(){
            if (mainWindow.mode !== "combat")
                mainWindow.mode = "combat"
            if (musicEngine.source !== "../music/battle.wav")
                musicEngine.source = "../music/battle.wav"

            mainWindow.turn = "enemy"
            mainWindow.relayCombatUseReport()
            mainWindow.relayEnemyAttackOrder()
            mainWindow.relayPlayerInfoRequest()
        }

        function receiveEscapeAttemptReport(fleeRoll){
            if (fleeRoll === true){
                mainWindow.displayText("Escaped succesfully!")
            }
            else {
                if (mainWindow.mode !== "combat")
                    mainWindow.mode = "combat"
                if (musicEngine.source !== "../music/battle.wav")
                    musicEngine.source = "../music/battle.wav"
                mainWindow.displayText("Failed to get away!")
            }
        }

        function receiveCombatItemType(position, type){
            mainWindow.relayCombatItemType(position, type)
        }

        Connections {
            target: userCommands
            onSendUseRequest:{
                if (textDisplayBox.visible === false)
                    mainWindow.relayUseRequest()
            }

            onSendTalkRequest:{
                if (textDisplayBox.visible === false)
                    mainWindow.relayTalkRequest()
            }

            onSendInventoryRequest:{
                if (textDisplayBox.visible === false)
                    mainWindow.relayInventoryRequest()
            }

            onSendStatusRequest:{
                if (textDisplayBox.visible === false)
                    mainWindow.relayStatusRequest()
            }

            onSendAttackOrder:{
                if (textDisplayBox.visible === false){
                    if (mainWindow.mode !== "combat")
                        mainWindow.mode = "combat"
                    if (textDisplayBox.visible === false){
                        if (musicEngine.source !== "../music/battle.wav"){
                            musicEngine.source = "../music/battle.wav"
                        }
                        mainWindow.relayPlayerAttackOrder()
                    }
                }
            }
            onRequestAbilities:{
                mainWindow.relayAbilitiesRequest()
            }

            onSendAbilityUseOrder:{
               mainWindow.relayAbilityUseOrder(position-1)
            }

            onSendGuardOrder:{
                if (textDisplayBox.visible === false){
                    if (mainWindow.mode !== "combat")
                        mainWindow.mode = "combat"
                    if (musicEngine.source !== "../music/battle.wav")
                        musicEngine.source = "../music/battle.wav"
                    mainWindow.turn = "enemy"
                    mainWindow.relayGuardOrder()
                    mainWindow.relayEnemyAttackOrder()
                    mainWindow.relayPlayerInfoRequest()
                }
            }

            onSendCombatUseRequest: {
                mainWindow.relayCombatUseRequest(row, column)
            }

            onSendCombatInventoryRequest: {
                mainWindow.relayCombatInventoryRequest()
            }

            onSendFleeOrder:{
                if (textDisplayBox.visible === false)
                    mainWindow.relayFleeOrder()
            }

            onRequestPlayerInfo:{
                mainWindow.relayPlayerInfoRequest()
            }

        }

        Connections {
            target: itemGridView
            onSendItemPosition:{
                mainWindow.requestItemInfo(row, column)
            }
        }
        Connections {
            target: equipView
            onSendEquipPosition: {
                mainWindow.requestEquipType(index)
            }
        }
        Connections {
            target: itemView
            onEquipItemRequest: {
                mainWindow.relayEquipItemRequest(row, column)
            }
            onRequestEquippedItemInfo: {
                mainWindow.relayRequestEquippedItemInfo(index)
            }
            onUseItemRequest:{
                mainWindow.relayUseItemRequest(row, column)
            }
            onDiscardItemRequest: {
                mainWindow.relayDiscardItemRequest(row, column)
            }
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
                onDisplayEntity: {
                    if (type === "none")
                        sprite.source = ""
                    else if (type === "chest")
                        sprite.source = "../img/chest.png"
                    else if (type === "old man")
                        sprite.source = "../img/old man.png"
                    else if (type === "amazon")
                        sprite.source = "../img/amazon.gif"
                    else if (type === "demon")
                        sprite.source = "../img/demon.gif"
                    else if (type === "dragon")
                        sprite.source = "../img/dragon.gif"
                    else if (type === "goblin")
                        sprite.source = "../img/goblin.gif"
                    else if (type === "horseman")
                        sprite.source = "../img/horseman.gif"
                }
            }

            Image {
                id: sprite
                anchors {
                    bottom: parent.bottom
                    bottomMargin: parent.height/8
                    horizontalCenter: parent.horizontalCenter
                }
                source: ""
                fillMode: Image.PreserveAspectFit
            }
        }

        Image {
            id: arrow
            anchors {
                top: parent.top
                topMargin: parent.height/20
                horizontalCenter: parent.horizontalCenter
            }
            source: "../img/arrow.png"
            fillMode: Image.PreserveAspectFit
        }

        Rectangle {
            id: textDisplayBox
            width: parent.width
            height: parent.height/4.5
            color: "black"
            visible: false
            anchors {
                bottom: mainWindow.bottom
            }

            Connections {
                target: mainWindow
                onDisplayText: {
                    mainWindow.focus = false
                    textDisplayBox.visible = true
                    textDisplayBox.focus = true
                    textBox.text = text
                }
            }

            Keys.onReturnPressed: {
                if (textDisplayBox.visible === true){
                    if (mainWindow.mode !== "combat" && mainWindow.turn === "player"){
                        textDisplayBox.visible = false
                        textDisplayBox.focus = false
                        mainWindow.focus = true
                    }
                    else if (mainWindow.mode === "combat" && mainWindow.turn === "player"){
                        mainWindow.turn = "enemy"
                        textDisplayBox.visible = false
                        textDisplayBox.focus = false
                        mainWindow.focus = true
                        mainWindow.relayEnemyAttackOrder()
                        mainWindow.relayPlayerInfoRequest()
                    }
                    else if (mainWindow.mode === "combat" && mainWindow.turn === "enemy"){
                        mainWindow.turn = "player"
                        textDisplayBox.visible = false
                        textDisplayBox.focus = false
                        mainWindow.focus = true
                    }
                }
            }

            Text {
                id: textBox
                width: parent.width
                height: parent.height
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                text: ""
                font.pointSize: 20
                color: "green"
            }
        }

        Rectangle {
            id: statusScreen
            width: parent.width
            height: parent.height
            color: "black"
            visible: false

            Image {
                id: statusScreenBackground
                anchors.fill: parent
                source: "../img/info.jpg"
                fillMode: Image.Stretch
                cache: false
            }

            Connections {
                target: mainWindow
                onRelayPlayerStatus: {
                    mainWindow.focus = false
                    statusScreen.visible = true
                    statusScreen.focus = true
                    statusInfo.text = info
                }
            }

            Keys.onReturnPressed: {
                if (statusScreen.visible === true){
                    statusScreen.visible = false
                    statusScreen.focus = false
                    mainWindow.focus = true
                }
            }

            Text {
                id: statusInfo
                width: parent.width
                height: parent.height
                horizontalAlignment: Text.AlignLeft
                verticalAlignment: Text.AlignTop
                text: ""
                font.pointSize: 25
                color: "gold"
            }
        }

        Rectangle {
            id: inventoryScreen
            width: parent.width
            height: parent.height
            visible: false

            Connections {
                target: mainWindow
                onRelayInventoryInfo: {
                    mainWindow.focus = false
                    inventoryScreen.visible = true
                    inventoryScreen.focus = true
                }
            }

            Keys.onReturnPressed: {
                if (inventoryScreen.visible === true){
                    inventoryScreen.visible = false
                    inventoryScreen.focus = false
                    mainWindow.focus = true
                }
            }

            EquipView{
                id: equipView
            }

            MyItemView{
                id: itemView

                Connections {
                    target: equipView
                    onSendEquipPosition: {
                        itemView.requestEquippedItemInfo(index)
                    }
                }
            }

            ItemGrid{
                id: itemGridView
            }
        }
    }

    Rectangle {
        id: gameOverScreen
        visible: false
        width: parent.width
        height: parent.height

        Connections {
            target: mainWindow
            onDisplayGameOver:{
                mainWindow.focus = false
                gameOverScreen.visible = true
                gameOverScreen.focus = true
                musicEngine.source = "../music/death.wav"
            }
        }

        Image {
            id: gameOverText
            anchors.fill: parent
            source: "../img/gameover.jpg"
            fillMode: Image.Stretch
            cache: false
        }
    }

    Rectangle {
        id: titleScreen
        visible: true
        width: parent.width
        height: parent.height
        color: "transparent"

        Connections {
            target: newGameButton
            onClicked: {
                titleScreen.visible = false
                titleScreen.focus = false
                mainWindow.visible = true
                mainWindow.focus = true
                musicEngine.source = "../music/corridor.wav"
            }
        }

        Image {
            id: titleScreenBackground
            anchors.fill: parent
            source: "../img/info.jpg"
            fillMode: Image.Stretch
            cache: false
        }

        CustomButton {
            id: newGameButton
            anchors {
                left: parent.left
                verticalCenter: parent.verticalCenter
                horizontalCenter: parent.horizontalCenter
                leftMargin: parent.width/9
            }
            text: "NEW GAME"
        }
    }
}
