import QtQuick
import PictureConvert
import QtQuick.Dialogs
import QtQuick.Controls 6.8
import QtQuick.Layouts

Window {
    width: 1200
    height: 600

    minimumWidth: width
    minimumHeight: height
    maximumWidth: width
    maximumHeight: height

    visible: true
    flags: Qt.Window | Qt.WindowTitleHint | Qt.WindowCloseButtonHint | Qt.WindowMinimizeButtonHint
    title: "PictureConvert"


    property url inputFolderUrl
    property url outputFolderUrl
    FolderDialog {
        id: inputFolderDialog
        title: "选择输入文件夹"
        onAccepted: inputFolderUrl = currentFolder
    }

    FolderDialog {
        id: outputFolderDialog
        title: "选择输出文件夹"
        onAccepted: outputFolderUrl = currentFolder
    }

    Rectangle {
        id: bg
        anchors.fill: parent
        color: "#f0f0f0"

        Image {
            anchors.fill: parent
            source: "images/bg.jpg"
            fillMode: Image.PreserveAspectCrop
        }
    }

    Rectangle {
        id: inputArea
        width: parent.width / 2
        height: parent.height
        color: "#00ffffff"

        Rectangle {
            id: input
            color: "#7bffffff"
            radius: 61
            anchors {
                fill: parent
                margins: 20
            }

            RowLayout {
                id: folderSelectLayout
                width: parent.width
                spacing: 20
                anchors.left: parent.left
                anchors.leftMargin: 10
                anchors.top: parent.top
                anchors.topMargin: 100
                anchors.right: parent.right
                anchors.rightMargin: 10


                // 左列：输入输出路径
                ColumnLayout {
                    Layout.fillWidth: true
                    Layout.preferredWidth: 4 // 占比 3/5
                    spacing: 58

                    Text {
                        id: inputText
                        text: inputFolderUrl.toString() === "" ? "请选择输入文件夹" : inputFolderUrl.toString().replace("file:///", "")
                        font.pointSize: 20
                        height: 70
                        Layout.fillWidth: true
                        color: "#000000"
                        padding: 10
                        elide: Text.ElideMiddle
                        horizontalAlignment: Text.AlignHCenter


                    }

                    Text {
                        id: outputText
                        text: outputFolderUrl.toString() === "" ? "请选择输出文件夹" : outputFolderUrl.toString().replace("file:///", "")
                        font.pointSize: 20
                        height: 70
                        Layout.fillWidth: true
                        color: "#000000"
                        padding: 10
                        elide: Text.ElideMiddle
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignTop


                    }
                }


                // 右列：按钮
                ColumnLayout {
                    Layout.fillWidth: true
                    Layout.preferredWidth: 1  // 占比 2/5
                    spacing: 30

                    Button {
                        id: inputButton
                        icon.source: "images/folder.png"
                        font.pointSize: 13
                        Layout.preferredHeight: 70
                        Layout.fillWidth: true
                        background: Rectangle {
                            color: inputButton.pressed ? "#8a41bfb6" :
                                (inputButton.hovered ? "#d941bfb6" : "#b941bfb6")
                            radius: height / 2
                            Behavior on color {
                                PropertyAnimation {
                                    duration: 100
                                }
                            }
                        }
                        onClicked: inputFolderDialog.open()
                    }

                    Button {
                        id: outputButton
                        icon.source: "images/folder.png"
                        font.pointSize: 13
                        Layout.preferredHeight: 70
                        Layout.fillWidth: true
                        background: Rectangle {
                            color: outputButton.pressed ? "#8a41bfb6" :
                                (outputButton.hovered ? "#d941bfb6" : "#b941bfb6")
                            radius: height / 2
                            Behavior on color {
                                PropertyAnimation {
                                    duration: 100
                                }
                            }
                        }
                        onClicked: outputFolderDialog.open()
                    }
                }
            }


            Button {
                id: confirmButton
                x: 101
                y: 453
                width: 358
                height: 77
                text: qsTr("开始转换")
                font.pointSize: 13
                background: Rectangle {
                    color: confirmButton.pressed ? "#8a41bfb6" :  // 按下时颜色变深
                        (confirmButton.hovered ? "#d941bfb6" : "#b941bfb6")  // 悬停时颜色变浅
                    radius: height / 2
                    Behavior on color {
                        PropertyAnimation {
                            duration: 100
                        }
                    }
                }
                onClicked: {
                    pathReceiver.setPaths(inputFolderUrl.toString(), outputFolderUrl.toString())
                    pictureConvert.batchProcessImages()
                }
            }

        }

    }

    Rectangle {
        id: outputArea
        width: parent.width / 2
        height: parent.height
        color: "#00ffffff"
        anchors.right: parent.right

        Rectangle {
            id: output
            color: "#7bffffff"
            radius: 61
            anchors {
                fill: parent
                margins: 20
            }

            ScrollView{
                anchors.centerIn: parent
                width: 519
                height: 500
                TextArea {
                    id: logArea
                    anchors.centerIn: parent
                    wrapMode: Text.Wrap
                    readOnly: true
                    font.pointSize: 10
                    placeholderTextColor: "#aa353637"
                    placeholderText: qsTr("Text Area")

                    Connections{
                        target: textAreaLog
                        onLogMessage:function(message){
                            logArea.text += message + "\n"
                            logArea.cursorPosition = logArea.text.length
                        }
                    }
                }
            }
        }
    }

}

