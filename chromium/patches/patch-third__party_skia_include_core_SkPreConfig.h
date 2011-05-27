$NetBSD: patch-third__party_skia_include_core_SkPreConfig.h,v 1.2 2011/05/27 13:23:09 rxg Exp $

--- third_party/skia/include/core/SkPreConfig.h.orig	2011-05-24 08:02:00.000000000 +0000
+++ third_party/skia/include/core/SkPreConfig.h
@@ -37,7 +37,8 @@
         #define SK_BUILD_FOR_WIN32
     #elif defined(__SYMBIAN32__)
         #define SK_BUILD_FOR_WIN32
-    #elif defined(linux)
+    #elif defined(linux) || defined(__DragonFly__) || defined(__FreeBSD__) || \
+          defined(__NetBSD__) || defined(__OpenBSD__)
         #define SK_BUILD_FOR_UNIX
     #elif TARGET_OS_IPHONE || TARGET_IPHONE_SIMULATOR
         #define SK_BUILD_FOR_IOS
