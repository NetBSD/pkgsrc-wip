$NetBSD: patch-src__mongo__db__dur_recover.cpp,v 1.1 2012/11/29 14:52:38 fhajny Exp $

Backport Boost 1.50.x support based on
https://github.com/mongodb/mongo/commit/b3b1949de30b5dc1bde3d91aa197a8587d17d193
--- src/mongo/db/dur_recover.cpp.orig	2012-08-28 05:28:11.000000000 +0000
+++ src/mongo/db/dur_recover.cpp
@@ -72,7 +72,7 @@ namespace mongo {
                     i != boost::filesystem::directory_iterator();
                     ++i ) {
                 boost::filesystem::path filepath = *i;
-                string fileName = boost::filesystem::path(*i).leaf();
+                string fileName = boost::filesystem::path(*i).leaf().string();
                 if( str::startsWith(fileName, "j._") ) {
                     unsigned u = str::toUnsigned( str::after(fileName, '_') );
                     if( m.count(u) ) {
@@ -85,7 +85,7 @@ namespace mongo {
                 if( i != m.begin() && m.count(i->first - 1) == 0 ) {
                     uasserted(13532,
                     str::stream() << "unexpected file in journal directory " << dir.string()
-                      << " : " << boost::filesystem::path(i->second).leaf() << " : can't find its preceeding file");
+                      << " : " << boost::filesystem::path(i->second).leaf().string() << " : can't find its preceeding file");
                 }
                 files.push_back(i->second);
             }
