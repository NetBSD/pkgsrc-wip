$NetBSD$

Builds on amd64.

--- clients/lcdproc/machine_NetBSD.c.orig	2021-01-24 06:10:24.774432154 +0000
+++ clients/lcdproc/machine_NetBSD.c
@@ -54,7 +54,11 @@
 #include <sys/dkstat.h>
 #include <sched.h>
 #include <uvm/uvm_extern.h>
+#ifdef __x86_64__
+#include <i386/apmvar.h>
+#else
 #include <machine/apmvar.h>
+#endif
 #include <errno.h>
 #include <sys/socket.h>
 #include <net/if.h>
