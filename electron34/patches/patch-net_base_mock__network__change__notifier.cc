$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- net/base/mock_network_change_notifier.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ net/base/mock_network_change_notifier.cc
@@ -103,7 +103,7 @@ MockNetworkChangeNotifier::GetCurrentCon
   return connection_cost_;
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 AddressMapOwnerLinux* MockNetworkChangeNotifier::GetAddressMapOwnerInternal() {
   return address_map_owner_;
 }
