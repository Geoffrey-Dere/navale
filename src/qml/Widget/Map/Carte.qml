import QtQuick 2.5
import QtQml.Models 2.1
import QtQuick.Layouts 1.3
import QtGraphicalEffects 1.0



Item{
    id : root

    readonly property alias tailleCellule: grid.cellHeight
    property alias  modele: grid.model
    property string caseDropClef : "clef"
    property bool actif: true


    signal clickAt(int case_id)

    Rectangle{

        id : contour_map
        anchors.fill : parent
        anchors.topMargin: 10;
        anchors.leftMargin: 10;
        anchors.bottomMargin: 10;
        anchors.rightMargin: 10;
        color : "black"

        GridView {

            property int decalageX: contour_map.anchors.leftMargin + grid.anchors.leftMargin
            property int  decalageY: contour_map.anchors.topMargin + grid.anchors.topMargin

            id : grid
            anchors.fill : parent
            anchors.topMargin: 5;
            anchors.leftMargin: 5;
            anchors.bottomMargin: 5;
            anchors.rightMargin: 5;
            cellHeight: Math.ceil(grid.height/10)
            cellWidth: Math.ceil(grid.width/10)
            interactive: false

            model : undefined
            delegate : Case{

                objectName: "summaryDelegate"
                property int index: model.index

                id : delegation
                width: grid.cellWidth
                height: grid.cellHeight
                couleur : couleurCase
                numero: numeroCase
                clef: caseDropClef

                onXChanged:{
                    grid.model.modifierPositionCase(numeroCase, delegation.x + grid.decalageX, delegation.y + grid.decalageY);
                }
                onYChanged:{
                    grid.model.modifierPositionCase(numeroCase, delegation.x + grid.decalageX, delegation.y + grid.decalageY);
                }


                MouseArea{
                    anchors.fill: parent
                    enabled: root.actif

                    onClicked: {
                        root.clickAt(numeroCase);
                    }
                }
            }
        }
    }
}
