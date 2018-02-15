$NetBSD$

--- lib/tsan/rtl/tsan_interceptors.cc.orig	2018-02-15 04:24:50.078973737 +0000
+++ lib/tsan/rtl/tsan_interceptors.cc
@@ -2424,7 +2424,7 @@ struct ScopedSyscall {
   }
 };
 
-#if !SANITIZER_FREEBSD && !SANITIZER_MAC && !SANITIZER_NETBSD
+#if !SANITIZER_FREEBSD && !SANITIZER_MAC
 static void syscall_access_range(uptr pc, uptr p, uptr s, bool write) {
   TSAN_SYSCALL();
   MemoryAccessRange(thr, pc, p, s, write);
