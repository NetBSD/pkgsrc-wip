$NetBSD: patch-nuvieDefs.h,v 1.1 2015/08/17 21:22:15 yhardy Exp $

Define nearbyint, use random on NetBSD.

--- nuvieDefs.h.orig	2014-01-12 23:48:46.000000000 +0000
+++ nuvieDefs.h
@@ -50,6 +50,7 @@ typedef uint8 nuvie_game_t; // Game type
 #define clamp_min(v, c)  (((v) < (c)) ? (c) : (v))
 #define clamp_max(v, c)  (((v) > (c)) ? (c) : (v))
 #define clamp(v, c1, c2) ( ((v) < (c1)) ? (c1) : (((v) > (c2)) ? (c2) : (v)) )
+#define nearbyint(f)     rint(f)
 
 #define WRAPPED_COORD(c,level) ((c)&((level)?255:1023))
 #define WRAP_COORD(c,level) ((c)&=((level)?255:1023))
@@ -108,7 +109,7 @@ typedef unsigned char BOOL;
 #endif
 
 
-#ifdef MACOSX
+#if defined(MACOSX) || defined(__NetBSD__)
 #define NUVIE_RAND random
 #else
 #define NUVIE_RAND rand
