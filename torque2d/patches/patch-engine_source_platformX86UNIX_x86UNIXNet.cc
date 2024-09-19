$NetBSD$

--- engine/source/platformX86UNIX/x86UNIXNet.cc.orig	2016-04-04 01:25:01.000000000 +0000
+++ engine/source/platformX86UNIX/x86UNIXNet.cc
@@ -39,12 +39,14 @@
 #include <net/if_ppp.h>
 #include <sys/ioctl.h>   /* ioctl() */
 #include <net/ppp_defs.h>
-#elif defined(__OpenBSD__) || defined(__FreeBSD__)
+#elif defined(__OpenBSD__) || defined(__FreeBSD__) || defined(__NetBSD__)
 #include <sys/ioctl.h>   /* ioctl() */
 #include <net/ppp_defs.h>
 #endif
 
+#if !defined(__NetBSD__)
 #include <netipx/ipx.h>
+#endif
 #include <stdlib.h>
 
 #include "console/console.h"
