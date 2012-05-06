$NetBSD: patch-src_netbsd.h,v 1.1 2012/05/06 10:47:16 imilh Exp $

--- src/netbsd.h.orig	2010-03-25 17:42:39.000000000 +0000
+++ src/netbsd.h
@@ -33,4 +33,6 @@
 int get_entropy_avail(unsigned int *);
 int get_entropy_poolsize(unsigned int *);
 
+kvm_t *kd;
+
 #endif /*NETBSD_H_*/
