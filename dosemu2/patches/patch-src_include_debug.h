$NetBSD$

--- src/include/debug.h.orig	2017-11-02 06:22:58.000000000 +0000
+++ src/include/debug.h
@@ -3,4 +3,8 @@
  *
  * for details see file COPYING in the DOSEMU distribution
  */
+#ifdef __linux__
 #include "../arch/linux/async/debug.h"
+#elif defined(__NetBSD__)
+#include "../arch/netbsd/async/debug.h"
+#endif
