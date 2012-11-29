$NetBSD: patch-src__mongo__tools__tool.cpp,v 1.1 2012/11/29 14:52:39 fhajny Exp $

Backport Boost 1.50.x support based on
https://github.com/mongodb/mongo/commit/b3b1949de30b5dc1bde3d91aa197a8587d17d193
--- src/mongo/tools/tool.cpp.orig	2012-08-28 05:28:11.000000000 +0000
+++ src/mongo/tools/tool.cpp
@@ -118,12 +118,6 @@ namespace mongo {
         // we want durability to be disabled.
         cmdLine.dur = false;
 
-#if( BOOST_VERSION >= 104500 )
-    boost::filesystem::path::default_name_check( boost::filesystem2::no_check );
-#else
-    boost::filesystem::path::default_name_check( boost::filesystem::no_check );
-#endif
-
         _name = argv[0];
 
         /* using the same style as db.cpp */
