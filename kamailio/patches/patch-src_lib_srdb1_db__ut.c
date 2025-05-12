$NetBSD$

Work around namespace visibility issues with a big hammer, leaving
actually understanding and fixing properly for later.

Not yet reported upstream.

--- src/lib/srdb1/db_ut.c.orig	2025-03-20 08:05:45.000000000 +0000
+++ src/lib/srdb1/db_ut.c
@@ -33,6 +33,10 @@
 #include "../../core/pvar.h"
 #endif
 
+#if defined(__OS_netbsd)
+#include <sys/types.h>
+#endif
+
 /**
  * make strptime available
  * use 600 for 'Single UNIX Specification, Version 3'
@@ -45,6 +49,7 @@
 										* of the above define on
 										* features.h/unistd.h syscall() */
 #define _DEFAULT_SOURCE 1 /* _BSD_SOURCE is deprecated */
+#define _NETBSD_SOURCE
 #else
 #define _XOPEN_SOURCE_EXTENDED 1 /* solaris */
 #endif
