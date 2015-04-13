$NetBSD: patch-src_watchdog_wd__packet.c,v 1.1 2015/04/13 20:00:00 fhajny Exp $

Needs sys/wait.h here too.
--- src/watchdog/wd_packet.c.orig	2015-04-08 07:28:03.000000000 +0000
+++ src/watchdog/wd_packet.c
@@ -33,6 +33,7 @@
 #include <sys/un.h>
 #include <sys/types.h>
 #include <sys/socket.h>
+#include <sys/wait.h>
 #include <netinet/in.h>
 #include <netinet/tcp.h>
 #include <netdb.h>
