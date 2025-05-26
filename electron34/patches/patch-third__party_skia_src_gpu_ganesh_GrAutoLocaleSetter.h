$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/skia/src/gpu/ganesh/GrAutoLocaleSetter.h.orig	2025-02-24 19:59:26.000000000 +0000
+++ third_party/skia/src/gpu/ganesh/GrAutoLocaleSetter.h
@@ -27,7 +27,7 @@
 #define HAVE_XLOCALE 0
 #endif
 
-#if defined(SK_BUILD_FOR_ANDROID) || defined(__UCLIBC__) || defined(_NEWLIB_VERSION)
+#if defined(SK_BUILD_FOR_ANDROID) || defined(__UCLIBC__) || defined(_NEWLIB_VERSION) || defined(__NetBSD__)
 #define HAVE_LOCALE_T 0
 #else
 #define HAVE_LOCALE_T 1
