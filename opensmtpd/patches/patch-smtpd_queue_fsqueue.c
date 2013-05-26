$NetBSD: patch-smtpd_queue_fsqueue.c,v 1.1 2013/05/26 20:34:34 szptvlfn Exp $

NetBSD use statvfs, not statfs.

--- smtpd/queue_fsqueue.c.orig	2013-05-16 15:19:59.000000000 +0000
+++ smtpd/queue_fsqueue.c
@@ -28,6 +28,10 @@
 #endif
 #include <sys/param.h>
 #include <sys/mount.h>
+#ifdef __NetBSD__
+#include <sys/statvfs.h>
+#define statfs statvfs
+#endif
 
 #include <ctype.h>
 #include <err.h>
