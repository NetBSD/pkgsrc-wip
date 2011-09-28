$NetBSD: patch-hostfs.c,v 1.1.1.1 2011/09/28 14:57:12 ryo-on Exp $

--- hostfs.c.orig	2011-09-28 02:57:08.000000000 +0000
+++ hostfs.c
@@ -31,7 +31,7 @@
 #else
 #include <unistd.h>
 #endif
-#if defined __unix || defined __MACH__
+#if defined __unix || defined __MACH__ || defined __NetBSD__
 #include <utime.h>
 #else
 #include <sys/utime.h>
