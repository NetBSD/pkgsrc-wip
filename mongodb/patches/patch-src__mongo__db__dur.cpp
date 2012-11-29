$NetBSD: patch-src__mongo__db__dur.cpp,v 1.1 2012/11/29 14:52:38 fhajny Exp $

Backport Boost 1.50.x support based on
https://github.com/mongodb/mongo/commit/b3b1949de30b5dc1bde3d91aa197a8587d17d193
--- src/mongo/db/dur.cpp.orig	2012-08-28 05:28:11.000000000 +0000
+++ src/mongo/db/dur.cpp
@@ -770,7 +770,7 @@ namespace mongo {
 
             bool samePartition = true;
             try {
-                const string dbpathDir = boost::filesystem::path(dbpath).native_directory_string();
+                const string dbpathDir = boost::filesystem::path(dbpath).string();
                 samePartition = onSamePartition(getJournalDir().string(), dbpathDir);
             }
             catch(...) {
