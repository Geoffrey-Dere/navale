import QtQuick 2.0
import QtQuick.Controls 1.4
import ThemeLoader 1.0

MenuBar{
id :menu
    Menu{
        title : "fichier"
        MenuItem {
            text : "Quitter"
            shortcut: "Alt+F4"
            onTriggered: Qt.quit();


        }
    }
    Menu{
        title : "parametre"
        Menu{
            title : "couleur"
            MenuItem {
                text: "sombre"
                checkable: true
                exclusiveGroup:  ExclusiveGroup { id: couleur}
                onTriggered: Theme.changerTheme("sombre");
            }
            MenuItem {
                text: "vert"
                checkable: true
                exclusiveGroup: couleur
                onTriggered: Theme.changerTheme("");
            }
        }
    }

    Menu{
        title : "strategie"
            MenuItem {
                text: "aleatoire"
                checkable: true
                exclusiveGroup:  ExclusiveGroup { id: strategie}
                onTriggered: ModeleLauncher.strategie = "default";
                checked: ModeleLauncher.strategie === "default"
            }
            MenuItem {
                text: "En ligne"
                checkable: true
                exclusiveGroup: strategie
                onTriggered: ModeleLauncher.strategie = "ligne";
                checked: ModeleLauncher.strategie === "ligne";
            }
            MenuItem {
                text: "Diagonale"
                checkable: true
                exclusiveGroup: strategie
                onTriggered: ModeleLauncher.strategie = "diagonale";
                checked: ModeleLauncher.strategie === "diagonale";
            }

    }


}
//    Button{
//        text : "black"
//        onClicked: ThemeManager.theme = "sombre"
//    }

