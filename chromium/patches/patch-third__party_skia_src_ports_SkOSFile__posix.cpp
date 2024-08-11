$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/skia/src/ports/SkOSFile_posix.cpp.orig	2024-07-24 02:45:41.951108000 +0000
+++ third_party/skia/src/ports/SkOSFile_posix.cpp
@@ -25,7 +25,7 @@
 #endif
 
 void sk_fsync(FILE* f) {
-#if !defined(SK_BUILD_FOR_ANDROID) && !defined(__UCLIBC__) && !defined(_NEWLIB_VERSION)
+#if !defined(SK_BUILD_FOR_ANDROID) && !defined(__UCLIBC__) && !defined(_NEWLIB_VERSION) && !defined(__OpenBSD__)
     int fd = fileno(f);
     fsync(fd);
 #endif
