$NetBSD: patch-net_base_listen__socket__unittest.h,v 1.1 2011/04/28 03:09:02 rxg Exp $

--- net/base/listen_socket_unittest.h.orig	2011-04-13 08:01:17.000000000 +0000
+++ net/base/listen_socket_unittest.h
@@ -11,6 +11,7 @@
 #if defined(OS_WIN)
 #include <winsock2.h>
 #elif defined(OS_POSIX)
+#include <sys/types.h>
 #include <sys/socket.h>
 #include <errno.h>
 #include <arpa/inet.h>
