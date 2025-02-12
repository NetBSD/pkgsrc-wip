$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/net/base/mock_network_change_notifier.h.orig	2024-12-17 17:58:49.000000000 +0000
+++ src/3rdparty/chromium/net/base/mock_network_change_notifier.h
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
