$NetBSD$
* map conflicts with map from net/if.h, use std::map explicitly
--- src/lib/dhcp/iface_mgr_sun.cc.orig	2019-11-19 14:50:43.000000000 +0000
+++ src/lib/dhcp/iface_mgr_sun.cc
@@ -39,7 +39,7 @@ IfaceMgr::detectIfaces() {
         isc_throw(Unexpected, "Network interfaces detection failed.");
     }
 
-    typedef map<string, IfacePtr> IfaceLst;
+    typedef std::map<string, IfacePtr> IfaceLst;
     IfaceLst::iterator iface_iter;
     IfaceLst ifaces;
 
