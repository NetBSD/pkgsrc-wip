$NetBSD: patch-native__client_src_trusted_debug__stub_transport__common.cc,v 1.1 2011/05/27 13:23:09 rxg Exp $

--- native_client/src/trusted/debug_stub/transport_common.cc.orig	2011-05-24 08:19:25.000000000 +0000
+++ native_client/src/trusted/debug_stub/transport_common.cc
@@ -14,6 +14,7 @@
 
 #include <arpa/inet.h>
 #include <netdb.h>
+#include <netinet/in.h>
 #include <sys/select.h>
 #include <sys/socket.h>
 #include <sys/types.h>
