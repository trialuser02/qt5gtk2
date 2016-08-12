#Qt version check (taken from QtCreator)
defineTest(minQtVersion) {
    maj = $$1
    min = $$2
    patch = $$3
    isEqual(QT_MAJOR_VERSION, $$maj) {
        isEqual(QT_MINOR_VERSION, $$min) {
            isEqual(QT_PATCH_VERSION, $$patch) {
                return(true)
            }
            greaterThan(QT_PATCH_VERSION, $$patch) {
                return(true)
            }
        }
        greaterThan(QT_MINOR_VERSION, $$min) {
            return(true)
        }
    }
    greaterThan(QT_MAJOR_VERSION, $$maj) {
        return(true)
    }
    return(false)
}

!minQtVersion(5, 7, 0) {
    message("Cannot build Qt5Gtk2 with Qt version $${QT_VERSION}.")
    error("Use at least Qt 5.7.0.")
}

TEMPLATE = subdirs

SUBDIRS += src/qt5gtk2-qtplugin src/qt5gtk2-style

include(qt5gtk2.pri)

message (PLUGINDIR=$$PLUGINDIR)
