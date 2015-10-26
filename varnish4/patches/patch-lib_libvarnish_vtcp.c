$NetBSD$

--- lib/libvarnish/vtcp.c.orig	2015-09-30 11:39:14.000000000 +0000
+++ lib/libvarnish/vtcp.c
@@ -32,6 +32,7 @@
 #include <sys/types.h>
 #include <sys/socket.h>
 #include <sys/ioctl.h>
+#include <sys/time.h>
 #ifdef HAVE_SYS_FILIO_H
 #  include <sys/filio.h>
 #endif
