#include "audios.h"

Audios::Audios(QObject *parent) : RequestBase(parent)
{}

void Audios::add(qint64 ownerId, qint64 audioId) {
    QUrlQuery query;
    query.addQueryItem("owner_id", QString::number(ownerId));
    query.addQueryItem("audio_id", QString::number(audioId));
    _api->makeApiGetRequest("audio.add", query, ApiRequest::AUDIO_ADD);
}

void Audios::get() {
    QUrlQuery query;
    query.addQueryItem("settings2", "true");
    _api->makeApiGetRequest("/rotor/station/user:onyourwave/tracks", query, ApiRequest::AUDIO_GET);
}

void Audios::getRecommendations(int count) {
    QUrlQuery query;
    //if (ownerId != 0) query.addQueryItem("owner_id", QString::number(ownerId));
    query.addQueryItem("count", QString::number(count));
    _api->makeApiGetRequest("audio.getRecommendations", query, ApiRequest::AUDIO_GET);
}

void Audios::search(QString _query) {
    QUrlQuery query;
    query.addQueryItem("q", _query);
    query.addQueryItem("auto_complete", "1");
    query.addQueryItem("lyrics", "0");
    query.addQueryItem("performer_only", "0");
    query.addQueryItem("sort", "2");
    query.addQueryItem("count", "300");
    _api->makeApiGetRequest("audio.search", query, ApiRequest::AUDIO_SEARCH);
}