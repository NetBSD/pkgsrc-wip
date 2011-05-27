$NetBSD: patch-net_base_net__util.cc,v 1.2 2011/05/27 13:23:09 rxg Exp $

--- net/base/net_util.cc.orig	2011-05-24 08:01:14.000000000 +0000
+++ net/base/net_util.cc
@@ -24,6 +24,7 @@
 #include <fcntl.h>
 #include <ifaddrs.h>
 #include <netdb.h>
+#include <sys/socket.h>
 #include <net/if.h>
 #include <netinet/in.h>
 #endif
