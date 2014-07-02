$NetBSD: patch-qt_src_3rdparty_sqlite_sqlite3.c,v 1.1 2014/07/02 21:20:08 fhajny Exp $

Do not mess with XOPEN_SOURCE on SunOS. Fixes GCC builds.
--- qt/src/3rdparty/sqlite/sqlite3.c.orig	2014-06-07 00:54:20.000000000 +0000
+++ qt/src/3rdparty/sqlite/sqlite3.c
@@ -424,7 +424,7 @@
 **
 ** See also ticket #2741.
 */
-#if !defined(_XOPEN_SOURCE) && !defined(__DARWIN__) && !defined(__APPLE__) && SQLITE_THREADSAFE && !defined(VXWORKS)
+#if !defined(_XOPEN_SOURCE) && !defined(__DARWIN__) && !defined(__APPLE__) && !defined(__sun) && SQLITE_THREADSAFE && !defined(VXWORKS)
 #  define _XOPEN_SOURCE 500  /* Needed to enable pthread recursive mutexes */
 #endif
 
