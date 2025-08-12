$NetBSD$

--- spa/plugins/support/cpu.c.orig	2024-10-21 16:08:11.337154178 +0000
+++ spa/plugins/support/cpu.c
@@ -10,7 +10,7 @@
 #include <sched.h>
 #include <fcntl.h>
 
-#if defined(__FreeBSD__) || defined(__MidnightBSD__)
+#if defined(__FreeBSD__) || defined(__MidnightBSD__) || defined(__NetBSD__)
 #include <sys/sysctl.h>
 #endif
 
@@ -86,7 +86,7 @@ impl_cpu_force_flags(void *object, uint3
 	return 0;
 }
 
-#ifndef __FreeBSD__
+#if !defined(__FreeBSD__) && !defined(__NetBSD__)
 static uint32_t get_count(struct impl *this)
 {
 	cpu_set_t cpuset;
