$NetBSD$

--- Engine/source/platformX86UNIX/x86UNIXNet.cpp.orig	2016-07-12 13:56:01.000000000 +0000
+++ Engine/source/platformX86UNIX/x86UNIXNet.cpp
@@ -40,12 +40,14 @@
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
