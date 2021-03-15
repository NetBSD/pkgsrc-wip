$NetBSD$

--- src/3rdparty/chromium/net/socket/socks5_client_socket.cc.orig	2020-07-15 18:56:00.000000000 +0000
+++ src/3rdparty/chromium/net/socket/socks5_client_socket.cc
@@ -4,6 +4,10 @@
 
 #include "net/socket/socks5_client_socket.h"
 
+#if defined(OS_BSD)
+#include <netinet/in.h>
+#endif
+
 #include <utility>
 
 #include "base/bind.h"
