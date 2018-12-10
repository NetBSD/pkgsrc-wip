$NetBSD$

--- lib/sanitizer_common/sanitizer_platform_interceptors.h.orig	2018-12-10 09:29:18.793406716 +0000
+++ lib/sanitizer_common/sanitizer_platform_interceptors.h
@@ -543,4 +543,9 @@
 #define SANITIZER_INTERCEPT_MD2 SI_NETBSD
 #define SANITIZER_INTERCEPT_SHA2 SI_NETBSD
 
+#define SANITIZER_INTERCEPT_VIS SI_NETBSD
+#define SANITIZER_INTERCEPT_NETBSD_MOUNT SI_NETBSD
+#define SANITIZER_INTERCEPT_CDBR SI_NETBSD
+#define SANITIZER_INTERCEPT_GETCHAR SI_POSIX
+
 #endif  // #ifndef SANITIZER_PLATFORM_INTERCEPTORS_H
