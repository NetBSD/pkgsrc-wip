$NetBSD: patch-all.h,v 1.3 2012/02/03 17:07:30 realzhtw Exp $

--- all.h.orig	2011-11-10 18:10:25.000000000 +0000
+++ all.h
@@ -23,7 +23,9 @@
 #include <sys/stat.h>
 #include <sys/time.h>
 #include <sys/wait.h>
-#if defined __APPLE__ || defined BSD
+#if defined __FreeBSD__
+# include <libutil.h>
+#elif defined __APPLE__ || defined __NetBSD__ || defined __OpenBSD__ || defined __DragonFly__
 # include <util.h>
 #else
 # include <pty.h>
