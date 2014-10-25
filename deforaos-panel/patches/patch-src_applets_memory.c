$NetBSD: patch-src_applets_memory.c,v 1.1 2014/10/25 00:00:42 khorben Exp $

--- src/applets/memory.c.orig	2014-06-27 11:22:53.000000000 +0000
+++ src/applets/memory.c
@@ -21,12 +21,13 @@
 #include <errno.h>
 #if defined(__linux__)
 # include <sys/sysinfo.h>
-#elif defined(__FreeBSD__) || defined(__NetBSD__)
+#elif defined(__FreeBSD__)
+# include <sys/sysctl.h>
+# include <sys/vmmeter.h>
+# include <vm/vm_param.h>
+#elif defined(__NetBSD__)
 # include <sys/sysctl.h>
 # include <sys/vmmeter.h>
-# if defined(__FreeBSD__)
-#  include <vm/vm_param.h>
-# endif
 #endif
 #include <libintl.h>
 #include "Panel.h"
