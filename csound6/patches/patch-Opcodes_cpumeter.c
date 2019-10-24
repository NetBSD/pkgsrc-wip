$NetBSD$

Add NetBSD and DragonFlyBSD support.

--- Opcodes/cpumeter.c.orig	2019-07-12 21:54:19.000000000 +0000
+++ Opcodes/cpumeter.c
@@ -36,7 +36,7 @@
 #include <float.h>
 
 // only available on Linux (no /proc/stat on OSX)
-#if defined(LINUX)
+#if defined(LINUX) || defined(__NetBSD__) || defined(__DragonFly__)
 /*######  Miscellaneous global stuff  ####################################*/
 #define SMLBUFSIZ (512)
 #define TEST (0)
