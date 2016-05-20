include(../Navale.pri)
#include(../deployment.pri)


TEMPLATE = app
TARGET = main

BUILD_PATH = ../../build
BIN_PATH = ../../bin

CONFIG(debug, debug|release) {
    # Debug
    DEFINES += CORE_DEBUG
    TARGET = $$join(TARGET,,,d)

    unix:OBJECTS_DIR = $${BUILD_PATH}/debug/.obj/unix
    win32:OBJECTS_DIR = $${BUILD_PATH}/debug/.obj/win32
    mac:OBJECTS_DIR = $${BUILD_PATH}/debug/.obj/mac
    UI_DIR = $${BUILD_PATH}/debug/.ui
    MOC_DIR = $${BUILD_PATH}/debug/.moc
    RCC_DIR = $${BUILD_PATH}/debug/.rcc

    # package destdir
    PACKAGE_DESTDIR	= $${BIN_PATH}/debug
    PACKAGE_TARGET	= TARGET

    mac:APP_DIR	= $${PACKAGE_DESTDIR}/$${PACKAGE_TARGET}.app/Contents/MacOs
    else:unix|win32:APP_DIR = $${PACKAGE_DESTDIR}
    APP_DIR = $${PACKAGE_DESTDIR}
    DESTDIR	= $$APP_DIR
}
else {
    # Release
    DEFINES += CORE_RELEASE

    unix:OBJECTS_DIR = $${BUILD_PATH}/debug/.obj/unix
    win32:OBJECTS_DIR = $${BUILD_PATH}/debug/.obj/win32
    mac:OBJECTS_DIR = $${BUILD_PATH}/debug/.obj/mac
    UI_DIR = $${BUILD_PATH}/debug/.ui
    MOC_DIR = $${BUILD_PATH}/debug/.moc
    RCC_DIR = $${BUILD_PATH}/debug/.rcc

    # package destdir
    PACKAGE_DESTDIR	= $${BIN_PATH}/release
    PACKAGE_TARGET	= TARGET

    mac:APP_DIR	= $${PACKAGE_DESTDIR}/$${PACKAGE_TARGET}.app/Contents/MacOs
    else:unix|win32:APP_DIR = $${PACKAGE_DESTDIR}
    APP_DIR = $${PACKAGE_DESTDIR}
    DESTDIR	= $$APP_DIR
}






RESOURCES += \
    qml.qrc \
    image.qrc


DISTFILES = \
    qml/Theme.qml \
    qml/+sombre/Theme.qml \
    qml/Entities/Navire.qml \
    Theme.qml \
    test.html \
    qml/Partie.qml \
    qml/Widget/Menus.qml \
    qml/Widget/Map/Carte.qml \
    qml/Widget/Map/Case.qml \
    qml/Launcher.qml \
    qml/main.qml \
    qml/PartiePlacement.qml \
    modele.qmodel \
    model2.qmodel

SOURCES = \
    main.cpp \
    launcher.cpp \
    niveau/niveau.cpp \
    strategie/strategieattaque.cpp \
    Map/map.cpp \
    thememanager.cpp \
    Global/partie.cpp \
    Map/casegraphique.cpp \
    strategie/encroix.cpp \
    strategie/enligne.cpp \
    Global/joueur.cpp \
    Global/navireFactory/factorymosaique.cpp \
    Global/navireFactory/xxmosaique.cpp \
    Global/Navire/navire2d.cpp \
     Global/Navire/navire3d.cpp \
    Global/Navire/navire4d.cpp \
    Global/partieFactory/partiefactory.cpp \
    Global/navireFactory/navireFactory.cpp \
    Global/partieFactory/partiesimplefactory.cpp \
    Global/Navire/xxcroiseur.cpp \
    Global/Navire/xvicaravelle.cpp \
    Global/Navire/xvigalion.cpp \
    Global/Navire/xxporteavion.cpp \
    Global/Navire/navire.cpp \
    Global/Navire/xxpatrouilleur.cpp \
    Global/Navire/xvichebec.cpp \
    Global/navireFactory/xvimosaique.cpp \
    Global/partieFactory/partiemosaiqueafactory.cpp \
    Global/navireFactory/simplefactory.cpp \
    Global/navireFactory/xxsimple.cpp \
    Global/navireFactory/xvisimple.cpp \
    Graphique/Global/Navire/naviregraphique.cpp \
    Map/caseMap.cpp \
    strategie/default.cpp \
    Global/logger.cpp \
    niveau/facile.cpp \
    niveau/moyen.cpp \
    niveau/difficile.cpp


HEADERS = \
    launcher.h \
    niveau/niveau.h \
    strategie/strategieattaque.h \
    Map/map.h \
    thememanager.h \
    Global/partie.h \
    Map/casegraphique.h \
    strategie/encroix.h \
    strategie/enligne.h \
    Global/joueur.h \
    Global/navireFactory/factorymosaique.h \
    Global/navireFactory/xxmosaique.h \
    Global/Navire/navire2d.h \
     Global/Navire/navire3d.h \
    Global/Navire/navire4d.h \
    Global/partieFactory/partiefactory.h \
    Global/navireFactory/navireFactory.h \
    Global/partieFactory/partiesimplefactory.h \
    Global/Navire/xxcroiseur.h \
    Global/Navire/xvicaravelle.h \
    Global/Navire/xvigalion.h \
    Global/Navire/xxporteavion.h \
    Global/Navire/navire.h \
    Global/Navire/xxpatrouilleur.h \
    Global/Navire/xvichebec.h \
    Global/navireFactory/xvimosaique.h \
    Global/partieFactory/partiemosaiqufactory.h \
    Global/navireFactory/simplefactory.h \
    Global/navireFactory/xxsimple.h \
    Global/navireFactory/xvisimple.h \
    Graphique/Global/Navire/naviregraphique.h \
    Map/caseMap.h \
    strategie/default.h \
    Global/logger.h \
    niveau/facile.h \
    niveau/moyen.h \
    niveau/difficile.h



