$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- net/base/mock_network_change_notifier.h.orig	2025-02-24 19:59:26.000000000 +0000
+++ net/base/mock_network_change_notifier.h
@@ -84,7 +84,7 @@ class MockNetworkChangeNotifier : public
   // use_default_connection_cost_implementation is set to true.
   ConnectionCost GetCurrentConnectionCost() override;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   void SetAddressMapOwnerLinux(AddressMapOwnerLinux* address_map_owner) {
     address_map_owner_ = address_map_owner;
   }
@@ -104,7 +104,7 @@ class MockNetworkChangeNotifier : public
   bool use_default_connection_cost_implementation_ = false;
   NetworkChangeNotifier::NetworkList connected_networks_;
   std::unique_ptr<SystemDnsConfigChangeNotifier> dns_config_notifier_;
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   raw_ptr<AddressMapOwnerLinux> address_map_owner_ = nullptr;
 #endif
 };
