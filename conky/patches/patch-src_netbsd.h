$NetBSD: patch-src_netbsd.h,v 1.2 2012/05/07 08:45:17 imilh Exp $

--- src/netbsd.h.orig	2010-03-25 17:42:39.000000000 +0000
+++ src/netbsd.h
@@ -12,6 +12,8 @@
 #include <kvm.h>
 #include <nlist.h>
 
+#include <pthread.h>
+
 #include <sys/time.h>
 #include <sys/sysctl.h>
 #include <sys/types.h>
@@ -33,4 +35,6 @@
 int get_entropy_avail(unsigned int *);
 int get_entropy_poolsize(unsigned int *);
 
+kvm_t *kd;
+
 #endif /*NETBSD_H_*/
