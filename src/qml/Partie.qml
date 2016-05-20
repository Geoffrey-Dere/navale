import QtQuick 2.4
import QtQuick.Window 2.2
import QtQuick.Controls 1.4
import QtQuick.Dialogs 1.2
import QtGraphicalEffects 1.0
import QtQuick.Layouts 1.3
import QtQuick.Controls.Styles 1.1


import ThemeLoader 1.0
import Navire 1.0

import "Widget/Map"
import "Widget"



Item{


    signal finPartie(bool rejouer);

    id : fenetre_jeu
    width : 500
    height : 500

    Component.onCompleted: partie.lancer();

    ColumnLayout{
        id : cartes
        spacing: 5

        Repeater{
            model : partie.nombreJoueur();


            Carte{

                property QtObject joueur : partie.getJoueur(index) ;
                id : carte
                Layout.preferredWidth : height
                actif : true
                modele : joueur.map;

                Component.onCompleted: {
                    Layout.preferredHeight  = fenetre_jeu.height / 2 - 20
                }

                onClickAt: {
                    partie.attaquer(index , case_id);
                }


                //placement des bateaux
                Component{
                    id : delegate
                    Repeater{
                        id : repeater
                        delegate: NavireGraphique{
                            id : delegation1
                            width: model.modelData.horizontale ? carte.tailleCellule * model.modelData.taille : carte.tailleCellule;
                            height:  model.modelData.horizontale  ? carte.tailleCellule :  carte.tailleCellule * model.modelData.taille;
                            x : parent.x + joueur.positionXNavire(modelData)
                            y : parent.y + joueur.positionYNavire(modelData)
                            modele : model.modelData
                        }
                        Component.onCompleted:if(joueur.estHumain()) repeater.model = joueur.getListNavire();
                    }
                }

                Loader{ id : loader ;}
                Timer  { interval: 100; running: true;repeat: false;
                    onTriggered: {
                        if(joueur !==null)
                            loader.sourceComponent=delegate;
                    }
                }
            }
        }
    }

    ScrollView {
        id : log
        anchors.right: parent.right
        anchors.left : cartes.right
        anchors.top : parent.top
        anchors.margins: 30
        height: parent.height - 200
        frameVisible: true
        Rectangle{
            anchors.fill: parent ;
            color : Theme.theme.fondRectangle
        }

        ListView{
            id : list
            interactive: false
            currentIndex: 50
            model:logger
            delegate: Text{
                text : "<"+date+"> : " + message;
                color : couleur
            }

            onCountChanged: {
                var newIndex = count - 1
                positionViewAtEnd()
                currentIndex = newIndex
            }

        }
    }

    Text{
        id : chrono
        anchors.top : log.bottom
        anchors.horizontalCenter: log.horizontalCenter
        anchors.topMargin: 20
        text: "joueur " + partie.joueurCourant + " : Temps restant : " + partie.temps  + "s" ;
    }


    Text{
        text: "Navires restants"
        color : Theme.theme.texteCouleur;
        anchors.bottom: info.top
        anchors.horizontalCenter: info.horizontalCenter
        anchors.bottomMargin: 2
    }

    //rectange info couleur
    Row {
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 20
        anchors.right : info.left
        anchors.rightMargin: 20
        spacing: 5
        Rectangle { color: "purple"; width: txt1.width +10 ; height: 40  ;
            Text{ id : txt1 ; anchors.centerIn: parent ; text : "case touchée";}
        }
        Rectangle { color: "green"; width: txt2.width + 10; height: 40;
            Text{ id : txt2; anchors.centerIn: parent ; text : "case détruite";}
        }

        Rectangle { color: "red"; width: txt3.width +10; height: 40;
            Text{ id : txt3 ; anchors.centerIn: parent ; text : "case ratée";}
        }
    }


    // rectangle info navire
    Rectangle{
        id : info
        anchors.bottom: parent.bottom
        anchors.right: parent.right
        anchors.margins: 5
        height : colone.height+30
        width: colone.width + 30
        border.color: "black"
        color : Theme.theme.fondRectangle
        Column{
            id : colone
            anchors.left:  parent.left
            anchors.leftMargin: 5
            anchors.top :  parent.top
            anchors.topMargin: 5

            Repeater{
                model : partie.nombreJoueur()
                Label{
                    id : label_joueur
                    text : partie.getJoueur(index).identifiant+ " : " + partie.getJoueur(index).nbNavire
                    color : Theme.theme.texteCouleur
                }
            }
        }
    }


    Connections{
        target : partie
        onFin:{
            loader_dialog.sourceComponent = dialog
            loader_dialog.item.gagnant = joueur ;
        }
    }


    //boite de dialogue fin de partie

    Loader{ id : loader_dialog}
    Loader { id : test}

    Component{
        id : dialog

        Window{

            property bool rejouer: false
            property string gagnant

            id : dialog_fin
         //   flags : Qt.Widget
            modality: Qt.ApplicationModal
            minimumWidth : 350
            minimumHeight: 100
            maximumHeight: minimumHeight
            maximumWidth: minimumWidth
            visible: true;
            title: "fin de partie"

            Rectangle{
                anchors.fill: parent
                color : Theme.theme.fondRectangle
            }


            Text{
                id : label
                text : "<b> " + gagnant + "</b> a remporté cette partie";
                color : Theme.theme.texteCouleur;
                anchors.centerIn: parent
            }

            Row{
                id : pannel
                anchors.top: label.bottom
                anchors.topMargin: 5
                anchors.horizontalCenter: label.horizontalCenter

                Button{
                    text : "continuer"
                    onClicked:{
                        rejouer = true
                        dialog_fin.close();
                        finPartie(true);
                    }
                }
            }
            onClosing:{
                finPartie(rejouer)
            }
        }
    }
}


