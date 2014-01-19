$NetBSD: patch-src_pulsecore_svolume__mmx.c,v 1.2 2014/01/19 23:17:02 makoto Exp $

Avoid bad register usage on OSX 32-bit.

--- src/pulsecore/svolume_mmx.c~	2014-01-19 23:46:10.000000000 +0900
+++ src/pulsecore/svolume_mmx.c	2014-01-19 23:48:02.000000000 +0900
@@ -243,7 +243,7 @@ static void pa_volume_s16re_mmx(int16_t 
 #endif /* defined (__i386__) || defined (__amd64__) */
 
 void pa_volume_func_init_mmx(pa_cpu_x86_flag_t flags) {
-#if defined (__i386__) || defined (__amd64__)
+#if (defined (__i386__) && !defined(__APPLE__)) || defined (__amd64__)
     if ((flags & PA_CPU_X86_MMX) && (flags & PA_CPU_X86_CMOV)) {
         pa_log_info("Initialising MMX optimized volume functions.");
 
