$NetBSD: patch-v8_src_globals.h,v 1.1 2011/05/27 13:23:09 rxg Exp $

--- v8/src/globals.h.orig	2011-05-24 08:20:55.000000000 +0000
+++ v8/src/globals.h
@@ -177,7 +177,8 @@ typedef byte* Address;
 #endif
 
 #if (defined(__APPLE__) && defined(__MACH__)) || \
-    defined(__FreeBSD__) || defined(__OpenBSD__)
+    defined(__DragonFly__) || defined(__FreeBSD__) || \
+    defined(__NetBSD__) || defined(__OpenBSD__)
 #define USING_BSD_ABI
 #endif
 
