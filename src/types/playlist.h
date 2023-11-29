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

#ifndef PLAYLIST_H
#define PLAYLIST_H

#include "cover.h"
#include <QDateTime>
#include <QObject>

class PlaylistPrivate {
public:
    bool available;
    QString backgroundImageUrl;
    QString backgroundVideoUrl;
    Cover cover;
    Cover coverWithoutText;
    QDateTime created;
    QString description;
    QString descriptionFormatted;
    int durationMs;
    bool everPlayed;
    QString generatedPlaylistType;
    QString idForFrom;
    bool isBanner;
    bool isPremiere;
    int kind;
    QDateTime modified;
    QString ogImage;
    QString playlistUuid;
    int revision;
    int snapshot;
    QStringList tags;
    QString title;
    int trackCount;
};

class Playlist : public QObject {
    Q_OBJECT
    Q_PROPERTY(bool available READ available)
    Q_PROPERTY(QString backgroundImageUrl READ backgroundImageUrl)
    Q_PROPERTY(QString backgroundVideoUrl READ backgroundVideoUrl)
    Q_PROPERTY(Cover cover READ cover)
    Q_PROPERTY(Cover coverWithoutText READ coverWithoutText)
    Q_PROPERTY(QDateTime created READ created)
    Q_PROPERTY(QString description READ description)
    Q_PROPERTY(QString descriptionFormatted READ descriptionFormatted)
    Q_PROPERTY(int durationMs READ durationMs)
    Q_PROPERTY(bool everPlayed READ everPlayed)
    Q_PROPERTY(QString generatedPlaylistType READ generatedPlaylistType)
    Q_PROPERTY(QString idForFrom READ idForFrom)
    Q_PROPERTY(bool isBanner READ isBanner)
    Q_PROPERTY(bool isPremiere READ isPremiere)
    Q_PROPERTY(int kind READ kind)
    // TODO: add madeFor
    Q_PROPERTY(QDateTime modified READ modified)
    Q_PROPERTY(QString ogImage READ ogImage)
    // TODO: add owner
    Q_PROPERTY(QString playlistUuid READ playlistUuid)
    Q_PROPERTY(int revision READ revision)
    Q_PROPERTY(int snapshot READ snapshot)
    Q_PROPERTY(QStringList tags READ tags)
    Q_PROPERTY(QString title READ title)
    Q_PROPERTY(int trackCount READ trackCount)
    // TODO: add tracks

public:
    explicit Playlist(const Playlist& other, QObject* parent = nullptr);
    explicit Playlist(QJsonObject object, QObject* parent = nullptr);
    virtual ~Playlist();
    Playlist& operator=(const Playlist& other);

    bool available() const;
    const QString& backgroundImageUrl() const;
    const QString& backgroundVideoUrl() const;
    const Cover& cover() const;
    const Cover& coverWithoutText() const;
    const QDateTime& created() const;
    const QString& description() const;
    const QString& descriptionFormatted() const;
    int durationMs() const;
    bool everPlayed() const;
    const QString& generatedPlaylistType() const;
    const QString& idForFrom() const;
    bool isBanner() const;
    bool isPremiere() const;
    int kind() const;
    const QDateTime& modified() const;
    const QString& ogImage() const;
    const QString& playlistUuid() const;
    int revision() const;
    int snapshot() const;
    const QStringList& tags() const;
    const QString& title() const;
    int trackCount() const;

private:
    PlaylistPrivate* d_ptr;
};

#endif // PLAYLIST_H