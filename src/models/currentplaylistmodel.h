/*
 * Copyright (C) 2023 Chupligin Sergey <neochapay@gmail.com>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public License
 * along with this library; see the file COPYING.LIB.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 */

#ifndef CURRENTPLAYLISTMODEL_H
#define CURRENTPLAYLISTMODEL_H

#include "../types/track.h"
#include "../types/playlist.h"

#include <QAbstractListModel>

class CurrentPlayListModel : public QAbstractListModel {
    Q_OBJECT
    Q_PROPERTY(int rowCount READ rowCount NOTIFY rowCountChanged)
    Q_PROPERTY(int currentIndex READ currentIndex WRITE setCurrentIndex NOTIFY currentIndexChanged)
    Q_PROPERTY(bool nextReady READ nextReady NOTIFY nextReadyChanged)

public:
    explicit CurrentPlayListModel(QObject* parent = 0);
    int currentIndex() const;
    void setCurrentIndex(int newCurrentIndex);

    virtual QVariant data(const QModelIndex& index, int role) const;

    int rowCount(const QModelIndex& parent = QModelIndex()) const;
    QHash<int, QByteArray> roleNames() const { return m_hash; }

    bool insertRow(int position, Track* track, const QModelIndex& index = QModelIndex());
    bool removeRows(int position, int rows, const QModelIndex& index = QModelIndex());

    Q_INVOKABLE void push(Track* track);
    Q_INVOKABLE void setPlaylist(Playlist* playlist);
    Q_INVOKABLE Track* getTrack(int index);
    Q_INVOKABLE Track* getCurrentTrack();
    Q_INVOKABLE Track* getPrevTrack();
    Q_INVOKABLE void clear();

    bool nextReady() const;

signals:
    void rowCountChanged();
    void currentIndexChanged();
    void nextReadyChanged();

private slots:
    void calculateNextready();

private:
    int m_currentIndex;

    QHash<int, QByteArray> m_hash;
    QList<Track*> m_currentTracks;
    Track* m_prevTrack;
    Track* m_nextTrack;
};

#endif // CURRENTPLAYLISTMODEL_H
