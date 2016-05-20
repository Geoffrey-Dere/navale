import QtQuick 2.0

import CaseImp 1.0

Case {

    id : root
    property int numero: 0
    property string clef
    signal cliquer(int case_id)

    Text{
        text : numero
        anchors.centerIn: parent
    }

    DropArea {
        property int id_case: numero
        id: zoneDrop
        keys: [ clef ]
        anchors.fill: parent
        states: [
            State {
                when: zoneDrop.containsDrag
                PropertyChanges {
                    target: root
                    couleur : "grey";

                }
            }
        ]
    }
}


