$NetBSD$

--- lib/sanitizer_common/sanitizer_internal_defs.h.orig	2017-10-02 13:17:03.000000000 +0000
+++ lib/sanitizer_common/sanitizer_internal_defs.h
@@ -36,7 +36,7 @@
 #endif
 
 // TLS is handled differently on different platforms
-#if SANITIZER_LINUX
+#if SANITIZER_LINUX || SANITIZER_NETBSD
 # define SANITIZER_TLS_INITIAL_EXEC_ATTRIBUTE \
     __attribute__((tls_model("initial-exec"))) thread_local
 #else
