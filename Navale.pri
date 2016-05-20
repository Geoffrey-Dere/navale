QT += qml quick widgets webview
CONFIG += c++11

HEADERS += \
    $$PWD/src/Global/Navire/navire2d.h \
    $$PWD/src/Global/Navire/navire3d.h \
    $$PWD/src/Global/Navire/navire2d.h \
    $$PWD/src/Global/Navire/navire3d.h \
    $$PWD/src/strategie/default.h \
    $$PWD/src/strategie/encroix.h \
    $$PWD/src/strategie/enligne.h \
    $$PWD/src/strategie/niveau.h \
    $$PWD/src/strategie/strategieattaque.h

SOURCES += \
    $$PWD/src/Global/Navire/navire2d.cpp \
    $$PWD/src/Global/Navire/navire3d.cpp \
    $$PWD/src/Global/Navire/navire2d.cpp \
    $$PWD/src/Global/Navire/navire3d.cpp \
    $$PWD/src/strategie/default.cpp \
    $$PWD/src/strategie/encroix.cpp \
    $$PWD/src/strategie/enligne.cpp \
    $$PWD/src/strategie/niveau.cpp \
    $$PWD/src/strategie/strategieattaque.cpp

DISTFILES += \
    $$PWD/model.qmodel
