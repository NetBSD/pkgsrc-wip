$NetBSD: patch-plugins_bladesio1_gui.c,v 1.1 2013/11/12 12:26:33 othyro Exp $

Add NetBSD support.

--- plugins/bladesio1/gui.c.orig	2013-02-23 02:54:51.000000000 +0000
+++ plugins/bladesio1/gui.c
@@ -27,7 +27,11 @@
 
 #include <sys/socket.h>
 #include <sys/ioctl.h>
+#if defined(__linux__)
 #include <linux/if.h>
+#elif defined(__NetBSD__)
+#include <net/if.h>
+#endif
 #include <netinet/in.h>
 #include <arpa/inet.h>
 #include <netdb.h>
