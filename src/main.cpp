#include <QApplication>
#include <QQmlApplicationEngine>
//#include <QQmlEngine>
#include <QtQml>
#include <QDebug>

#include "launcher.h"
#include "thememanager.h"
#include "Map/map.h"
#include "Map/casegraphique.h"
#include <QtWebView/QtWebView>
#include "Global/Navire/navire.h"
#include "Graphique/Global/Navire/naviregraphique.h"
#include "Global/logger.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QtWebView::initialize();

    QQmlApplicationEngine engine;
    Launcher launcher(&engine);

    //enregistre pour être instancié via le qml
    qmlRegisterType<CaseGraphique>("CaseImp", 1, 0, "Case");
    qmlRegisterType<NavireGraphique>("Navire", 1, 0, "NavireGraphique");

    qmlRegisterType<Map>();
    qmlRegisterType<Navire>();

    qmlRegisterSingletonType(QUrl("qrc:/Theme.qml"), "ThemeLoader", 1, 0, "Theme");

    engine.rootContext()->setContextProperty("ModeleLauncher",  &launcher);
    engine.rootContext()->setContextProperty("ThemeManager", ThemeManager::getInstance(&engine));
     engine.rootContext()->setContextProperty("logger",  Logger::getInstance());


    engine.load(QUrl(QStringLiteral("qrc:/qml/main.qml")));

    return app.exec();
}
