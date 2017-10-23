$NetBSD$

--- lib/sanitizer_common/sanitizer_platform_limits_netbsd.h.orig	2017-10-20 11:21:05.000000000 +0000
+++ lib/sanitizer_common/sanitizer_platform_limits_netbsd.h
@@ -313,7 +313,7 @@ struct __sanitizer_wordexp_t {
   uptr we_nbytes;
 };
 
-typedef void __sanitizer_FILE;
+typedef char __sanitizer_FILE;
 #define SANITIZER_HAS_STRUCT_FILE 0
 
 extern int shmctl_ipc_stat;
