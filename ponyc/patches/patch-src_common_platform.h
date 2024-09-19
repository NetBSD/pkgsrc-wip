$NetBSD$

Add NetBSD

--- src/common/platform.h.orig	2019-07-27 10:37:45.000000000 +0000
+++ src/common/platform.h
@@ -34,6 +34,9 @@
 #elif defined(__DragonFly__)
 #  define PLATFORM_IS_BSD
 #  define PLATFORM_IS_DRAGONFLY
+#elif defined(__NetBSD__)
+#  define PLATFORM_IS_BSD
+#  define PLATFORM_IS_NETBSD
 #elif defined(__OpenBSD__)
 #  define PLATFORM_IS_BSD
 #  define PLATFORM_IS_OPENBSD
