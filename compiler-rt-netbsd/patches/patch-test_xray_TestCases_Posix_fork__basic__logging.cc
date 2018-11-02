$NetBSD$

--- test/xray/TestCases/Posix/fork_basic_logging.cc.orig	2018-08-21 21:25:31.000000000 +0000
+++ test/xray/TestCases/Posix/fork_basic_logging.cc
@@ -15,14 +15,20 @@
 #include <stdio.h>
 #include <unistd.h>
 #include <stdint.h>
+#if !defined(__NetBSD__)
 #include <sys/syscall.h>
+#endif
 
 //modified from sanitizer
 
 static uintptr_t syscall_gettid() {
   uint64_t retval;
+#if defined(__NetBSD__)
+  retval = getpid();
+#else
   asm volatile("syscall" : "=a"(retval) : "a"(__NR_gettid) : "rcx", "r11",
                "memory", "cc");
+#endif
   return retval;
 }
 
