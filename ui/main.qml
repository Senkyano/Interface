import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Window {
    width: 640
    height: 480
    visible: true
    title: "Monitoring Entity"
    color: "#0D1117"

	Column {
		anchors.centerIn: parent
		spacing: 20
		
		Rectangle {
			width: 200; height: 200
			radius: 100
			color: "#e74c3c"
			border.color: "white"
			border.width: 4

			Column {
				anchors.centerIn: parent
				Text {
					property real animatedValue: weatherBackend.temperature
					color: "white"
					font.bold: true
					font.pixelSize: 40

					Behavior on animatedValue {
						SequentialAnimation {
							NumberAnimation {
								duration: 1000; easing.type: Easing.OutExpo
							}
						}
					}
					text: animatedValue.toFixed(1) + "°C"
				}
				Text {
					text: "TEMPÉRATURE"
					color: "white"
					font.pixelSize: 12
					anchors.horizontalCenter: parent.horizontalCenter
				}
			}
		}
	}
}