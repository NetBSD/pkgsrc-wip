$NetBSD$

--- tools/hal-storage-unmount.c.orig	2008-08-10 13:50:10.000000000 +0000
+++ tools/hal-storage-unmount.c
@@ -31,13 +31,17 @@
 #include <string.h>
 #include <glib.h>
 #include <glib/gstdio.h>
-#ifdef __FreeBSD__
+#if defined(__FreeBSD__) || defined(__DragonFly__) || defined(__APPLE__)
 #include <fstab.h>
 #include <sys/param.h>
 #include <sys/ucred.h>
 #include <sys/mount.h>
 #include <limits.h>
 #include <pwd.h>
+#elif __NetBSD__
+#include <fstab.h>
+#include <sys/param.h>
+#include <sys/mount.h>
 #elif sun
 #include <fcntl.h>
 #include <sys/mnttab.h>
