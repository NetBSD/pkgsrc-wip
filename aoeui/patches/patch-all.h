$NetBSD: patch-all.h,v 1.2 2012/02/03 16:12:02 realzhtw Exp $

--- all.h.orig	2010-10-14 21:48:53.000000000 +0000
+++ all.h
@@ -23,8 +23,10 @@
 #include <sys/stat.h>
 #include <sys/time.h>
 #include <sys/wait.h>
-#ifdef __APPLE__
+#if defined(__APPLE__) || defined(__OpenBSD__) || defined(__NetBSD__)
 # include <util.h>
+#elif defined(__FreeBSD__) || defined(__DragonFly__)
+# include <libutil.h>
 #else
 # include <pty.h>
 #endif
