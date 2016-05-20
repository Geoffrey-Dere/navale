import QtQuick 2.0
import QtQuick.Window 2.2
import QtQuick.Controls 1.4

import ThemeLoader 1.0

import "Widget"
ApplicationWindow {


    id : main
    visible: true
    minimumHeight: 700
    minimumWidth: 800
    maximumHeight: 700
    maximumWidth: 800

    x: Screen.width / 2 - width / 2
     y: Screen.height / 2 - height / 2

    title: qsTr("Bataille Navalle")

    menuBar : Menus{}


    onClosing: {
         close.accepted = true;
        loader_partie.sourceComponent= undefined;
        loader_placement.sourceComponent= undefined;
    }

    Loader{id : loader_partie;}

    Loader{id : loader_placement}

    Launcher{
        id : start
        anchors.fill: parent
        visible : true

        onVisibleChanged: {
//            if(visible){
//                loader_partie.sourceComponent =  undefined
//                loader_placement.sourceComponent= undefined;
//            }
        }

        onDemarrer: {
            loader_partie.sourceComponent = componant_partie

        }
    }


    Component{
        id : componant_partie
        Connections{
            target : partie;
            onCommencer:{
                if(placement){ // le joueur place ses bateaux
                    loader_placement.sourceComponent = vuePlacement
                    loader_placement.item.navire_A_Poser = nb_navire ;
                } else {
                    loader_partie.sourceComponent=partie_principal;
                }
                start.visible=false;
            }

        }
    }


    Component{
        id : partie_principal
        Partie{
            width: main.width
            height: main.height
            onFinPartie: {
                if(!rejouer)
                    close();
                start.visible = true
                loader_partie.sourceComponent =  undefined
                loader_placement.sourceComponent= undefined;

            }
        }
    }


    Component{
        id : vuePlacement
        PartiePlacement{
            id : me
            width: main.width
            height: main.height
            onTerminer: {
                loader_partie.sourceComponent = partie_principal
                me.visible = false;
            }
        }
    }
}
