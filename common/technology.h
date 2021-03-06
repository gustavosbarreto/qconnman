/*
 * qconnman - Connman Applet
 * Copyright (C) 2011 O.S. Systems
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.

 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
*/

#ifndef _TECHNOLOGY_H
#define _TECHNOLOGY_H

#include <QObject>
#include <QDBusVariant>

class QDBusPendingCallWatcher;
class ConnmanTechnology;

class Technology: public QObject
{
    Q_OBJECT

public:
    Technology(const QString &path, QObject *parent);

    QString state();

signals:
    void propertiesChanged();
    void stateChanged();

private slots:
    void processProperties(QDBusPendingCallWatcher *watcher);
    void propertyChanged(const QString &name, const QDBusVariant &value);

private:
    ConnmanTechnology *m_technology;
    QVariantMap m_properties;
};

#endif
