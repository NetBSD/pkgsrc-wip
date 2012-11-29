$NetBSD: patch-src__mongo__db__dur_journal.cpp,v 1.1 2012/11/29 14:52:38 fhajny Exp $

Backport Boost 1.50.x support based on
https://github.com/mongodb/mongo/commit/b3b1949de30b5dc1bde3d91aa197a8587d17d193
--- src/mongo/db/dur_journal.cpp.orig	2012-08-28 05:28:11.000000000 +0000
+++ src/mongo/db/dur_journal.cpp
@@ -176,7 +176,7 @@ namespace mongo {
                 for ( boost::filesystem::directory_iterator i( getJournalDir() );
                         i != boost::filesystem::directory_iterator();
                         ++i ) {
-                    string fileName = boost::filesystem::path(*i).leaf();
+                    string fileName = boost::filesystem::path(*i).leaf().string();
                     if( anyFiles || str::startsWith(fileName, "j._") )
                         return true;
                 }
@@ -194,7 +194,7 @@ namespace mongo {
                 for ( boost::filesystem::directory_iterator i( getJournalDir() );
                         i != boost::filesystem::directory_iterator();
                         ++i ) {
-                    string fileName = boost::filesystem::path(*i).leaf();
+                    string fileName = boost::filesystem::path(*i).leaf().string();
                     if( str::startsWith(fileName, "j._") ) {
                         try {
                             removeOldJournalFile(*i);
