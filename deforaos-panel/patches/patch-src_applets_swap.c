$NetBSD: patch-src_applets_swap.c,v 1.1 2014/10/25 00:00:42 khorben Exp $

--- src/applets/swap.c.orig	2014-06-27 11:23:35.000000000 +0000
+++ src/applets/swap.c
@@ -23,6 +23,7 @@
 # include <sys/sysinfo.h>
 #elif defined(__NetBSD__)
 # include <sys/sysctl.h>
+# include <uvm/uvm_extern.h>
 #endif
 #include <libintl.h>
 #include "Panel.h"
