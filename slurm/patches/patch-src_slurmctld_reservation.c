$NetBSD: patch-src_slurmctld_reservation.c,v 1.1 2013/11/29 17:57:03 outpaddling Exp $

--- src/slurmctld/reservation.c.orig	2013-11-04 21:19:15.000000000 +0000
+++ src/slurmctld/reservation.c
@@ -44,7 +44,7 @@
 #  include <pthread.h>
 #endif				/* WITH_PTHREADS */
 
-#if defined(__FreeBSD__)
+#if defined(__FreeBSD__) || defined(__NetBSD__)
 #include <signal.h>
 #endif
 
