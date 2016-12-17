$NetBSD$

--- source/Plugins/Process/Linux/Procfs.h.orig	2016-09-10 17:36:23.000000000 +0000
+++ source/Plugins/Process/Linux/Procfs.h
@@ -12,6 +12,7 @@
 
 #include <sys/ptrace.h>
 
+#if !defined(__NetBSD__)
 #ifdef __ANDROID__
 #if defined(__arm64__) || defined(__aarch64__)
 typedef unsigned long elf_greg_t;
@@ -29,3 +30,4 @@ typedef struct user_fpsimd_state elf_fpr
 #else // __ANDROID__
 #include <sys/procfs.h>
 #endif // __ANDROID__
+#endif
