$NetBSD: patch-net_base_net__util.cc,v 1.1 2011/04/28 03:09:02 rxg Exp $

--- net/base/net_util.cc.orig	2011-04-13 08:01:17.000000000 +0000
+++ net/base/net_util.cc
@@ -25,9 +25,9 @@
 #include <fcntl.h>
 #include <ifaddrs.h>
 #include <netdb.h>
+#include <sys/socket.h>
 #include <net/if.h>
 #include <netinet/in.h>
-#include <sys/socket.h>
 #endif
 
 #include "base/base64.h"
