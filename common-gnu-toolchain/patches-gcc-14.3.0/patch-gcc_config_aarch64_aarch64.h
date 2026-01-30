$NetBSD$

--- gcc/config/aarch64/aarch64.h.orig	2025-05-23 11:02:04.284197394 +0000
+++ gcc/config/aarch64/aarch64.h
@@ -1410,7 +1410,8 @@ extern enum aarch64_code_model aarch64_c
 
 /* Extra specs when building a native AArch64-hosted compiler.
    Option rewriting rules based on host system.  */
-#if defined(__aarch64__)
+/* NetBSD does not export necessary info via /proc/cpuinfo. */
+#if defined(__aarch64__) && !defined(CROSS_DIRECTORY_STRUCTURE)
 extern const char *host_detect_local_cpu (int argc, const char **argv);
 #define HAVE_LOCAL_CPU_DETECT
 # define EXTRA_SPEC_FUNCTIONS                                           \
