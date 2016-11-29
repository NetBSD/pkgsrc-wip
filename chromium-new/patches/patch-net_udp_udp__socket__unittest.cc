$NetBSD$

--- net/udp/udp_socket_unittest.cc.orig	2016-11-10 20:02:16.000000000 +0000
+++ net/udp/udp_socket_unittest.cc
@@ -271,7 +271,7 @@ TEST_F(UDPSocketTest, ConnectNonBlocking
 }
 #endif
 
-#if defined(OS_MACOSX)
+#if defined(OS_MACOSX) || defined(OS_BSD)
 // UDPSocketPrivate_Broadcast is disabled for OSX because it requires
 // root permissions on OSX 10.7+.
 TEST_F(UDPSocketTest, DISABLED_Broadcast) {
