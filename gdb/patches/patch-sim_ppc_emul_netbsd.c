$NetBSD: patch-sim_ppc_emul_netbsd.c,v 1.1 2013/06/01 14:16:29 makoto Exp $

time_t conversion compatibility, experimental.
Please correct the naming, thank you.

--- ./work/gdb-7.5.1/sim/ppc/emul_netbsd.c.orig	2013-06-01 22:30:13.000000000 +0900
+++ ./sim/ppc/emul_netbsd.c	2013-06-01 22:37:17.000000000 +0900
@@ -119,6 +119,7 @@
 
 #if WITH_NetBSD_HOST
 #define SYS(X) ASSERT(call == (SYS_##X))
+#define SYSSYS(X) ASSERT(call == (SYS___##X50))
 #else
 #define SYS(X)
 #endif
@@ -738,7 +739,11 @@
   if (WITH_TRACE && ppc_trace[trace_os_emul])
     printf_filtered ("0x%lx, 0x%lx", (long)t_addr, (long)tz_addr);
 
+#if 0
   SYS(gettimeofday);
+#else
+  SYS___gettimeofday50;
+#endif
   emul_write_status(processor, status, err);
   if (status == 0) {
     if (t_addr != 0)
@@ -768,7 +773,11 @@
   if (WITH_TRACE && ppc_trace[trace_os_emul])
     printf_filtered ("%d, 0x%lx", who, (long)rusage_addr);
 
+#if 0
   SYS(getrusage);
+#else
+  SYS___getrusage50;
+#endif
   emul_write_status(processor, status, err);
   if (status == 0) {
     if (rusage_addr != 0)
