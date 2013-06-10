$NetBSD: patch-yateclass.h,v 1.1 2013/06/10 12:33:30 othyro Exp $

Add NetBSD support.

--- yateclass.h.orig	2012-08-07 12:58:45.000000000 +0000
+++ yateclass.h
@@ -129,7 +129,7 @@ typedef unsigned long in_addr_t;
 #include <sys/time.h>
 #include <sys/socket.h>
 
-#if defined(__FreeBSD__)
+#if defined(__FreeBSD__) || defined(__NetBSD__)
 #include <netinet/in_systm.h>
 #endif
 
