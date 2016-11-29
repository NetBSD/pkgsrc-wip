$NetBSD$

--- net/udp/udp_socket_posix.cc.orig	2016-11-10 20:02:16.000000000 +0000
+++ net/udp/udp_socket_posix.cc
@@ -48,7 +48,7 @@ const int kBindRetries = 10;
 const int kPortStart = 1024;
 const int kPortEnd = 65535;
 
-#if defined(OS_MACOSX)
+#if defined(OS_MACOSX) || defined(OS_BSD)
 
 // Returns IPv4 address in network order.
 int GetIPv4AddressFromIndex(int socket, uint32_t index, uint32_t* address) {
@@ -672,7 +672,7 @@ int UDPSocketPosix::SetMulticastOptions(
   if (multicast_interface_ != 0) {
     switch (addr_family_) {
       case AF_INET: {
-#if !defined(OS_MACOSX)
+#if !defined(OS_MACOSX) && !defined(OS_BSD)
         ip_mreqn mreq;
         mreq.imr_ifindex = multicast_interface_;
         mreq.imr_address.s_addr = htonl(INADDR_ANY);
@@ -747,7 +747,7 @@ int UDPSocketPosix::JoinGroup(const IPAd
       if (addr_family_ != AF_INET)
         return ERR_ADDRESS_INVALID;
 
-#if !defined(OS_MACOSX)
+#if !defined(OS_MACOSX) && !defined(OS_BSD)
       ip_mreqn mreq;
       mreq.imr_ifindex = multicast_interface_;
       mreq.imr_address.s_addr = htonl(INADDR_ANY);
