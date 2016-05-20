import QtQuick 2.4
import QtQuick.Window 2.2
import QtQuick.Controls 1.4
import QtQuick.Dialogs 1.2
import QtGraphicalEffects 1.0
import QtQuick.Layouts 1.3


import ThemeLoader 1.0
import Navire 1.0

import "Widget/Map"
import "Widget"
import "Entities"

Item {

    id : fenetre

    property int navire_A_Poser: 5
    property QtObject joueur: partie.getNextJoueurAPlacer()
    property var listeNavire: []
    signal terminer()


    //    WebView {
    //            id: webview
    //            url: "qrc:/test.html"
    //            anchors.fill: parent
    //    }

    Rectangle{
        anchors.fill: parent
        color : Theme.theme.fondRectangle
    }

    Text{
        id : titre
        text : "positionnez vos bateaux"
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: parent.top
        anchors.topMargin: 20
        color : Theme.theme.texteCouleur

    }

    Text {
        text :"double clic pour changer le sens du bateau"
        anchors.bottom : terrain.top
        anchors.horizontalCenter: terrain.horizontalCenter
        visible : continuer.visible == false ? true : false
        color : Theme.theme.texteCouleur
    }

    Carte{
        id : terrain
        modele : joueur.map
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        anchors.topMargin: 25
        width: 410
        height: 410
        caseDropClef: "maclef"
    }


    Component {
        id: repeaterDelegate
        Navire {
            id : navire
            clef : "maclef"

            anchors.top: terrain.bottom
            anchors.topMargin: 15
            anchors.leftMargin: 15
            anchors.horizontalCenter: terrain.horizontalCenter

            state : navire.horizontale ? "" : "verti"
            tailleCase: terrain.tailleCellule
            nombreCase: taille

            couleur: cc
            states : [
                State {
                    name: "verti"
                    AnchorChanges{
                        target : navire
                        anchors.left: terrain.right
                        anchors.horizontalCenter: undefined
                        anchors.verticalCenter: terrain.verticalCenter
                        anchors.top:undefined
                    }
                }
            ]

            onEstPoser: {
                navire_A_Poser--;
                joueur.placerNavire(repeaterModel.courant, cases, navire.horizontale);
                if(navire_A_Poser > 0)
                    nouveauNavire();
                else
                    continuer.visible = true
            }
        }
    }



    Button{
        id : continuer
        text : "continuer"
        anchors.top: terrain.bottom ; anchors.topMargin: 20
        anchors.horizontalCenter: terrain.horizontalCenter
        visible : false;

        onClicked: {
            fenetre.terminer()
        }
    }


    /****modele pour ajouter de dans des navires dynamiquement *******/
    ListModel {
        property QtObject courant
        id: repeaterModel
    }

    Repeater {
        model: repeaterModel
        delegate: repeaterDelegate
    }

    /*****************/

    Component.onCompleted:{
        nouveauNavire();
    }

    function nouveauNavire(){
        var navire =  joueur.getNextNavireAPlacer();
        repeaterModel.courant = navire;
        listeNavire.push(navire);
        repeaterModel.append( {cc : "blue", taille : navire.taille } )
    }

}
