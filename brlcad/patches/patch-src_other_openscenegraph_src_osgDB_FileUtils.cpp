$NetBSD$

Add NetBSD support.

--- src/other/openscenegraph/src/osgDB/FileUtils.cpp.orig	2016-08-09 06:52:02.000000000 +0000
+++ src/other/openscenegraph/src/osgDB/FileUtils.cpp
@@ -76,7 +76,7 @@ typedef char TCHAR;
     #if (MAC_OS_X_VERSION_MAX_ALLOWED <= 1040)
         #define stat64 stat
     #endif
-#elif defined(__CYGWIN__) || defined(__FreeBSD__) || defined(__DragonFly__) || \
+#elif defined(__CYGWIN__) || defined(__FreeBSD__) || defined(__DragonFly__) || defined(__NetBSD__) || \
       (defined(__hpux) && !defined(_LARGEFILE64_SOURCE))
     #define stat64 stat
 #endif
@@ -1250,5 +1250,3 @@ bool osgDB::containsCurrentWorkingDirect
     {
     }
 #endif
-
-
