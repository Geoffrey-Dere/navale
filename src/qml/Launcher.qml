import QtQuick 2.4
import QtQuick.Controls 1.4
import QtQuick.Dialogs 1.2
import QtGraphicalEffects 1.0
import QtQuick.Layouts 1.3

import ThemeLoader 1.0

import "Widget"

Item{
    id : fenetre
    height:400
    width: 500

    signal demarrer()

    property string description: ""


    //    GroupBox {
    //        title: "paramètre"

    Rectangle{
        anchors.fill: parent
        color : Theme.theme.fondRectangle
    }

    Loader{ id : loader_partie;} // crée dynamiquement partie qml


    Label{
        id : titre
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top : parent.top
        anchors.topMargin: 20
        text : "BATAILLE NAVALE"
        color :  Theme.theme.texteCouleur
        font.bold : true
        font.pointSize: 15
        font.family: "Courier"

    }


    /**** Niveau ****/

    Rectangle {
        id : difficulte
        anchors.top : titre.bottom
        anchors.horizontalCenter: titre.horizontalCenter
        width: parent.width /2
        height : parent.height/3
        anchors.topMargin: 20
        color : "transparent"

        Label {
            id: label_difficulte
            width: 44
            height: 11
            text: qsTr("Difficuté")
            anchors.horizontalCenterOffset: 0
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: parent.top
            anchors.topMargin: 0
            color: Theme.theme.texteCouleur
        }

        ListView{
            id : liste_niveau
            height: currentItem.height +10
            width: currentItem.width * count + count*10
            anchors.top: label_difficulte.bottom
            anchors.topMargin: 19
            anchors.horizontalCenter: parent.horizontalCenter
            orientation: ListView.Horizontal
            interactive: false
            model : ModeleLauncher.niveau
            delegate: niveauDelegate
            spacing: 10
            currentIndex: ModeleLauncher.index_niveau;
        }

        Rectangle {
            id: rec_info_difficulte
            height: 85
            anchors.right: liste_niveau.right
            anchors.rightMargin: 0
            anchors.left: liste_niveau.left
            anchors.leftMargin: 0
            anchors.top: liste_niveau.bottom
            anchors.topMargin: 0
            layer.enabled: true
            layer.effect: InnerShadow {
                // transparentBorder: true
                horizontalOffset: -1
                verticalOffset: -1
                radius: 16
                spread: 0

                samples: 24
                color: "#b0000000"
            }

            Text {
                id: texte_difficulte
                x: 118
                y: 42
                text: description
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.verticalCenter: parent.verticalCenter
                font.pixelSize: 12
            }
        }


        Component{
            id : niveauDelegate
            Rectangle{
                id : rect
                width: 100
                height: 50
                radius: 10
                antialiasing: true
                border.color: "black"
                border.width: ListView.isCurrentItem ? 2 : 0
                color : "lightGray"

                layer.enabled: true
                layer.effect: DropShadow {
                    //  transparentBorder: true
                    horizontalOffset: 7
                    verticalOffset: 3
                    radius: 8
                    samples: 17
                    color: "#80000000"
                }

                Text{
                    id : nom
                    anchors.centerIn: parent
                    text : model.modelData.nom
                    font.pointSize: 12
                }
                MouseArea{
                    anchors.fill: parent
                    acceptedButtons: Qt.AllButtons;
                    cursorShape : Qt.ArrowCursor
                    hoverEnabled : true
                    onEntered: {
                        nom.font.bold = true;
                        description = model.modelData.description
                    }
                    onExited:{
                        nom.font.bold = false;
                        description = "";
                    }
                    onClicked: ModeleLauncher.index_niveau = index
                }
            }
        }

    }

    /*********/

    ExclusiveGroup { id: position_depart}

    GroupBox {
        id : groupBoxParametre
        title: "paramètre"
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: difficulte.bottom
        anchors.topMargin: 7
        width: grid_parametre.width +50
        height: grid_parametre.height + 50

        GridLayout {
        id : grid_parametre
        columns: 2
        rowSpacing: 10
        anchors.centerIn: parent

        /* choix position ********/
        Text{
            text : "position de départ"
             color :  Theme.theme.texteCouleur
            Layout.columnSpan: 2
            Layout.alignment: Qt.AlignHCenter | Qt.AlignBottom

        }
        RadioButton{
            text : "aleatoire"
            exclusiveGroup: position_depart
            Layout.alignment: Qt.AlignLeft
            checked: ModeleLauncher.placement === false
            onClicked: ModeleLauncher.placement = false
        }

        RadioButton{
            text : "choix"
            exclusiveGroup: position_depart
            checked: ModeleLauncher.placement === true
            Layout.alignment: Qt.AlignRight
            onClicked: ModeleLauncher.placement = true

        }
        /************************/

        //choix mode
        Text{
            text : "Choix du mode de jeu "
              color :  Theme.theme.texteCouleur
            Layout.columnSpan: 2
            Layout.alignment: Qt.AlignHCenter | Qt.AlignBottom

        }
        ComboBox {
            width: 163
            height: 20
            Layout.columnSpan: 2
            Layout.alignment: Qt.AlignHCenter
            currentIndex: 1
            model: ModeleLauncher.getListeMode();
            onCurrentIndexChanged:ModeleLauncher.setMode(currentText);
            Component.onCompleted: ModeleLauncher.setMode(currentText);
        }

        //choix epoque
        Text{
            text : "Choix de l'époque "
              color :  Theme.theme.texteCouleur
            Layout.columnSpan: 2
            Layout.alignment: Qt.AlignHCenter | Qt.AlignBottom

        }
        ComboBox {
            width: 163
            height: 20
            Layout.columnSpan: 2
            Layout.alignment: Qt.AlignHCenter
            currentIndex: ModeleLauncher.epoque();
            model: ModeleLauncher.getListeEpoque();
            onCurrentIndexChanged:ModeleLauncher.setEpoque(currentText);
            Component.onCompleted: ModeleLauncher.setEpoque(currentText);
        }

        //choix nombre bateaux
        Text{
            text : "Nombres de Bateaux  "
              color :  Theme.theme.texteCouleur
            Layout.columnSpan: 2
            Layout.alignment: Qt.AlignHCenter | Qt.AlignBottom

        }
        ComboBox {
            width: 163
            height: 20
            Layout.columnSpan: 2
            Layout.alignment: Qt.AlignHCenter
            currentIndex: ModeleLauncher.nombre_navire - 2
            model: ListModel {
                id: cbItems
                ListElement { text: 2; }
                ListElement { text: 3; }
                ListElement { text: 4; }
                ListElement { text: 5; }
                ListElement { text: 6; }
            }
            onCurrentIndexChanged: ModeleLauncher.nombre_navire = cbItems.get(currentIndex).text;
            Component.onCompleted: ModeleLauncher.nombre_navire = cbItems.get(currentIndex).text;
        }
        }
    }

    Button{
        anchors.top : groupBoxParametre.bottom
        anchors.topMargin: 10;
        anchors.horizontalCenter: groupBoxParametre.horizontalCenter
        text : "commencer"
        onClicked: ModeleLauncher.start();
    }



    /** charger page qml suivante dynamiquement **/

    Loader{ id : loader_connection }

    Connections{
        target : ModeleLauncher;
        onPartieChanged:{
            fenetre.demarrer()
        }
    }
}


