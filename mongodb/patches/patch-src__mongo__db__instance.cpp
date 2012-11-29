$NetBSD: patch-src__mongo__db__instance.cpp,v 1.1 2012/11/29 14:52:38 fhajny Exp $

Backport Boost 1.50.x support based on
https://github.com/mongodb/mongo/commit/b3b1949de30b5dc1bde3d91aa197a8587d17d193
--- src/mongo/db/instance.cpp.orig	2012-08-28 05:28:11.000000000 +0000
+++ src/mongo/db/instance.cpp
@@ -833,13 +833,13 @@ namespace mongo {
                 i != boost::filesystem::directory_iterator(); ++i ) {
             if ( directoryperdb ) {
                 boost::filesystem::path p = *i;
-                string dbName = p.leaf();
+                string dbName = p.leaf().string();
                 p /= ( dbName + ".ns" );
                 if ( exists( p ) )
                     names.push_back( dbName );
             }
             else {
-                string fileName = boost::filesystem::path(*i).leaf();
+                string fileName = boost::filesystem::path(*i).leaf().string();
                 if ( fileName.length() > 3 && fileName.substr( fileName.length() - 3, 3 ) == ".ns" )
                     names.push_back( fileName.substr( 0, fileName.length() - 3 ) );
             }
@@ -1102,7 +1102,7 @@ namespace mongo {
     }
 
     void acquirePathLock(bool doingRepair) {
-        string name = ( boost::filesystem::path( dbpath ) / "mongod.lock" ).native_file_string();
+        string name = ( boost::filesystem::path( dbpath ) / "mongod.lock" ).string();
 
         bool oldFile = false;
 
