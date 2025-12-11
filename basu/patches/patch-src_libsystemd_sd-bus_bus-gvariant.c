$NetBSD$

--- src/libsystemd/sd-bus/bus-gvariant.c.orig	2022-12-16 10:13:02.000000000 +0000
+++ src/libsystemd/sd-bus/bus-gvariant.c
@@ -2,6 +2,8 @@
 
 #ifdef __FreeBSD__
 #include <sys/endian.h>
+#elif defined(__NetBSD__)
+#include <endian.h>
 #endif
 
 #include <errno.h>
