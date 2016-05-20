import QtQuick 2.0
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4

TextField {

    style: TextFieldStyle {
        textColor: "black"
        background: Rectangle {
            radius: 2
            border.color: "green"
            border.width: 1
        }
    }

    states: [
        State {
            name: "erreur"

            PropertyChanges {
                target: field; style : style_erreur;
            }
        }
    ]

    Component{
        id : style_erreur
        TextFieldStyle {
            textColor: "red"
            background: Rectangle {
                radius: 2
                border.color: "red"
                border.width: 2
            }
        }
    }
}
