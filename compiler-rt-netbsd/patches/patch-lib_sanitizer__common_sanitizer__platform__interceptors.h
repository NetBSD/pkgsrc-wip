$NetBSD$

--- lib/sanitizer_common/sanitizer_platform_interceptors.h.orig	2018-01-08 15:33:13.000000000 +0000
+++ lib/sanitizer_common/sanitizer_platform_interceptors.h
@@ -432,4 +432,6 @@
 #define SANITIZER_INTERCEPT_SIGNAL_AND_SIGACTION (!SI_WINDOWS && SI_NOT_FUCHSIA)
 #define SANITIZER_INTERCEPT_BSD_SIGNAL SI_ANDROID
 
+#define SANITIZER_INTERCEPT_KVM SI_NETBSD
+
 #endif  // #ifndef SANITIZER_PLATFORM_INTERCEPTORS_H
