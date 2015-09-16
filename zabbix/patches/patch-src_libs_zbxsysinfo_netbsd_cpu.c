$NetBSD: patch-src_libs_zbxsysinfo_netbsd_cpu.c,v 1.1 2015/09/16 12:56:59 heidnes Exp $

Add some more includes to make this build on netbsd-7.

--- src/libs/zbxsysinfo/netbsd/cpu.c.orig	2015-02-23 12:28:14.000000000 +0000
+++ src/libs/zbxsysinfo/netbsd/cpu.c
@@ -24,6 +24,10 @@
 #include "zbxalgo.h"
 #include "zbxjson.h"
 
+#include <sys/types.h>
+#include <sys/sysctl.h>
+#include <uvm/uvm_extern.h>
+
 static int	get_cpu_num()
 {
 #ifdef HAVE_FUNCTION_SYSCTL_HW_NCPU	/* NetBSD 3.1 i386; NetBSD 4.0 i386 */
