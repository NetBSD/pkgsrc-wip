$NetBSD: patch-clucene_configs_clucene-config-generic.h,v 1.1 2012/09/04 16:52:14 ftigeot Exp $

float_t doesn't exist on NetBSD.

--- clucene/configs/clucene-config-generic.h.orig	2012-08-21 17:01:59.000000000 +0000
+++ clucene/configs/clucene-config-generic.h
@@ -48,6 +48,9 @@
 /* undef uint64_t uint64_t */
 
 /* undef float_t*/
+#if defined(__NetBSD__)
+typedef float float_t;
+#endif
 
 /* undef size_t size_t */
 
