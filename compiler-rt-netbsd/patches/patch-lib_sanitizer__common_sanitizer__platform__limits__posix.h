$NetBSD$

--- lib/sanitizer_common/sanitizer_platform_limits_posix.h.orig	2017-07-16 22:40:10.000000000 +0000
+++ lib/sanitizer_common/sanitizer_platform_limits_posix.h
@@ -15,6 +15,8 @@
 #ifndef SANITIZER_PLATFORM_LIMITS_POSIX_H
 #define SANITIZER_PLATFORM_LIMITS_POSIX_H
 
+#if SANITIZER_FREEBSD || SANITIZER_LINUX || SANITIZER_MAC
+
 #include "sanitizer_internal_defs.h"
 #include "sanitizer_platform.h"
 
@@ -1485,4 +1487,6 @@ struct __sanitizer_cookie_io_functions_t
   COMPILER_CHECK(offsetof(struct __sanitizer_##CLASS, MEMBER) ==          \
                  offsetof(struct CLASS, MEMBER))
 
+#endif // SANITIZER_FREEBSD || SANITIZER_LINUX || SANITIZER_MAC
+
 #endif
