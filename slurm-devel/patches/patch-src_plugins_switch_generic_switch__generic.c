$NetBSD: patch-src_plugins_switch_generic_switch__generic.c,v 1.1 2015/04/20 13:08:37 outpaddling Exp $

# Ensure proper #include order

--- src/plugins/switch/generic/switch_generic.c.orig	2015-03-19 19:38:01.000000000 +0000
+++ src/plugins/switch/generic/switch_generic.c
@@ -40,12 +40,13 @@
 #  include "config.h"
 #endif
 
-#if !defined(__FreeBSD__)
-#include <net/if.h>
-#endif
 #include <netinet/in.h>
 #include <arpa/inet.h>
 #include <sys/types.h>
+/* net/if.h must come after sys/types.h on NetBSD */
+#if !defined(__FreeBSD__)
+#include <net/if.h>
+#endif
 #include <sys/socket.h>
 #include <ifaddrs.h>
 #include <netdb.h>
