$NetBSD$

--- lib/sanitizer_common/sanitizer_platform_limits_posix.h.orig	2017-07-16 22:40:10.000000000 +0000
+++ lib/sanitizer_common/sanitizer_platform_limits_posix.h
@@ -15,6 +15,10 @@
 #ifndef SANITIZER_PLATFORM_LIMITS_POSIX_H
 #define SANITIZER_PLATFORM_LIMITS_POSIX_H
 
+#if SANITIZER_NETBSD
+#error include sanitizer_platform_limits_netbsd.h on NetBSD
+#endif
+
 #include "sanitizer_internal_defs.h"
 #include "sanitizer_platform.h"
 
