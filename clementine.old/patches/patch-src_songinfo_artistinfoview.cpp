$NetBSD$

Remove echonest support, see
https://github.com/clementine-player/Clementine/commit/a8a0f2e4fdd3d4b2fd23b8628a3abc27c290d01d

--- src/songinfo/artistinfoview.cpp.orig	2016-04-19 15:08:35.000000000 +0000
+++ src/songinfo/artistinfoview.cpp
@@ -16,24 +16,16 @@
 */
 
 #include "artistinfoview.h"
-#include "echonestbiographies.h"
-#include "echonestimages.h"
 #include "songinfofetcher.h"
 #include "songkickconcerts.h"
 #include "widgets/prettyimageview.h"
 
 #ifdef HAVE_LIBLASTFM
-#include "echonestsimilarartists.h"
-#include "echonesttags.h"
 #endif
 
 ArtistInfoView::ArtistInfoView(QWidget* parent) : SongInfoBase(parent) {
-  fetcher_->AddProvider(new EchoNestBiographies);
-  fetcher_->AddProvider(new EchoNestImages);
   fetcher_->AddProvider(new SongkickConcerts);
 #ifdef HAVE_LIBLASTFM
-  fetcher_->AddProvider(new EchoNestSimilarArtists);
-  fetcher_->AddProvider(new EchoNestTags);
 #endif
 }
 
