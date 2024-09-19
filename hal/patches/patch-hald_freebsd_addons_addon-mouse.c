$NetBSD$

--- hald/freebsd/addons/addon-mouse.c.orig	2009-08-24 12:42:29.000000000 +0000
+++ hald/freebsd/addons/addon-mouse.c
@@ -29,7 +29,9 @@
 #include <sys/types.h>
 #include <sys/event.h>
 #include <sys/time.h>
+#ifdef __FreeBSD__
 #include <sys/proc.h>
+#endif
 #if __FreeBSD_version >= 800058
 #include <sys/types.h>
 #include <sys/user.h>
