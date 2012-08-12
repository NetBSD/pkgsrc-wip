$NetBSD: patch-library_net.c,v 1.2 2012/08/12 20:28:46 mwilhelmy Exp $

NetBSD also has endian.h located in include/sys

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
