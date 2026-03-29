import QtQuick
import QtQuick.Controls

Window {
    width: 640
    height: 480
    visible: true
    title: "Drone Control Center"
    color: "#0D1117"

    Text {
        anchors.centerIn: parent
        text: "Système Drone : Connecté"
        color: "#00ff00"
        font.pixelSize: 24
        font.bold: true
    }
}