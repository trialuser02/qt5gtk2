#!/bin/sh

MYDIR=$(dirname $0)

export QT_DEBUG_PLUGINS=1
export QT_QPA_PLATFORMTHEME=qt5gtk2
#export QT_QPA_PLATFORM_PLUGIN_PATH=$(dirname $0)/../../qt5gtk2/src/qt5gtk2-qtplugin
$MYDIR/standarddialogs
