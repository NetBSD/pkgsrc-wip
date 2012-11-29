$NetBSD: patch-src__mongo__dbtests__framework.cpp,v 1.1 2012/11/29 14:52:38 fhajny Exp $

Backport Boost 1.50.x support based on
https://github.com/mongodb/mongo/commit/b3b1949de30b5dc1bde3d91aa197a8587d17d193
--- src/mongo/dbtests/framework.cpp.orig	2012-08-28 05:28:11.000000000 +0000
+++ src/mongo/dbtests/framework.cpp
@@ -199,7 +199,7 @@ namespace mongo {
                 boost::filesystem::create_directory(p);
             }
 
-            string dbpathString = p.native_directory_string();
+            string dbpathString = p.string();
             dbpath = dbpathString.c_str();
 
             cmdLine.prealloc = false;
