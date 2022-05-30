$NetBSD$

Apparently FreeBSD adaptation, not recently confirmed (mef).

--- freebsd_ppi.h.orig	2022-05-07 20:29:58.000000000 +0000
+++ freebsd_ppi.h
@@ -21,7 +21,11 @@
 #ifndef freebsd_ppi_h
 #define freebsd_ppi_h
 
+#ifdef __FreeBSD__
 #include <dev/ppbus/ppi.h>
+#else
+#include <dev/misc/ppi/ppi.h>
+#endif
 
 #define ppi_claim(fd) {}
 
