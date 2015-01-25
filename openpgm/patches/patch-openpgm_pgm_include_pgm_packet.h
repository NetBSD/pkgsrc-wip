$NetBSD: patch-openpgm_pgm_include_pgm_packet.h,v 1.1 2015/01/25 09:13:36 obache Exp $

--- openpgm/pgm/include/pgm/packet.h.orig	2011-03-23 06:43:10.000000000 +0000
+++ openpgm/pgm/include/pgm/packet.h
@@ -27,6 +27,7 @@
 
 #ifndef _WIN32
 #	include <sys/socket.h>
+#	include <netinet/in_systm.h>
 #	include <netinet/in.h>
 #	include <netinet/ip.h>
 #endif
