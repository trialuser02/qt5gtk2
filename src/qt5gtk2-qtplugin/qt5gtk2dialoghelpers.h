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

#ifndef QGTK2DIALOGHELPERS_P_H
#define QGTK2DIALOGHELPERS_P_H

#include <QHash>
#include <QList>
#include <QUrl>
#include <QScopedPointer>
#include <QString>
#include <qpa/qplatformdialoghelper.h>

typedef struct _GtkDialog GtkDialog;
typedef struct _GtkFileFilter GtkFileFilter;

QT_BEGIN_NAMESPACE

class QGtk2Dialog;
class QColor;

class Qt5Gtk2ColorDialogHelper : public QPlatformColorDialogHelper
{
    Q_OBJECT

public:
    Qt5Gtk2ColorDialogHelper();
    ~Qt5Gtk2ColorDialogHelper();

    bool show(Qt::WindowFlags flags, Qt::WindowModality modality, QWindow *parent) Q_DECL_OVERRIDE;
    void exec() Q_DECL_OVERRIDE;
    void hide() Q_DECL_OVERRIDE;

    void setCurrentColor(const QColor &color) Q_DECL_OVERRIDE;
    QColor currentColor() const Q_DECL_OVERRIDE;

private Q_SLOTS:
    void onAccepted();

private:
    static void onColorChanged(Qt5Gtk2ColorDialogHelper *helper);
    void applyOptions();

    QScopedPointer<QGtk2Dialog> d;
};

class Qt5Gtk2FileDialogHelper : public QPlatformFileDialogHelper
{
    Q_OBJECT

public:
    Qt5Gtk2FileDialogHelper();
    ~Qt5Gtk2FileDialogHelper();

    bool show(Qt::WindowFlags flags, Qt::WindowModality modality, QWindow *parent) Q_DECL_OVERRIDE;
    void exec() Q_DECL_OVERRIDE;
    void hide() Q_DECL_OVERRIDE;

    bool defaultNameFilterDisables() const Q_DECL_OVERRIDE;
    void setDirectory(const QUrl &directory) Q_DECL_OVERRIDE;
    QUrl directory() const Q_DECL_OVERRIDE;
    void selectFile(const QUrl &filename) Q_DECL_OVERRIDE;
    QList<QUrl> selectedFiles() const Q_DECL_OVERRIDE;
    void setFilter() Q_DECL_OVERRIDE;
    void selectNameFilter(const QString &filter) Q_DECL_OVERRIDE;
    QString selectedNameFilter() const Q_DECL_OVERRIDE;

private Q_SLOTS:
    void onAccepted();

private:
    static void onSelectionChanged(GtkDialog *dialog, Qt5Gtk2FileDialogHelper *helper);
    static void onCurrentFolderChanged(Qt5Gtk2FileDialogHelper *helper);
    void applyOptions();
    void setNameFilters(const QStringList &filters);

    QUrl _dir;
    QList<QUrl> _selection;
    QHash<QString, GtkFileFilter*> _filters;
    QHash<GtkFileFilter*, QString> _filterNames;
    QScopedPointer<QGtk2Dialog> d;
};

class Qt5Gtk2FontDialogHelper : public QPlatformFontDialogHelper
{
    Q_OBJECT

public:
    Qt5Gtk2FontDialogHelper();
    ~Qt5Gtk2FontDialogHelper();

    bool show(Qt::WindowFlags flags, Qt::WindowModality modality, QWindow *parent) Q_DECL_OVERRIDE;
    void exec() Q_DECL_OVERRIDE;
    void hide() Q_DECL_OVERRIDE;

    void setCurrentFont(const QFont &font) Q_DECL_OVERRIDE;
    QFont currentFont() const Q_DECL_OVERRIDE;

private Q_SLOTS:
    void onAccepted();

private:
    void applyOptions();

    QScopedPointer<QGtk2Dialog> d;
};

QT_END_NAMESPACE

#endif // QT5GTK2DIALOGHELPERS_P_H
