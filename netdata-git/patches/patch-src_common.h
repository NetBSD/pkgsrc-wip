$NetBSD$

--- src/common.h.orig	2017-01-23 19:49:04.000000000 +0000
+++ src/common.h
@@ -23,9 +23,9 @@
 
 #else /* !defined(ENABLE_JEMALLOC) && !defined(ENABLE_TCMALLOC) */
 
-#if !(defined(__FreeBSD__) || defined(__APPLE__))
+#if !(defined(__FreeBSD__) || defined(__APPLE__) || defined(__NetBSD__))
 #include <malloc.h>
-#endif /* __FreeBSD__ || __APPLE__ */
+#endif /* __FreeBSD__ || __APPLE__ || __NetBSD__ */
 
 #endif
 
@@ -67,9 +67,9 @@
 #include <syslog.h>
 #include <sys/mman.h>
 
-#if !(defined(__FreeBSD__) || defined(__APPLE__))
+#if !(defined(__FreeBSD__) || defined(__APPLE__) || defined(__NetBSD__))
 #include <sys/prctl.h>
-#endif /* __FreeBSD__ || __APPLE__*/
+#endif /* __FreeBSD__ || __APPLE__ || __NetBSD__*/
 
 #include <sys/resource.h>
 #include <sys/socket.h>
@@ -187,10 +187,12 @@
 #include "plugin_freebsd.h"
 #elif defined(__APPLE__)
 #include "plugin_macos.h"
+#elif defined(__NetBSD__)
+#include "plugin_netbsd.h"
 #else
 #include "plugin_proc.h"
 #include "plugin_proc_diskspace.h"
-#endif /* __FreeBSD__, __APPLE__*/
+#endif /* __FreeBSD__, __APPLE__, __NetBSD__*/
 
 #include "plugin_tc.h"
 #include "plugins_d.h"
