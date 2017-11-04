#Some conf to redirect intermediate stuff in separate dirs
UI_DIR=./.build/ui/
MOC_DIR=./.build/moc/
OBJECTS_DIR=./.build/obj
RCC_DIR=./.build/rcc

CONFIG += hide_symbols

QMAKE_DISTCLEAN += -r .build

#Install paths
unix {
  isEmpty(PLUGINDIR):PLUGINDIR = $$[QT_INSTALL_PLUGINS]
}
