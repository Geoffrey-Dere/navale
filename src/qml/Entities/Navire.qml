import QtQuick 2.5
import QtQuick.Layouts 1.3

/*
 * Génère un navire
 */

Item{
    id: root
    property int  nombreCase : 5
    property int tailleCase: 25
    property string clef: "clef"
    property string couleur : "red"
    property bool horizontale : true
    readonly property bool verticale: !horizontale

    signal estPoser(variant cases);


    width  :{
        if(horizontale)
            tailleCase + tailleCase*(nombreCase-1);
        else
            tailleCase
    }

    height :{
        if(!horizontale)
            height : tailleCase + tailleCase*(nombreCase-1);
        else
            tailleCase

    }

    Rectangle {
        property bool fixe: case1.Drag.target
        id : case1
        color: couleur;
        width: tailleCase ; height: tailleCase;
        anchors.left : parent.left;
        anchors.top: parent.top
        Drag.keys: clef
        Drag.active: mouseArea2.drag.active
        Drag.hotSpot.x: tailleCase /2
        Drag.hotSpot.y: tailleCase /2
        border.color : "black"
        border.width : 1

        states : State{
            when  : mouseArea2.drag.active
            AnchorChanges {target : case1 ; anchors.left : undefined ; anchors.top : undefined}
        }

        Connections{
            target : mouseArea2
            onPoser :{
                case1.parent = case1.Drag.target;
                case1.parent.enabled = false
                mouseArea2.listeCase.push(case1.parent.id_case)
            }
        }
    }

    Repeater {
        id : reapeter
        model: nombreCase - 1
        Rectangle {
            property bool fixe: rec.Drag.target
            id : rec
            width: tailleCase ; height: tailleCase;
            parent : root
            color: couleur

            anchors.left: horizontale?  case1.right : case1.left
            anchors.leftMargin:  horizontale ? index*tailleCase : 0
            anchors.top: horizontale ? case1.top : case1.bottom
            anchors.topMargin: horizontale ? 0 : index*tailleCase


            Drag.active: mouseArea2.drag.active
            Drag.hotSpot.x: tailleCase /2
            Drag.hotSpot.y: tailleCase /2
            Drag.keys: clef
            border.color : "black"
            border.width : 1

            states : State{
                name : "ok"
                PropertyChanges{
                    target : rec;
                    anchors.left: parent.left
                    anchors.top: parent.top
                    anchors.leftMargin: 0
                    anchors.topMargin: 0
                }
            }

            Connections{
                target : mouseArea2
                onPoser :{
                    rec.parent = rec.Drag.target;
                    rec.state = "ok";
                    rec.parent.enabled = false
                    mouseArea2.listeCase.push(rec.parent.id_case)
                }
            }
        }
    }

    MouseArea {

        property var listeCase: []
        signal  poser(); // envoyer quand un navire a été posé sur la map

        id: mouseArea2
        anchors.fill: parent
        drag.target: case1
        onReleased:
            if(verification()){
                poser();
                mouseArea2.enabled = false
                estPoser(listeCase);
            }

        onDoubleClicked:{
            horizontale = !horizontale
        }

        Component.onCompleted:{
            if(nombreCase<1)
                nombreCase=1
        }
    }

    // fonction qui permet de case1er si toutes les cases sont posées
    function verification(){

        var res = case1.fixe;
        for(var i = 0 ; i < nombreCase-1 ; i++){
            res = res & reapeter.itemAt(i).fixe;
        }

        return res ;
    }

}

