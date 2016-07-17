$NetBSD$

--- net/udp/udp_socket_unittest.cc.orig	2016-06-24 01:02:25.000000000 +0000
+++ net/udp/udp_socket_unittest.cc
@@ -266,7 +266,7 @@ TEST_F(UDPSocketTest, ConnectNonBlocking
 }
 #endif
 
-#if defined(OS_MACOSX)
+#if defined(OS_MACOSX) || defined(OS_BSD)
 // UDPSocketPrivate_Broadcast is disabled for OSX because it requires
 // root permissions on OSX 10.7+.
 TEST_F(UDPSocketTest, DISABLED_Broadcast) {
