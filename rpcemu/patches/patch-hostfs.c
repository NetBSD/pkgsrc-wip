$NetBSD: patch-hostfs.c,v 1.1.1.1 2011/09/28 14:55:43 ryo-on Exp $

* Support NetBSD

--- hostfs.c.orig	2010-09-19 19:25:37.000000000 +0000
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
