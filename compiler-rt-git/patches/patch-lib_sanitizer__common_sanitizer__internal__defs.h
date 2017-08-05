$NetBSD$

--- lib/sanitizer_common/sanitizer_internal_defs.h.orig	2017-07-04 05:53:22.000000000 +0000
+++ lib/sanitizer_common/sanitizer_internal_defs.h
@@ -132,9 +132,9 @@ typedef int pid_t;
 // WARNING: OFF_T may be different from OS type off_t, depending on the value of
 // _FILE_OFFSET_BITS. This definition of OFF_T matches the ABI of system calls
 // like pread and mmap, as opposed to pread64 and mmap64.
-// FreeBSD, Mac and Linux/x86-64 are special.
-#if SANITIZER_FREEBSD || SANITIZER_MAC || \
-  (SANITIZER_LINUX && defined(__x86_64__))
+// FreeBSD, NetBSD, Mac and Linux/x86-64 are special.
+#if SANITIZER_FREEBSD || SANITIZER_NETBSD || SANITIZER_MAC || \
+    (SANITIZER_LINUX && defined(__x86_64__))
 typedef u64 OFF_T;
 #else
 typedef uptr OFF_T;
