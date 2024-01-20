/***************************************************************************
 *   Copyright (C) 2015 The Qt Company Ltd.                                *
 *   Copyright (C) 2016-2024 Ilya Kotov, forkotov02@ya.ru                  *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.         *
 ***************************************************************************/

#include "qt5gtk2theme.h"
#include "qt5gtk2dialoghelpers.h"
#include <QVariant>

#undef signals
#include <gtk/gtk.h>

#include <X11/Xlib.h>

QT_BEGIN_NAMESPACE

const char *Qt5Gtk2Theme::name = "qt5gtk2";

static QString gtkSetting(const gchar *propertyName)
{
    GtkSettings *settings = gtk_settings_get_default();
    gchararray value;
    g_object_get(settings, propertyName, &value, NULL);
    QString str = QString::fromUtf8(value);
    g_free(value);
    return str;
}

Qt5Gtk2Theme::Qt5Gtk2Theme()
{
    // gtk_init will reset the Xlib error handler, and that causes
    // Qt applications to quit on X errors. Therefore, we need to manually restore it.
    int (*oldErrorHandler)(Display *, XErrorEvent *) = XSetErrorHandler(NULL);

    gtk_init(0, 0);

    XSetErrorHandler(oldErrorHandler);
}

QVariant Qt5Gtk2Theme::themeHint(QPlatformTheme::ThemeHint hint) const
{
    switch (hint) {
    case QPlatformTheme::SystemIconThemeName:
        return QVariant(gtkSetting("gtk-icon-theme-name"));
    case QPlatformTheme::SystemIconFallbackThemeName:
        return QVariant(gtkSetting("gtk-fallback-icon-theme"));
    case QPlatformTheme::StyleNames:
    {
        QStringList styleNames;
        styleNames << "qt5gtk2";
        //styleNames << QGnomeTheme::themeHint(hint).toStringList();
        return styleNames;
    }
#if (QT_VERSION >= QT_VERSION_CHECK(5, 10, 0))
    case QPlatformTheme::ShowShortcutsInContextMenus:
        return true;
#endif
    default:
        return QGnomeTheme::themeHint(hint);
    }
}

QString Qt5Gtk2Theme::gtkFontName() const
{
    QString cfgFontName = gtkSetting("gtk-font-name");
    if (!cfgFontName.isEmpty())
        return cfgFontName;
    return QGnomeTheme::gtkFontName();
}

bool Qt5Gtk2Theme::usePlatformNativeDialog(DialogType type) const
{
    switch (type) {
    case ColorDialog:
        return true;
    case FileDialog:
        return true;
    case FontDialog:
        return true;
    default:
        return false;
    }
}

QPlatformDialogHelper *Qt5Gtk2Theme::createPlatformDialogHelper(DialogType type) const
{
    switch (type) {
    case ColorDialog:
        return new Qt5Gtk2ColorDialogHelper;
    case FileDialog:
        return new Qt5Gtk2FileDialogHelper;
    case FontDialog:
        return new Qt5Gtk2FontDialogHelper;
    default:
        return 0;
    }
}

QT_END_NAMESPACE
