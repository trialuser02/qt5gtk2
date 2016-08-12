#Some conf to redirect intermediate stuff in separate dirs
UI_DIR=./.build/ui/
MOC_DIR=./.build/moc/
OBJECTS_DIR=./.build/obj
RCC_DIR=./.build/rcc

CONFIG += hide_symbols


unix {
QMAKE_LFLAGS_DEBUG += "-Wl,--as-needed -Wl,--no-undefined -Wl,-z,relro -Wl,--build-id -Wl,--enable-new-dtags"
QMAKE_LFLAGS += "-Wl,--as-needed -Wl,--no-undefined -Wl,-z,relro -Wl,--build-id -Wl,--enable-new-dtags"
}

#Install paths
unix {

isEmpty(PLUGINDIR):PLUGINDIR = $$[QT_INSTALL_PLUGINS]
}
