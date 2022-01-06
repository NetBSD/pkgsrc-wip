$NetBSD$

Treat NetBSD like FreeBSD.

--- Source/MediaStorageAndFileFormat/gdcmFileStreamer.cxx.orig	2021-10-06 19:38:42.000000000 +0000
+++ Source/MediaStorageAndFileFormat/gdcmFileStreamer.cxx
@@ -32,7 +32,7 @@
 #include <io.h>
 typedef int64_t off64_t;
 #else
-#if defined(__APPLE__) || defined(__FreeBSD__)
+#if defined(__APPLE__) || defined(__FreeBSD__) || defined(__NetBSD__)
 #  define off64_t off_t
 #endif
 #include <unistd.h> // ftruncate
