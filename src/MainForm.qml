import QtQuick 2.5
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.2

Item {
    width: 640
    height: 480

    RowLayout {
        anchors.centerIn: parent

        Button {
            id: connectButton
            text: qsTr("Connect")
            onClicked: nxt.Connect(connectionPortTextEdit.text)
        }

        Button {
            id: disconnectButton
            text: qsTr("Disconnect")
            onClicked: nxt.Disconnect()
        }
    }

    TextEdit {
        id: connectionPortTextEdit
        x: 277
        y: 202
        width: 45
        height: 20
        text: qsTr("3")
        horizontalAlignment: Text.AlignRight
        font.pixelSize: 12
    }

    Text {
        id: text1
        x: 245
        y: 202
        text: qsTr("Port:")
        font.pixelSize: 12
    }

    CheckBox {
        id: connectedCheckBox
        x: 330
        y: 202
        text: qsTr("Connected")
        enabled: false
        activeFocusOnPress: false
        checked: nxt.isConnected
    }

    TableView {
        id: tableView
        anchors.rightMargin: 0
            anchors.topMargin: 271

            frameVisible: false
            sortIndicatorVisible: false

            anchors.fill: parent

            Layout.minimumWidth: 400
            Layout.minimumHeight: 240
            Layout.preferredWidth: 600
            Layout.preferredHeight: 400

            TableViewColumn {
                id: motorAColumn
                title: "Motor A"
                role: "motorA"
                movable: false
                resizable: false
                width: 100
            }

            TableViewColumn {
                id: touchColumn
                title: "Touch"
                role: "touch"
                movable: false
                resizable: false
                width: 100
            }

            model: nxtMonitor.history.statusList
    }
}

