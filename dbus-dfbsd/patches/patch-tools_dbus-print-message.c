$NetBSD: patch-tools_dbus-print-message.c,v 1.2 2015/12/06 11:35:55 wiz Exp $

Fix build on NetBSD 5.x and 6.x.

--- tools/dbus-print-message.c.orig	2015-10-07 20:10:37.000000000 +0000
+++ tools/dbus-print-message.c
@@ -30,6 +30,9 @@
 #include <sys/un.h>
 #include <unistd.h>
 #include <netinet/in.h>
+#ifdef __NetBSD__
+#include <netinet/in_systm.h>
+#endif
 #include <netinet/ip.h>
 #include <arpa/inet.h>
 #endif
