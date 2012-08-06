$NetBSD: patch-library_net.c,v 1.1 2012/08/06 15:04:47 mwilhelmy Exp $

--- library/net.c.orig	2011-12-22 10:06:27.000000000 +0000
+++ library/net.c
@@ -59,7 +59,7 @@ static int wsa_init_done = 0;
 #include <netdb.h>
 #include <errno.h>
 
-#if defined(__FreeBSD__) || defined(__OpenBSD__)
+#if defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__NetBSD__)
 #include <sys/endian.h>
 #elif defined(__APPLE__)
 #include <machine/endian.h>
