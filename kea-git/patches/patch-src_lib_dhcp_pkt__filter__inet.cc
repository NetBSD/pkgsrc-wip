$NetBSD$

* illumos uses ip_pktinfo just like linux

--- src/lib/dhcp/pkt_filter_inet.cc.orig	2020-01-02 23:01:48.000000000 +0000
+++ src/lib/dhcp/pkt_filter_inet.cc
@@ -86,8 +86,8 @@ PktFilterInet::openSocket(Iface& iface,
                   << "/port=" << port);
     }
 
-    // On Linux systems IP_PKTINFO socket option is supported. This
-    // option is used to retrieve destination address of the packet.
+    // On Linux and Solaris systems IP_PKTINFO socket option is supported.
+    // This option is used to retrieve destination address of the packet.
 #if defined (IP_PKTINFO) && defined (OS_LINUX)
     int flag = 1;
     if (setsockopt(sock, IPPROTO_IP, IP_PKTINFO, &flag, sizeof(flag)) != 0) {
@@ -95,6 +95,13 @@ PktFilterInet::openSocket(Iface& iface,
         isc_throw(SocketConfigError, "setsockopt: IP_PKTINFO: failed.");
     }
 
+#elif defined (IP_RECVPKTINFO) && defined (OS_SOLARIS)
+    int flag = 1;
+    if (setsockopt(sock, IPPROTO_IP, IP_RECVPKTINFO, &flag, sizeof(flag)) != 0) {
+        close(sock);
+        isc_throw(SocketConfigError, "setsockopt: IP_RECVPKTINFO: failed.");
+    }
+
     // On BSD systems IP_RECVDSTADDR is used instead of IP_PKTINFO.
 #elif defined (IP_RECVDSTADDR) && defined (OS_BSD)
     int flag = 1;
@@ -167,7 +174,7 @@ PktFilterInet::receive(Iface& iface, con
 // Linux systems support IP_PKTINFO option which is used to retrieve the
 // destination address of the received packet. On BSD systems IP_RECVDSTADDR
 // is used instead.
-#if defined (IP_PKTINFO) && defined (OS_LINUX)
+#if defined (IP_PKTINFO) && (defined (OS_LINUX) || defined (OS_SOLARIS))
     struct in_pktinfo* pktinfo;
     struct cmsghdr* cmsg = CMSG_FIRSTHDR(&m);
 
@@ -243,7 +250,7 @@ PktFilterInet::send(const Iface&, uint16
 // In the future the OS-specific code may be abstracted to a different
 // file but for now we keep it here because there is no code yet, which
 // is specific to non-Linux systems.
-#if defined (IP_PKTINFO) && defined (OS_LINUX)
+#if defined (IP_PKTINFO) && (defined (OS_LINUX) || defined (OS_SOLARIS))
     // Setting the interface is a bit more involved.
     //
     // We have to create a "control message", and set that to
