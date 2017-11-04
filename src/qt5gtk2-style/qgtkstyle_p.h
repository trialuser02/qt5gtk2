/***************************************************************************
 *   Copyright (C) 2015 The Qt Company Ltd.                                *
 *   Copyright (C) 2016-2017 Ilya Kotov, forkotov02@ya.ru                  *
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

#ifndef QGTKSTYLE_P_H
#define QGTKSTYLE_P_H

//
//  W A R N I N G
//  -------------
//
// This file is not part of the Qt API.  It exists purely as an
// implementation detail.  This header file may change from version to
// version without notice, or even be removed.
//
// We mean it.
//

//#include <private/qwindowsstyle_p.h>
#include <QPalette>
#include <QFont>
#include <QFileDialog>
#include <QCommonStyle>

QT_BEGIN_NAMESPACE


#if !defined(QT_NO_STYLE_GTK)

class QPainterPath;
class QGtkStylePrivate;

class QGtkStyle : public QCommonStyle
{
    Q_OBJECT
    Q_DECLARE_PRIVATE(QGtkStyle)

public:
    QGtkStyle();
    QGtkStyle(QGtkStylePrivate &dd);

    ~QGtkStyle();

    QPalette standardPalette() const Q_DECL_OVERRIDE;

    void drawPrimitive(PrimitiveElement element, const QStyleOption *option,
                       QPainter *painter, const QWidget *widget) const Q_DECL_OVERRIDE;
    void drawControl(ControlElement control, const QStyleOption *option,
                     QPainter *painter, const QWidget *widget) const Q_DECL_OVERRIDE;
    void drawComplexControl(ComplexControl control, const QStyleOptionComplex *option,
                            QPainter *painter, const QWidget *widget) const Q_DECL_OVERRIDE;
    void drawItemPixmap(QPainter *painter, const QRect &rect, int alignment,
                        const QPixmap &pixmap) const Q_DECL_OVERRIDE;
    void drawItemText(QPainter *painter, const QRect &rect, int alignment, const QPalette &pal,
                      bool enabled, const QString& text, QPalette::ColorRole textRole) const Q_DECL_OVERRIDE;

    int pixelMetric(PixelMetric metric, const QStyleOption *option = 0,
                    const QWidget *widget = 0) const Q_DECL_OVERRIDE;
    int styleHint(StyleHint hint, const QStyleOption *option,
                  const QWidget *widget, QStyleHintReturn *returnData) const Q_DECL_OVERRIDE;

    QStyle::SubControl hitTestComplexControl(ComplexControl cc, const QStyleOptionComplex *opt,
                              const QPoint &pt, const QWidget *w) const Q_DECL_OVERRIDE;

    QRect subControlRect(ComplexControl control, const QStyleOptionComplex *option,
                         SubControl subControl, const QWidget *widget) const Q_DECL_OVERRIDE;
    QRect subElementRect(SubElement sr, const QStyleOption *opt, const QWidget *w) const Q_DECL_OVERRIDE;
    QRect itemPixmapRect(const QRect &r, int flags, const QPixmap &pixmap) const Q_DECL_OVERRIDE;


    QSize sizeFromContents(ContentsType type, const QStyleOption *option,
                           const QSize &size, const QWidget *widget) const Q_DECL_OVERRIDE;
    QIcon standardIcon(StandardPixmap standardIcon, const QStyleOption *option = 0,
                       const QWidget *widget = 0) const Q_DECL_OVERRIDE;
    QPixmap standardPixmap(StandardPixmap sp, const QStyleOption *option,
                           const QWidget *widget) const Q_DECL_OVERRIDE;
    QPixmap generatedIconPixmap(QIcon::Mode iconMode, const QPixmap &pixmap,
                                const QStyleOption *opt) const Q_DECL_OVERRIDE;

    void polish(QWidget *widget) Q_DECL_OVERRIDE;
    void polish(QApplication *app) Q_DECL_OVERRIDE;
    void polish(QPalette &palette) Q_DECL_OVERRIDE;

    void unpolish(QWidget *widget) Q_DECL_OVERRIDE;
    void unpolish(QApplication *app) Q_DECL_OVERRIDE;
};

#endif //!defined(QT_NO_STYLE_QGTK)

QT_END_NAMESPACE

#endif //QGTKSTYLE_P_H
