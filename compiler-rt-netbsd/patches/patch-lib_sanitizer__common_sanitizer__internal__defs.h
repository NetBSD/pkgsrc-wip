$NetBSD$

--- lib/sanitizer_common/sanitizer_internal_defs.h.orig	2017-10-02 13:17:03.000000000 +0000
+++ lib/sanitizer_common/sanitizer_internal_defs.h
@@ -39,6 +39,8 @@
 #if SANITIZER_LINUX
 # define SANITIZER_TLS_INITIAL_EXEC_ATTRIBUTE \
     __attribute__((tls_model("initial-exec"))) thread_local
+#elif SANITIZER_NETBSD
+# define SANITIZER_TLS_INITIAL_EXEC_ATTRIBUTE thread_local
 #else
 # define SANITIZER_TLS_INITIAL_EXEC_ATTRIBUTE
 #endif
