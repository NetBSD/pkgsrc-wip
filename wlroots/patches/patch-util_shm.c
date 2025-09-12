$NetBSD$

* For fchmod(2)

--- util/shm.c.orig	2025-09-12 14:11:20.694413854 +0000
+++ util/shm.c
@@ -2,6 +2,9 @@
 #include <fcntl.h>
 #include <string.h>
 #include <sys/mman.h>
+#if defined(__NetBSD__)
+#define _NETBSD_SOURCE
+#endif
 #include <sys/stat.h>
 #include <time.h>
 #include <unistd.h>
