$NetBSD$

Support NetBSD.

--- desktop_version/physfs/physfs_platform_unix.c.orig	2020-01-10 16:45:29.000000000 +0000
+++ desktop_version/physfs/physfs_platform_unix.c
@@ -57,6 +57,10 @@
 #include <sys/sysctl.h>
 #endif
 
+#ifdef __NetBSD__
+#include <sys/statvfs.h>
+#define statfs statvfs
+#endif
 
 #include "physfs_internal.h"
 
