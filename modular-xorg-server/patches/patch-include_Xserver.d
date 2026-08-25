$NetBSD$

--- include/Xserver.d.orig	2026-08-20 01:02:10.000000000 +0000
+++ include/Xserver.d
@@ -27,7 +27,7 @@
 #define string char *
 #define pid_t uint32_t
 #define zoneid_t uint32_t
-#elif defined(__FreeBSD__)
+#elif defined(__FreeBSD__) || defined(__NetBSD__)
 #define zoneid_t id_t
 #else
 #include <sys/types.h>
