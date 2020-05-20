$NetBSD: patch-lib_isc_unix_socket.c,v 1.3 2019/10/24 12:50:36 otis Exp $

* Fix build on SmartOS. In this special case, _XOPEN_SOURCE has to be only
  defined on SmartOS.

--- lib/isc/unix/socket.c.orig	2019-10-02 06:24:10.000000000 +0000
+++ lib/isc/unix/socket.c
@@ -11,6 +11,15 @@
 
 /*! \file */
 
+/* needed for CMSG_DATA */
+#if defined(__sun)
+#if (__STDC_VERSION__ - 0 < 199901L)
+#define _XOPEN_SOURCE 500
+#else
+#define _XOPEN_SOURCE 600
+#endif
+#endif
+
 #include <inttypes.h>
 #include <stdbool.h>
 #include <sys/param.h>
