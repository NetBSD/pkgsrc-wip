$NetBSD$

--- lib/scudo/scudo_platform.h.orig	2017-11-06 03:58:05.000000000 +0000
+++ lib/scudo/scudo_platform.h
@@ -16,7 +16,7 @@
 
 #include "sanitizer_common/sanitizer_allocator.h"
 
-#if !SANITIZER_LINUX && !SANITIZER_FUCHSIA
+#if !SANITIZER_LINUX && !SANITIZER_FUCHSIA && !SANITIZER_NETBSD
 # error "The Scudo hardened allocator is not supported on this platform."
 #endif
 
@@ -27,7 +27,7 @@
 # if SANITIZER_ANDROID || SANITIZER_FUCHSIA
 // Android and Fuchsia use a pool of TSDs shared between threads.
 #  define SCUDO_TSD_EXCLUSIVE 0
-# elif SANITIZER_LINUX && !SANITIZER_ANDROID
+# elif SANITIZER_NETBSD || (SANITIZER_LINUX && !SANITIZER_ANDROID)
 // Non-Android Linux use an exclusive TSD per thread.
 #  define SCUDO_TSD_EXCLUSIVE 1
 # else
