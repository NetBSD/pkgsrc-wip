$NetBSD$

Avoid problem with macro of the same name on NetBSD.

--- engine/support.c.orig	2025-03-18 09:58:08.894815118 +0000
+++ engine/support.c
@@ -223,7 +223,7 @@ DCell timeval2us(struct timeval *tvp)
 #endif
 }
 
-DCell timespec2ns(struct timespec *tvp)
+DCell gf_timespec2ns(struct timespec *tvp)
 {
 #ifndef BUGGY_LONG_LONG
   return (tvp->tv_sec*(DCell)1000000000LL)+tvp->tv_nsec;
