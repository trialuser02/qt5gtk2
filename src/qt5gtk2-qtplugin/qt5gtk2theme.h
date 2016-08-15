/***************************************************************************
 *   Copyright (C) 2015 The Qt Company Ltd.                                *
 *   Copyright (C) 2016 Ilya Kotov, forkotov02@hotmail.ru                  *                               *
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

#ifndef QT5GTK2THEME_H
#define QT5GTK2THEME_H

#include <private/qgenericunixthemes_p.h>

QT_BEGIN_NAMESPACE

class Qt5Gtk2Theme : public QGnomeTheme
{
public:
    Qt5Gtk2Theme();

    virtual QVariant themeHint(ThemeHint hint) const Q_DECL_OVERRIDE;
    virtual QString gtkFontName() const Q_DECL_OVERRIDE;

    bool usePlatformNativeDialog(DialogType type) const Q_DECL_OVERRIDE;
    QPlatformDialogHelper *createPlatformDialogHelper(DialogType type) const Q_DECL_OVERRIDE;

    static const char *name;
};

QT_END_NAMESPACE

#endif // QT5GTK2THEME_H
