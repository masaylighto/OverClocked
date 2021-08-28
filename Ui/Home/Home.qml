import QtQuick
import QtQuick.Window
import QtQuick.Controls 2.5
Window {
    minimumWidth: 350
    minimumHeight: 450
    visible: true
    color: "Transparent"
    flags: Qt.FramelessWindowHint
    id:window

    function setInitalValueOfVoltage(Voltage)
    {

    voltageSlider.value=Voltage;
return 0;
    }
    function setInitalValueOffrequency(frequency)
    {
    frequencySlider.value=Frequancy;
return 0;
    }
    Rectangle{

        anchors.fill: parent

        id:maincontaner
        color: Qt.rgba(40,40,40,0.90)
        clip: true

        radius: 20


        MouseArea{



            id: mouse
            property int prevX: 0
            property int prevY: 0
            anchors.fill: parent
            onPressed: {prevX=mouse.x; prevY=mouse.y}
            onPositionChanged:{
                var deltaX = mouse.x - prevX;
                window.x += deltaX;
                prevX = mouse.x - deltaX;

                var deltaY = mouse.y - prevY
                window.y += deltaY;
                prevY = mouse.y - deltaY;
            }
        }

        Rectangle{

            height: 20
            width: 20
            radius: 4
            x:parent.width-30
            y:10
            color: Qt.rgba(40,40,40,0.30)
            Text {

                text: qsTr("×")
                font.pixelSize: 22
                anchors.centerIn: parent
            }
            MouseArea{
                anchors.fill: parent
                onPressed:  {

                    close();
                }

            }
        }
        Rectangle
        {
            height: 20
            width: 20
            radius: 4
            x:parent.width-60
            y:10
            color: Qt.rgba(40,40,40,0.30)
            Text {

                text: qsTr("-")
                font.pixelSize: 22
                anchors.centerIn: parent
            }
            MouseArea{
                anchors.fill: parent
                onPressed:  {

                    showMinimized();
                }

            }
        }
        Slider {
            id:frequencySlider
            objectName: "frequencySlider"
            width: 10
            height: 300
            x:parent.width*0.15
            orientation: Qt.Vertical
            y:(parent.height-height)/2
            from: 700
            value: 700
            to: 2147
            stepSize: 1
            onValueChanged: {
                homeClass._ChangeFrequency(value)

                frequencyvalue.y=(frequencySlider.value/2847)*frequencyvalue.parent.height
            }
            onPressedChanged:
            {

                frequencyvalue.visible=!voltagevalue.visible

            }
        }
        Slider {
            id:voltageSlider
            objectName: "voltageSlider"
            width: 10
            height: 300
            x:parent.width*0.85
            orientation: Qt.Vertical
            y:(parent.height-height)/2
            from: 2
            value: 2
            to: 16
            stepSize: 1
            onValueChanged: {

                homeClass._ChangeVoltage(value)
                voltagevalue.y=((voltageSlider.value*100/16)*voltagevalue.parent.height)/100
            }
            onPressedChanged:
            {

                voltagevalue.visible=!voltagevalue.visible

            }
        }
        Rectangle{

            width: 1
            height: voltageSlider.height
            x:voltageSlider.x-40
            y:voltageSlider.y
            rotation: 180
            Text {
                id: voltagevalue
                text:voltageSlider.value
                visible: false
                rotation: 180
                y:0
            }

        }
        Rectangle{

            width: 1
            height: frequencySlider.height
            x:frequencySlider.x+60
            y:frequencySlider.y
            rotation: 180
            Text {
                id: frequencyvalue
                text:frequencySlider.value
                visible: false
                rotation: 180
                y:0
            }

        }
        Column{
            x:frequencySlider.x-20
            y:frequencySlider.y-maxMhz.height-10
            Text{
                id:maxMhz
                text: "2147mhz"
                font.pixelSize: 15
            }
            Rectangle{
                width: 1
                height: frequencySlider.height+20
                color: "transparent"
            }

            Text{
                id:minMhz
                text: "800mhz"
                font.pixelSize: 15
            }
        }
        Rectangle{
            width: 8
            height: frequencySlider.height
            anchors.centerIn: parent

            radius: 4
            color: "transparent"
            border.color: "black"
        }
        Column{
            x:voltageSlider.x-10
            y:voltageSlider.y-maxVoltage.height-10
            Text{
                id:maxVoltage
                text: "16v"
                font.pixelSize: 15
            }
            Rectangle{
                width: 1
                height: voltageSlider.height+20
                color: "transparent"
            }

            Text{
                id:minVoltage
                text: " 2v"
                font.pixelSize: 15
            }
        }

    }



}

