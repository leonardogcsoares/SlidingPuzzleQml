import QtQuick 2.5
import QtQuick.Window 2.2
import GameComponents 1.0

Window {
    visible: true
    width: 550
    height: 800

    Rectangle {
        id: rectangle1
        width: 550
        height: 800
        anchors.centerIn: parent

        Jogo {
            id: jogo
        }

        GridView {
            id: gridView1
            x: 25
            y: 25
            width: 500
            height: 500
            model: gameModel
            delegate: Item {

                Column {
                    Rectangle{
                        width: 125
                        height: width
                        border.color: "black"
                        anchors.horizontalCenter: parent.horizontalCenter
                        Text {
                            text: model.modelData.value == 0 ? " " : model.modelData.value
                            anchors.centerIn: parent
                            font.bold: true
                        }

                        MouseArea {
                            anchors.fill: parent
                            onClicked: {

//                                 rectangle1.qmlSignal("" + model.modelData.value);
                                jogo.cellClicked(model.modelData.value, model.modelData.index);
//                                jogoBase.refresh()
                            }
                        }
                    }
                }
            }
            cellHeight: 125
            cellWidth: 125
        }
    }
}
