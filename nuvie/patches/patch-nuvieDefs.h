$NetBSD: patch-nuvieDefs.h,v 1.1 2015/08/17 21:22:15 yhardy Exp $

Use random on NetBSD.

--- nuvieDefs.h.orig	2014-01-12 23:48:46.000000000 +0000
+++ nuvieDefs.h
@@ -108,7 +109,7 @@ typedef unsigned char BOOL;
 #endif
 
 
-#ifdef MACOSX
+#if defined(MACOSX) || defined(__NetBSD__)
 #define NUVIE_RAND random
 #else
 #define NUVIE_RAND rand
