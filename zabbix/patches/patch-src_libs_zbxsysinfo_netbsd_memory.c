$NetBSD: patch-src_libs_zbxsysinfo_netbsd_memory.c,v 1.1 2015/09/16 12:56:59 heidnes Exp $

Add some more includes to make this build on netbsd-7.

--- src/libs/zbxsysinfo/netbsd/memory.c.orig	2015-02-23 12:28:14.000000000 +0000
+++ src/libs/zbxsysinfo/netbsd/memory.c
@@ -21,6 +21,10 @@
 #include "sysinfo.h"
 #include "log.h"
 
+#include <sys/types.h>
+#include <sys/sysctl.h>
+#include <uvm/uvm_extern.h>
+
 static int			mib[] = {CTL_VM, VM_UVMEXP2};
 static size_t			len;
 static struct uvmexp_sysctl	uvm;
