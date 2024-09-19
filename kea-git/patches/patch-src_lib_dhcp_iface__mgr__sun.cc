$NetBSD$

* map conflicts with map from net/if.h, use std::map explicitly
* enable bpf filter
* get the mac adresses the right way on illumos
  based on illumos-ims.diff from
  https://gitlab.isc.org/isc-projects/kes/issues/631
  copyright ISC licensed under mpl-2.0
  https://www.mozilla.org/en-US/MPL/2.0/

--- src/lib/dhcp/iface_mgr_sun.cc.orig	2020-01-02 23:01:48.000000000 +0000
+++ src/lib/dhcp/iface_mgr_sun.cc
@@ -10,6 +10,7 @@
 
 #include <dhcp/iface_mgr.h>
 #include <dhcp/iface_mgr_error_handler.h>
+#include <dhcp/pkt_filter_bpf.h>
 #include <dhcp/pkt_filter_inet.h>
 #include <exceptions/exceptions.h>
 
@@ -39,7 +40,12 @@ IfaceMgr::detectIfaces() {
         isc_throw(Unexpected, "Network interfaces detection failed.");
     }
 
-    typedef map<string, IfacePtr> IfaceLst;
+    int sock = socket(PF_INET, SOCK_DGRAM, 0);
+    if (sock < 0) {
+        isc_throw(Unexpected, "Can't get a socket.");
+    }
+
+    typedef std::map<string, IfacePtr> IfaceLst;
     IfaceLst::iterator iface_iter;
     IfaceLst ifaces;
 
@@ -51,6 +57,7 @@ IfaceMgr::detectIfaces() {
         if (!(ifindex = if_nametoindex(ifname))) {
             // Interface name does not have corresponding index ...
             freeifaddrs(iflist);
+            close(sock);
             isc_throw(Unexpected, "Interface " << ifname << " has no index");
         }
 
@@ -62,9 +69,26 @@ IfaceMgr::detectIfaces() {
         IfacePtr iface(new Iface(ifname, ifindex));
         iface->setFlags(ifptr->ifa_flags);
         ifaces.insert(pair<string, IfacePtr>(ifname, iface));
+
+        // Get the MAC address.
+        struct lifreq lif;
+        memset(&lif, 0, sizeof(lif));
+        if (strlcpy(lif.lifr_name, ifname, LIFNAMSIZ) > LIFNAMSIZ) {
+           freeifaddrs(iflist);
+           close(sock);
+           isc_throw(Unexpected, "ifname to long for lifr_name in iface_mrg_sun");
+        }
+        if (ioctl(sock, SIOCGLIFHWADDR, &lif) < 0) {
+            continue;
+        }
+        struct sockaddr_dl * ldata =
+            reinterpret_cast<struct sockaddr_dl *>(&lif.lifr_addr);
+        const uint8_t * ptr = reinterpret_cast<uint8_t *>(LLADDR(ldata));
+        iface->setHWType(ldata->sdl_type);
+        iface->setMac(ptr, ldata->sdl_alen);
     }
 
-    // Second lookup to get MAC and IP addresses
+    // Second lookup to get IP addresses
     for (ifptr = iflist; ifptr != 0; ifptr = ifptr->ifa_next) {
         iface_iter = ifaces.find(ifptr->ifa_name);
         if (iface_iter == ifaces.end()) {
@@ -72,15 +96,7 @@ IfaceMgr::detectIfaces() {
         }
         // Common byte pointer for following data
         const uint8_t * ptr = 0;
-        if(ifptr->ifa_addr->sa_family == AF_LINK) {
-            // HWAddr
-            struct sockaddr_dl * ldata =
-                reinterpret_cast<struct sockaddr_dl *>(ifptr->ifa_addr);
-            ptr = reinterpret_cast<uint8_t *>(LLADDR(ldata));
-
-            iface_iter->second->setHWType(ldata->sdl_type);
-            iface_iter->second->setMac(ptr, ldata->sdl_alen);
-        } else if(ifptr->ifa_addr->sa_family == AF_INET6) {
+        if(ifptr->ifa_addr->sa_family == AF_INET6) {
             // IPv6 Addr
             struct sockaddr_in6 * adata =
                 reinterpret_cast<struct sockaddr_in6 *>(ifptr->ifa_addr);
@@ -100,6 +116,7 @@ IfaceMgr::detectIfaces() {
     }
 
     freeifaddrs(iflist);
+    close(sock);
 
     // Interfaces registering
     for(IfaceLst::const_iterator iface_iter = ifaces.begin();
@@ -124,10 +141,17 @@ void Iface::setFlags(uint64_t flags) {
 }
 
 void
-IfaceMgr::setMatchingPacketFilter(const bool /* direct_response_desired */) {
+IfaceMgr::setMatchingPacketFilter(const bool direct_response_desired) {
     // @todo Currently we ignore the preference to use direct traffic
     // because it hasn't been implemented for Solaris.
-    setPacketFilter(PktFilterPtr(new PktFilterInet()));
+    // Fixed: solaris/illumos now supports bpf
+    if (direct_response_desired) {
+        setPacketFilter(PktFilterPtr(new PktFilterBPF()));
+
+    } else {
+        setPacketFilter(PktFilterPtr(new PktFilterInet()));
+
+    }
 }
 
 bool
