$NetBSD$

--- readline/rltty.c.orig	2017-09-11 11:24:05.000000000 +0000
+++ readline/rltty.c
@@ -31,6 +31,10 @@
 #include <errno.h>
 #include <stdio.h>
 
+//#if defined (HAVE_SYS_IOCTL_H)
+#  include <sys/ioctl.h>
+//#endif /* HAVE_UNISTD_H *
+
 #if defined (HAVE_UNISTD_H)
 #  include <unistd.h>
 #endif /* HAVE_UNISTD_H */
