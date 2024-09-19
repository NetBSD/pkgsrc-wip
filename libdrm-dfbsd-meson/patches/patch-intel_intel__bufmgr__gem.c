$NetBSD$

--- intel/intel_bufmgr_gem.c.orig	2019-03-12 11:55:31.000000000 +0000
+++ intel/intel_bufmgr_gem.c
@@ -43,6 +43,9 @@
 #include <unistd.h>
 #include <assert.h>
 #include <pthread.h>
+#if defined(STRICT_XSRC_NETBSD)
+#include <stddef.h>
+#endif
 #include <sys/ioctl.h>
 #include <sys/stat.h>
 #include <sys/types.h>
