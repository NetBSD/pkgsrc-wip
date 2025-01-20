$NetBSD$

--- sysinfo.c.orig	2025-01-20 16:40:33.164730511 +0000
+++ sysinfo.c
@@ -30,9 +30,12 @@
 #include <sys/types.h>
 #include <sys/param.h>
 #include <sys/sysctl.h>
+#ifndef __NetBSD__
 #include <sys/user.h>
+#endif
 #include <sys/sysctl.h>
 
+#include <time.h>
 #include <limits.h>
 #include <kvm.h>
 #include <string.h>
