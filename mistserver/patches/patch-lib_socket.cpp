$NetBSD$

Portability

--- lib/socket.cpp.orig	2026-01-29 16:39:02.000000000 +0000
+++ lib/socket.cpp
@@ -455,7 +455,13 @@ std::string Socket::getBinForms(std::str
   memset(&hints, 0, sizeof(struct addrinfo));
   hints.ai_family = AF_UNSPEC;
   hints.ai_socktype = SOCK_STREAM;
-  hints.ai_flags = AI_ADDRCONFIG | AI_V4MAPPED | AI_ALL;
+  hints.ai_flags = AI_ADDRCONFIG;
+#ifdef AI_V4MAPPED
+  hints.ai_flags |= AI_V4MAPPED;
+#endif
+#ifdef AI_ALL
+  hints.ai_flags |= AI_ALL;
+#endif
   hints.ai_protocol = 0;
   hints.ai_canonname = NULL;
   hints.ai_addr = NULL;
@@ -487,7 +493,11 @@ std::deque<Socket::Address> Socket::getA
   hints.ai_family = family==AF_UNSPEC?AF_INET6:family;
   hints.ai_socktype = SOCK_DGRAM;
   hints.ai_flags = AI_ADDRCONFIG | AI_PASSIVE;
+#ifdef AI_V4MAPPED
+#ifdef AI_ALL
   if (v4MappedResults) { hints.ai_flags |= AI_V4MAPPED | AI_ALL; }
+#endif
+#endif
   hints.ai_protocol = IPPROTO_UDP;
   int s = getaddrinfo(addr.c_str(), ss.str().c_str(), &hints, &result);
   if (!s){
@@ -1768,7 +1778,10 @@ void Socket::Connection::setHost(std::st
   memset(&hints, 0, sizeof(struct addrinfo));
   hints.ai_family = AF_UNSPEC;
   hints.ai_socktype = SOCK_STREAM;
-  hints.ai_flags = AI_ADDRCONFIG | AI_V4MAPPED;
+  hints.ai_flags = AI_ADDRCONFIG;
+#ifdef AI_V4MAPPED
+  hints.ai_flags |= AI_V4MAPPED;
+#endif
   hints.ai_protocol = 0;
   hints.ai_canonname = NULL;
   hints.ai_addr = NULL;
@@ -2913,7 +2926,10 @@ uint16_t Socket::UDPConnection::bind(int
   bool repeatWithIPv4 = false;
   struct addrinfo hints, *addr_result, *rp;
   memset(&hints, 0, sizeof(hints));
-  hints.ai_flags = AI_ADDRCONFIG | AI_PASSIVE | AI_V4MAPPED;
+  hints.ai_flags = AI_ADDRCONFIG | AI_PASSIVE;
+#ifdef AI_V4MAPPED
+  hints.ai_flags |= AI_V4MAPPED;
+#endif
   if (destAddr.size()){
     hints.ai_family = destAddr.family();
   }else{
