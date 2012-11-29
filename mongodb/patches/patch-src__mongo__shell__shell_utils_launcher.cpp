$NetBSD: patch-src__mongo__shell__shell_utils_launcher.cpp,v 1.1 2012/11/29 14:52:39 fhajny Exp $

Backport Boost 1.50.x support based on
https://github.com/mongodb/mongo/commit/b3b1949de30b5dc1bde3d91aa197a8587d17d193
--- src/mongo/shell/shell_utils_launcher.cpp.orig	2012-08-28 05:28:11.000000000 +0000
+++ src/mongo/shell/shell_utils_launcher.cpp
@@ -184,7 +184,7 @@ namespace mongo {
             }
 #endif
 
-            _argv.push_back( programPath.native_file_string() );
+            _argv.push_back( programPath.string() );
 
             _port = -1;
 
