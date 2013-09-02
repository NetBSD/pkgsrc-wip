$NetBSD: patch-octcap__include_OC_oc__config.h,v 1.1 2013/09/02 19:08:25 thomasklausner Exp $

Add minimal NetBSD support.

--- octcap_include/OC/oc_config.h.orig	2010-10-27 12:30:16.000000000 +0000
+++ octcap_include/OC/oc_config.h
@@ -77,6 +77,9 @@
 #include <linux/module.h>
 #endif /* MODULE */
 
+#elif defined(__NetBSD__)
+#include <sys/endian.h>
+
 #elif defined(__hpux) && !defined(_KERNEL)
 
 #include <sys/stdsyms.h>
