$NetBSD$

* enable test on illumos
* use ifru_Addr_sa that is available on illumos and linux

--- src/lib/dhcp/tests/iface_mgr_unittest.cc.orig	2022-07-26 06:08:02.000000000 +0000
+++ src/lib/dhcp/tests/iface_mgr_unittest.cc
@@ -1649,7 +1649,7 @@ TEST_F(IfaceMgrTest, setPacketFilter6) {
     EXPECT_NO_THROW(iface_mgr->setPacketFilter(custom_packet_filter));
 }
 
-#if defined OS_LINUX || OS_BSD
+#if defined OS_LINUX || OS_BSD || OS_SOLARIS
 
 // This test is only supported on Linux and BSD systems. It checks
 // if it is possible to use the IfaceMgr to select the packet filter
@@ -2782,7 +2782,7 @@ checkIfFlags(const Iface & iface,
 bool
 checkIfAddrs(const Iface & iface, struct ifaddrs *& ifptr) {
     const unsigned char * p = 0;
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_SOLARIS)
     // Workaround for Linux ...
     if(ifptr->ifa_data != 0) {
         // We avoid localhost as it has no MAC Address
@@ -2806,7 +2806,7 @@ checkIfAddrs(const Iface & iface, struct
         }
 
         const uint8_t * p =
-            reinterpret_cast<uint8_t *>(ifr.ifr_ifru.ifru_hwaddr.sa_data);
+            reinterpret_cast<uint8_t *>(ifr.ifr_ifru.ifru_addr.sa_data);
 
         close(s);
 
