$NetBSD: patch-net_base_listen__socket__unittest.cc,v 1.1 2011/04/28 03:09:02 rxg Exp $

--- net/base/listen_socket_unittest.cc.orig	2011-04-13 08:01:17.000000000 +0000
+++ net/base/listen_socket_unittest.cc
@@ -6,6 +6,9 @@
 
 #include <fcntl.h>
 #include <sys/types.h>
+#if defined(OS_BSD)
+#include <netinet/in.h>
+#endif
 
 #include "base/eintr_wrapper.h"
 #include "net/base/net_util.h"
