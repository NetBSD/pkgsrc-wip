$NetBSD$

--- lib/sanitizer_common/sanitizer_internal_defs.h.orig	2017-07-04 05:53:22.000000000 +0000
+++ lib/sanitizer_common/sanitizer_internal_defs.h
@@ -133,8 +133,8 @@ typedef int pid_t;
 // _FILE_OFFSET_BITS. This definition of OFF_T matches the ABI of system calls
 // like pread and mmap, as opposed to pread64 and mmap64.
 // FreeBSD, Mac and Linux/x86-64 are special.
-#if SANITIZER_FREEBSD || SANITIZER_MAC || \
-  (SANITIZER_LINUX && defined(__x86_64__))
+#if SANITIZER_FREEBSD || SANITIZER_NETBSD || SANITIZER_MAC || \
+    (SANITIZER_LINUX && defined(__x86_64__))
 typedef u64 OFF_T;
 #else
 typedef uptr OFF_T;
