import QtQuick 2.5
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.2

Item {
    width: 640
    height: 480

    // Signalok, melyek a kiadott parancsokat jelzik és a nyomógombok
    //  eseménykezelői aktiválják őket.
    signal connectCommand(int port);
    signal disconnectCommand;

    RowLayout {
        anchors.centerIn: parent

        Button {
            id: connectButton
            text: qsTr("Connect")
            onClicked: connectCommand(connectionPortTextEdit.text)
        }

        Button {
            id: disconnectButton
            text: qsTr("Disconnect")
            onClicked: disconnectCommand()
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
}

