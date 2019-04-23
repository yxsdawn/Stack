import QtQuick 2.6
import QtQuick.Window 2.2
import QtQuick.Controls 2.1

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")
    signal convertNumber(string decimal_number)
    function showOctalNumber(octal_number)
    {
        textEdit2.text = octal_number
    }

    MouseArea {
        anchors.fill: parent
        onClicked: {

        }
    }

    TextEdit {
        id: textEdit
        text: qsTr("100")
        verticalAlignment: Text.AlignVCenter
        anchors.top: parent.top
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.topMargin: 20
        Rectangle {
            anchors.fill: parent
            anchors.margins: -10
            color: "transparent"
            border.width: 1
        }
    }

    TextEdit {
        id: textEdit2
        verticalAlignment: Text.AlignVCenter
        anchors.top: parent.top
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.topMargin: 60
        Rectangle {
            anchors.fill: parent
            anchors.margins: -10
            color: "transparent"
            border.width: 1
        }
    }

    Button{
        id:covertBtn
        text:qsTr("CONVERT")
        onClicked: {
            convertNumber(textEdit.text)
        }
    }
}
