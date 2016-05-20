pragma Singleton
import QtQuick 2.0


Item{

    property alias theme : themeLoader.item

    Loader{
        id : themeLoader
        source :Qt.resolvedUrl("qml/Theme.qml")


        Connections{
            target : ThemeManager
            onThemeChanged :{
                themeLoader.source = Qt.resolvedUrl("qml/Theme.qml")
                console.log(themeLoader.source);
            }
        }
    }

    function changerTheme(valeur){
        console.log(valeur);
        ThemeManager.theme = valeur;
    }

}
