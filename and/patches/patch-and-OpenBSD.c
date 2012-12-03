$NetBSD: patch-and-OpenBSD.c,v 1.1 2012/12/03 23:12:46 othyro Exp $

sys/resourcevar.h is not supposed to be exposed to userland.

--- and-OpenBSD.c.orig	2004-03-06 13:34:02.000000000 +0000
+++ and-OpenBSD.c
@@ -31,8 +31,9 @@
 #include <sys/proc.h>
 #include <sys/time.h>
 #include <sys/resource.h>
+#if !defined(__NetBSD__)
 #include <sys/resourcevar.h>
-
+#endif
 #ifdef __FreeBSD__
 #include <sys/user.h>
 #endif
