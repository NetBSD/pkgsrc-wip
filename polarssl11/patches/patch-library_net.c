--- library/net.c.orig	2011-12-22 10:06:27.000000000 +0000
+++ library/net.c	2012-12-05 22:30:14.000000000 +0000
@@ -59,10 +59,13 @@
 #include <netdb.h>
 #include <errno.h>
 
-#if defined(__FreeBSD__) || defined(__OpenBSD__)
+#if defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__NetBSD__) || \
+    defined(__DragonflyBSD__)
 #include <sys/endian.h>
 #elif defined(__APPLE__)
 #include <machine/endian.h>
+#elif defined(sun)
+#include <sys/isa_defs.h>
 #else
 #include <endian.h>
 #endif
