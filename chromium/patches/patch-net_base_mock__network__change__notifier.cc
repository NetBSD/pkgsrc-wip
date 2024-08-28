$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- net/base/mock_network_change_notifier.cc.orig	2024-08-21 22:46:23.528962400 +0000
+++ net/base/mock_network_change_notifier.cc
@@ -103,7 +103,7 @@ MockNetworkChangeNotifier::GetCurrentCon
   return connection_cost_;
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 AddressMapOwnerLinux* MockNetworkChangeNotifier::GetAddressMapOwnerInternal() {
   return address_map_owner_;
 }
