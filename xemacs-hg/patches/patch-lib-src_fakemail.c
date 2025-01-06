$NetBSD: patch-lib-src_fakemail.c,v 1.1 2017/11/15 14:57:58 hauke Exp $

Fix build on DragonFly.

--- lib-src/fakemail.c.orig	2025-01-06 18:59:57.821754390 +0000
+++ lib-src/fakemail.c
@@ -140,7 +140,7 @@ static boolean no_problems = true;
 #include <osreldate.h>
 #endif
 
-#if defined(__FreeBSD_version) && __FreeBSD_version >= 400000 
+#if defined(__FreeBSD_version) && __FreeBSD_version >= 400000  || defined(__DragonFly__)
 #define CURRENT_USER 
 #endif 
 
