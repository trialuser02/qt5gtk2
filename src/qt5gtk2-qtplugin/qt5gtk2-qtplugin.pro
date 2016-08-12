include(../../qt5gtk2.pri)

TARGET = qt5gtk2

QT += core-private gui-private platformsupport-private

HEADERS += \
    qt5gtk2theme.h \
    qt5gtk2dialoghelpers.h

SOURCES += \
        main.cpp \
    qt5gtk2theme.cpp \
    qt5gtk2dialoghelpers.cpp

TEMPLATE = lib
TARGET = qt5gtk2
CONFIG += plugin \
          link_pkgconfig \

PKGCONFIG += gtk+-2.0

target.path = $$PLUGINDIR/platformthemes
INSTALLS += target
