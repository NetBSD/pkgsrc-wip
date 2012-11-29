$NetBSD: patch-src__mongo__db__pdfile.cpp,v 1.1 2012/11/29 14:52:38 fhajny Exp $

Backport Boost 1.50.x support based on
https://github.com/mongodb/mongo/commit/b3b1949de30b5dc1bde3d91aa197a8587d17d193
--- src/mongo/db/pdfile.cpp.orig	2012-08-28 05:28:11.000000000 +0000
+++ src/mongo/db/pdfile.cpp
@@ -1675,7 +1675,7 @@ namespace mongo {
             virtual bool apply( const Path &p ) {
                 if ( !boost::filesystem::exists( p ) )
                     return false;
-                boostRenameWrapper( p, newPath_ / ( p.leaf() + ".bak" ) );
+                boostRenameWrapper( p, newPath_ / ( p.leaf().string() + ".bak" ) );
                 return true;
             }
             virtual const char * op() const {
@@ -1783,7 +1783,7 @@ namespace mongo {
             uniqueReservedPath( ( preserveClonedFilesOnFailure || backupOriginalFiles ) ?
                                 "backup" : "_tmp" );
         MONGO_ASSERT_ON_EXCEPTION( boost::filesystem::create_directory( reservedPath ) );
-        string reservedPathString = reservedPath.native_directory_string();
+        string reservedPathString = reservedPath.string();
 
         bool res;
         {
