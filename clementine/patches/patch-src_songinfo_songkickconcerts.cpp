$NetBSD$

Remove echonest support, see
https://github.com/clementine-player/Clementine/commit/a8a0f2e4fdd3d4b2fd23b8628a3abc27c290d01d

--- src/songinfo/songkickconcerts.cpp.orig	2016-04-19 15:08:35.000000000 +0000
+++ src/songinfo/songkickconcerts.cpp
@@ -21,9 +21,6 @@
 #include <QVBoxLayout>
 #include <QXmlStreamWriter>
 
-#include <echonest/Artist.h>
-#include <echonest/TypeInformation.h>
-
 #include <qjson/parser.h>
 
 #include "core/closure.h"
@@ -47,57 +44,13 @@ SongkickConcerts::SongkickConcerts() {
 }
 
 void SongkickConcerts::FetchInfo(int id, const Song& metadata) {
-  Echonest::Artist::SearchParams params;
-  params.push_back(
-      qMakePair(Echonest::Artist::Name, QVariant(metadata.artist())));
-  qLog(Debug) << "Params:" << params;
-  QNetworkReply* reply = Echonest::Artist::search(
-      params,
-      Echonest::ArtistInformation(Echonest::ArtistInformation::NoInformation,
-                                  QStringList() << kSongkickArtistBucket));
-  qLog(Debug) << reply->request().url();
-  NewClosure(reply, SIGNAL(finished()), this,
-             SLOT(ArtistSearchFinished(QNetworkReply*, int)), reply, id);
+  emit Finished(id);
+  return;
 }
 
 void SongkickConcerts::ArtistSearchFinished(QNetworkReply* reply, int id) {
-  reply->deleteLater();
-  try {
-    Echonest::Artists artists = Echonest::Artist::parseSearch(reply);
-    if (artists.isEmpty()) {
-      qLog(Debug) << "Failed to find artist in echonest";
-      emit Finished(id);
-      return;
-    }
-
-    const Echonest::Artist& artist = artists[0];
-    const Echonest::ForeignIds& foreign_ids = artist.foreignIds();
-    QString songkick_id;
-    for (const Echonest::ForeignId& id : foreign_ids) {
-      if (id.catalog == "songkick") {
-        songkick_id = id.foreign_id;
-        break;
-      }
-    }
-
-    if (songkick_id.isEmpty()) {
-      qLog(Debug) << "Failed to fetch songkick foreign id for artist";
-      emit Finished(id);
-      return;
-    }
-
-    QStringList split = songkick_id.split(':');
-    if (split.count() != 3) {
-      qLog(Error) << "Weird songkick id";
-      emit Finished(id);
-      return;
-    }
-
-    FetchSongkickCalendar(split[2], id);
-  } catch (Echonest::ParseError& e) {
-    qLog(Error) << "Error parsing echonest reply:" << e.errorType() << e.what();
-    emit Finished(id);
-  }
+  emit Finished(id);
+  return;
 }
 
 void SongkickConcerts::FetchSongkickCalendar(const QString& artist_id, int id) {
