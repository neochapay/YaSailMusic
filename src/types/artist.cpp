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

#include "artist.h"

Artist::Artist(QObject* parent)
    : QObject(parent)
    , d_ptr(new ArtistPrivate())
{
}

Artist::Artist(const Artist& other, QObject* parent)
    : QObject(parent)
    , d_ptr(other.d_ptr)
{
}

Artist::Artist(QJsonObject object, QObject* parent)
    : QObject(parent)
    , d_ptr(new ArtistPrivate())
{
    d_ptr->composer = object.value("composer").toBool();
    d_ptr->coverPrefix = object.value("cover").toObject().take("prefix").toString();
    d_ptr->coverType = object.value("cover").toObject().take("type").toString();
    d_ptr->coverUri = object.value("cover").toObject().take("uri").toString();
    // m_disclaimers = object.value("disclaimers").toArray();
    // m_genres = object.value("genres").toArray();
    d_ptr->name = object.value("name").toString();
    d_ptr->artistId = object.value("artistId").toString();
    d_ptr->various = object.value("various").toBool();
}

Artist::~Artist()
{
    delete d_ptr;
}

Artist& Artist::operator=(const Artist& other)
{
    *d_ptr = *other.d_ptr;
    return *this;
}

bool Artist::composer() const
{
    return d_ptr->composer;
}

const QString& Artist::coverPrefix() const
{
    return d_ptr->coverPrefix;
}

const QString& Artist::coverType() const
{
    return d_ptr->coverType;
}

const QString& Artist::coverUri() const
{
    return d_ptr->coverUri;
}

const QStringList& Artist::disclaimers() const
{
    return d_ptr->disclaimers;
}

const QStringList& Artist::genres() const
{
    return d_ptr->genres;
}

const QString& Artist::name() const
{
    return d_ptr->name;
}

QString Artist::artistId() const
{
    return d_ptr->artistId;
}

bool Artist::various() const
{
    return d_ptr->various;
}
