import QtQuick 2.5
import QtQuick.Window 2.2
import GameComponents 1.0

Rectangle {
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

        Grid {
            x: 25; y: 25; width: 500; height: 500
            columns: 4; rows: 4;
            Item {
                width: 125
                height: width
                Rectangle{
                    anchors.fill: parent
                    border.color: "black"
                    anchors.horizontalCenter: parent.horizontalCenter
                    Text {
                        objectName: "cell00"
                        text: " "
                        anchors.centerIn: parent
                        font.pixelSize: 30

                    }
                }
                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        jogo.cellClicked(0);
                    }
                }
            }
            Item {
                width: 125
                height: width
                Rectangle{
                    anchors.fill: parent
                    border.color: "black"
                    anchors.horizontalCenter: parent.horizontalCenter
                    Text {
                        objectName: "cell01"
                        text: " "
                        anchors.centerIn: parent
                        font.pixelSize: 30

                    }
                }
                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        jogo.cellClicked(1);
                    }
                }
            }
            Item {
                width: 125
                height: width
                Rectangle{
                    anchors.fill: parent
                    border.color: "black"
                    anchors.horizontalCenter: parent.horizontalCenter
                    Text {
                        objectName: "cell02"
                        text: " "
                        anchors.centerIn: parent
                        font.pixelSize: 30
                    }
                }
                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        jogo.cellClicked(2);
                    }
                }
            }
            Item {
                width: 125
                height: width
                Rectangle{
                    anchors.fill: parent
                    border.color: "black"
                    anchors.horizontalCenter: parent.horizontalCenter
                    Text {
                        objectName: "cell03"
                        text: " "
                        anchors.centerIn: parent
                        font.pixelSize: 30
                    }
                }
                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        jogo.cellClicked(3);
                    }
                }
            }
            Item {
                width: 125
                height: width
                Rectangle{
                    anchors.fill: parent
                    border.color: "black"
                    anchors.horizontalCenter: parent.horizontalCenter
                    Text {
                        objectName: "cell10"
                        text: " "
                        anchors.centerIn: parent
                        font.pixelSize: 30
                    }
                }
                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        jogo.cellClicked(4);
                    }
                }
            }
            Item {
                width: 125
                height: width
                Rectangle{
                    anchors.fill: parent
                    border.color: "black"
                    anchors.horizontalCenter: parent.horizontalCenter
                    Text {
                        objectName: "cell11"
                        text: " "
                        anchors.centerIn: parent
                        font.pixelSize: 30
                    }
                }
                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        jogo.cellClicked(5);
                    }
                }
            }
            Item {
                width: 125
                height: width
                Rectangle{
                    anchors.fill: parent
                    border.color: "black"
                    anchors.horizontalCenter: parent.horizontalCenter
                    Text {
                        objectName: "cell12"
                        text: " "
                        anchors.centerIn: parent
                        font.pixelSize: 30
                    }
                }
                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        jogo.cellClicked(6);
                    }
                }
            }
            Item {
                width: 125
                height: width
                Rectangle{
                    anchors.fill: parent
                    border.color: "black"
                    anchors.horizontalCenter: parent.horizontalCenter
                    Text {
                        objectName: "cell13"
                        text: " "
                        anchors.centerIn: parent
                        font.pixelSize: 30
                    }
                }
                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        jogo.cellClicked(7);
                    }
                }
            }
            Item {
                width: 125
                height: width
                Rectangle{
                    anchors.fill: parent
                    border.color: "black"
                    anchors.horizontalCenter: parent.horizontalCenter
                    Text {
                        objectName: "cell20"
                        text: " "
                        anchors.centerIn: parent
                        font.pixelSize: 30
                    }
                }
                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        jogo.cellClicked(8);
                    }
                }
            }
            Item {
                width: 125
                height: width
                Rectangle{
                    anchors.fill: parent
                    border.color: "black"
                    anchors.horizontalCenter: parent.horizontalCenter
                    Text {
                        objectName: "cell21"
                        text: " "
                        anchors.centerIn: parent
                        font.pixelSize: 30
                    }
                }
                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        jogo.cellClicked(9);
                    }
                }
            }
            Item {
                width: 125
                height: width
                Rectangle{
                    anchors.fill: parent
                    border.color: "black"
                    anchors.horizontalCenter: parent.horizontalCenter
                    Text {
                        objectName: "cell22"
                        text: " "
                        anchors.centerIn: parent
                        font.pixelSize: 30
                    }
                }
                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        jogo.cellClicked(10);
                    }
                }
            }
            Item {
                width: 125
                height: width
                Rectangle{
                    anchors.fill: parent
                    border.color: "black"
                    anchors.horizontalCenter: parent.horizontalCenter
                    Text {
                        objectName: "cell23"
                        text: " "
                        anchors.centerIn: parent
                        font.pixelSize: 30
                    }
                }
                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        jogo.cellClicked(11);
                    }
                }
            }
            Item {
                width: 125
                height: width
                Rectangle{
                    anchors.fill: parent
                    border.color: "black"
                    anchors.horizontalCenter: parent.horizontalCenter
                    Text {
                        objectName: "cell30"
                        text: " "
                        anchors.centerIn: parent
                        font.pixelSize: 30
                    }
                }
                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        jogo.cellClicked(12);
                    }
                }
            }
            Item {
                width: 125
                height: width
                Rectangle{
                    anchors.fill: parent
                    border.color: "black"
                    anchors.horizontalCenter: parent.horizontalCenter
                    Text {
                        objectName: "cell31"
                        text: " "
                        anchors.centerIn: parent
                        font.pixelSize: 30
                    }
                }
                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        jogo.cellClicked(13);
                    }
                }
            }
            Item {
                width: 125
                height: width
                Rectangle{
                    anchors.fill: parent
                    border.color: "black"
                    anchors.horizontalCenter: parent.horizontalCenter
                    Text {
                        objectName: "cell32"
                        text: " "
                        anchors.centerIn: parent
                        font.pixelSize: 30
                    }
                }
                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        jogo.cellClicked(14);
                    }
                }
            }
            Item {
                width: 125
                height: width
                Rectangle{
                    anchors.fill: parent
                    border.color: "black"
                    anchors.horizontalCenter: parent.horizontalCenter
                    Text {
                        objectName: "cell33"
                        text: " "
                        anchors.centerIn: parent
                        font.pixelSize: 30
                    }
                }
                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        jogo.cellClicked(15);
                    }
                }
            }
        }
    }
}
