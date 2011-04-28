$NetBSD: patch-third__party_libjingle_source_talk_base_network.cc,v 1.1 2011/04/28 03:09:03 rxg Exp $

--- third_party/libjingle/source/talk/base/network.cc.orig	2011-04-13 08:13:43.000000000 +0000
+++ third_party/libjingle/source/talk/base/network.cc
@@ -252,7 +252,7 @@ bool NetworkManager::CreateNetworks(bool
 
   struct ifreq* ptr = reinterpret_cast<struct ifreq*>(ifc.ifc_buf);
   struct ifreq* end =
-      reinterpret_cast<struct ifreq*>(ifc.ifc_buf + ifc.ifc_len);
+      reinterpret_cast<struct ifreq*>((char *)ifc.ifc_buf + ifc.ifc_len);
 
   while (ptr < end) {
     struct sockaddr_in* inaddr =
