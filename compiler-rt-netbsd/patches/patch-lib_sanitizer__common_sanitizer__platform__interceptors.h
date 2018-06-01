$NetBSD$

--- lib/sanitizer_common/sanitizer_platform_interceptors.h.orig	2018-06-01 09:36:54.000000000 +0000
+++ lib/sanitizer_common/sanitizer_platform_interceptors.h
@@ -498,4 +498,9 @@
 #define SANITIZER_INTERCEPT_PROTOENT SI_NETBSD
 #define SANITIZER_INTERCEPT_NETENT SI_NETBSD
 
+#define SANITIZER_INTERCEPT_SYSCTL SI_NETBSD
+#define SANITIZER_INTERCEPT_ATOF SI_NETBSD
+#define SANITIZER_INTERCEPT_FTS SI_NETBSD
+#define SANITIZER_INTERCEPT_REGEX SI_NETBSD
+
 #endif  // #ifndef SANITIZER_PLATFORM_INTERCEPTORS_H
