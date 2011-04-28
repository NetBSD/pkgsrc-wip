$NetBSD: patch-third__party_skia_include_core_SkPreConfig.h,v 1.1 2011/04/28 03:09:03 rxg Exp $

--- third_party/skia/include/core/SkPreConfig.h.orig	2011-04-13 08:02:00.000000000 +0000
+++ third_party/skia/include/core/SkPreConfig.h
@@ -71,6 +71,8 @@
 #if !defined(SK_RESTRICT)
     #define SK_RESTRICT __restrict__
 #endif
+#undef SK_RESTRICT
+#define SK_RESTRICT
 
 //////////////////////////////////////////////////////////////////////
 
