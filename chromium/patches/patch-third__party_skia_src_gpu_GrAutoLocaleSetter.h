$NetBSD$

--- third_party/skia/src/gpu/GrAutoLocaleSetter.h.orig	2016-11-01 21:00:04.000000000 +0000
+++ third_party/skia/src/gpu/GrAutoLocaleSetter.h
@@ -22,7 +22,7 @@
 #include <xlocale.h>
 #endif
 
-#if defined(SK_BUILD_FOR_ANDROID) || defined(__UCLIBC__) || defined(_NEWLIB_VERSION)
+#if defined(SK_BUILD_FOR_ANDROID) || defined(__UCLIBC__) || defined(_NEWLIB_VERSION) || defined(__NetBSD__)
 #define HAVE_LOCALE_T 0
 #else
 #define HAVE_LOCALE_T 1
